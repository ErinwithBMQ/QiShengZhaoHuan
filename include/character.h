//
// Created by Erin on 2024/1/13.
//

//处理角色相关的函数

#ifndef SDL_SAMPLE_CHARACTER_H
#define SDL_SAMPLE_CHARACTER_H

#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

//元素对应：0火系，1雷系，2水系，3风系，4草系, 5随机元素，-1物理

typedef struct chara {
    int index;         //角色编号
    int index_game;    //游戏内编号。1~3为敌方角色， 4~6为我方角色
    int xue;           //角色血量
    int hudun;         //角色目前护盾数
    char *name[4];     //依次存放名字，普通攻击，元素战技，元素爆发的名字
    int baofa_num;     //元素爆发所需要的充能
    int baofa_now;     //当前充能
    int shanghai[3];   //依次存放普通攻击，元素战技，元素爆发的基本伤害
    int shanghai_more[3]; //依次存放三种攻击因为元素反应或技能效果的加成伤害
    int yuansu;       //该角色元素类型
    bool yuansu_fu[5]; //当前角色身上的元素附着状态
    bool zhuang[2];    //当前状态。0是死亡位
    bool if_xuan;      //是否为选中状态
    bool if_chu;       //是否为当前出战角色
    int special_state; //特殊状态剩余次数
    int huiorcount; // 回合减少还是次数减少，0为无特殊状态，1为回合减少，2为普攻次数减少，3为攻击次数减少
    bool if_pugongfumo; //普通攻击是否处于附魔状态
    bool if_bao;     //是否饱腹

    SDL_Texture *image;          //角色正常图片
    SDL_Texture *image_dead;     //角色死亡图片
    SDL_Texture *image_choose;   //角色被选中图片
    SDL_Texture *image_message;  //角色信息图片
    SDL_Texture *image_message_big;  //角色信息图片（大）
    SDL_Texture *image_special;  //角色特殊状态图片

    //技能对应的函数指针
    void (*yszj)(struct chara *chara1, struct chara *chara2, struct chara *chara3, struct chara *chara);
    void (*ysbf)(struct chara *chara1, struct chara *chara2, struct chara *chara3, struct chara *chara);
    void (*SpecialAddition)(struct chara *chara);
} Character;

extern Character Alhaitham;
extern Character Lingren;
extern Character Huoxing;
extern Character Zihuang;
extern Character Antant;
extern Character CXK;
extern Character Chen;
extern Character Shierteer;
extern Character Ren;
extern Character Kafuka;
extern Character Kelai;

extern Character Qiuqiuren;
extern Character MudunQiuqiu;
extern Character HuofuQiuqiu;
extern Character LeifuQiuqiu;
extern Character LeiQiuqiuShe;
extern Character HailuanguiHuo;
extern Character HailuanguiLei;
extern Character Tewalin;
extern Character Shuichong;
extern Character Huochong;
extern Character Leichui;

extern SDL_Renderer *renderer;
extern SDL_Window *window;
extern Mix_Music *music;

extern int jihua;
extern int caoyuanhe;

void quit_delete();

void CharacterImageLoad();  //初始化加载角色图片

void CharacterImageDestroy();  //销毁图片

void PresentCharacterGame(Character *chara, int num);  //在游戏中展示角色信息

bool IfCharacterAlive(Character *chara); //判断角色是否死亡

void CharacterDeadOrAlive(Character *chara1, Character *chara2, Character *chara3,
                          Character *chara4, Character *chara5, Character *chara6);

bool IfChongMan(Character *chara);  //判断角色充能是否充满

bool IfCharacterChoose(Character *chara);  //是否选中该角色

void ShowCharacterMessage(Character *chara);  //展示角色具体信息

bool IfFirstChooseCharacter(Character *chara); //选角色页面选择角色


#endif //SDL_SAMPLE_CHARACTER_H
