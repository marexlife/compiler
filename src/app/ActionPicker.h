#ifndef MAREX_APP_ACTIONPICKER_H
#define MAREX_APP_ACTIONPICKER_H
#include <string_view>

namespace marex::app {
template <typename FileAction, typename ShellAction,
          typename ShowHelpScreenAction>
static void select_action(
    int argc, char* argv[], FileAction file_action,
    ShellAction shell_action,
    ShowHelpScreenAction show_help_screen_action) {
    if (argc < 2) {
        shell_action();
        return;
    }

    const std::string_view first_argument = argv[1];

    static const std::string_view help_command =
        "--help";

    if (first_argument == help_command) [[unlikely]] {
        show_help_screen_action();

        return;
    }

    file_action(argc, argv);
}

}  // namespace marex::app
#endif  // MAREX_APP_ACTIONPICKER_H