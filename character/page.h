//
// Created by Erin on 2024/1/15.
//

//处理各个页面的函数

#ifndef SDL_SAMPLE_PAGE_H
#define SDL_SAMPLE_PAGE_H

void MainPage(SDL_Renderer *renderer, SDL_Window *window);
int ChooseLevel(SDL_Renderer *renderer, SDL_Window *window);
void ChooseCharacter(SDL_Renderer *renderer, SDL_Window *window);
void BeginBattle(SDL_Renderer *renderer, SDL_Window *window, int count);
void InBattle(SDL_Renderer *renderer, SDL_Window *window, int *count);
void AfterBattle(SDL_Renderer *renderer, SDL_Window *window);
void WinBattle(SDL_Renderer *renderer, SDL_Window *window);
void LoseBattle(SDL_Renderer *renderer, SDL_Window *window);

#endif //SDL_SAMPLE_PAGE_H
