# !/bin/bash

g++ ./*.cpp ./*/*.cpp -o app  && gdb ./app && rm ./app