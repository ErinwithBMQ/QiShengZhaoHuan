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

    SDL_Event event;

    while (1)
    {
        Character now = Alhaitham;
        Character emy = Lingren;

        for (int i = 1; i <= 3; ++i) {
            PresentCharacterGame(&emy, i, renderer);
        }

        for (int i = 4; i <= 6; ++i) {
            PresentCharacterGame(&now, i, renderer);
        }

        TTF_Font *font_title = TTF_OpenFont("./res/HYWH85W.ttf", 32);
        SDL_Color color_title = {0x00, 0x00, 0x00, 0x00};
        SDL_Surface *surface_title = TTF_RenderUTF8_Solid(font_title, "七圣召唤", color_title);
        SDL_Texture *texture_title = SDL_CreateTextureFromSurface(renderer, surface_title);
        SDL_Rect rect_title = {.x = 0, .y = 0};
        SDL_QueryTexture(texture_title, NULL, NULL, &rect_title.w, &rect_title.h);
        SDL_RenderCopy(renderer, texture_title, NULL, &rect_title);


        SDL_RenderPresent(renderer);

        while (SDL_PollEvent(&event))
        {

            switch (event.type) {
                case SDL_QUIT:
                    SDL_DestroyTexture(texture_title);
                    SDL_FreeSurface(surface_title);

                    SDL_DestroyWindow(window);
                    SDL_DestroyRenderer(renderer);
                    TTF_CloseFont(font_title);

                    IMG_Quit();
                    SDL_Quit();
                    TTF_Quit();
                    return 0;

                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                    {
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
                    break;
                default:
                    break;
            }
        }
        SDL_Delay(5);
    }


    return 0;
}