import os
from subprocess import run

run(["cmake", ".", "-B", "build"], check=True)
run(["cmake", "--build", "build"], check=True)

if os.name == "nt":
    run(["./build/src/compiler/Debug/compiler.exe"], check=False)
else:
    run(["./build/src/compiler/compiler"], check=False)
