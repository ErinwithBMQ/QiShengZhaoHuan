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

void Lingren_yszj(Character *chara1, Character *chara2, Character *chara3, Character *chara);
void Lingren_ysbf(Character *chara1, Character *chara2, Character *chara3, Character *chara);
void Lingren_SpecialAdditon(Character *chara);
void QingliuSkill(Character *chara4, Character *chara5, Character *chara6);

void CXK_yszj(Character *chara1, Character *chara2, Character *chara3, Character *chara);
void CXK_ysbf(Character *chara1, Character *chara2, Character *chara3, Character *chara);
void CXK_SpecialAddition(Character *chara);

void Chen_yszj(Character *chara1, Character *chara2, Character *chara3, Character *chara);
void Chen_ysbf(Character *chara1, Character *chara2, Character *chara3, Character *chara);

void Alhaitham_yszj(Character *chara1, Character *chara2, Character *chara3, Character *chara);
void Alhaitham_ysbf(Character *chara1, Character *chara2, Character *chara3, Character *chara);
void Alhaitham_SpecialAdditon(Character *chara);

void Huoxing_yszj(Character *chara1, Character *chara2, Character *chara3, Character *chara);
void Huoxing_ysbf(Character *chara1, Character *chara2, Character *chara3, Character *chara);
void Huoxing_SpecialAdditon(Character *chara);

void Zihuang_yszj(Character *chara1, Character *chara2, Character *chara3, Character *chara);
void Zihuang_ysbf(Character *chara1, Character *chara2, Character *chara3, Character *chara);
void Zihuang_SpecialAdditon(Character *chara);

void Ren_yszj(Character *chara1, Character *chara2, Character *chara3, Character *chara);
void Ren_ysbf(Character *chara1, Character *chara2, Character *chara3, Character *chara);
void Ren_SpecialAddition(Character *chara);
void RenPuHuiXue(Character *chara);

void Kafuka_yszj(Character *chara1, Character *chara2, Character *chara3, Character *chara);
void Kafuka_ysbf(Character *chara1, Character *chara2, Character *chara3, Character *chara);

void Tewalin_yszj(Character *chara1, Character *chara2, Character *chara3, Character *chara);
void Tewalin_ysbf(Character *chara1, Character *chara2, Character *chara3, Character *chara);

void Hai_yszj(Character *chara1, Character *chara2, Character *chara3, Character *chara);
void Hai_SpecialAddition(Character *chara);

void Leichui_yszj(Character *chara1, Character *chara2, Character *chara3, Character *chara);
void Leichui_ysbf(Character *chara1, Character *chara2, Character *chara3, Character *chara);
void Leichui_SpecialAddition(Character *chara);

void Mudun_yszj(Character *chara1, Character *chara2, Character *chara3, Character *chara);

void SpecialAdditionReduceTurn(Character *chara4, Character *chara5, Character *chara6);  //回合减少的特殊状态
void SpecialAdditionReduceCountPu(Character *chara); //普攻减少的特殊状态
void SpecialAdditionReduceCountAll(Character *chara);  //只要攻击就减少的特殊状态

#endif //QSZH_CHARACTER_SKILL_H
