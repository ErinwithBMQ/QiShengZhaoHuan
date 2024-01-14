#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "character/character.h"
#include "action/action.h"

#undef main

int main(int argc, char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO); //初始化
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);

    SDL_Window *window = SDL_CreateWindow("Hello world", 100, 100, 1200, 800, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Surface *surface_back = IMG_Load("./image/alhaitham.jpg");
    SDL_Texture *texture_back = SDL_CreateTextureFromSurface(renderer, surface_back);

    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
    SDL_RenderClear(renderer);

    SDL_Rect rect = {.x = 518, .y = 57};
    SDL_QueryTexture(texture_back, NULL, NULL, &rect.w, &rect.h);
    SDL_RenderCopy(renderer, texture_back, NULL, &rect);
    //将texture内容传到渲染器
    SDL_RenderPresent(renderer);
    SDL_Delay(10000);


    SDL_DestroyTexture(texture_back);
    SDL_FreeSurface(surface_back);

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    IMG_Quit();
    SDL_Quit();

    return 0;
}