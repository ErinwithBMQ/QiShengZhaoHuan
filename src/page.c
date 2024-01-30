//
// Created by Erin on 2024/1/15.
//

// TODO：1.深度元素反应  2.行动牌  3.战斗日志  4.战斗动画  5.难度选择以及对手逻辑  6.元素骰子重投

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <character.h>
#include <battle.h>
#include <page.h>
#include <summon.h>
#include <character_skill.h>
#include <ElementalReaction.h>

void MainPage()
{
    SDL_Event event_main;
    while (1)
    {
        SDL_Texture *texture_main = IMG_LoadTexture(renderer, "./res/image/qszh.jpg");
        SDL_RenderCopy(renderer, texture_main, NULL, NULL);
        SDL_RenderPresent(renderer);

        SDL_DestroyTexture(texture_main);

        while (SDL_PollEvent(&event_main))
        {

            switch (event_main.type) {
                case SDL_QUIT:
                    CharacterImageDestroy();
                    SummonImageDestroy();
                    quit_delete();
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
        SDL_Delay(5);
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

        SDL_DestroyTexture(texture_win);

        while (SDL_PollEvent(&event_main))
        {
            switch (event_main.type) {
                case SDL_QUIT:
                    CharacterImageDestroy();
                    SummonImageDestroy();
                    quit_delete();
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
        SDL_Delay(5);
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

        TTF_Font *font_message = TTF_OpenFont("./res/HYWH85W.ttf", 32);
        SDL_Color color_message = {0xff, 0xff, 0xff, 0xff};

        SDL_Surface *surface_message = TTF_RenderUTF8_Solid(font_message, "请选择初始出战角色", color_message);
        SDL_Texture *texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);
        SDL_Rect rect_message = {.x = 470, .y = 330};
        SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
        SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

        SDL_RenderPresent(renderer);

        TTF_CloseFont(font_message);
        SDL_FreeSurface(surface_message);
        SDL_DestroyTexture(texture_message);

        while (SDL_PollEvent(&event))
        {

            switch (event.type)
            {
                case SDL_QUIT:
                    CharacterImageDestroy();
                    SummonImageDestroy();
                    quit_delete();
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
        SDL_Delay(5);
    }
}

int InBattle(int *count, int *who_first, int tou[],
             Character *chara1, Character *chara2, Character *chara3,
             Character *chara4, Character *chara5, Character *chara6,
             Character **charanow, Character **chara_enemy_now)
{
    SDL_RenderClear(renderer);

    // 初始化是否结束回合，谁先开始行动
    bool if_final_a = false;
    bool if_final_b = false;
    int who_fight = *who_first;

    int enemy_count = 0;  //对方行动步骤

    while (1)
    {
        if (if_final_a == true && if_final_b == true)  //特殊情况：两方都结束回合但我方角色死亡需要切换角色
        {
            if ((*charanow)->xue == 0)
            {
                ChangeCharacterWhenDead(charanow, chara4, chara5, chara6);
                continue;
            }
            else
            {
                break;  //结束本回合
            }
        }

        //页面显示

        SDL_RenderClear(renderer);

        ShowTheWhole(chara1, chara2, chara3, chara4, chara5, chara6);
        ShowTou(tou);
        ShowButtom();
        ShowEndHH(who_fight);
        ShowIfEndTurn(if_final_a, if_final_b);

        if (who_fight == 1)
        {
            ShowWeAction();
        }
        else
        {
            ShowEnemyAction();
        }

        for (int i = 0; i < 5; ++i)
        {
            if (summon_all[i]->index != 0)
            {
                PresentSummonGame(summon_all[i]);
            }
        }

        SDL_RenderPresent(renderer);


        //我方角色死亡强制切换角色
        if ((*charanow)->xue == 0)
        {
            ChangeCharacterWhenDead(charanow, chara4, chara5, chara6);

            continue;
        }

        if (who_fight == 1 && if_final_a == false)  //我方行动
        {
            ChangeCharacterShanghai(*charanow, *chara_enemy_now);  //提前计算基础元素反应伤害

            if ((*charanow)->special_state > 0)  //调用角色本身特殊状态函数
            {
                if ((*charanow)->SpecialAddition != NULL)
                {
                    (*charanow)->SpecialAddition(*charanow);
                }
            }
            else
            {
                (*charanow)->if_pugongfumo = false;
            }


            //普攻附魔后计算基础元素反应增伤
            ChangeCharacterShanghaiPu(*charanow, *chara_enemy_now);

            //特殊增伤计算
            QingliuSkill(chara4, chara5, chara6);
            // TODO：激化、草原核的增伤
            JihuaAddition(*charanow);
            CaoyuanheAddition(*charanow);

            //选择哪个技能
            int whichone = ChooseWhichSkill(charanow, tou, chara4, chara5, chara6, if_final_a);

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
                ReduceTou(*charanow, tou, 1);  //减少骰子
                kill_blood(*charanow, *chara_enemy_now, 1);  //扣血

                // TODO：深度元素反应

                //如果有附魔那就造成元素附着
                if ((*charanow)->if_pugongfumo)
                {
                    YuanSuFuZhuo(*charanow, *chara_enemy_now);
                    JihuaReduce(*charanow);
                    CaoyuanheReduce(*charanow);
                    ChooseWhichReaction(*charanow, chara_enemy_now, chara1, chara2, chara3);
                }

                ShowKillEnemyBlood(chara1, chara2, chara3, (*charanow)->shanghai[0] + (*charanow)->shanghai_more[0]);  //展示扣血动画

                //充能增加
                if ((*charanow)->baofa_now < (*charanow)->baofa_num)
                {
                    (*charanow)->baofa_now++;
                }

                //刃的回血机制判断
                RenPuHuiXue(*charanow);

                //关闭全部攻击
                if_all_attack = false;

                //是否减少特殊状态数目
                SpecialAdditionReduceCountPu(*charanow);
                SpecialAdditionReduceCountAll(*charanow);

                //敌方是否要强制切换角色
                ChangeCharacterEnemy(chara_enemy_now, chara1, chara2, chara3);
                //判断是否结束游戏
                int n = if_end(chara1, chara2, chara3, chara4, chara5, chara6);

                if (n == 0)  //不结束，对方行动
                {
                    if (!if_final_b)
                    {
                        who_fight = 0;
                    }

                    continue;
                }
                else if (n == 1)  //我方胜利
                {
                    return 1;
                }
                else if (n == -1)  //地方胜利
                {
                    return 0;
                }
            }
            else if (whichone == 2) //使用元素战技
            {
                //TODO: 造成伤害动画
                ReduceTou(*charanow, tou, 2);
                kill_blood(*charanow, *chara_enemy_now, 2);

                JihuaReduce(*charanow);
                CaoyuanheReduce(*charanow);

                ChooseWhichReaction(*charanow, chara_enemy_now, chara1, chara2, chara3);

                if ((*charanow)->yszj != NULL)
                {
                    (*charanow)->yszj(chara1, chara2, chara3, *charanow);
                }

                SpecialAdditionReduceCountAll(*charanow);

                ShowKillEnemyBlood(chara1, chara2, chara3, (*charanow)->shanghai[1] + (*charanow)->shanghai_more[1]);
                YuanSuFuZhuo(*charanow, *chara_enemy_now);

                if ((*charanow)->baofa_now < (*charanow)->baofa_num)
                {
                    (*charanow)->baofa_now++;
                }

                if_all_attack = false;

                ChangeCharacterEnemy(chara_enemy_now, chara1, chara2, chara3);
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
                SpecialAdditionReduceCountAll(*charanow);

                JihuaReduce(*charanow);
                CaoyuanheReduce(*charanow);

                if ((*charanow)->ysbf != NULL)
                {
                    (*charanow)->ysbf(chara1, chara2, chara3, *charanow);
                }

                kill_blood(*charanow, *chara_enemy_now, 3);

                ChooseWhichReaction(*charanow, chara_enemy_now, chara1, chara2, chara3);

                ShowKillEnemyBlood(chara1, chara2, chara3, (*charanow)->shanghai[2] + (*charanow)->shanghai_more[2]);
                YuanSuFuZhuo(*charanow, *chara_enemy_now);

                if_all_attack = false;

                (*charanow)->baofa_now = 0;
                ChangeCharacterEnemy(chara_enemy_now, chara1, chara2, chara3);
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
            else if (whichone == 4)  //切换角色
            {
                if (!if_final_b)
                {
                    who_fight = 0;
                }

                ReduceTouChange(chara4, chara5, chara6, tou);

                continue;
            }
        }


        if (who_fight == 0 && if_final_b == false)  //对方行动
        {
            //TODO:对手逻辑的编写

            SDL_Delay(1000);

            ChangeCharacterShanghai(*chara_enemy_now, *charanow);
            kill_blood(*chara_enemy_now, *charanow, 2);
            ShowKillWeBlood(chara4, chara5, chara6, (*chara_enemy_now)->shanghai[1] + (*chara_enemy_now)->shanghai_more[1]);
            YuanSuFuZhuo(*chara_enemy_now, *charanow);
            who_fight = 1;
            if_final_b = true;
            if_all_attack = false;

            int n = if_end(chara1, chara2, chara3, chara4, chara5, chara6);
            if (n == -1)
            {
                return 0;
            }
        }


        SDL_Delay(5);
    }

    return -1;
}

int AfterBattle(int *count, Character **chara_now, Character **chara_enemy_now,
                 Character *chara1, Character *chara2, Character *chara3,
                 Character *chara4, Character *chara5, Character *chara6)
{
    for (int i = 0; i < 3; ++i)
    {
        if (summon_all[i]->index != 0)
        {
            SDL_RenderClear(renderer);

            SDL_Texture *texture_back = IMG_LoadTexture(renderer, "./res/image/back1.jpg");
            SDL_RenderCopy(renderer, texture_back, NULL, NULL);

            PresentCharacterGame(chara1, 1);
            PresentCharacterGame(chara2, 2);
            PresentCharacterGame(chara3, 3);
            PresentCharacterGame(chara4, 4);
            PresentCharacterGame(chara5, 5);
            PresentCharacterGame(chara6, 6);

            for (int j = 0; j < 5; ++j)
            {
                if (summon_all[j]->index != 0)
                {
                    PresentSummonGame(summon_all[j]);
                }
            }

            TTF_Font *font_summon = TTF_OpenFont("./res/HYWH85W.ttf", 32);
            SDL_Color color_summon = {0xff, 0xff, 0xff, 0xff};
            SDL_Rect rect_end = {.x = 550, .y = 360};
            SDL_Surface *surface_turn = TTF_RenderUTF8_Solid(font_summon, "结算阶段", color_summon);
            SDL_Texture *texture_turn = SDL_CreateTextureFromSurface(renderer, surface_turn);

            SDL_QueryTexture(texture_turn, NULL, NULL, &rect_end.w, &rect_end.h);
            SDL_RenderCopy(renderer, texture_turn, NULL, &rect_end);

            SDL_RenderPresent(renderer);

            SDL_Delay(1000);

            TTF_CloseFont(font_summon);
            SDL_FreeSurface(surface_turn);
            SDL_DestroyTexture(texture_turn);
            SDL_DestroyTexture(texture_back);

            ChangeSummonShanghai(summon_all[i], *chara_enemy_now);
            SummonKillBlood(summon_all[i], *chara_enemy_now);
            ShowKillEnemyBlood(chara1, chara2, chara3, summon_all[i]->shanghai + summon_all[i]->shanghai_more);
            if (SummonDestroy(summon_all[i]))
            {
                i--;
            }

            ChangeCharacterEnemy(chara_enemy_now, chara1, chara2, chara3);
            int n = if_end(chara1, chara2, chara3, chara4, chara5, chara6);

            if (n == 1)
            {
                return 1;
            }
            else if (n == -1)
            {
                return 0;
            }
        }
        SDL_Delay(5);
    }

    SDL_RenderClear(renderer);

    SDL_Texture *texture_back = IMG_LoadTexture(renderer, "./res/image/back1.jpg");
    SDL_RenderCopy(renderer, texture_back, NULL, NULL);

    PresentCharacterGame(chara1, 1);
    PresentCharacterGame(chara2, 2);
    PresentCharacterGame(chara3, 3);
    PresentCharacterGame(chara4, 4);
    PresentCharacterGame(chara5, 5);
    PresentCharacterGame(chara6, 6);

    for (int j = 0; j < 5; ++j)
    {
        if (summon_all[j]->index != 0)
        {
            PresentSummonGame(summon_all[j]);
        }
    }

    TTF_Font *font_summon = TTF_OpenFont("./res/HYWH85W.ttf", 32);
    SDL_Color color_summon = {0xff, 0xff, 0xff, 0xff};
    SDL_Rect rect_end = {.x = 550, .y = 360};
    SDL_Surface *surface_turn = TTF_RenderUTF8_Solid(font_summon, "回合结束", color_summon);
    SDL_Texture *texture_turn = SDL_CreateTextureFromSurface(renderer, surface_turn);

    SDL_QueryTexture(texture_turn, NULL, NULL, &rect_end.w, &rect_end.h);
    SDL_RenderCopy(renderer, texture_turn, NULL, &rect_end);

    SDL_RenderPresent(renderer);

    SDL_Delay(1000);

    TTF_CloseFont(font_summon);
    SDL_FreeSurface(surface_turn);
    SDL_DestroyTexture(texture_turn);
    SDL_DestroyTexture(texture_back);

    (*count)++;

    SpecialAdditionReduceTurn(chara4, chara5, chara6);

    return -1;
}

void LoseBattle()
{

}

bool ChooseCharacter(Character *chara4, Character *chara5, Character *chara6)
{
    SDL_Event event;

    Character *chara[3] = {chara4, chara5, chara6};

    int count = 0;

    while (1)
    {
        SDL_RenderClear(renderer);

        SDL_Texture *texture_back = IMG_LoadTexture(renderer, "./res/image/choosechara.jpg");
        SDL_RenderCopy(renderer, texture_back, NULL, NULL);

        SDL_DestroyTexture(texture_back);

        if (chara4->index != 0)
        {
            SDL_Rect rect_chara = {.x = 85, .y = 98};
            SDL_QueryTexture(chara4->image, NULL, NULL, &rect_chara.w, &rect_chara.h);
            SDL_RenderCopy(renderer, chara4->image, NULL, &rect_chara);
        }

        if (chara5->index != 0)
        {
            SDL_Rect rect_chara = {.x = 85, .y = 335};
            SDL_QueryTexture(chara5->image, NULL, NULL, &rect_chara.w, &rect_chara.h);
            SDL_RenderCopy(renderer, chara5->image, NULL, &rect_chara);
        }

        if (chara6->index != 0)
        {
            SDL_Rect rect_chara = {.x = 85, .y = 581};
            SDL_QueryTexture(chara6->image, NULL, NULL, &rect_chara.w, &rect_chara.h);
            SDL_RenderCopy(renderer, chara6->image, NULL, &rect_chara);
        }

        SDL_RenderPresent(renderer);

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT: //直接退出
                    CharacterImageDestroy();
                    SummonImageDestroy();
                    quit_delete();
                    exit(0);
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_LCTRL || event.key.keysym.sym == SDLK_RCTRL)
                    {
                        if (count == 3)
                        {
                            return true;
                        }
                        else
                        {
                            TTF_Font *font_title = TTF_OpenFont("./res/HYWH85W.ttf", 32);
                            SDL_Color color_title = {0xff, 0xff, 0xff, 0xff};
                            SDL_Surface *surface_title = TTF_RenderUTF8_Solid(font_title, "角色选择数还未达到三个！", color_title);
                            SDL_Texture *texture_title = SDL_CreateTextureFromSurface(renderer, surface_title);
                            SDL_Rect rect_title = {.x = 600, .y = 220};
                            SDL_QueryTexture(texture_title, NULL, NULL, &rect_title.w, &rect_title.h);
                            SDL_RenderCopy(renderer, texture_title, NULL, &rect_title);

                            SDL_RenderPresent(renderer);
                            SDL_Delay(1500);

                            SDL_DestroyTexture(texture_title);
                            SDL_FreeSurface(surface_title);
                            TTF_CloseFont(font_title);
                            break;
                        }
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN: //鼠标左键
                    if (event.button.button == SDL_BUTTON_LEFT)
                    {
                        int x = event.button.x;
                        int y = event.button.y;

                        if (x >= 1180 && x <= 1275 && y>= 20 && y <= 104)
                        {
                            return false;
                        }

                        if (x >= 363 && x <= 673 && y>= 446 && y <= 518)
                        {
                            if (IfFirstChooseCharacter(&Alhaitham) && count < 3)
                            {
                                *(chara[count]) = Alhaitham;
                                chara[count]->index_game = count + 4;
                                count++;
                                break;
                            }
                            else
                            {
                                break;
                            }
                        }

                        if (x >= 363 && x <= 673 && y>= 518 && y <= 591)
                        {
                            if (IfFirstChooseCharacter(&Zihuang) && count < 3)
                            {
                                *(chara[count]) = Zihuang;
                                chara[count]->index_game = count + 4;
                                count++;
                                break;
                            }
                            else
                            {
                                break;
                            }
                        }

                        if (x >= 363 && x <= 673 && y>= 591 && y <= 671)
                        {
                            if (IfFirstChooseCharacter(&Huoxing) && count < 3)
                            {
                                *(chara[count]) = Huoxing;
                                chara[count]->index_game = count + 4;
                                count++;
                                break;
                            }
                            else
                            {
                                break;
                            }
                        }

                        if (x >= 363 && x <= 673 && y>= 671 && y <= 734)
                        {
                            if (IfFirstChooseCharacter(&Antant) && count < 3)
                            {
                                *(chara[count]) = Antant;
                                chara[count]->index_game = count + 4;
                                count++;
                                break;
                            }
                            else
                            {
                                break;
                            }
                        }

                        if (x >= 673 && x <= 967 && y>= 446 && y <= 518)
                        {
                            if (IfFirstChooseCharacter(&Lingren) && count < 3)
                            {
                                *(chara[count]) = Lingren;
                                chara[count]->index_game = count + 4;
                                count++;
                                break;
                            }
                            else
                            {
                                break;
                            }
                        }

                        if (x >= 673 && x <= 967 && y>= 518 && y <= 591)
                        {
                            if (IfFirstChooseCharacter(&CXK) && count < 3)
                            {
                                *(chara[count]) = CXK;
                                chara[count]->index_game = count + 4;
                                count++;
                                break;
                            }
                            else
                            {
                                break;
                            }
                        }

                        if (x >= 673 && x <= 967 && y>= 591 && y <= 671)
                        {
                            if (IfFirstChooseCharacter(&Ren) && count < 3)
                            {
                                *(chara[count]) = Ren;
                                chara[count]->index_game = count + 4;
                                count++;
                                break;
                            }
                            else
                            {
                                break;
                            }
                        }

                        if (x >= 673 && x <= 967 && y>= 671 && y <= 734)
                        {
                            if (IfFirstChooseCharacter(&Chen) && count < 3)
                            {
                                *(chara[count]) = Chen;
                                chara[count]->index_game = count + 4;
                                count++;
                                break;
                            }
                            else
                            {
                                break;
                            }
                        }
                    }
                    break;
                default:
                    break;
            }
        }
        SDL_Delay(5);
    }
}
