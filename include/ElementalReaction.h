//
// Created by Erin on 2024/1/30.
//

// 处理深度元素反应的函数

#ifndef QSZH_ELEMENTALREACTION_H
#define QSZH_ELEMENTALREACTION_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include <character.h>
#include <summon.h>
#include <character_skill.h>
#include <battle.h>

extern int shanghaimore[7];

//选择发生哪个反应
void ChooseWhichReaction(int yuansu_we, Character **enemy, Character *chara1, Character *chara2, Character *chara3);

void KuoSan(Character *chara1, Character *chara2, Character *chara3, int yuansu);
void JiHua();
void ZhanFang();
void ChaoZai(Character **enemy, Character *chara1, Character *chara2, Character *chara3);
void GanDian(Character *chara1, Character *chara2, Character *chara3);
void RanShao();

void KuosanJiashang(int yuansu, Character *enemy);

//激化领域和草原核增伤与处理函数
void JihuaAddition(Character *chara);
void CaoyuanheAddition(Character *chara);
void JihuaReduce(Character *chara);
void CaoyuanheReduce(Character *chara);

void JihuaAddtionSummon(Summon *summon);
void CaoyuanheAddtionSummon(Summon *summon);

#endif //QSZH_ELEMENTALREACTION_H
