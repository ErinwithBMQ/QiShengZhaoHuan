//
// Created by Erin on 2024/1/18.
//
#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <battle.h>
#include <time.h>
#include <stdlib.h>

void ChangeCharacterShanghai(Character *chara, Character *enemy) //底层基础伤害的元素反应加成
{
    if (enemy->yuansu_fu[0]) //如果对方是火元素附着
    {
        if (chara->yuansu == 2) //水系角色
        {
            chara->shanghai[1] += 2;
            chara->shanghai[2] += 2;
        }
        else if (chara->yuansu == 1)  //雷系角色
        {
            chara->shanghai[1] += 2;
            chara->shanghai[2] += 2;
        }
        else if (chara->yuansu == 4) //草系角色
        {
            chara->shanghai[1] += 1;
            chara->shanghai[2] += 1;
        }
    }
    else if (enemy->yuansu_fu[1]) //雷元素附着
    {
        if (chara->yuansu == 2) //水系角色
        {
            chara->shanghai[1] += 1;
            chara->shanghai[2] += 1;
        }
        else if (chara->yuansu == 0)  //火系角色
        {
            chara->shanghai[1] += 2;
            chara->shanghai[2] += 2;
        }
        else if (chara->yuansu == 4) //草系角色
        {
            chara->shanghai[1] += 1;
            chara->shanghai[2] += 1;
        }
    }
    else if (enemy->yuansu_fu[2]) //水元素附着
    {
        if (chara->yuansu == 1) //雷系角色
        {
            chara->shanghai[1] += 1;
            chara->shanghai[2] += 1;
        }
        else if (chara->yuansu == 0)  //火系角色
        {
            chara->shanghai[1] += 2;
            chara->shanghai[2] += 2;
        }
        else if (chara->yuansu == 4) //草系角色
        {
            chara->shanghai[1] += 1;
            chara->shanghai[2] += 1;
        }
    }
    else if (enemy->yuansu_fu[4]) //草元素附着
    {
        if (chara->yuansu == 2) //水系角色
        {
            chara->shanghai[1] += 1;
            chara->shanghai[2] += 1;
        }
        else if (chara->yuansu == 0)  //火系角色
        {
            chara->shanghai[1] += 1;
            chara->shanghai[2] += 1;
        }
        else if (chara->yuansu == 1) //雷系角色
        {
            chara->shanghai[1] += 1;
            chara->shanghai[2] += 1;
        }
    }
}

void Touzi(int tou[], int count, Character *chara)
{
    SDL_Texture *texture_back = IMG_LoadTexture(renderer, "./res/image/back.jpg");
    SDL_RenderCopy(renderer, texture_back, NULL, NULL);

    TTF_Font *font_message = TTF_OpenFont("./res/HYWH85W.ttf", 50);
    SDL_Color color_message = {0x00, 0x00, 0x00, 0x00};
    SDL_Surface *surface_message = TTF_RenderUTF8_Solid(font_message, "第    回合", color_message);
    SDL_Texture *texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);
    SDL_Rect rect_message = {.x = 530, .y = 330};
    SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
    SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

    char arr[5];
    itoa(count, arr, 10);
    surface_message = TTF_RenderUTF8_Solid(font_message, arr, color_message);
    texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);
    rect_message.x = 580;
    SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
    SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

    int yuansu = chara->yuansu;
    tou[yuansu]++;
    tou[5]++;

    srand((unsigned int)time(NULL));
    for (int i = 0; i < 6; ++i)
    {
        int result = rand() % 6;
        tou[result] += 1;
    }

    ShowTouzi(tou);

    SDL_RenderPresent(renderer);

    SDL_Delay(1500);
}

void ShowTouzi(int tou[])
{
    TTF_Font *font_message = TTF_OpenFont("./res/HYWH85W.ttf", 24);
    SDL_Color color_message = {0x00, 0x00, 0x00, 0x00};

    SDL_Surface *surface_message = TTF_RenderUTF8_Solid(font_message, "火元素骰个数：", color_message);
    SDL_Texture *texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);
    SDL_Rect rect_message = {.x = 960, .y = 250};
    SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
    SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

    char arr[5];
    itoa(tou[0], arr, 10);
    surface_message = TTF_RenderUTF8_Solid(font_message, arr, color_message);
    texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);
    rect_message.x = 1120;
    SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
    SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

    surface_message = TTF_RenderUTF8_Solid(font_message, "雷元素骰个数：", color_message);
    texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);
    rect_message.x = 960;
    rect_message.y = 280;
    SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
    SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

    itoa(tou[1], arr, 10);
    surface_message = TTF_RenderUTF8_Solid(font_message, arr, color_message);
    texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);
    rect_message.x = 1120;
    rect_message.y = 280;
    SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
    SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

    surface_message = TTF_RenderUTF8_Solid(font_message, "水元素骰个数：", color_message);
    texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);
    rect_message.x = 960;
    rect_message.y = 310;
    SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
    SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

    itoa(tou[2], arr, 10);
    surface_message = TTF_RenderUTF8_Solid(font_message, arr, color_message);
    texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);
    rect_message.x = 1120;
    rect_message.y = 310;
    SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
    SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

    surface_message = TTF_RenderUTF8_Solid(font_message, "冰元素骰个数：", color_message);
    texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);
    rect_message.x = 960;
    rect_message.y = 340;
    SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
    SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

    itoa(tou[3], arr, 10);
    surface_message = TTF_RenderUTF8_Solid(font_message, arr, color_message);
    texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);
    rect_message.x = 1120;
    rect_message.y = 340;
    SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
    SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

    surface_message = TTF_RenderUTF8_Solid(font_message, "草元素骰个数：", color_message);
    texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);
    rect_message.x = 960;
    rect_message.y = 370;
    SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
    SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

    itoa(tou[4], arr, 10);
    surface_message = TTF_RenderUTF8_Solid(font_message, arr, color_message);
    texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);
    rect_message.x = 1120;
    rect_message.y = 370;
    SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
    SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

    surface_message = TTF_RenderUTF8_Solid(font_message, "万能元素骰个数：", color_message);
    texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);
    rect_message.x = 960;
    rect_message.y = 400;
    SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
    SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

    itoa(tou[5], arr, 10);
    surface_message = TTF_RenderUTF8_Solid(font_message, arr, color_message);
    texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);
    rect_message.x = 1150;
    rect_message.y = 400;
    SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
    SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

    TTF_CloseFont(font_message);
    SDL_FreeSurface(surface_message);
    SDL_DestroyTexture(texture_message);
}

