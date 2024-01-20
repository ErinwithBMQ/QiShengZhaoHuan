//
// Created by Erin on 2024/1/15.
//

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <character.h>
#include <battle.h>
#include <page.h>

void MainPage()
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

void WinBattle()
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

void BeginBattle(Character *chara1, Character *chara2, Character *chara3,
                 Character *chara4, Character *chara5, Character *chara6, Character **chara_now)
{
    SDL_RenderClear(renderer);


    SDL_Event event;
    while (1)
    {
        SDL_Texture *texture_back = IMG_LoadTexture(renderer, "./res/image/back1.jpg");
        SDL_RenderCopy(renderer, texture_back, NULL, NULL);

        PresentCharacterGame(chara1, 1);
        PresentCharacterGame(chara2, 2);
        PresentCharacterGame(chara3, 3);
        PresentCharacterGame(chara4, 4);
        PresentCharacterGame(chara5, 5);
        PresentCharacterGame(chara6, 6);

        SDL_RenderPresent(renderer);

        while (SDL_PollEvent(&event))
        {

            switch (event.type) {
                case SDL_QUIT:
                    exit(0);

                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT)
                    {
                        int x = event.button.x;
                        int y = event.button.y;
                        if (x >= 400 && x <= 520 && y >= 400 && y <= 655)
                        {
                            chara4->if_xuan = true;
                            PresentCharacterGame(chara4, 4);
                            if (IfCharacterChoose(chara4))
                            {
                                *chara_now = chara4;
                                return;
                            }
                        }
                        else if (x >= 570 && x <= 690 && y >= 400 && y <= 655)
                        {
                            chara5->if_xuan = true;
                            PresentCharacterGame(chara5, 5);
                            if (IfCharacterChoose(chara5))
                            {
                                *chara_now = chara5;
                                return;
                            }
                        }
                        else if (x >= 740 && x <= 860 && y >= 400 && y <= 655)
                        {
                            chara6->if_xuan = true;
                            PresentCharacterGame(chara6, 6);
                            if (IfCharacterChoose(chara6))
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

int InBattle(int *count, int *who_first, int tou[],
             Character *chara1, Character *chara2, Character *chara3,
             Character *chara4, Character *chara5, Character *chara6,
             Character **charanow, Character **chara_enemy_now)
{
    SDL_RenderClear(renderer);

    bool if_final_a = false;
    bool if_final_b = false;
    int who_fight = *who_first;

    while (if_final_a == false || if_final_b == false)
    {
        SDL_RenderClear(renderer);

        ShowTheWhole(chara1, chara2, chara3, chara4, chara5, chara6);
        ShowTouzi(tou);
        ShowButtom();
        ShowEndHH();

        SDL_RenderPresent(renderer);

        if (who_fight == 1 && if_final_a == false)
        {
            ChangeCharacterShanghai(*charanow, *chara_enemy_now);

            int whichone = ChooseWhichSkill(*charanow, tou);

            if (whichone == -1) //退出战斗
            {
                return 1;
            }
            else if (whichone == 0)  //未选择技能
            {
                continue;
            }
            else if (whichone == -2) //结束本局战斗
            {
                if_final_a = true;
                who_fight = 0;
                if (if_final_b == true)
                {
                    *who_first = 0;
                }
                else
                {
                    *who_first = 1;
                }
                continue;
            }
            else if (whichone == 1) //使用普通攻击
            {
                //TODO: 造成伤害动画,元素反应，特殊效果，召唤物
                ReduceTou(*charanow, tou, 1);
                kill_blood(*charanow, *chara_enemy_now, 1);

                if ((*charanow)->baofa_now < (*charanow)->baofa_num)
                {
                    (*charanow)->baofa_now++;
                }

                int n = if_end(chara1, chara2, chara3, chara4, chara5, chara6);
                if (n == 0)
                {
                    if (!if_final_b)
                    {
                        who_fight = 0;
                    }

                    continue;
                }
                else if (n == 1)
                {
                    return 1;
                }
                else if (n == -1)
                {
                    return 0;
                }
            }
            else if (whichone == 2) //使用元素战技
            {
                //TODO: 造成伤害动画
                ReduceTou(*charanow, tou, 2);
                kill_blood(*charanow, *chara_enemy_now, 2);
                YuanSuFuZhuo(*charanow, *chara_enemy_now);

                if ((*charanow)->baofa_now < (*charanow)->baofa_num)
                {
                    (*charanow)->baofa_now++;
                }

                int n = if_end(chara1, chara2, chara3, chara4, chara5, chara6);
                if (n == 0)
                {
                    if (!if_final_b)
                    {
                        who_fight = 0;
                    }

                    continue;
                }
                else if (n == 1)
                {
                    return 1;
                }
                else if (n == -1)
                {
                    return 0;
                }
            }
            else if (whichone == 3) //使用元素爆发
            {
                //TODO: 造成伤害动画
                ReduceTou(*charanow, tou, 3);
                kill_blood(*charanow, *chara_enemy_now, 3);
                YuanSuFuZhuo(*charanow, *chara_enemy_now);

                (*charanow)->baofa_now = 0;
                int n = if_end(chara1, chara2, chara3, chara4, chara5, chara6);
                if (n == 0)
                {
                    if (!if_final_b)
                    {
                        who_fight = 0;
                    }

                    continue;
                }
                else if (n == 1)
                {
                    return 1;
                }
                else if (n == -1)
                {
                    return 0;
                }
            }
        }

        if (who_fight == 0 && if_final_b == false)
        {
            //TODO:对手逻辑的编写
            who_fight = 1;
            if_final_b = true;
        }


        SDL_Delay(5);
    }

    return -1;
}

void AfterBattle(int *count,
                 Character *chara1, Character *chara2, Character *chara3,
                 Character *chara4, Character *chara5, Character *chara6)
{
    (*count)++;
}

void LoseBattle()
{

}
