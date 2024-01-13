//
// Created by Erin on 2024/1/13.
//
#include "character.h"

Character Antant = {
        .index = 0,
        .xue = 10,
        .hudun = 0,
        .name = {
                "蚂蚁老师",
                "开始上课",
                "OJ作业",
                "机试来喽",
        },
        .baofa_num = 3,
        .baofa_now = 0,
        .shanghai = {1,3,7},
        .yuansu = 'h',
        .yuansu_fu = {0,0,0,0,0},
        .zhuang = {0,0},
};

Character Alhaitham = {
        .index = 1,
        .xue = 10,
        .hudun = 0,
        .name = {
                "艾尔海森",
                "溯因反绎法",
                "显像",
                "束缚",
        },
        .baofa_num = 2,
        .baofa_now = 0,
        .shanghai = {2,3,5},
        .yuansu = 'c',
        .yuansu_fu = {0,0,0,0,0},
        .zhuang = {0,0},
};

Character Qiuqiuren = {
        .index = 10,
        .xue = 8,
        .hudun = 0,
        .name = {
                "丘丘人",
                "普通的一击",
                "用力的一击",
                "全力一击！",
        },
        .baofa_num = 2,
        .baofa_now = 0,
        .shanghai = {1,2,4},
        .yuansu = '0',
        .yuansu_fu = {0,0,0,0,0},
        .zhuang = {0,0},
};

void present_character_game(Character *chara, int num)
{

};

bool if_character_alive(Character *chara)
{
    if (chara->zhuang[0])
    {
        return false;
    }
    return true;
};

void change_character_shanghai(Character *chara, Character *enemy)
{

};

bool if_chongman(Character *chara)
{
    if (chara->baofa_now == chara->baofa_num)
    {
        return false;
    }
    return false;
};