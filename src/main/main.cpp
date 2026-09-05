#include <exception>
#include <format>
#include <functional>
#include <print>
#include <string_view>

#include "App.h"

int main(int argc, char* argv[]) {
    const auto message =
        std::invoke([&] -> std::string_view {
            try {
                marex::app::App app{};

                app.run(argc, argv);

                return "success";
            } catch (const std::exception& exception) {
                return exception.what();
            } catch (...) {
                return "unkown error";
            }
        });

    std::println("{}", message);
}
