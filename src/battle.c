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
#include <character.h>

void ChangeCharacterShanghai(Character *chara, Character *enemy) //底层基础伤害的元素反应加成
{
    CleanShanghai(chara);

    if (enemy->yuansu_fu[0]) //如果对方是火元素附着
    {
        if (chara->yuansu == 2) //水系角色
        {
            chara->shanghai_more[1] += 2;
            chara->shanghai_more[2] += 2;
        }
        else if (chara->yuansu == 1)  //雷系角色
        {
            chara->shanghai_more[1] += 2;
            chara->shanghai_more[2] += 2;
        }
        else if (chara->yuansu == 4) //草系角色
        {
            chara->shanghai_more[1] += 1;
            chara->shanghai_more[2] += 1;
        }
    }
    else if (enemy->yuansu_fu[1]) //雷元素附着
    {
        if (chara->yuansu == 2) //水系角色
        {
            chara->shanghai_more[1] += 1;
            chara->shanghai_more[2] += 1;
        }
        else if (chara->yuansu == 0)  //火系角色
        {
            chara->shanghai_more[1] += 2;
            chara->shanghai_more[2] += 2;
        }
        else if (chara->yuansu == 4) //草系角色
        {
            chara->shanghai_more[1] += 1;
            chara->shanghai_more[2] += 1;
        }
    }
    else if (enemy->yuansu_fu[2]) //水元素附着
    {
        if (chara->yuansu == 1) //雷系角色
        {
            chara->shanghai_more[1] += 1;
            chara->shanghai_more[2] += 1;
        }
        else if (chara->yuansu == 0)  //火系角色
        {
            chara->shanghai_more[1] += 2;
            chara->shanghai_more[2] += 2;
        }
        else if (chara->yuansu == 4) //草系角色
        {
            chara->shanghai_more[1] += 1;
            chara->shanghai_more[2] += 1;
        }
    }
    else if (enemy->yuansu_fu[4]) //草元素附着
    {
        if (chara->yuansu == 2) //水系角色
        {
            chara->shanghai_more[1] += 1;
            chara->shanghai_more[2] += 1;
        }
        else if (chara->yuansu == 0)  //火系角色
        {
            chara->shanghai_more[1] += 1;
            chara->shanghai_more[2] += 1;
        }
        else if (chara->yuansu == 1) //雷系角色
        {
            chara->shanghai_more[1] += 1;
            chara->shanghai_more[2] += 1;
        }
    }
}

