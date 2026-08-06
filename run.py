from subprocess import run

run(["cmake", ".", "-B", "build"], check=True)
run(["cmake", "--build", "build"], check=True)
run(["./build/src/compiler/compiler"], check=False)
