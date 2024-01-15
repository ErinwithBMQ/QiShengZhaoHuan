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
                    CharacterImageDestroy();

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
                        InBattle(renderer, window, 0);
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
                    CharacterImageDestroy();

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

void InBattle(SDL_Renderer *renderer, SDL_Window *window, int *count)
{
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
                    CharacterImageDestroy();

                    SDL_DestroyTexture(texture_title);
                    SDL_FreeSurface(surface_title);

                    SDL_DestroyWindow(window);
                    SDL_DestroyRenderer(renderer);
                    TTF_CloseFont(font_title);

                    IMG_Quit();
                    SDL_Quit();
                    TTF_Quit();
                    exit(0);

                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                    {
                        WinBattle(renderer, window);
                    }
                    break;
                default:
                    break;
            }
        }
        SDL_Delay(5);
    }
}