void Touzi(int tou[], int count, Character *chara)
{
    SDL_Texture *texture_back = IMG_LoadTexture(renderer, "./res/image/water.jpg");
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
    SDL_Color color_message = {0xff, 0xff, 0xff, 0xff};

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

int ChooseWhichSkill(Character **chara, int tou[],
                     Character *chara4, Character *chara5, Character *chara6)
{
    SDL_Event event;
    while (1)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT: //直接退出
                    SDL_DestroyWindow(window);
                    SDL_DestroyRenderer(renderer);
                    exit(0);
                case SDL_KEYDOWN: //esc结束本局游戏
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                    {
                        return -1;
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN: //鼠标左键
                    if (event.button.button == SDL_BUTTON_LEFT)
                    {
                        int x = event.button.x;
                        int y = event.button.y;
                        if (x <= 1025 && x >= 955 && y <= 775 && y >= 705) //普通攻击
                        {
                            if (!IfTouEnough(*chara, tou, 1))
                            {
                                PrintTouNotEnough();

                                return 0;
                            }

                            ShowCharacterMessage(*chara);
                            ShowShanghai(*chara, 1);
                            SDL_RenderPresent(renderer);

                            int num = IfChooseSkill();

                            if (num == 1)
                            {
                                return 1;
                            }
                            else
                            {
                                return 0;
                            }

                        }
                        else if (x <= 1140 && x >= 1065 && y <= 775 && y >= 705) //元素战技
                        {
                            if (!IfTouEnough(*chara, tou, 2))
                            {
                                PrintTouNotEnough();

                                return 0;
                            }

                            ShowCharacterMessage(*chara);
                            ShowShanghai(*chara, 2);
                            SDL_RenderPresent(renderer);
                            int num = IfChooseSkill();

                            if (num == 1)
                            {
                                return 2;
                            }
                            else
                            {
                                return 0;
                            }
                        }
                        else if (x <= 1250 && x >= 1175 && y <= 775 && y >= 705) //元素爆发
                        {
                            if (!IfChongMan(*chara)) //如果还没充满
                            {
                                PrintChongnengNotEnough();

                                return 0;
                            }

                            if (!IfTouEnough(*chara, tou, 3))
                            {
                                PrintTouNotEnough();

                                return 0;
                            }

                            ShowCharacterMessage(*chara);
                            ShowShanghai(*chara, 3);
                            SDL_RenderPresent(renderer);

                            int num = IfChooseSkill();

                            if (num == 1)
                            {
                                return 3;
                            }
                            else
                            {
                                return 0;
                            }
                        }
                        else if (x <= 108 && x >= 12 && y <= 448 && y >= 352) //结束回合
                        {
                            return -2;
                        }

                        else if (x >= 400 && x <= 520 && y >= 400 && y <= 655)
                        {
                            if (IfChangeCharacter(*chara, chara4, 4, tou))
                            {
                                *chara = chara4;
                                return 4;
                            }
                            return 0;
                        }
                        else if (x >= 570 && x <= 690 && y >= 400 && y <= 655)
                        {
                            if (IfChangeCharacter(*chara, chara5, 5, tou))
                            {
                                *chara = chara5;
                                return 4;
                            }
                            return 0;
                        }
                        else if (x >= 740 && x <= 860 && y >= 400 && y <= 655)
                        {
                            if (IfChangeCharacter(*chara, chara6, 6, tou))
                            {
                                *chara = chara6;
                                return 4;
                            }
                            return 0;
                        }
                    }
                default:
                    break;
            }
        }
    }
}

int if_end(Character *chara1, Character *chara2, Character *chara3,
           Character *chara4, Character *chara5, Character *chara6)
{
    if (chara1->xue == 0 && chara2->xue == 0 && chara3->xue == 0)
    {
        return 1;
    }
    if (chara4->xue == 0 && chara5->xue == 0 && chara6->xue == 0)
    {
        return -1;
    }
    return 0;
}

void CleanShanghai(Character *chara)
{
    for (int i = 0; i < 3; ++i)
    {
        chara->shanghai_more[i] = 0;
    }
}

void ShowTheWhole(Character *chara1, Character *chara2, Character *chara3,
                  Character *chara4, Character *chara5, Character *chara6)
{
    SDL_Texture *texture_back = IMG_LoadTexture(renderer, "./res/image/back1.jpg");
    SDL_RenderCopy(renderer, texture_back, NULL, NULL);

    PresentCharacterGame(chara1, 1);
    PresentCharacterGame(chara2, 2);
    PresentCharacterGame(chara3, 3);
    PresentCharacterGame(chara4, 4);
    PresentCharacterGame(chara5, 5);
    PresentCharacterGame(chara6, 6);


    TTF_Font *font_title = TTF_OpenFont("./res/HYWH85W.ttf", 32);
    SDL_Color color_title = {0xff, 0xff, 0xff, 0xff};
    SDL_Surface *surface_title = TTF_RenderUTF8_Solid(font_title, "七圣召唤", color_title);
    SDL_Texture *texture_title = SDL_CreateTextureFromSurface(renderer, surface_title);
    SDL_Rect rect_title = {.x = 0, .y = 0};
    SDL_QueryTexture(texture_title, NULL, NULL, &rect_title.w, &rect_title.h);
    SDL_RenderCopy(renderer, texture_title, NULL, &rect_title);


    SDL_DestroyTexture(texture_back);
    SDL_DestroyTexture(texture_title);
    SDL_FreeSurface(surface_title);
    TTF_CloseFont(font_title);
}

