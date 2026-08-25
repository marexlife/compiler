#include <exception>
#include <iostream>

#include "App.h"

int main(int argc, char* argv[]) {
    try {
        marex::app::App app{};

        app.run(argc, argv);
    } catch (const std::exception& exception) {
        std::cout << exception.what() << '\n';
    } catch (...) {
        std::cout << "unkown error\n";
    }
}
