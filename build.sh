#!/bin/sh

gcc -I./raylib/include \
    -std=c11 \
    -Wall -Wextra -Wshadow \
    -O2 -g3 \
    -o snake main.c \
    -L./raylib/lib -l:libraylib.a -lm
