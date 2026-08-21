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
