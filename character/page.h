//
// Created by Erin on 2024/1/15.
//

//处理各个页面的函数

#ifndef SDL_SAMPLE_PAGE_H
#define SDL_SAMPLE_PAGE_H

void MainPage();
int ChooseLevel();
void ChooseCharacter();
void BeginBattle(int count);
void InBattle(int *count);
void AfterBattle();
void WinBattle();
void LoseBattle();

#endif //SDL_SAMPLE_PAGE_H
