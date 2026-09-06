rm -rf build
cmake . -B build -GNinja
cmake --build build
cd tests
./../build/src/main/main main.mrx
clang main.c -o app
./app
