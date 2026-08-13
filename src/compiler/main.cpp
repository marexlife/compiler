#include "App.h"
#include <exception>
#include <iostream>

int main(int argc, char *argv[]) {
    try {
        marex::app::App().run(argc, argv);
    } catch (const std::exception &exception) {
        std::cout << exception.what() << '\n';
    } catch (...) {
        std::cout << "unkown error\n";
    }
}
