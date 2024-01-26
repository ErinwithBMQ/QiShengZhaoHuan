cmake_minimum_required(VERSION 3.26)
project(qszh C)
set(CMAKE_C_STANDARD 17)

include_directories("D:\\QiShengZhaoHuan\\SDL2-2.26.0-allinone\\x86_64-w64-mingw32\\include")
link_directories("D:\\QiShengZhaoHuan\\SDL2-2.26.0-allinone\\x86_64-w64-mingw32\\lib")

include_directories(include)

add_executable(main main.c
        src/action.c
        src/character.c
        src/page.c
        src/battle.c
        src/record.c
        src/summon.c
        src/character_skill.c)


target_link_libraries(main PRIVATE
        mingw32
        SDL2main
        SDL2
        SDL2_image
        SDL2_mixer
        SDL2_ttf
)