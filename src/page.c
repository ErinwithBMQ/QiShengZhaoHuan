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
        SDL_Texture *texture_main = IMG_LoadTexture(renderer, "./res/image/qszh.jpg");
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

void BeginBattle(SDL_Renderer *renderer, SDL_Window *window, int *count,
                 Character *chara1, Character *chara2, Character *chara3,
                 Character *chara4, Character *chara5, Character *chara6, Character **chara_now)
{
    SDL_RenderClear(renderer);


    SDL_Event event;
    while (1)
    {
        SDL_Texture *texture_back = IMG_LoadTexture(renderer, "./res/image/back.jpg");
        SDL_RenderCopy(renderer, texture_back, NULL, NULL);

        PresentCharacterGame(chara1, 1, renderer);
        PresentCharacterGame(chara2, 2, renderer);
        PresentCharacterGame(chara3, 3, renderer);
        PresentCharacterGame(chara4, 4, renderer);
        PresentCharacterGame(chara5, 5, renderer);
        PresentCharacterGame(chara6, 6, renderer);

        SDL_RenderPresent(renderer);


        while (SDL_PollEvent(&event))
        {

            switch (event.type) {
                case SDL_QUIT:
                    CharacterImageDestroy();

                    SDL_DestroyWindow(window);
                    SDL_DestroyRenderer(renderer);

                    IMG_Quit();
                    SDL_Quit();
                    TTF_Quit();
                    exit(0);

                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT)
                    {
                        int x = event.button.x;
                        int y = event.button.y;
                        if (x >= 400 && x <= 520 && y >= 400 && y <= 655)
                        {
                            chara4->if_xuan = true;
                            PresentCharacterGame(chara4, 4, renderer);
                            if (IfCharacterChoose(renderer, window, chara4))
                            {
                                *chara_now = chara4;
                                return;
                            }
                        }
                        else if (x >= 570 && x <= 690 && y >= 400 && y <= 655)
                        {
                            chara5->if_xuan = true;
                            PresentCharacterGame(chara5, 5, renderer);
                            if (IfCharacterChoose(renderer, window, chara5))
                            {
                                *chara_now = chara5;
                                return;
                            }
                        }
                        else if (x >= 740 && x <= 860 && y >= 400 && y <= 655)
                        {
                            chara6->if_xuan = true;
                            PresentCharacterGame(chara6, 6, renderer);
                            if (IfCharacterChoose(renderer, window, chara6))
                            {
                                *chara_now = chara6;
                                return;
                            }
                        }
                    }
                    break;
                default:
                    break;
            }
        }
        SDL_Delay(3);
    }
}

int InBattle(SDL_Renderer *renderer, SDL_Window *window, int *count,
              Character *chara1, Character *chara2, Character *chara3,
              Character *chara4, Character *chara5, Character *chara6, Character **charanow)
{
    SDL_RenderClear(renderer);

    SDL_Event event;
    while (1)
    {
        SDL_Texture *texture_back = IMG_LoadTexture(renderer, "./res/image/back.jpg");
        SDL_RenderCopy(renderer, texture_back, NULL, NULL);

        PresentCharacterGame(chara1, 1, renderer);
        PresentCharacterGame(chara2, 2, renderer);
        PresentCharacterGame(chara3, 3, renderer);
        PresentCharacterGame(chara4, 4, renderer);
        PresentCharacterGame(chara5, 5, renderer);
        PresentCharacterGame(chara6, 6, renderer);


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
                        return 1;
                    }
                    break;
                default:
                    break;
            }
        }
        SDL_Delay(5);
    }
}

void LoseBattle(SDL_Renderer *renderer, SDL_Window *window)
{

}
