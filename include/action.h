//
// Created by Erin on 2024/1/14.
//

//处理行动牌相关的函数

#ifndef SDL_SAMPLE_ACTION_H
#define SDL_SAMPLE_ACTION_H

#include <stdbool.h>

typedef struct card {
    int index;     //卡牌编号
    char *name;    //卡牌名称
    char type;     //卡牌类型
    char num;      //需要骰子数目
    bool if_same;  //是否需要相同元素骰子
} Card;

void show_mycard(Card mycard[], int n);                    //游戏内展示卡牌
void show_card_function(Card mycard[], int n, int num);    //展示卡牌的具体信息
void use_mycard(Card mycard[], int n, int num);            //使用卡牌


#endif //SDL_SAMPLE_ACTION_H
