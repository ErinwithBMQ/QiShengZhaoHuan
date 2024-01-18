//
// Created by Erin on 2024/1/15.
//

//处理各个页面的函数

#ifndef SDL_SAMPLE_PAGE_H
#define SDL_SAMPLE_PAGE_H

void MainPage();
int ChooseLevel();
void ChooseCharacter();

void BeginBattle(Character *chara1, Character *chara2, Character *chara3,
                 Character *chara4, Character *chara5, Character *chara6, Character **charanow);

int InBattle(int *count, bool *who_first, int tou[],
              Character *chara1, Character *chara2, Character *chara3,
              Character *chara4, Character *chara5, Character *chara6, Character **charanow);

void AfterBattle(int *count,
                 Character *chara1, Character *chara2, Character *chara3,
                 Character *chara4, Character *chara5, Character *chara6);
void WinBattle();
void LoseBattle();

#endif //SDL_SAMPLE_PAGE_H
