# raylib-imgui

Starter project using **C++**, **raylib**, **Dear ImGui**, and **CMake**.

## Requirements

- CMake 3.20+
- C++17 compiler
- Git

## Build

### Linux

```bash
cmake -S . -B build
cmake --build build -j
./build/raylib_imgui
```

### Windows (Visual Studio)

```powershell
cmake -S . -B build
cmake --build build --config Release
.\build\Release\raylib_imgui.exe
```

## Notes

Dependencies are fetched automatically with CMake `FetchContent`.