void kill_blood(Character *chara, Character *enemy, int n)
{
    int shanghai;
    shanghai = chara->shanghai[n - 1] + chara->shanghai_more[n - 1];
    if (enemy->hudun >= shanghai)
    {
        enemy->hudun -= shanghai;
        return;
    }
    if (enemy->hudun < shanghai)
    {
        shanghai -= enemy->hudun;
        enemy->hudun = 0;
        enemy->xue -= shanghai;
        if (enemy->xue < 0)
        {
            enemy->xue = 0;
        }
        return;
    }
}

int IfChooseSkill()
{
    SDL_Event event_skill;

    while (SDL_WaitEvent(&event_skill))
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
                } else if (event_skill.key.keysym.sym == SDLK_ESCAPE)
                {
                    return 0;
                }
                break;
            default:
                break;
        }
    }
}

void ShowEndHH()
{
    SDL_Texture *texture_HH = IMG_LoadTexture(renderer, "./res/image/jshh.png");
    SDL_Rect rect_HH = {.x = 10, .y = 350};
    SDL_QueryTexture(texture_HH, NULL, NULL, &rect_HH.w, &rect_HH.h);
    SDL_RenderCopy(renderer, texture_HH, NULL, &rect_HH);
}

bool IfTouEnough(Character *chara, int tou[], int n)
{
    int yuansu = chara->yuansu;
    if (n == 1)
    {
        int total = 0;
        for (int i = 0; i < 6; ++i)
        {
            total += tou[i];
        }
        if ((tou[yuansu] + tou[5]) >= 1 && total >= 3)
        {
            return true;
        }
        return false;
    }
    else
    {
        if ((tou[yuansu] + tou[5]) >= 3)
        {
            return true;
        }
        return false;
    }
}

void ReduceTou(Character *chara, int tou[], int n)
{
    int yuansu = chara->yuansu;
    if (n == 1)
    {
        if (tou[yuansu] == 0)
        {
            tou[5]--;
            int count = 0;
            int i = 0;
            while (count < 2)
            {
                if (tou[i] != 0)
                {
                    tou[i]--;
                    count++;
                }
                else
                {
                    i++;
                    if (i > 5)
                    {
                        i = 0;
                    }
                }
            }
            return;
        }
        else
        {
            tou[yuansu]--;
            int total = 0;

            for (int i = 0; i < 5; ++i) {
                if (i != yuansu)
                {
                    total++;
                }
            }

            if (total == 0)
            {
                if (tou[yuansu] >= 2)
                {
                    tou[yuansu] -= 2;
                    return;
                }
                else
                {
                    int le = 2 - tou[yuansu];
                    tou[yuansu] = 0;
                    tou[5] -= le;
                    return;
                }
            }

            if (total == 1)
            {
                for (int i = 0; i < 5; ++i)
                {
                    if (i != yuansu && tou[i] > 0)
                    {
                        tou[i]--;
                        break;
                    }
                }
                if (tou[yuansu] > 0)
                {
                    tou[yuansu]--;
                }
                else
                {
                    tou[5]--;
                }
                return;
            }

            if (total >= 2)
            {
                int count = 0;
                int i = 0;
                while (count < 2)
                {
                    if (tou[i] != 0 && i != yuansu && i != 5)
                    {
                        tou[i]--;
                        count++;
                    }
                    else
                    {
                        i++;
                        if (i > 5)
                        {
                            i = 0;
                        }
                    }
                }
                return;
            }
        }
    }
    else
    {
        if (tou[yuansu] >= 3)
        {
            tou[yuansu] -= 3;
            return;
        }
        else
        {
            int le = 3 - tou[yuansu];
            tou[yuansu] = 0;
            tou[5] -= le;
            return;
        }
    }
}

void PrintTouNotEnough()
{
    TTF_Font *font_message = TTF_OpenFont("./res/HYWH85W.ttf", 32);
    SDL_Color color_message = {0xff, 0xff, 0xff, 0xff};
    SDL_Surface *surface_message = TTF_RenderUTF8_Solid(font_message, "元素骰子不足", color_message);
    SDL_Texture *texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);
    SDL_Rect rect_message = {.x = 540, .y = 350};
    SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
    SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

    SDL_RenderPresent(renderer);

    SDL_Delay(1000);

    TTF_CloseFont(font_message);
    SDL_FreeSurface(surface_message);
    SDL_DestroyTexture(texture_message);
}

