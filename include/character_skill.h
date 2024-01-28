//
// Created by Erin on 2024/1/26.
//

//每个角色技能额外效果的函数

#ifndef QSZH_CHARACTER_SKILL_H
#define QSZH_CHARACTER_SKILL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include <character.h>
#include <summon.h>

extern bool if_all_attack;

void Antant_yszj(Character *chara1, Character *chara2, Character *chara3, Character *chara);
void Antant_ysbf(Character *chara1, Character *chara2, Character *chara3, Character *chara);
void Lingren_ysbf(Character *chara1, Character *chara2, Character *chara3, Character *chara);
void CXK_yszj(Character *chara1, Character *chara2, Character *chara3, Character *chara);
void Chen_yszj(Character *chara1, Character *chara2, Character *chara3, Character *chara);
void Chen_ysbf(Character *chara1, Character *chara2, Character *chara3, Character *chara);

#endif //QSZH_CHARACTER_SKILL_H