void ShowButtom()
{
    SDL_Texture *texture_buttom = IMG_LoadTexture(renderer, "./res/image/ptgj.png");
    SDL_Rect rect_buttom = {.x = 950, .y = 700};
    SDL_QueryTexture(texture_buttom, NULL, NULL, &rect_buttom.w, &rect_buttom.h);
    SDL_RenderCopy(renderer, texture_buttom, NULL, &rect_buttom);

    texture_buttom = IMG_LoadTexture(renderer, "./res/image/yszj.png");
    rect_buttom.x = 1060;
    SDL_QueryTexture(texture_buttom, NULL, NULL, &rect_buttom.w, &rect_buttom.h);
    SDL_RenderCopy(renderer, texture_buttom, NULL, &rect_buttom);

    texture_buttom = IMG_LoadTexture(renderer, "./res/image/ysbf.png");
    rect_buttom.x = 1170;
    SDL_QueryTexture(texture_buttom, NULL, NULL, &rect_buttom.w, &rect_buttom.h);
    SDL_RenderCopy(renderer, texture_buttom, NULL, &rect_buttom);

    SDL_DestroyTexture(texture_buttom);
}

int ChooseWhichSkill(Character *chara)
{
    SDL_Event event;
    while (1)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    SDL_DestroyWindow(window);
                    SDL_DestroyRenderer(renderer);
                    exit(0);
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                    {
                        return -1;
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT)
                    {
                        int x = event.button.x;
                        int y = event.button.y;
                        if (x <= 1025 && x >= 955 && y <= 775 && y >= 705)
                        {
                            ShowCharacterMessage(chara);
                            SDL_RenderPresent(renderer);
                            SDL_Event event_skill;
                            while (1)
                            {
                                while (SDL_PollEvent(&event_skill))
                                {
                                    switch (event_skill.type)
                                    {
                                        case SDL_QUIT:
                                            SDL_DestroyWindow(window);
                                            SDL_DestroyRenderer(renderer);
                                            exit(0);
                                        case SDL_KEYDOWN:
                                            if (event_skill.key.keysym.sym == SDLK_SPACE)
                                            {
                                                return 1;
                                            }
                                            else if (event_skill.key.keysym.sym == SDLK_ESCAPE)
                                            {
                                                return 0;
                                            }
                                            break;
                                        default:
                                            break;
                                    }
                                }
                            }
                        }
                        else if (x <= 1140 && x >= 1065 && y <= 775 && y >= 705)
                        {
                            ShowCharacterMessage(chara);
                            SDL_RenderPresent(renderer);
                            SDL_Event event_skill;
                            while (1)
                            {
                                while (SDL_PollEvent(&event_skill))
                                {
                                    switch (event_skill.type)
                                    {
                                        case SDL_QUIT:
                                            SDL_DestroyWindow(window);
                                            SDL_DestroyRenderer(renderer);
                                            exit(0);
                                        case SDL_KEYDOWN:
                                            if (event_skill.key.keysym.sym == SDLK_SPACE)
                                            {
                                                return 2;
                                            }
                                            else if (event_skill.key.keysym.sym == SDLK_ESCAPE)
                                            {
                                                return 0;
                                            }
                                            break;
                                        default:
                                            break;
                                    }
                                }
                            }
                        }
                        else if (x <= 1250 && x >= 1175 && y <= 775 && y >= 705)
                        {
                            ShowCharacterMessage(chara);
                            SDL_RenderPresent(renderer);
                            SDL_Event event_skill;
                            while (1)
                            {
                                while (SDL_PollEvent(&event_skill))
                                {
                                    switch (event_skill.type)
                                    {
                                        case SDL_QUIT:
                                            SDL_DestroyWindow(window);
                                            SDL_DestroyRenderer(renderer);
                                            exit(0);
                                        case SDL_KEYDOWN:
                                            if (event_skill.key.keysym.sym == SDLK_SPACE)
                                            {
                                                return 3;
                                            }
                                            else if (event_skill.key.keysym.sym == SDLK_ESCAPE)
                                            {
                                                return 0;
                                            }
                                            break;
                                        default:
                                            break;
                                    }
                                }
                            }
                        }
                    }
                default:
                    break;
            }
        }
    }
}