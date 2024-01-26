//
// Created by Erin on 2024/1/25.
//

//关于处理游戏记录以及对局内展示战斗日志的函数

#ifndef QSZH_RECORD_H
#define QSZH_RECORD_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include <character.h>
#include <stdbool.h>

void RecordWhoseTurnFirst(int who_first);
void RecordWhoseTurn(int who_turn);
void RecordKillBlood(Character *chara, Character *enemy, int n, int who);
void RecordWhoDead(Character *chara, int who);
void RecordChangeCharacter(Character *chara1, Character *chara2, int who);
void RecordWhoEndTurn(bool final);


#endif //QSZH_RECORD_H
