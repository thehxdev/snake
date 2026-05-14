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

### Generic build (No build script)
After you downloaded and extracted Raylib using instructions above, you can use just the C++ compiler.
This project uses unity build and the only thing that you have to do is pass the information about
Raylib directory path and the `build.cpp` file to your compiler.

The simplest build command on Mingw64 GCC (Win32):
```bash
g++ -I.\raylib\include -L.\raylib\lib -o snake.exe build.cpp -l:libraylib.a -lwinmm -lgdi32
```

The same for GCC/Clang (Unix-like):
```bash
g++ -I./raylib/include -L./raylib/lib -o snake build.cpp -l:libraylib.a -lm
```

## Photos
![Screenshot](./assets/screenshot.png)