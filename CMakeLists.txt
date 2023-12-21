cmake_minimum_required(VERSION 3.26)
project(sdl_sample C)
set(CMAKE_C_STANDARD 17)

include_directories("D:\\mingw(CLion+VSC)\\SDL2-2.26.0-allinone\\x86_64-w64-mingw32\\include")
link_directories("D:\\mingw(CLion+VSC)\\SDL2-2.26.0-allinone\\x86_64-w64-mingw32\\lib")

add_executable(main main.c)

target_link_libraries(main PRIVATE
        mingw32
        SDL2main
        SDL2
        SDL2_image
        SDL2_mixer
        SDL2_ttf
)