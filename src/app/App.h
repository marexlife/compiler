#ifndef COMPILER_APP_APP_H
#define COMPILER_APP_APP_H
#include "Lexer.h"
#include <cstddef>
#include <string_view>

namespace compiler::app {
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
    static void selectAction(int argc, char *argv[],
                             FileAction fileAction,
                             ShellAction shellAction) {
        if (argc < 2) {
            shellAction();
            return;
        }

        const std::string_view firstArgument = argv[1];

        static const std::string_view helpCommand = "--help";

        if (firstArgument == helpCommand) {
            showHelpScreen();

            return;
        }

        fileAction(argc, argv);
    }

    static void showHelpScreen();
    void compileFiles(int argc, char *argv[]);
    void compileFile(std::string_view argument, std::size_t fileId);

    void compile(std::string &&sourceCode);
    void runShellMode();
    void runShellIteration();
    [[nodiscard]] static std::string queryUserCommand();
    void executeUserCommand(std::string &&);

  private:
    lex::Lexer lexer;
};
} // namespace compiler::app
#endif // COMPILER_APP_APP_H
