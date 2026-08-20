#ifndef MAREX_APP_APP_H
#define MAREX_APP_APP_H
#include "AppModeKind.h"
#include "Lexer.h"
#include "Logger.h"
#include <concepts>
#include <string_view>
#include <utility>

namespace marex::app {
class App final {
  public:
    App() = default;
    App(App &&) = delete;
    App &operator=(App &&) = delete;
    App(const App &) = delete;
    App &operator=(const App &) = delete;
    ~App() = default;

    void run(int argc, char **argv);

    template <typename FileAction, typename ShellAction>
    static void select_action(int argc, char *argv[],
                              FileAction file_action,
                              ShellAction shell_action) {
        if (argc < 2) {
            shell_action();
            return;
        }

        const std::string_view first_argument = argv[1];

        static const std::string_view help_command = "--help";

        if (first_argument == help_command) [[unlikely]] {
            show_help_screen();

            return;
        }

        file_action(argc, argv);
    }

    template <typename FileModeAction, typename ShellModeAction,
              typename... ActionArguments>
        requires std::invocable<FileModeAction, ActionArguments...> &&
                 std::invocable<ShellModeAction, ActionArguments...>
    static void
    handle_mode_kind(AppModeKind app_mode_kind,
                     FileModeAction &&file_mode_action,
                     ShellModeAction &&shell_mode_action,
                     ActionArguments... action_arguments) {
        switch (app_mode_kind) {
        case app::AppModeKind::FileMode:
            file_mode_action(
                std::forward<ActionArguments>(action_arguments)...);
            break;
        case app::AppModeKind::ShellMode:
            shell_mode_action(
                std::forward<ActionArguments>(action_arguments)...);
            break;
        case app::AppModeKind::Undecided:
            core::Logger::log_fatal_error(
                "compiler state is not decided");
        default:
            core::Logger::log_fatal_error("compile state is invalid");
        }
    }

    static void handle_lexer_failure(
        absl::StatusOr<lex::TokenStream> &lexer_result,
        AppModeKind app_mode_kind);
    static void show_help_screen();
    void compile_files(int argc, char *argv[]);
    void compile_file(std::string_view argument);

    void compile(std::string source_code, AppModeKind app_mode_kind);
    void run_shell_mode();
    void run_shell_iteration();
    [[nodiscard]] static std::string query_user_command();
    void execute_user_command(std::string &&);

  private:
    lex::Lexer lexer;
};
} // namespace marex::app
#endif // MAREX_APP_APP_H
