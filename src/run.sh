# !/bin/bash

g++ ./*.cpp ./classes/*/*.cpp ./interfaces/*.cpp ./repositories/*.cpp ./services/*/*.cpp -o app && ./app && rm ./app