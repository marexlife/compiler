#ifndef COMPILER_APP_APP_H
#define COMPILER_APP_APP_H
#include <filesystem>
#include <vector>

#include "Cli.h"
#include "Lexer.h"
#include "absl/status/statusor.h"

namespace compiler::app {
class App final {
public:
    App() = default;

    void run(int argc, char** argv);

    template <typename FileAction, typename ShellAction>
    static void selectAction(absl::StatusOr<std::vector<std::filesystem::path>>&& userFiles,
        FileAction fileAction, ShellAction shellAction)
    {
        if (userFiles.ok() && userFiles->size() != 0) {
            fileAction(std::move(*userFiles));
        } else {
            shellAction();
        }
    }

    void runFileMode(std::vector<std::filesystem::path>&& filepaths);
    void runShellMode();

private:
    lex::Lexer lexer;
};
} // namespace compiler::app
#endif // COMPILER_APP_APP_H
