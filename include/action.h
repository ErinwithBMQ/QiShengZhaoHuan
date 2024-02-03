//
// Created by Erin on 2024/1/14.
//

//处理行动牌相关的函数

#ifndef SDL_SAMPLE_ACTION_H
#define SDL_SAMPLE_ACTION_H

#include <stdbool.h>
#include <character.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

typedef struct card {
    int index;     //卡牌编号
    char *name;    //卡牌名称
    char *type;    //卡牌类型
    char num;      //需要骰子数目
    char *message;
    bool if_same;  //是否需要相同元素骰子
    bool if_xuan;  //是否为选中状态
    void (*Action)(Character *chara, int yuansu1, int yuansu2, int yuansu3, int tou[]);
    SDL_Texture *image;
} Card;

extern Card bestfriend;
extern Card fengbu;
extern Card hegui;
extern Card huanban;
extern Card jiaogei;
extern Card xingtian;
extern Card yunchou;
extern Card tiantian;
extern Card jueyun;

extern Card *card_all[9];
extern Card *my_card[9];
extern int my_card_num;

extern int liaolijiashang[2];

extern bool if_kuaijie;
extern bool if_notusetou;
extern bool if_qiehuanjuese;

void CardImageLoad();
void CardImageDestroy();

void ShowMyCard();                   //游戏内展示卡牌
void ShowCardFunction(Card *card);    //展示卡牌的具体信息
bool if_choosecard(Card *card, int index, int tou[], int yuansu, int yuansu1, int yuansu2, int yuansu3);
void UseMyCard(int index);

void Action_1(Character *chara, int yuansu1, int yuansu2, int yuansu3, int tou[]);
void Action_2(Character *chara, int yuansu1, int yuansu2, int yuansu3, int tou[]);
void Action_3(Character *chara, int yuansu1, int yuansu2, int yuansu3, int tou[]);
void Action_4(Character *chara, int yuansu1, int yuansu2, int yuansu3, int tou[]);
void Action_5(Character *chara, int yuansu1, int yuansu2, int yuansu3, int tou[]);
void Action_6(Character *chara, int yuansu1, int yuansu2, int yuansu3, int tou[]);
void Action_7(Character *chara, int yuansu1, int yuansu2, int yuansu3, int tou[]);
void Action_8(Character *chara, int yuansu1, int yuansu2, int yuansu3, int tou[]);
void Action_9(Character *chara, int yuansu1, int yuansu2, int yuansu3, int tou[]);

void ActionLiaoliJiaShang(Character *chara);

#endif //SDL_SAMPLE_ACTION_H