void PrintChongnengNotEnough()
{
    TTF_Font *font_message = TTF_OpenFont("./res/HYWH85W.ttf", 32);
    SDL_Color color_message = {0xff, 0xff, 0xff, 0xff};
    SDL_Surface *surface_message = TTF_RenderUTF8_Solid(font_message, "角色充能不足", color_message);
    SDL_Texture *texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);
    SDL_Rect rect_message = {.x = 540, .y = 350};
    SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
    SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

    SDL_RenderPresent(renderer);

    SDL_Delay(1000);

    TTF_CloseFont(font_message);
    SDL_FreeSurface(surface_message);
    SDL_DestroyTexture(texture_message);
}

void YuanSuFuZhuo(Character *chara, Character *enemy)
{
    int yuansu = chara->yuansu;
    for (int i = 0; i < 5; ++i)
    {
        if (enemy->yuansu_fu[i] == true && i != yuansu)
        {
            enemy->yuansu_fu[i] = false;
            return;
        }
    }
    enemy->yuansu_fu[yuansu] = true;
}

void ShowShanghai(Character *chara, int n)
{
    TTF_Font *font_message = TTF_OpenFont("./res/HYWH85W.ttf", 24);
    SDL_Color color_message = {0xff, 0xff, 0xff, 0xff};
    SDL_Surface *surface_message;
    SDL_Texture *texture_message;
    SDL_Rect rect_message = {.x = 430, .y = 335};

    if (n == 1)
    {
        surface_message = TTF_RenderUTF8_Solid(font_message, "对敌人使用普通攻击：", color_message);
    }
    else if (n == 2)
    {
        surface_message = TTF_RenderUTF8_Solid(font_message, "对敌人使用元素战技：", color_message);
    }
    else
    {
        surface_message = TTF_RenderUTF8_Solid(font_message, "对敌人使用元素爆发：", color_message);
    }

    texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);
    SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
    SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

    rect_message.x = 670;
    surface_message = TTF_RenderUTF8_Solid(font_message, chara->name[n], color_message);
    texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);
    SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
    SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

    char shanghai[10];
    itoa((chara->shanghai[n - 1] + chara->shanghai_more[n - 1]), shanghai, 10);
    rect_message.x = 430;
    rect_message.y = 360;
    surface_message = TTF_RenderUTF8_Solid(font_message, "对敌人造成    点伤害", color_message);
    texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);
    SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
    SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

    rect_message.x = 550;
    rect_message.y = 360;
    surface_message = TTF_RenderUTF8_Solid(font_message, shanghai, color_message);
    texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);
    SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
    SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

    if (n != 1)
    {
        rect_message.x = 430;
        rect_message.y = 385;
        surface_message = TTF_RenderUTF8_Solid(font_message, "对敌人造成元素附着", color_message);
        texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);
        SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
        SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);
    }

    TTF_CloseFont(font_message);
    SDL_FreeSurface(surface_message);
    SDL_DestroyTexture(texture_message);
}

