cmake_minimum_required(VERSION 3.20)

project(raylib_imgui LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
  raylib
  GIT_REPOSITORY https://github.com/raysan5/raylib.git
  GIT_TAG 5.5
)
FetchContent_MakeAvailable(raylib)

FetchContent_Declare(
  imgui
  GIT_REPOSITORY https://github.com/ocornut/imgui.git
  GIT_TAG v1.91.9b
)
FetchContent_MakeAvailable(imgui)

FetchContent_Declare(
  rlimgui
  GIT_REPOSITORY https://github.com/raylib-extras/rlImGui.git
  GIT_TAG main
)
FetchContent_MakeAvailable(rlimgui)

add_executable(raylib_imgui
  src/main.cpp
)

target_include_directories(raylib_imgui PRIVATE
  ${imgui_SOURCE_DIR}
  ${rlimgui_SOURCE_DIR}
)

target_link_libraries(raylib_imgui PRIVATE
  raylib
  rlImGui
)

if (WIN32)
  target_link_libraries(raylib_imgui PRIVATE winmm)
endif()

if (UNIX AND NOT APPLE)
  target_link_libraries(raylib_imgui PRIVATE dl pthread m X11)
endif()
