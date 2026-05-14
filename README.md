# Snake
Simple snake game with [Raylib](https://raylib.com).

## Build
Download [Raylib v6.0](https://github.com/raysan5/raylib/releases/tag/6.0),
extract the archive and rename the resulting directory to `raylib`. That means
in the project's root directory must be a directory called `raylib`. Then use
`build.sh` on Unix-like platforms and `build.bat` on Win32.

### Win32 Notes
`build.bat` uses Mingw64 GCC compiler that you can download from [HERE](https://winlibs.com).
You must download the `mingw-w64` version of Raylib in order to use it.

Clang compiler on Win32 tries to emulate MSVC compiler and expects `msvc16` version of Raylib.
To use Clang on Windows you must change the library name from `libraylib.a` to `raylib.lib` in
the `build.bat` file.

### Generic build
After you downloaded and extracted Raylib using instructions above, you can use just the C++ compiler
to build this project. This project uses unity build and the only thing that you have to do is pass
the information about Raylib directory path and the `build.cpp` file to your compiler.

The simplest build command on Mingw64 GCC (Windows):
```bash
g++ -I.\raylib\include -L.\raylib\lib -o snake.exe build.cpp -l:libraylib.a -lwinmm
```

The same for GCC/Clang (Unix-like):
```bash
g++ -I./raylib/include -L./raylib/lib -o snake build.cpp -l:libraylib.a -lm
```

## Photos
![Screenshot](./assets/screenshot.png)