bool IfChangeCharacter(Character *charanow, Character *chara, int num, int tou[])
{
    chara->if_xuan = true;

    if (chara->if_chu)
    {
        while (1)
        {
            PresentCharacterGame(chara, num);
            ShowCharacterMessage(chara);
            SDL_RenderPresent(renderer);
            SDL_Event event_choose;
            while (SDL_WaitEvent(&event_choose))
            {
                switch (event_choose.type)
                {
                    case SDL_QUIT:
                        SDL_DestroyWindow(window);
                        SDL_DestroyRenderer(renderer);
                        exit(0);
                    case SDL_KEYDOWN:
                        if (event_choose.key.keysym.sym == SDLK_ESCAPE)
                        {
                            chara->if_xuan = false;
                            return false;
                        }
                }
            }
        }

    }
    else
    {
        if (IfTouNotZero(tou))
        {
            while (1)
            {
                PresentCharacterGame(chara, num);
                ShowCharacterMessage(chara);
                SDL_RenderPresent(renderer);
                TTF_Font *font_message = TTF_OpenFont("./res/HYWH85W.ttf", 24);
                SDL_Color color_message = {0xff, 0xff, 0xff, 0xff};

                SDL_Surface *surface_message = TTF_RenderUTF8_Solid(font_message, "是否切换至 ", color_message);
                SDL_Texture *texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);
                SDL_Rect rect_message = {.x = 490, .y = 330};
                SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
                SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

                surface_message = TTF_RenderUTF8_Solid(font_message, chara->name[0], color_message);
                texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);
                rect_message.x = 620;
                SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
                SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

                surface_message = TTF_RenderUTF8_Solid(font_message, "消耗一个元素骰子", color_message);
                texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);
                rect_message.x = 510;
                rect_message.y = 360;
                SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
                SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);


                SDL_Surface *surface_yesno = TTF_RenderUTF8_Solid(font_message, "按space选中，按esc取消选择", color_message);
                SDL_Texture *texture_yesno = SDL_CreateTextureFromSurface(renderer, surface_yesno);
                SDL_Rect rect_yesno = {.x = 460, .y = 390};
                SDL_QueryTexture(texture_yesno, NULL, NULL, &rect_yesno.w, &rect_yesno.h);
                SDL_RenderCopy(renderer, texture_yesno, NULL, &rect_yesno);

                SDL_RenderPresent(renderer);


                SDL_Event event_choose;
                while (SDL_WaitEvent(&event_choose))
                {
                    switch (event_choose.type)
                    {
                        case SDL_QUIT:
                            SDL_DestroyWindow(window);
                            SDL_DestroyRenderer(renderer);
                            TTF_CloseFont(font_message);
                            SDL_FreeSurface(surface_message);
                            SDL_DestroyTexture(texture_message);
                            SDL_FreeSurface(surface_yesno);
                            SDL_DestroyTexture(texture_yesno);
                            exit(0);
                        case SDL_KEYDOWN:
                            if (event_choose.key.keysym.sym == SDLK_ESCAPE)
                            {
                                TTF_CloseFont(font_message);
                                SDL_FreeSurface(surface_message);
                                SDL_DestroyTexture(texture_message);
                                SDL_FreeSurface(surface_yesno);
                                SDL_DestroyTexture(texture_yesno);

                                chara->if_xuan = false;
                                return false;
                            }
                            else if (event_choose.key.keysym.sym == SDLK_SPACE)
                            {
                                TTF_CloseFont(font_message);
                                SDL_FreeSurface(surface_message);
                                SDL_DestroyTexture(texture_message);
                                SDL_FreeSurface(surface_yesno);
                                SDL_DestroyTexture(texture_yesno);

                                chara->if_xuan = false;
                                chara->if_chu = true;
                                charanow->if_chu = false;
                                return true;
                            }
                        default:
                            break;
                    }
                }



            }
        }
        else
        {
            PresentCharacterGame(chara, num);
            ShowCharacterMessage(chara);

            PrintTouNotEnough();

            SDL_RenderPresent(renderer);

            chara->if_xuan = false;
            return false;
        }
    }
}

bool ReduceTouChange(Character *chara4, Character *chara5, Character *chara6, int tou[])
{
    int yuansu4 = chara4->yuansu;
    int yuansu5 = chara5->yuansu;
    int yuansu6 = chara6->yuansu;

    int total = 0;
    for (int i = 0; i < 5; ++i)
    {
        if (i != yuansu4 && i != yuansu5 && i != yuansu6)
        {
            total += tou[i];
        }
    }

    if (total == 0)
    {
        for (int i = 0; i < 6; ++i)
        {
            if (tou[i] > 0)
            {
                tou[i]--;
                return true;
            }
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        if (i != yuansu4 && i != yuansu5 && i != yuansu6 && tou[i] > 0)
        {
            tou[i]--;
            return true;
        }
    }
}

bool IfTouNotZero(int tou[])
{
    int count;
    for (int i = 0; i < 6; ++i)
    {
        count += tou[i];
    }
    if (count)
    {
        return true;
    }
    return false;
}