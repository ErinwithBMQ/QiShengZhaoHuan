//
// Created by Erin on 2024/1/13.
//

//处理角色相关的函数

#ifndef SDL_SAMPLE_CHARACTER_H
#define SDL_SAMPLE_CHARACTER_H

#include <stdbool.h>

typedef struct chara {
    int index;         //角色编号
    int xue;           //角色血量
    int hudun;         //角色目前护盾数
    char *name[4];     //依次存放名字，普通攻击，元素战技，元素爆发的名字
    int baofa_num;     //元素爆发所需要的充能
    int baofa_now;     //当前充能
    int shanghai[3];   //依次存放普通攻击，元素战技，元素爆发的基本伤害
    char yuansu;       //该角色元素类型
    bool yuansu_fu[5]; //当前角色身上的元素附着状态
    bool zhuang[2];    //该角色其他状态.第一位是死亡，第二位是冰冻
    bool if_xuan;      //是否为当前选中角色
    bool if_chu;
    SDL_Texture *image;
    SDL_Texture *image_dead;
    SDL_Texture *image_choose;
    SDL_Texture *image_message;
} Character;

extern Character Alhaitham;
extern Character Lingren;


void CharacterImageLoad(SDL_Renderer *renderer);
void CharacterImageDestroy();

void PresentCharacterGame(Character *chara, int num, SDL_Renderer *renderer);  //在游戏中展示角色信息
bool IfCharacterAlive(Character *chara); //判断角色是否死亡
void ChangeCharacterShanghai(Character *chara, Character *enemy); //计算角色伤害
bool IfChongMan(Character *chara);

bool IfCharacterChoose(SDL_Renderer *renderer, SDL_Window *window, Character *chara);

void ShowCharacterMessage(SDL_Renderer *renderer, Character *chara);


#endif //SDL_SAMPLE_CHARACTER_H
