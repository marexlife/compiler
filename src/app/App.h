#ifndef COMPILER_APP_APP_H
#define COMPILER_APP_APP_H
#include <filesystem>

#include "Cli.h"
#include "Lexer.h"

namespace compiler::app {
class App final {
public:
    App() = default;

    void run(int argc, char** argv);

    template <typename FileAction, typename ShellAction>
    static void selectAction(int argc, char** argv,
        FileAction fileAction, ShellAction shellAction)
    {
        if (auto user_filepath
            = cl::Cli::getUserFilesPath(argc, argv);
            user_filepath.ok()) [[likely]] {

            if (user_filepath->size() == 0) {
                goto shell;
            }

            fileAction(std::move(*user_filepath));

            return;
        }

    shell:
        shellAction();
    }

    void runFileMode(std::vector<std::filesystem::path>&& filepaths);
    void runShellMode();

private:
    lex::Lexer lexer;
};
} // namespace compiler::app
#endif // COMPILER_APP_APP_H
