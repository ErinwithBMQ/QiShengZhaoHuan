#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "character/character.h"
#include "action/action.h"

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
        .yuansu_fu = {0,0,0,0,0},
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
        .yuansu_fu = {0,0,0,0,0},
        .zhuang = {0,0},
        .if_xuan = false,
};

int main(int argc, char *argv[])
{
        SDL_Window *window = SDL_CreateWindow("Hello world", 100, 100, WIDTH, HIGH, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Init(SDL_INIT_VIDEO); //初始化
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
    TTF_Init();


    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
    SDL_RenderClear(renderer);


    /*SDL_Surface *surface_back = IMG_Load("./res/image/alhaitham.jpg");
    SDL_Texture *texture_back = SDL_CreateTextureFromSurface(renderer, surface_back);
    SDL_Rect rect = {.x = 518, .y = 57};
    SDL_QueryTexture(texture_back, NULL, NULL, &rect.w, &rect.h);
    SDL_RenderCopy(renderer, texture_back, NULL, &rect);*/
    //将texture内容传到渲染器

    Character now = Alhaitham;
    Character emy = Lingren;

    for (int i = 1; i <= 3; ++i) {
        present_character_game(&emy, i, renderer);
    }

    for (int i = 4; i <= 6; ++i) {
        present_character_game(&now, i, renderer);
    }

    TTF_Font *font_title = TTF_OpenFont("./res/HYWH85W.ttf", 32);
    SDL_Color color_title = {0x00, 0x00, 0x00, 0x00};
    SDL_Surface *surface_title = TTF_RenderText_Blended(font_title, "Genshin Impact", color_title);
    SDL_Texture *texture_title = SDL_CreateTextureFromSurface(renderer, surface_title);
    SDL_Rect rect_title = {.x = 0, .y = 0};
    SDL_QueryTexture(texture_title, NULL, NULL, &rect_title.w, &rect_title.h);
    SDL_RenderCopy(renderer, texture_title, NULL, &rect_title);


    SDL_RenderPresent(renderer);
    SDL_Delay(8000);


    //SDL_DestroyTexture(texture_back);
    //SDL_FreeSurface(surface_back);
    SDL_DestroyTexture(texture_title);
    SDL_FreeSurface(surface_title);

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    TTF_CloseFont(font_title);

    IMG_Quit();
    SDL_Quit();
    TTF_Quit();

    return 0;
}