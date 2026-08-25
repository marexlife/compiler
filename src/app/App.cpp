#include "App.h"

#include <cstddef>
#include <cstdlib>
#include <filesystem>
#include <format>
#include <iostream>
#include <string>
#include <string_view>
#include <thread>
#include <utility>
#include <vector>

#include "ActionPicker.h"
#include "AppModeKind.h"
#include "Fetcher.h"
#include "Lexer.h"
#include "LexerPrinter.h"
#include "Logger.h"
#include "Parser.h"
#include "TokenStream.h"
#include "Walker.h"
#include "absl/status/statusor.h"

namespace marex::app {
void App::run(int argc, char* argv[]) {
    marex::app::select_action(
        argc, argv,
        [&](int argc, char* argv[]) {
            App::compile_files(argc, argv);
        },
        [&]() { App::run_shell_mode(); },
        [&]() { App::show_help_screen(); });
}

void App::compile_files(int argc, char* argv[]) {
    std::vector<std::jthread> workers;

    workers.reserve(
        static_cast<std::size_t>(argc - 1));

    for (char** arg = argv; arg != argv + argc;
         ++arg) {
        workers.emplace_back(std::jthread(
            [&]() { App::compile_file(*arg); }));
    }
}

void App::show_help_screen() {
    std::cout << R"(Help screen:
A. --help to get to here
B. 'clear;' to clear the screen in Shell mode
C. list files that should be compiled)";

    std::exit(EXIT_SUCCESS);
}

void App::compile(std::string source_code,
                  AppModeKind app_mode_kind) {
    absl::StatusOr<lex::TokenStream> lexer_result =
        lexer.run(std::move(source_code));

    if (!lexer_result.ok()) [[unlikely]] {
        handle_lexer_failure(lexer_result,
                             app_mode_kind);

        return;
    }

    lex::LexerPrinter::print_lexer_result(
        *lexer_result);

    parse::Parser::run(std::move(*lexer_result));
}

void App::handle_lexer_failure(
    absl::StatusOr<lex::TokenStream>& lexer_result,
    AppModeKind app_mode_kind) {
    marex::app::handle_mode_kind(
        app_mode_kind,
        [&](std::string_view error_message) {
            core::Logger::log_fatal_error(
                error_message);
        },
        [&](std::string_view error_message) {
            core::Logger::log_error(error_message);
        },
        lexer_result.status().message());
}

void App::compile_file(std::string_view argument) {
    const bool isDirectory =
        std::filesystem::is_directory(argument);

    if (!isDirectory) [[unlikely]] {
        std::string error_message = std::format(
            "{} argument is not a directory",
            argument);
        core::Logger::log_fatal_error(error_message);
    }

    std::string source_code =
        fetch::Fetcher::run(argument);

    App::compile(std::move(source_code),
                 AppModeKind::FileMode);
}

std::string App::query_user_command() {
    std::cout << "Input a command...\n";

    std::string user_command;
    std::getline(std::cin, user_command);

    return user_command;
}

void App::execute_user_command(
    std::string&& user_command) {
    App::compile(std::move(user_command),
                 AppModeKind::ShellMode);
}

void App::run_shell_iteration() {
    std::string user_command = query_user_command();

    App::execute_user_command(std::move(user_command));

    std::cin.get();
}

void App::run_shell_mode() {
    std::cout << "Shell mode:\n";

    for (;;) {
        App::run_shell_iteration();
    }
}
}  // namespace marex::app
