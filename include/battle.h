//
// Created by Erin on 2024/1/18.
//

// 处理战斗过程的函数

#ifndef QSZH_BATTLE_H
#define QSZH_BATTLE_H

#include <character.h>

extern int shanghai[5];
extern bool if_showkillblood;

void ChangeCharacterShanghai(Character *chara, Character *enemy); //计算角色伤害并更新
void ChangeCharacterShanghaiPu(Character *chara, Character *enemy);
void CleanShanghai(Character *chara);  //清除加成伤害

void SuijiChouka(int num);

void Touzi(int tou[], int count, Character *chara, int who_first);  //每回合开始显示第几回合，模拟掷骰子

void ShowTou(int tou[]);

void ShowTouzi(int tou[]);  //展示骰子数目
void ShowButtom();          //展示选择技能按钮
void ShowShanghai(Character *chara, int n);  //展示角色本次能造成多少伤害
void ShowTheWhole(Character *chara1, Character *chara2, Character *chara3,
                  Character *chara4, Character *chara5, Character *chara6);  //展示台面、六个角色信息
void ShowEndHH(int who_fight);  //展示结束回合按钮
void ShowIfEndTurn(bool if_final_a, bool if_final_b); //展示是否结束回合
void ShowTurn(int count);

void ShowEnemyMessage(Character *enemy);

int ChooseWhichSkill(Character **chara, int tou[], Character *chara1, Character *chara2, Character *chara3,
                     Character *chara4, Character *chara5, Character *chara6, bool if_finnal_a);  //观测鼠标，选择哪一个按钮

int if_end(Character *chara1, Character *chara2, Character *chara3,
           Character *chara4, Character *chara5, Character *chara6);  //判断对局是否结束

void kill_blood(Character *chara, Character *enemy, int n);  //扣除对方血量

int IfChooseSkill(int n);  //再次确定是否选择该技能
bool IfEndTurn(bool if_final_a); //再次确定是否结束回合
bool IfChangeCharacter(Character *charanow, Character *chara, int num, int tou[]); //是否切换角色
bool IfChangeCharacterDead(Character *charanow, Character *chara, int num);

bool IfTouEnough(Character *chara, int tou[], int n);  //判断骰子数是否足够
bool IfTouNotZero(int tou[]); //判断骰子数是否为0

void ReduceTou(Character *chara, int tou[], int n);    //减少骰子数量
void ReduceTouChange(Character *chara4, Character *chara5, Character *chara6, int tou[]);

void YuanSuFuZhuo(Character *chara, Character *enemy); //对敌人造成元素附着

void PrintTouNotEnough();  //提示骰子不够
void PrintChongnengNotEnough();  //提示充能不够

void ChangeCharacterEnemy(Character **chara_enemy_now, Character *chara1, Character *chara2, Character *chara3);
bool ChangeEnemyAuto(Character **chara_enemy_now, Character *chara1, Character *chara2, Character *chara3);

void ShowEnemyAction();  //展示敌方正在行动
void ShowWeAction();     //展示我方正在行动

bool ChangeCharacterWhenDead(Character **chara, Character *chara4, Character *chara5, Character *chara6);
//我方角色死亡时强制切换角色

void ShowKillBlood(Character *chara1, Character *chara2, Character *chara3,
                   Character *chara4, Character *chara5, Character *chara6);
void ShowKillBloodOwn(Character *chara, int bloodkill, int yuansu, bool if_main);


#endif //QSZH_BATTLE_H
