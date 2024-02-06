//
// Created by Erin on 2024/1/15.
//

// TODO：3.战斗日志  4.战斗动画  7.角色信息的详细显示  8.主页选项

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
#include <action.h>
#include <time.h>

void MainPage()
{
    SDL_Event event_main;
    while (1)
    {
        SDL_Texture *texture_main = IMG_LoadTexture(renderer, "./res/image/mainpage.jpg");
        SDL_RenderCopy(renderer, texture_main, NULL, NULL);
        SDL_RenderPresent(renderer);

        SDL_DestroyTexture(texture_main);

        while (SDL_PollEvent(&event_main))
        {
            switch (event_main.type) {
                case SDL_QUIT:
                    quit_delete();
                    exit(0);
                case SDL_MOUSEBUTTONDOWN:
                    if (event_main.button.button == SDL_BUTTON_LEFT)
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

int MainchoosePage()
{
    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
    SDL_RenderClear(renderer);

    SDL_Texture *texture_mainchoose = IMG_LoadTexture(renderer, "./res/image/main_choose.jpg");
    SDL_RenderCopy(renderer, texture_mainchoose, NULL, NULL);
    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(texture_mainchoose);

    SDL_Event event_choose;
    while (1)
    {
        while (SDL_PollEvent(&event_choose))
        {
            switch (event_choose.type) {
                case SDL_QUIT:
                    quit_delete();
                    exit(0);
                case SDL_MOUSEBUTTONDOWN:
                    if (event_choose.button.button == SDL_BUTTON_LEFT)
                    {
                        int x = event_choose.button.x;
                        int y = event_choose.button.y;

                        if (x >= 474 && x <= 820 && y >= 251 && y <= 322)
                        {
                            return 1;
                        }
                        else if (x >= 474 && x <= 820 && y >= 381 && y <= 477)
                        {
                            return 2;
                        }
                        else if (x >= 474 && x <= 820 && y >= 510 && y <= 574)
                        {
                            return 3;
                        }
                        else if (x >= 474 && x <= 820 && y >= 646 && y <= 718)
                        {
                            quit_delete();
                            exit(0);
                        }
                    }
            }
        }
    }
}

bool ChooseLevel(Character *chara1, Character *chara2, Character *chara3)
{
    SDL_RenderClear(renderer);
    SDL_Texture *texture_choose = IMG_LoadTexture(renderer, "./res/image/choose_enemy.jpg");
    SDL_RenderCopy(renderer, texture_choose, NULL, NULL);
    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(texture_choose);

    SDL_Event event;

    while (1)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type) {
                case SDL_QUIT: //直接退出
                    quit_delete();
                    exit(0);
                case SDL_MOUSEBUTTONDOWN: //鼠标左键
                    if (event.button.button == SDL_BUTTON_LEFT)
                    {
                        int x = event.button.x;
                        int y = event.button.y;

                        if (x >= 20 && x <= 569 && y >= 175 && y <= 246)
                        {
                            *chara1 = Qiuqiuren;
                            *chara2 = Qiuqiuren;
                            *chara3 = Qiuqiuren;
                            return 1;
                        }
                        else if (x >= 20 && x <= 569 && y >= 314 && y <= 389)
                        {
                            *chara1 = Qiuqiuren;
                            *chara2 = MudunQiuqiu;
                            *chara3 = Qiuqiuren;
                            return 1;
                        }
                        else if (x >= 20 && x <= 569 && y >= 453 && y <= 525)
                        {
                            *chara1 = LeiQiuqiuShe;
                            *chara2 = LeiQiuqiuShe;
                            *chara3 = MudunQiuqiu;
                            return 1;
                        }
                        else if (x >= 20 && x <= 569 && y >= 592 && y <= 670)
                        {
                            *chara1 = LeifuQiuqiu;
                            *chara2 = HuofuQiuqiu;
                            *chara3 = MudunQiuqiu;
                            return 1;
                        }
                        else if (x >= 700 && x <= 1251 && y >= 175 && y <= 246)
                        {
                            *chara1 = HailuanguiHuo;
                            *chara2 = HailuanguiLei;
                            *chara3 = HailuanguiHuo;
                            return 1;
                        }
                        else if (x >= 700 && x <= 1251 && y >= 314 && y <= 389)
                        {
                            *chara1 = Huochong;
                            *chara2 = Leichui;
                            *chara3 = Shuichong;
                            return 1;
                        }
                        else if (x >= 700 && x <= 1251 && y >= 453 && y <= 525)
                        {
                            *chara1 = LeifuQiuqiu;
                            *chara2 = Tewalin;
                            *chara3 = HuofuQiuqiu;
                            return 1;
                        }
                        else if (x >= 700 && x <= 1251 && y >= 592 && y <= 670)
                        {
                            Character *chara_enemy[3] = {chara1, chara2, chara3};
                            srand((unsigned int)time(NULL));

                            for (int i = 0; i < 3; ++i)
                            {
                                int suiji = rand() % 11;
                                if (suiji == 0)
                                {
                                    *chara_enemy[i] = Qiuqiuren;
                                }
                                else if (suiji == 1)
                                {
                                    *chara_enemy[i] = LeiQiuqiuShe;
                                }
                                else if (suiji == 2)
                                {
                                    *chara_enemy[i] = HuofuQiuqiu;
                                }
                                else if (suiji == 3)
                                {
                                    *chara_enemy[i] = LeifuQiuqiu;
                                }
                                else if (suiji == 4)
                                {
                                    *chara_enemy[i] = MudunQiuqiu;
                                }
                                else if (suiji == 5)
                                {
                                    *chara_enemy[i] = HailuanguiHuo;
                                }
                                else if (suiji == 6)
                                {
                                    *chara_enemy[i] = HailuanguiLei;
                                }
                                else if (suiji == 7)
                                {
                                    *chara_enemy[i] = Huochong;
                                }
                                else if (suiji == 8)
                                {
                                    *chara_enemy[i] = Leichui;
                                }
                                else if (suiji == 9)
                                {
                                    *chara_enemy[i] = Shuichong;
                                }
                                else if (suiji == 10)
                                {
                                    *chara_enemy[i] = Tewalin;
                                }
                            }
                            return 1;
                        }
                        else if (x >= 1180 && x <= 1265 && y >= 20 && y <= 113)
                        {
                            return 0;
                        }
                    }
                default:
                    break;
            }
        }
    }
}

void WinBattle()
{
    if_changemusic = true;
    SDL_Event event_main;
    while (1)
    {
        SDL_Texture *texture_win = IMG_LoadTexture(renderer, "./res/image/win.jpg");
        SDL_RenderCopy(renderer, texture_win, NULL, NULL);
        SDL_RenderPresent(renderer);

        SDL_DestroyTexture(texture_win);

        while (SDL_PollEvent(&event_main))
        {
            switch (event_main.type) {
                case SDL_QUIT:
                    quit_delete();
                    exit(0);
                case SDL_MOUSEBUTTONDOWN:
                    if (event_main.button.button == SDL_BUTTON_LEFT)
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

    ShierteerKouXue(chara4, chara5, chara6);

    Character *chara_show = chara1;
    int jineng_index = 0;
    int if_qiehuan = 0;

    while (1)
    {
        if (if_showkillblood)
        {
            ShowKillBlood(chara1, chara2, chara3, chara4, chara5, chara6, chara_show, jineng_index);
            continue;
        }

        if (if_final_a == true && if_final_b == true)  //特殊情况：两方都结束回合但我方角色死亡需要切换角色
        {
            if ((*charanow)->xue == 0)
            {
                ChangeCharacterWhenDead(charanow, chara4, chara5, chara6);
                if_qiehuan = 1;
                continue;
            }
            else
            {
                break;  //结束本回合
            }
        }

        //页面显示

        int n = if_end(chara1, chara2, chara3, chara4, chara5, chara6);
        if (n == 1)
        {
            return 1;
        }
        else if (n == -1)
        {
            return 0;
        }

        CharacterDeadOrAlive(chara1, chara2, chara3, chara4, chara5, chara6);

        SDL_RenderClear(renderer);

        ShowTheWhole(chara1, chara2, chara3, chara4, chara5, chara6);
        ShowTou(tou);
        ShowButtom();
        ShowEndHH(who_fight);
        ShowIfEndTurn(if_final_a, if_final_b);
        ShowTurn(*count);
        ShowMyCard();

        if (who_fight == 1)
        {
            ShowWeAction();
        }
        else
        {
            ShowEnemyAction();
        }

        for (int i = 0; i < 4; ++i)
        {
            if (summon_all[i]->index != 0)
            {
                PresentSummonGame(summon_all[i]);
            }
        }

        SDL_RenderPresent(renderer);

        if (if_qiehuan == 1)
        {
            ShowQieHuanChara(*charanow);
            if_qiehuan = 0;
            continue;
        }
        else if (if_qiehuan == 2)
        {
            ShowQieHuanChara(*chara_enemy_now);
            if_qiehuan = 0;
            continue;
        }

        //我方角色死亡强制切换角色
        if ((*charanow)->xue == 0)
        {
            ChangeCharacterWhenDead(charanow, chara4, chara5, chara6);
            if ((*charanow)->xue > 0)
            {
                if_qiehuan = 1;
            }
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
            ActionLiaoliJiaShang(*charanow);
            //激化、草原核的增伤
            JihuaAddition(*charanow);
            CaoyuanheAddition(*charanow);

            //选择哪个技能
            int whichone = ChooseWhichSkill(charanow, tou, chara1, chara2, chara3, chara4, chara5, chara6, if_final_a);

            if (whichone == -1) //退出战斗
            {
                return 0;
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
                //TODO: 造成伤害动画
                ReduceTou(*charanow, tou, 1);  //减少骰子
                kill_blood(*charanow, *chara_enemy_now, 1);  //扣血

                shanghai[0] = (*charanow)->shanghai[0] + (*charanow)->shanghai_more[0];
                if_showkillblood = true;
                shanghai[2] = 5;
                shanghai[3] = 5;
                shanghai[4] = (*chara_enemy_now)->index_game;
                chara_show = *charanow;
                jineng_index = 1;

                //如果有附魔那就造成元素附着
                if ((*charanow)->if_pugongfumo)
                {
                    ChooseWhichReaction((*charanow)->yuansu, chara_enemy_now, chara1, chara2, chara3);
                    YuanSuFuZhuo(*charanow, *chara_enemy_now);
                    JihuaReduce(*charanow);
                    CaoyuanheReduce(*charanow);
                    shanghai[2] = (*charanow)->yuansu;
                }

                //充能增加
                if ((*charanow)->baofa_now < (*charanow)->baofa_num)
                {
                    (*charanow)->baofa_now++;
                }

                //刃的回血机制判断
                RenPuHuiXue(*charanow);

                //是否减少特殊状态数目
                SpecialAdditionReduceCountPu(*charanow);
                SpecialAdditionReduceCountAll(*charanow);

                //敌方是否要强制切换角色
                ChangeCharacterEnemy(chara_enemy_now, chara1, chara2, chara3);
                //判断是否结束游戏
                int n1 = if_end(chara1, chara2, chara3, chara4, chara5, chara6);

                if (if_qiehuanjuese)
                {
                    ChaoZai(charanow, chara4, chara5, chara6);
                    if_qiehuanjuese = false;
                }

                if (n1 == 0)  //不结束，对方行动
                {
                    if (!if_final_b)
                    {
                        who_fight = 0;
                    }

                    continue;
                }
            }
            else if (whichone == 2) //使用元素战技
            {
                //TODO: 造成伤害动画
                ReduceTou(*charanow, tou, 2);
                kill_blood(*charanow, *chara_enemy_now, 2);

                shanghai[0] = (*charanow)->shanghai[1] + (*charanow)->shanghai_more[1];
                if_showkillblood = true;
                shanghai[2] = (*charanow)->yuansu;
                shanghai[3] = 5;
                shanghai[4] = (*chara_enemy_now)->index_game;
                chara_show = *charanow;
                jineng_index = 2;

                JihuaReduce(*charanow);
                CaoyuanheReduce(*charanow);

                ChooseWhichReaction((*charanow)->yuansu, chara_enemy_now, chara1, chara2, chara3);

                SpecialAdditionReduceCountAll(*charanow);

                if ((*charanow)->yszj != NULL)
                {
                    (*charanow)->yszj(chara1, chara2, chara3, *charanow);
                }

                YuanSuFuZhuo(*charanow, *chara_enemy_now);

                if ((*charanow)->baofa_now < (*charanow)->baofa_num)
                {
                    (*charanow)->baofa_now++;
                }

                ChangeCharacterEnemy(chara_enemy_now, chara1, chara2, chara3);

                int n1 = if_end(chara1, chara2, chara3, chara4, chara5, chara6);

                if (if_qiehuanjuese)
                {
                    ChaoZai(charanow, chara4, chara5, chara6);
                    if_qiehuanjuese = false;
                }

                if (n1 == 0)
                {
                    if (!if_final_b)
                    {
                        who_fight = 0;
                    }

                    continue;
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
                shanghai[0] = (*charanow)->shanghai[2] + (*charanow)->shanghai_more[2];
                if_showkillblood = true;
                shanghai[2] = (*charanow)->yuansu;
                shanghai[3] = 5;
                shanghai[4] = (*chara_enemy_now)->index_game;
                chara_show = *charanow;
                jineng_index = 3;


                ChooseWhichReaction((*charanow)->yuansu, chara_enemy_now, chara1, chara2, chara3);

                YuanSuFuZhuo(*charanow, *chara_enemy_now);


                (*charanow)->baofa_now = 0;
                ChangeCharacterEnemy(chara_enemy_now, chara1, chara2, chara3);
                int n1 = if_end(chara1, chara2, chara3, chara4, chara5, chara6);

                if (if_qiehuanjuese)
                {
                    ChaoZai(charanow, chara4, chara5, chara6);
                    if_qiehuanjuese = false;
                }

                if (n1 == 0)
                {
                    if (!if_final_b)
                    {
                        who_fight = 0;
                    }

                    continue;
                }
            }
            else if (whichone == 4)  //切换角色
            {
                if (!if_final_b && if_kuaijie == false)
                {
                    who_fight = 0;
                }

                if (!if_notusetou)
                {
                    ReduceTouChange(chara4, chara5, chara6, tou);
                }

                if_kuaijie = false;
                if_notusetou = false;

                if_qiehuan = 1;

                continue;
            }
        }

        if (who_fight == 0 && if_final_b == false)  //对方行动
        {
            //TODO:对手逻辑的编写

            SDL_Delay(1200);

            ChangeCharacterShanghai(*chara_enemy_now, *charanow);  //提前计算基础元素反应伤害

            if ((*chara_enemy_now)->special_state > 0)  //调用角色本身特殊状态函数
            {
                if ((*chara_enemy_now)->SpecialAddition != NULL)
                {
                    (*chara_enemy_now)->SpecialAddition(*chara_enemy_now);
                }
            }
            else
            {
                (*chara_enemy_now)->if_pugongfumo = false;
            }

            //普攻附魔后计算基础元素反应增伤
            ChangeCharacterShanghaiPu(*chara_enemy_now, *charanow);

            if (enemy_count == 3)
            {
                if_final_b = true;
            }
            else if (enemy_count == 0 && ((*chara_enemy_now)->baofa_now < (*chara_enemy_now)->baofa_num))
            {
                kill_blood(*chara_enemy_now, *charanow, 2);

                shanghai[0] = (*chara_enemy_now)->shanghai[1] + (*chara_enemy_now)->shanghai_more[1];
                if_showkillblood = true;
                shanghai[2] = (*chara_enemy_now)->yuansu;
                shanghai[3] = 5;
                shanghai[4] = (*charanow)->index_game;
                chara_show = *chara_enemy_now;
                jineng_index = 2;

                if ((*chara_enemy_now)->yszj != NULL)
                {
                    (*chara_enemy_now)->yszj(chara4, chara5, chara6, *chara_enemy_now);
                }

                if ((*chara_enemy_now)->baofa_now < (*chara_enemy_now)->baofa_num)
                {
                    (*chara_enemy_now)->baofa_now++;
                }

                ChooseWhichReaction((*chara_enemy_now)->yuansu, charanow, chara4, chara5, chara6);

                YuanSuFuZhuo(*chara_enemy_now, *charanow);

                enemy_count++;
            }
            else if ((*chara_enemy_now)->baofa_now == (*chara_enemy_now)->baofa_num && enemy_count == 0)
            {
                kill_blood(*chara_enemy_now, *charanow, 3);

                shanghai[0] = (*chara_enemy_now)->shanghai[2] + (*chara_enemy_now)->shanghai_more[2];
                if_showkillblood = true;
                shanghai[2] = (*chara_enemy_now)->yuansu;
                shanghai[3] = 5;
                shanghai[4] = (*charanow)->index_game;
                chara_show = *chara_enemy_now;
                jineng_index = 3;

                (*chara_enemy_now)->baofa_now = 0;

                if ((*chara_enemy_now)->ysbf != NULL)
                {
                    (*chara_enemy_now)->ysbf(chara4, chara5, chara6, *chara_enemy_now);
                }

                ChooseWhichReaction((*chara_enemy_now)->yuansu, charanow, chara4, chara5, chara6);

                YuanSuFuZhuo(*chara_enemy_now, *charanow);

                enemy_count++;
            }
            else if (enemy_count == 1)
            {
                kill_blood(*chara_enemy_now, *charanow, 1);
                shanghai[0] = (*chara_enemy_now)->shanghai[0] + (*chara_enemy_now)->shanghai_more[0];
                if_showkillblood = true;
                shanghai[2] = 5;
                shanghai[3] = 5;
                shanghai[4] = (*charanow)->index_game;
                chara_show = *chara_enemy_now;
                jineng_index = 1;

                if ((*chara_enemy_now)->if_pugongfumo)
                {
                    ChooseWhichReaction((*chara_enemy_now)->yuansu, charanow, chara4, chara5, chara6);
                    YuanSuFuZhuo(*chara_enemy_now, *charanow);
                    shanghai[2] = (*chara_enemy_now)->yuansu;
                    (*chara_enemy_now)->special_state--;
                }

                if ((*chara_enemy_now)->baofa_now < (*chara_enemy_now)->baofa_num)
                {
                    (*chara_enemy_now)->baofa_now++;
                }

                enemy_count++;
            }
            else if (enemy_count == 2)
            {
                if ((*chara_enemy_now)->baofa_now < (*chara_enemy_now)->baofa_num)
                {
                    if (ChangeEnemyAuto(chara_enemy_now, chara1, chara2, chara3))
                    {
                        if_qiehuan = 2;
                        enemy_count++;
                    }
                    else
                    {
                        if_final_b = true;
                    }
                }
                else
                {
                    if_final_b = true;
                }
            }


            if (!if_final_a)
            {
                who_fight = 1;
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
    for (int i = 0; i < 4; ++i)
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

            for (int j = 0; j < 4; ++j)
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

            JihuaAddtionSummon(summon_all[i]);
            CaoyuanheAddtionSummon(summon_all[i]);

            ChooseWhichReaction(summon_all[i]->yuansu, chara_enemy_now, chara1, chara2, chara3);

            ChangeSummonShanghai(summon_all[i], *chara_enemy_now);

            SummonKillBlood(summon_all[i], *chara_enemy_now);

            shanghai[0] = summon_all[i]->shanghai + summon_all[i]->shanghai_more;
            shanghai[2] = summon_all[i]->yuansu;
            shanghai[3] = 5;
            shanghai[4] = (*chara_enemy_now)->index_game;

            ShowKillBlood(chara1, chara2, chara3, chara4, chara5, chara6, NULL, 0);

            summon_all[i]->shanghai_more = 0;

            if (summon_all[i]->index == 1)
            {
                summon_all[i]->yuansu = 5;
            }

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

    for (int j = 0; j < 4; ++j)
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

    SDL_Delay(800);

    SuijiChouka(2);

    TTF_CloseFont(font_summon);
    SDL_FreeSurface(surface_turn);
    SDL_DestroyTexture(texture_turn);
    SDL_DestroyTexture(texture_back);

    (*count)++;

    SpecialAdditionReduceTurn(chara4, chara5, chara6);

    liaolijiashang[0] = 0;
    liaolijiashang[1] = 0;

    return -1;
}

void LoseBattle()
{
    if_changemusic = true;
    SDL_Event event_main;
    while (1)
    {
        SDL_Texture *texture_LOSE = IMG_LoadTexture(renderer, "./res/image/lose.jpg");
        SDL_RenderCopy(renderer, texture_LOSE, NULL, NULL);
        SDL_RenderPresent(renderer);

        SDL_DestroyTexture(texture_LOSE);

        while (SDL_PollEvent(&event_main))
        {
            switch (event_main.type) {
                case SDL_QUIT:
                    quit_delete();
                    exit(0);
                case SDL_MOUSEBUTTONDOWN:
                    if (event_main.button.button == SDL_BUTTON_LEFT)
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

                        if (x >= 967 && x <= 1240 && y>= 446 && y <= 518)
                        {
                            if (IfFirstChooseCharacter(&Kafuka) && count < 3)
                            {
                                *(chara[count]) = Kafuka;
                                chara[count]->index_game = count + 4;
                                count++;
                                break;
                            }
                            else
                            {
                                break;
                            }
                        }

                        if (x >= 967 && x <= 1240 && y>= 518 && y <= 591)
                        {
                            if (IfFirstChooseCharacter(&Shierteer) && count < 3)
                            {
                                *(chara[count]) = Shierteer;
                                chara[count]->index_game = count + 4;
                                count++;
                                break;
                            }
                            else
                            {
                                break;
                            }
                        }

                        if (x >= 967 && x <= 1240 && y>= 591 && y <= 671)
                        {
                            if (IfFirstChooseCharacter(&Kelai) && count < 3)
                            {
                                *(chara[count]) = Kelai;
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

void Tujian()
{
    SDL_Event event_main;
    int show = 1;

    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);

    while (1)
    {
        if (show == 1)
        {
            int n = Tujian_1(&show);
            if (n == 0)
            {
                return;
            }
        }
        if (show == 2)
        {
            int n = Tujian_2(&show);
            if (n == 0)
            {
                return;
            }
        }
        if (show == 3)
        {
            int n = Tujian_3(&show);
            if (n == 0)
            {
                return;
            }
        }

//        while (SDL_PollEvent(&event_main))
//        {
//            switch (event_main.type) {
//                case SDL_QUIT:
//                    quit_delete();
//                    exit(0);
//                case SDL_MOUSEBUTTONDOWN:
//                    if (event_main.button.button == SDL_BUTTON_LEFT)
//                    {
//                        int x = event_main.button.x;
//                        int y = event_main.button.y;
//
//                        if (x >= 458 && y >= 52 && x <= 611 && y <= 106)
//                        {
//                            show = 1;
//                        }
//                        else if (x >= 646 && y >= 52 && x <= 792 && y <= 106)
//                        {
//                            show = 2;
//                        }
//                        else if (x >= 829 && y >= 52 && x <= 973 && y <= 106)
//                        {
//                            show = 3;
//                        }
//                        else if (x >= 1167 && y >= 28 && x <= 1258 && y <= 125)
//                        {
//                            return;
//                        }
//                    }
//                    break;
//                default:
//                    break;
//            }
//        }
//        SDL_Delay(5);
    }
}

void Wanfa()
{
    SDL_Event event_main;
    int show = 1;

    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);

    while (1)
    {
        if (show == 1)
        {
            SDL_RenderClear(renderer);
            SDL_Texture *texture_image = IMG_LoadTexture(renderer, "./res/image/wanfa_1.png");
            SDL_RenderCopy(renderer, texture_image, NULL, NULL);
            SDL_RenderPresent(renderer);

            SDL_DestroyTexture(texture_image);
        }
        else if (show == 2)
        {
            SDL_RenderClear(renderer);
            SDL_Texture *texture_image = IMG_LoadTexture(renderer, "./res/image/wanfa_2.png");
            SDL_RenderCopy(renderer, texture_image, NULL, NULL);
            SDL_RenderPresent(renderer);

            SDL_DestroyTexture(texture_image);
        }
        else if (show == 3)
        {
            SDL_RenderClear(renderer);
            SDL_Texture *texture_image = IMG_LoadTexture(renderer, "./res/image/wanfa_3.png");
            SDL_RenderCopy(renderer, texture_image, NULL, NULL);
            SDL_RenderPresent(renderer);

            SDL_DestroyTexture(texture_image);
        }


        while (SDL_PollEvent(&event_main))
        {
            switch (event_main.type) {
                case SDL_QUIT:
                    quit_delete();
                    exit(0);
                case SDL_MOUSEBUTTONDOWN:
                    if (event_main.button.button == SDL_BUTTON_LEFT)
                    {
                        int x = event_main.button.x;
                        int y = event_main.button.y;

                        if (x >= 498 && y >= 60 && x <= 667 && y <= 117)
                        {
                            show = 1;
                        }
                        else if (x >= 709 && y >= 60 && x <= 860 && y <= 117)
                        {
                            show = 2;
                        }
                        else if (x >= 903 && y >= 60 && x <= 1069 && y <= 117)
                        {
                            show = 3;
                        }
                        else if (x >= 1167 && y >= 28 && x <= 1258 && y <= 133)
                        {
                            return;
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

int Tujian_1(int *show)
{
    Character *chara_show = &Alhaitham;
    bool if_show = false;

    SDL_Event event_choose;

    while (1)
    {
        if(!if_show)
        {
            SDL_RenderClear(renderer);
            SDL_Texture *texture_image = IMG_LoadTexture(renderer, "./res/image/tujian_chara.jpg");
            SDL_RenderCopy(renderer, texture_image, NULL, NULL);
            SDL_RenderPresent(renderer);

            SDL_DestroyTexture(texture_image);
        }
        else
        {
            SDL_RenderClear(renderer);
            SDL_Texture *texture_image = IMG_LoadTexture(renderer, "./res/image/tujian_message.jpg");
            SDL_RenderCopy(renderer, texture_image, NULL, NULL);

            SDL_Rect rect_message = {.x = 291, .y = 313};
            SDL_QueryTexture(chara_show->image, NULL, NULL, &rect_message.w, &rect_message.h);
            SDL_RenderCopy(renderer, chara_show->image, NULL, &rect_message);

            rect_message.x = 560;
            rect_message.y = 227;
            SDL_QueryTexture(chara_show->image_message_big, NULL, NULL, &rect_message.w, &rect_message.h);
            SDL_RenderCopy(renderer, chara_show->image_message_big, NULL, &rect_message);

            SDL_RenderPresent(renderer);
            SDL_DestroyTexture(texture_image);
        }

        while (SDL_PollEvent(&event_choose))
        {
            switch (event_choose.type) {
                case SDL_QUIT:
                    quit_delete();
                    exit(0);
                case SDL_MOUSEBUTTONDOWN:
                    if (event_choose.button.button == SDL_BUTTON_LEFT)
                    {
                        int x = event_choose.button.x;
                        int y = event_choose.button.y;

                        if (!if_show)
                        {
                            if (x >= 24 && y >= 161 && x <= 184 && y <= 425)
                            {
                                chara_show = &Alhaitham;
                                if_show = true;
                            }
                            else if (x >= 221 && y >= 161 && x <= 375 && y <= 425)
                            {
                                chara_show = &Antant;
                                if_show = true;
                            }
                            else if (x >= 421 && y >= 161 && x <= 572 && y <= 425)
                            {
                                chara_show = &Zihuang;
                                if_show = true;
                            }
                            else if (x >= 628 && y >= 161 && x <= 781 && y <= 425)
                            {
                                chara_show = &Lingren;
                                if_show = true;
                            }
                            else if (x >= 836 && y >= 161 && x <= 994 && y <= 425)
                            {
                                chara_show = &Huoxing;
                                if_show = true;
                            }
                            else if (x >= 1053 && y >= 161 && x <= 1207 && y <= 425)
                            {
                                chara_show = &Ren;
                                if_show = true;
                            }
                            if (x >= 24 && y >= 473 && x <= 184 && y <= 748)
                            {
                                chara_show = &Kelai;
                                if_show = true;
                            }
                            else if (x >= 221 && y >= 473 && x <= 375 && y <= 748)
                            {
                                chara_show = &CXK;
                                if_show = true;
                            }
                            else if (x >= 421 && y >= 473 && x <= 572 && y <= 748)
                            {
                                chara_show = &Kafuka;
                                if_show = true;
                            }
                            else if (x >= 628 && y >= 473 && x <= 781 && y <= 748)
                            {
                                chara_show = &Chen;
                                if_show = true;
                            }
                            else if (x >= 836 && y >= 473 && x <= 994 && y <= 748)
                            {
                                chara_show = &Shierteer;
                                if_show = true;
                            }
                            else if (x >= 646 && y >= 52 && x <= 792 && y <= 106)
                            {
                                *show = 2;
                                return 1;
                            }
                            else if (x >= 829 && y >= 52 && x <= 973 && y <= 106)
                            {
                                *show = 3;
                                return 1;
                            }
                            else if (x >= 1167 && y >= 28 && x <= 1258 && y <= 125)
                            {
                                return 0;
                            }
                        }
                        else
                        {
                            if_show = false;
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

int Tujian_2(int *show)
{
    Character *chara_show = &Qiuqiuren;
    bool if_show = false;

    SDL_Event event_choose;

    while (1)
    {
        if(!if_show)
        {
            SDL_RenderClear(renderer);
            SDL_Texture *texture_image = IMG_LoadTexture(renderer, "./res/image/tujian_enemy.jpg");
            SDL_RenderCopy(renderer, texture_image, NULL, NULL);
            SDL_RenderPresent(renderer);

            SDL_DestroyTexture(texture_image);
        }
        else
        {
            SDL_Rect rect_message = {.x = 890, .y = 500};
            SDL_QueryTexture(chara_show->image_message, NULL, NULL, &rect_message.w, &rect_message.h);
            SDL_RenderCopy(renderer, chara_show->image_message, NULL, &rect_message);

            SDL_RenderPresent(renderer);
        }

        while (SDL_PollEvent(&event_choose))
        {
            switch (event_choose.type) {
                case SDL_QUIT:
                    quit_delete();
                    exit(0);
                case SDL_MOUSEBUTTONDOWN:
                    if (event_choose.button.button == SDL_BUTTON_LEFT)
                    {
                        int x = event_choose.button.x;
                        int y = event_choose.button.y;

                        if (!if_show)
                        {
                            if (x >= 20 && y >= 184 && x <= 184 && y <= 441)
                            {
                                chara_show = &Qiuqiuren;
                                if_show = true;
                            }
                            else if (x >= 208 && y >= 184 && x <= 368 && y <= 441)
                            {
                                chara_show = &HuofuQiuqiu;
                                if_show = true;
                            }
                            else if (x >= 405 && y >= 184 && x <= 563 && y <= 441)
                            {
                                chara_show = &MudunQiuqiu;
                                if_show = true;
                            }
                            else if (x >= 593 && y >= 184 && x <= 758 && y <= 441)
                            {
                                chara_show = &Leichui;
                                if_show = true;
                            }
                            else if (x >= 796 && y >= 184 && x <= 952 && y <= 441)
                            {
                                chara_show = &HailuanguiHuo;
                                if_show = true;
                            }
                            else if (x >= 999 && y >= 184 && x <= 1148 && y <= 441)
                            {
                                chara_show = &Tewalin;
                                if_show = true;
                            }
                            if (x >= 20 && y >= 493 && x <= 184 && y <= 772)
                            {
                                chara_show = &LeiQiuqiuShe;
                                if_show = true;
                            }
                            else if (x >= 208 && y >= 493 && x <= 368 && y <= 772)
                            {
                                chara_show = &LeifuQiuqiu;
                                if_show = true;
                            }
                            else if (x >= 405 && y >= 493 && x <= 563 && y <= 772)
                            {
                                chara_show = &Shuichong;
                                if_show = true;
                            }
                            else if (x >= 593 && y >= 493 && x <= 758 && y <= 772)
                            {
                                chara_show = &Huochong;
                                if_show = true;
                            }
                            else if (x >= 796 && y >= 493 && x <= 952 && y <= 772)
                            {
                                chara_show = &HailuanguiLei;
                                if_show = true;
                            }
                            else if (x >= 458 && y >= 52 && x <= 611 && y <= 106)
                            {
                                *show = 1;
                                return 1;
                            }
                            else if (x >= 829 && y >= 52 && x <= 973 && y <= 106)
                            {
                                *show = 3;
                                return 1;
                            }
                            else if (x >= 1167 && y >= 28 && x <= 1258 && y <= 125)
                            {
                                return 0;
                            }
                        }
                        else
                        {
                            if_show = false;
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

int Tujian_3(int *show)
{
    Card *card_show = &lianhua;
    bool if_show = false;

    SDL_Event event_choose;

    while (1)
    {
        if(!if_show)
        {
            SDL_RenderClear(renderer);
            SDL_Texture *texture_image = IMG_LoadTexture(renderer, "./res/image/tujian_shijian.jpg");
            SDL_RenderCopy(renderer, texture_image, NULL, NULL);
            SDL_RenderPresent(renderer);

            SDL_DestroyTexture(texture_image);
        }
        else
        {
            Showmessage(card_show);
        }

        while (SDL_PollEvent(&event_choose))
        {
            switch (event_choose.type) {
                case SDL_QUIT:
                    quit_delete();
                    exit(0);
                case SDL_MOUSEBUTTONDOWN:
                    if (event_choose.button.button == SDL_BUTTON_LEFT)
                    {
                        int x = event_choose.button.x;
                        int y = event_choose.button.y;

                        if (!if_show)
                        {
                            if (x >= 53 && y >= 197 && x <= 137 && y <= 339)
                            {
                                card_show = &huanban;
                                if_show = true;
                            }
                            else if (x >= 164 && y >= 197 && x <= 249 && y <= 339)
                            {
                                card_show = &jiaogei;
                                if_show = true;
                            }
                            else if (x >= 284 && y >= 197 && x <= 363 && y <= 339)
                            {
                                card_show = &hegui;
                                if_show = true;
                            }
                            else if (x >= 398 && y >= 197 && x <= 477 && y <= 339)
                            {
                                card_show = &fengbu;
                                if_show = true;
                            }
                            else if (x >= 53 && y >= 383 && x <= 137 && y <= 527)
                            {
                                card_show = &yunchou;
                                if_show = true;
                            }
                            else if (x >= 164 && y >= 383 && x <= 249 && y <= 527)
                            {
                                card_show = &xingtian;
                                if_show = true;
                            }
                            else if (x >= 284 && y >= 383 && x <= 363 && y <= 527)
                            {
                                card_show = &bestfriend;
                                if_show = true;
                            }
                            else if (x >= 398 && y >= 383 && x <= 477 && y <= 527)
                            {
                                card_show = &tiantian;
                                if_show = true;
                            }
                            else if (x >= 53 && y >= 579 && x <= 137 && y <= 715)
                            {
                                card_show = &tudou;
                                if_show = true;
                            }
                            else if (x >= 164 && y >= 579 && x <= 249 && y <= 715)
                            {
                                card_show = &lianhua;
                                if_show = true;
                            }
                            else if (x >= 284 && y >= 579 && x <= 363 && y <= 715)
                            {
                                card_show = &jueyun;
                                if_show = true;
                            }
                            else if (x >= 398 && y >= 579 && x <= 477 && y <= 715)
                            {
                                card_show = &fotiao;
                                if_show = true;
                            }
                            else if (x >= 458 && y >= 52 && x <= 611 && y <= 106)
                            {
                                *show = 1;
                                return 1;
                            }
                            else if (x >= 646 && y >= 52 && x <= 792 && y <= 106)
                            {
                                *show = 2;
                                return 1;
                            }
                            else if (x >= 1167 && y >= 28 && x <= 1258 && y <= 125)
                            {
                                return 0;
                            }
                        }
                        else
                        {
                            if_show = false;
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

void Showmessage(Card *card)
{
    SDL_Rect rect_message = {.x = 720, .y = 200};

    TTF_Font *font_message = TTF_OpenFont("./res/HYWH85W.ttf", 25);
    SDL_Color color_message = {0xff, 0xff, 0xff, 0xff};
    SDL_Surface *surface_message = TTF_RenderUTF8_Solid(font_message, card->name, color_message);
    SDL_Texture *texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);

    SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
    SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

    rect_message.y += 30;
    surface_message = TTF_RenderUTF8_Solid(font_message, card->type, color_message);
    texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);

    SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
    SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

    rect_message.y += 30;
    surface_message = TTF_RenderUTF8_Solid(font_message, "消耗  个元素骰", color_message);
    texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);
    SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
    SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

    char num[2];
    itoa(card->num, num, 10);
    rect_message.x = 770;
    surface_message = TTF_RenderUTF8_Solid(font_message, num, color_message);
    texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);
    SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
    SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

    rect_message.y += 30;
    rect_message.x = 720;
    surface_message = TTF_RenderUTF8_Solid(font_message, card->message, color_message);
    texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);

    SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
    SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

    SDL_RenderPresent(renderer);

    SDL_FreeSurface(surface_message);
    SDL_DestroyTexture(texture_message);
    TTF_CloseFont(font_message);
}
