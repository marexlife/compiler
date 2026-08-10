#ifndef COMPILER_APP_APP_H
#define COMPILER_APP_APP_H
#include <filesystem>
#include <vector>

#include "Lexer.h"
#include "absl/status/statusor.h"

namespace compiler::app {
class App final {
public:
    App() = default;
    App(App&&) = delete;
    App& operator=(App&&) = delete;
    App(const App&) = delete;
    App& operator=(const App&) = delete;
    ~App() = default;

    void run(int argc, char** argv);

    template <typename FileAction, typename ShellAction>
    static void selectAction(
        absl::StatusOr<std::vector<std::filesystem::path>>&&
            userFilePaths,
        FileAction fileAction, ShellAction shellAction)
    {
        if (userFilePaths.ok() && userFilePaths->size() != 0) {
            fileAction(std::move(*userFilePaths));
        } else {
            shellAction();
        }
    }

    void runFileMode(std::vector<std::filesystem::path>&& filepaths);
    void runShellMode();
    [[nodiscard]] static std::string queryUserCommand();
    void executeUserCommand(std::string &&);

private:
    lex::Lexer lexer;
};
} // namespace compiler::app
#endif // COMPILER_APP_APP_H
