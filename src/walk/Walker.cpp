#include "Walker.h"

#include <cstdlib>
#include <filesystem>
#include <format>
#include <fstream>
#include <stdexcept>
#include <string_view>

#include "Logger.h"

namespace marex::walk {
void Walker::run(
    parse::TranslationUnit&& translation_unit) {
    static const std::string_view output_file =
        "main.c";

    std::ofstream stream{output_file.data()};

    stream << translation_unit.as_string();

    core::Logger::log_info(
        std::format("wrote {}", output_file));

#ifdef _WINT32
    static std::string_view app_name = "app.exe";
#else
    static std::string_view app_name = "app";
#endif

    auto compile_command = std::format(
        "gcc {} -o {}", output_file, app_name);
    auto compile_command_result =
        std::system(compile_command.data());

    if (compile_command_result != 0) {
        throw std::runtime_error(
            "compiling file failed");
    }

    auto current_path =
        std::filesystem::current_path() / app_name;

    auto run_command_result =
        std::system(current_path.c_str());

    if (run_command_result != 0) {
        throw std::runtime_error(
            "compiling app failed");
    }
}
}  // namespace marex::walk