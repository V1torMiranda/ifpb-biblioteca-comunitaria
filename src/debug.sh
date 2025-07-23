# !/bin/bash

g++ -g ./*.cpp ./*/*.cpp -o app  && gdb --tui ./app && rm ./app