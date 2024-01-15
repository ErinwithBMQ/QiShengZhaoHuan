//
// Created by Erin on 2024/1/15.
//

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "character.h"

#include "page.h"

void MainPage(SDL_Renderer *renderer, SDL_Window *window)
{
    SDL_Event event_main;
    while (1)
    {
        SDL_Texture *texture_main = IMG_LoadTexture(renderer, "./res/image/Main.png");
        SDL_RenderCopy(renderer, texture_main, NULL, NULL);
        SDL_RenderPresent(renderer);

        while (SDL_PollEvent(&event_main))
        {

            switch (event_main.type) {
                case SDL_QUIT:
                    SDL_DestroyTexture(texture_main);

                    SDL_DestroyWindow(window);
                    SDL_DestroyRenderer(renderer);

                    IMG_Quit();
                    SDL_Quit();
                    TTF_Quit();
                    exit(0);
                case SDL_KEYDOWN:
                    if (event_main.key.keysym.sym == SDLK_SPACE)
                    {
                        SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
                        SDL_RenderClear(renderer); // 清除渲染器内容
                        return;
                    }
                    break;
                default:
                    break;
            }
        }
        SDL_Delay(3);
    }
}

void WinBattle(SDL_Renderer *renderer, SDL_Window *window)
{
    SDL_Event event_main;
    while (1)
    {
        SDL_Texture *texture_win = IMG_LoadTexture(renderer, "./res/image/win.png");
        SDL_RenderCopy(renderer, texture_win, NULL, NULL);
        SDL_RenderPresent(renderer);

        while (SDL_PollEvent(&event_main))
        {

            switch (event_main.type) {
                case SDL_QUIT:
                    SDL_DestroyTexture(texture_win);

                    SDL_DestroyWindow(window);
                    SDL_DestroyRenderer(renderer);

                    IMG_Quit();
                    SDL_Quit();
                    TTF_Quit();
                    exit(0);
                case SDL_KEYDOWN:
                    if (event_main.key.keysym.sym == SDLK_SPACE)
                    {
                        SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
                        SDL_RenderClear(renderer); // 清除渲染器内容
                        MainPage(renderer, window);
                    }
                    break;
                default:
                    break;
            }
        }
        SDL_Delay(3);
    }
}
