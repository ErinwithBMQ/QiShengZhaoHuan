//
// Created by Erin on 2024/1/18.
//

// 处理战斗过程的函数

#ifndef QSZH_BATTLE_H
#define QSZH_BATTLE_H

#include <character.h>

void ChangeCharacterShanghai(Character *chara, Character *enemy); //计算角色伤害并更新
void CleanShanghai(Character *chara);
void Touzi(int tou[], int count, Character *chara);

void ShowTouzi(int tou[]);
void ShowButtom();
void ShowShanghai(Character *chara);
void ShowTheWhole(Character *chara1, Character *chara2, Character *chara3,
                  Character *chara4, Character *chara5, Character *chara6);
void ShowEndHH();

int ChooseWhichSkill(Character *chara);
int if_end(Character *chara1, Character *chara2, Character *chara3,
           Character *chara4, Character *chara5, Character *chara6);
void kill_blood(Character *chara, Character *enemy, int n);
int IfChooseSkill();

#endif //QSZH_BATTLE_H
