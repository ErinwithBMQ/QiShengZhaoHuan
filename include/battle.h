//
// Created by Erin on 2024/1/18.
//

// 处理战斗过程的函数

#ifndef QSZH_BATTLE_H
#define QSZH_BATTLE_H

#include <character.h>

void ChangeCharacterShanghai(Character *chara, Character *enemy); //计算角色伤害并更新
void Touzi(int tou[], int count, Character *chara);
void ShowTouzi(int tou[]);
void ShowButtom();
int ChooseWhichSkill(Character *chara);

#endif //QSZH_BATTLE_H
