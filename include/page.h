//
// Created by Erin on 2024/1/15.
//

//处理各个页面的函数

#ifndef SDL_SAMPLE_PAGE_H
#define SDL_SAMPLE_PAGE_H

#include <action.h>

extern bool if_changemusic;

void MainPage();
int MainchoosePage();
bool ChooseLevel(Character *chara1, Character *chara2, Character *chara3);
bool ChooseCharacter(Character *chara4, Character *chara5, Character *chara6);

void BeginBattle(Character *chara1, Character *chara2, Character *chara3,
                 Character *chara4, Character *chara5, Character *chara6, Character **charanow);

int InBattle(int *count, int *who_first, int tou[],
              Character *chara1, Character *chara2, Character *chara3,
              Character *chara4, Character *chara5, Character *chara6,
              Character **charanow, Character **chara_enemy_now);

int AfterBattle(int *count, Character **chara_now, Character **chara_enemy_now,
                 Character *chara1, Character *chara2, Character *chara3,
                 Character *chara4, Character *chara5, Character *chara6);
void WinBattle();
void LoseBattle();

void Tujian();

int Tujian_1(int *show);
int Tujian_2(int *show);
int Tujian_3(int *show);
void Showmessage(Card *card);

void Wanfa();

#endif //SDL_SAMPLE_PAGE_H
