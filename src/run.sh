# !/bin/bash

g++ ./*.cpp ./classes/*/*.cpp ./repositories/**/*.cpp ./services/FstreamAdapter/*.cpp -o app && ./app && rm ./app