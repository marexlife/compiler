#ifndef MAREX_APP_ACTIONPICKER_H
#define MAREX_APP_ACTIONPICKER_H
#include "AppModeKind.h"
#include "Logger.h"
#include <string_view>

namespace marex::app {
template <typename FileAction, typename ShellAction,
    typename ShowHelpScreenAction>
static void select_action(int argc, char* argv[],
    FileAction file_action, ShellAction shell_action,
    ShowHelpScreenAction show_help_screen_action)
{
    if (argc < 2) {
        shell_action();
        return;
    }

    const std::string_view first_argument = argv[1];

    static const std::string_view help_command
        = "--help";

    if (first_argument == help_command) [[unlikely]] {
        show_help_screen_action();

        return;
    }

    file_action(argc, argv);
}

template <typename FileModeAction,
    typename ShellModeAction,
    typename... ActionArguments>
    requires std::invocable<FileModeAction,
                 ActionArguments...>
    && std::invocable<ShellModeAction,
        ActionArguments...>
static void handle_mode_kind(AppModeKind app_mode_kind,
    FileModeAction&& file_mode_action,
    ShellModeAction&& shell_mode_action,
    ActionArguments... action_arguments)
{
    switch (app_mode_kind) {
    case app::AppModeKind::FileMode:
        file_mode_action(std::forward<ActionArguments>(
            action_arguments)...);
        break;
    case app::AppModeKind::ShellMode:
        shell_mode_action(
            std::forward<ActionArguments>(
                action_arguments)...);
        break;
    case app::AppModeKind::Undecided:
        core::Logger::log_fatal_error(
            "compiler state is not decided");
    default:
        core::Logger::log_fatal_error(
            "compile state is invalid");
    }
}
} // namespace marex::app
#endif // MAREX_APP_ACTIONPICKER_H