//
// Created by Erin on 2024/1/15.
//

//处理各个页面的函数

#ifndef SDL_SAMPLE_PAGE_H
#define SDL_SAMPLE_PAGE_H

#include <action.h>

extern bool if_changemusic;

void MainPage();   //一开始的主页
int MainchoosePage();  //主页选择页面
bool ChooseLevel(Character *chara1, Character *chara2, Character *chara3);  //选择关卡
bool ChooseCharacter(Character *chara4, Character *chara5, Character *chara6);  //选择角色

void BeginBattle(Character *chara1, Character *chara2, Character *chara3,
                 Character *chara4, Character *chara5, Character *chara6, Character **charanow);  //战斗开始前

int InBattle(int *count, int *who_first, int tou[],
              Character *chara1, Character *chara2, Character *chara3,
              Character *chara4, Character *chara5, Character *chara6,
              Character **charanow, Character **chara_enemy_now);   //回合中

int AfterBattle(int *count, Character **chara_now, Character **chara_enemy_now,
                 Character *chara1, Character *chara2, Character *chara3,
                 Character *chara4, Character *chara5, Character *chara6);  //每回合结束的结算阶段
void WinBattle();  //胜利
void LoseBattle(); //失败

void Tujian();  //图鉴页面

int Tujian_1(int *show); //角色图鉴
int Tujian_2(int *show); //敌人图鉴
int Tujian_3(int *show); //行动牌图鉴
void Showmessage(Card *card);  //展示行动牌信息

void Wanfa();  //玩法说明页面

#endif //SDL_SAMPLE_PAGE_H
