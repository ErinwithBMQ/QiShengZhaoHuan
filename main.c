#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "include/character.h"
#include "include/action.h"
#include "include/page.h"

#undef main

#define HIGH 800
#define WIDTH 1300

Character Alhaitham = {
        .index = 1,
        .xue = 10,
        .hudun = 0,
        .name = {
                "艾尔海森",
                "溯因反绎法",
                "显像",
                "束缚",
        },
        .baofa_num = 2,
        .baofa_now = 0,
        .shanghai = {2,3,5},
        .yuansu = 'c',
        .yuansu_fu = {0,0,0,1,0},
        .zhuang = {0,0},
        .if_xuan = false,
};

Character Lingren = {
        .index = 2,
        .xue = 10,
        .hudun = 0,
        .name = {
                "神里绫人",
                "溯因反绎法",
                "显像",
                "束缚",
        },
        .baofa_num = 2,
        .baofa_now = 0,
        .shanghai = {2,3,5},
        .yuansu = 'c',
        .yuansu_fu = {1,0,0,0,0},
        .zhuang = {0,0},
        .if_xuan = false,
};

int main(int argc, char *argv[])
{
    SDL_Window *window = SDL_CreateWindow("Hello world", 100, 100, WIDTH, HIGH, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    CharacterImageLoad(renderer);



    SDL_Init(SDL_INIT_VIDEO); //初始化
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
    TTF_Init();



    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
    SDL_RenderClear(renderer);


    MainPage(renderer, window);

    InBattle(renderer, window, 0);

    return 0;
}