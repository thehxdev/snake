#!/bin/sh

g++ -I./raylib/include \
    -std=c++11 -Wall -Wextra -Wshadow \
    -O2 -g3 -s -static \
    -o snake build.cpp \
    -L./raylib/lib -l:libraylib.a -lm
