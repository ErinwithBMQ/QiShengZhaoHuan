//
// Created by Erin on 2024/1/25.
//

//处理角色召唤物的函数

#ifndef QSZH_SUMMON_H
#define QSZH_SUMMON_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include <character.h>

typedef struct summon {
    int index;     //召唤物编号
    char *name;    //召唤物的名字
    int yuansu;    //召唤物的元素
    int shanghai;  //召唤物的伤害
    int shanghai_more;
    int turn;      //召唤物的总持续回合
    int turn_now;  //召唤物目前的持续回合
    SDL_Texture *image; //召唤物图像
    int index_game; //召唤物游戏内编号
} Summon;

extern Summon *summon_all[4];
extern int summon_index_we;

extern Summon Zhujiao;
extern Summon Qingjing;
extern Summon Lanqiu;
extern Summon Fire;

void SummonImageLoad();
void SummonImageDestroy();

void PresentSummonGame(Summon *summon);   //展示召唤物

void ChangeSummonShanghai(Summon *summon, Character *enemy);  //计算元素反应伤害

void SummonKillBlood(Summon *summon, Character *enemy);  //扣血

bool SummonDestroy(Summon *summon); //回合满销毁

#endif //QSZH_SUMMON_H
