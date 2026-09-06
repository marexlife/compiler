rm -rf build
rm -rf tests/main.c
cmake . -B build -GNinja
cmake --build build
cd tests
./../build/src/main/main main.mrx
clang main.c -o app
./app
