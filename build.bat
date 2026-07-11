@echo off

call gcc -I.\raylib\include ^
     -std=c11 ^
     -Wall -Wextra -Wshadow ^
     -O2 -static -s ^
     -o snake.exe main.c ^
     -L.\raylib\lib -l:libraylib.a -lwinmm -lgdi32
