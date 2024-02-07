#include <stdio.h>
#include <intrin.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include <character.h>
#include <action.h>
#include <page.h>
#include <battle.h>
#include <summon.h>
#include <character_skill.h>
#include <ElementalReaction.h>
#include <time.h>

#undef main

#define HIGH 800
#define WIDTH 1300

Character Alhaitham = {
        .index = 1,
        .xue = 10,
        .hudun = 0,
        .name = {
                "艾尔海森",
                "溯因反绎法",
                "共相·理式摹写",
                "殊镜·显像缚结",
                "琢光镜",
        },
        .baofa_num = 2,
        .baofa_now = 0,
        .shanghai = {2,3,4},
        .shanghai_more = {0, 0, 0},
        .yuansu = 4,
        .yuansu_fu = {0,0,0,0,0},
        .zhuang = {0,0},
        .if_xuan = false,
        .if_chu = false,
        .yszj = Alhaitham_yszj,
        .ysbf = Alhaitham_ysbf,
        .SpecialAddition = Alhaitham_SpecialAddition,
        .special_state = 0,
        .huiorcount = 1,
        .if_pugongfumo = false,
};

Character Lingren = {
        .index = 2,
        .xue = 10,
        .hudun = 0,
        .name = {
                "神里绫人",
                "神里流·转",
                "神里流·镜花",
                "神里流·水囿",
                "泷云涧花"
        },
        .baofa_num = 2,
        .baofa_now = 0,
        .shanghai = {2,2,1},
        .shanghai_more = {0, 0, 0},
        .yuansu = 2,
        .yuansu_fu = {0,0,0,0,0},
        .zhuang = {0,0},
        .if_xuan = false,
        .if_chu = false,
        .yszj = Lingren_yszj,
        .ysbf = Lingren_ysbf,
        .SpecialAddition = Lingren_SpecialAddition,
        .special_state = 0,
        .huiorcount = 2,
};

Character Huoxing = {
        .index = 3,
        .xue = 10,
        .hudun = 0,
        .name = {
                "火星人",
                "破防",
                "我是主播",
                "火星人来也",
                "主播",
        },
        .baofa_num = 2,
        .baofa_now = 0,
        .shanghai = {2,3,3},
        .shanghai_more = {0, 0, 0},
        .yuansu = 0,
        .yuansu_fu = {0,0,0,0,0},
        .zhuang = {0,0},
        .if_xuan = false,
        .if_chu = false,
        .yszj = Huoxing_yszj,
        .ysbf = Huoxing_ysbf,
        .SpecialAddition = Huoxing_SpecialAddition,
        .special_state = 0,
        .huiorcount = 1,
};

Character Zihuang = {
        .index = 4,
        .xue = 10,
        .hudun = 0,
        .name = {
                "紫皇",
                "抽象",
                "96皇之力",
                "唯我至尊",
                "96皇",
        },
        .baofa_num = 2,
        .baofa_now = 0,
        .shanghai = {2,3,5},
        .shanghai_more = {0, 0, 0},
        .yuansu = 1,
        .yuansu_fu = {0,0,0,0,0},
        .zhuang = {0,0},
        .if_xuan = false,
        .if_chu = false,
        .yszj = Zihuang_yszj,
        .ysbf = Zihuang_ysbf,
        .SpecialAddition = Zihuang_SpecialAddition,
        .special_state = 0,
        .huiorcount = 3,
};

Character Antant = {
        .index = 5,
        .xue = 10,
        .hudun = 0,
        .name = {
                "蚂蚁蚂蚁",
                "开始上课",
                "OJ作业",
                "机试来了",
        },
        .baofa_num = 3,
        .baofa_now = 0,
        .shanghai = {2,2,3},
        .shanghai_more = {0, 0, 0},
        .yuansu = 4,
        .yuansu_fu = {0,0,0,0,0},
        .zhuang = {0,0},
        .if_xuan = false,
        .if_chu = false,
        .yszj = Antant_yszj,
        .ysbf = Antant_ysbf,
};

Character CXK = {
        .index = 6,
        .xue = 10,
        .hudun = 0,
        .name = {
                "蔡徐坤",
                "你干嘛",
                "唱跳Rap篮球",
                "鸡你太美",
        },
        .baofa_num = 2,
        .baofa_now = 0,
        .shanghai = {2,2,5},
        .shanghai_more = {0, 0, 0},
        .yuansu = 1,
        .yuansu_fu = {0,0,0,0,0},
        .zhuang = {0,0},
        .if_xuan = false,
        .if_chu = false,
        .yszj = CXK_yszj,
        .ysbf = CXK_ysbf,
        .SpecialAddition = CXK_SpecialAddition,
        .special_state = 10,
        .huiorcount = 0,
};

Character Chen = {
        .index = 7,
        .xue = 10,
        .hudun = 0,
        .name = {
                "假日威龙陈",
                "高压冲击",
                "“堇青之夜”",
                "“假日风暴”",
        },
        .baofa_num = 3,
        .baofa_now = 0,
        .shanghai = {2,2,6},
        .shanghai_more = {0, 0, 0},
        .yuansu = 2,
        .yuansu_fu = {0,0,0,0,0},
        .zhuang = {0,0},
        .if_xuan = false,
        .if_chu = false,
        .yszj = Chen_yszj,
        .ysbf = Chen_ysbf,
};

Character Shierteer = {
        .index = 8,
        .xue = 10,
        .hudun = 0,
        .name = {
                "史尔特尔",
                "烈焰魔剑",
                "熔核巨影",
                "黄昏",
                "黄昏",
        },
        .baofa_num = 2,
        .baofa_now = 0,
        .shanghai = {2,3,2},
        .shanghai_more = {0, 0, 0},
        .yuansu = 0,
        .yuansu_fu = {0,0,0,0,0},
        .zhuang = {0,0},
        .if_xuan = false,
        .if_chu = false,
        .ysbf = Shierteer_ysbf,
        .SpecialAddition = Shierteer_SpecialAddition,
        .special_state = 0,
        .huiorcount = 1,
};

Character Ren = {
        .index = 9,
        .xue = 10,
        .hudun = 0,
        .name = {
                "刃",
                "支离剑",
                "地狱变",
                "大辟万死",
                "无间剑树",
        },
        .baofa_num = 3,
        .baofa_now = 0,
        .shanghai = {2,2,6},
        .shanghai_more = {0, 0, 0},
        .yuansu = 3,
        .yuansu_fu = {0,0,0,0,0},
        .zhuang = {0,0},
        .if_xuan = false,
        .if_chu = false,
        .yszj = Ren_yszj,
        .ysbf = Ren_ysbf,
        .SpecialAddition = Ren_SpecialAddition,
        .special_state = 0,
        .huiorcount = 1,
};

Character Kafuka = {
        .index = 10,
        .xue = 10,
        .hudun = 0,
        .name = {
                "卡芙卡",
                "夜间喧嚣不止",
                "月光摩挲连绵",
                "悲剧尽头的颤音",
        },
        .baofa_num = 2,
        .baofa_now = 0,
        .shanghai = {2,2,3},
        .shanghai_more = {0, 0, 0},
        .yuansu = 1,
        .yuansu_fu = {0,0,0,0,0},
        .zhuang = {0,0},
        .if_xuan = false,
        .if_chu = false,
        .yszj = Kafuka_yszj,
        .ysbf = Kafuka_ysbf,
};

Character Kelai = {
        .index = 11,
        .xue = 10,
        .hudun = 0,
        .name = {
                "柯莱",
                "祈颂射艺",
                "拂花偈叶",
                "猫猫秘宝",
        },
        .baofa_num = 2,
        .baofa_now = 0,
        .shanghai = {2,3,2},
        .shanghai_more = {0, 0, 0},
        .yuansu = 4,
        .yuansu_fu = {0,0,0,0,0},
        .zhuang = {0,0},
        .if_xuan = false,
        .if_chu = false,
        .ysbf = Kelai_ysbf,
};

Character Qiuqiuren = {
        .index = 13,
        .xue = 6,
        .hudun = 0,
        .name = {
                "丘丘人",
                "普通的攻击",
                "用力的攻击",
                "全力攻击",
        },
        .baofa_num = 2,
        .baofa_now = 0,
        .shanghai = {1,3,4},
        .shanghai_more = {0, 0, 0},
        .yuansu = -1,
        .yuansu_fu = {0,0,0,0,0},
        .zhuang = {0,0},
        .if_xuan = false,
        .if_chu = false,
};

Character MudunQiuqiu = {
        .index = 14,
        .xue = 10,
        .hudun = 3,
        .name = {
                "木盾丘丘暴徒",
                "普通的攻击",
                "开盾攻击",
                "全力的一击",
        },
        .baofa_num = 2,
        .baofa_now = 0,
        .shanghai = {2,3,5},
        .shanghai_more = {0, 0, 0},
        .yuansu = -1,
        .yuansu_fu = {0,0,0,0,0},
        .zhuang = {0,0},
        .if_xuan = false,
        .if_chu = false,
        .yszj = Mudun_yszj,
};

Character HuofuQiuqiu = {
        .index = 15,
        .xue = 10,
        .hudun = 0,
        .name = {
                "火斧丘丘暴徒",
                "普通的攻击",
                "元素攻击",
                "全力的一击",
        },
        .baofa_num = 2,
        .baofa_now = 0,
        .shanghai = {2,3,5},
        .shanghai_more = {0, 0, 0},
        .yuansu = 0,
        .yuansu_fu = {0,0,0,0,0},
        .zhuang = {0,0},
        .if_xuan = false,
        .if_chu = false,
};

Character LeifuQiuqiu = {
        .index = 16,
        .xue = 10,
        .hudun = 0,
        .name = {
                "雷斧丘丘暴徒",
                "普通的攻击",
                "元素攻击",
                "全力的一击",
        },
        .baofa_num = 2,
        .baofa_now = 0,
        .shanghai = {2,3,5},
        .shanghai_more = {0, 0, 0},
        .yuansu = 1,
        .yuansu_fu = {0,0,0,0,0},
        .zhuang = {0,0},
        .if_xuan = false,
        .if_chu = false,
};

Character LeiQiuqiuShe = {
        .index = 17,
        .xue = 6,
        .hudun = 0,
        .name = {
                "雷丘丘射手",
                "普通的攻击",
                "元素攻击",
                "全力的一击",
        },
        .baofa_num = 2,
        .baofa_now = 0,
        .shanghai = {1,3,5},
        .shanghai_more = {0, 0, 0},
        .yuansu = 1,
        .yuansu_fu = {0,0,0,0,0},
        .zhuang = {0,0},
        .if_xuan = false,
        .if_chu = false,
};

Character HailuanguiHuo = {
        .index = 18,
        .xue = 10,
        .hudun = 0,
        .name = {
                "海乱鬼·火",
                "普通的攻击",
                "元素攻击",
                "仅此一刀！",
                "斩灭",
        },
        .baofa_num = 2,
        .baofa_now = 0,
        .shanghai = {1,2,5},
        .shanghai_more = {0, 0, 0},
        .yuansu = 0,
        .yuansu_fu = {0,0,0,0,0},
        .zhuang = {0,0},
        .if_xuan = false,
        .if_chu = false,
        .yszj = Hai_yszj,
        .SpecialAddition = Hai_SpecialAddition,
};

Character HailuanguiLei = {
        .index = 19,
        .xue = 10,
        .hudun = 0,
        .name = {
                "海乱鬼·雷",
                "普通的攻击",
                "元素攻击",
                "仅此一刀！",
                "斩灭",
        },
        .baofa_num = 2,
        .baofa_now = 0,
        .shanghai = {1,2,5},
        .shanghai_more = {0, 0, 0},
        .yuansu = 1,
        .yuansu_fu = {0,0,0,0,0},
        .zhuang = {0,0},
        .if_xuan = false,
        .if_chu = false,
        .yszj = Hai_yszj,
        .SpecialAddition = Hai_SpecialAddition,
};

Character Tewalin = {
        .index = 20,
        .xue = 20,
        .hudun = 0,
        .name = {
                "风魔龙特瓦林",
                "裂爪横击",
                "暴风轰击",
                "众天闭幕曲",
        },
        .baofa_num = 3,
        .baofa_now = 0,
        .shanghai = {2,2,6},
        .shanghai_more = {0, 0, 0},
        .yuansu = 3,
        .yuansu_fu = {0,0,0,0,0},
        .zhuang = {0,0},
        .if_xuan = false,
        .if_chu = false,
        .yszj = Tewalin_yszj,
        .ysbf = Tewalin_ysbf,
};

Character Shuichong = {
        .index = 21,
        .xue = 10,
        .hudun = 0,
        .name = {
                "愚人众·水铳重卫士",
                "铳枪攻击",
                "水铳冲击",
                "水铳守卫",
        },
        .baofa_num = 2,
        .baofa_now = 0,
        .shanghai = {2,3,4},
        .shanghai_more = {0, 0, 0},
        .yuansu = 2,
        .yuansu_fu = {0,0,0,0,0},
        .zhuang = {0,0},
        .if_xuan = false,
        .if_chu = false,
        .ysbf = Leichui_ysbf,
};

Character Huochong = {
        .index = 22,
        .xue = 10,
        .hudun = 0,
        .name = {
                "愚人众·火铳游击兵",
                "铳枪攻击",
                "火铳冲击",
                "火铳守卫",
        },
        .baofa_num = 2,
        .baofa_now = 0,
        .shanghai = {2,3,4},
        .shanghai_more = {0, 0, 0},
        .yuansu = 0,
        .yuansu_fu = {0,0,0,0,0},
        .zhuang = {0,0},
        .if_xuan = false,
        .if_chu = false,
        .ysbf = Leichui_ysbf,
};

Character Leichui = {
        .index = 23,
        .xue = 10,
        .hudun = 0,
        .name = {
                "愚人众·雷锤前锋军",
                "巨锤击打",
                "雷电之锤",
                "巨雷之声",
                "雷锤",
        },
        .baofa_num = 2,
        .baofa_now = 0,
        .shanghai = {2,3,4},
        .shanghai_more = {0, 0, 0},
        .yuansu = 1,
        .yuansu_fu = {0,0,0,0,0},
        .zhuang = {0,0},
        .if_xuan = false,
        .if_chu = false,
        .yszj = Leichui_yszj,
        .ysbf = Leichui_ysbf,
        .SpecialAddition = Leichui_SpecialAddition,
};

Summon Zhujiao = {
        .index = 1,
        .name = "助教",
        .yuansu = 5,
        .shanghai = 1,
        .shanghai_more = 0,
        .turn = 3,
        .turn_now = 3,
        .index_game = 0,
};

Summon Qingjing = {
        .index = 2,
        .name = "清净之园囿",
        .yuansu = 2,
        .shanghai = 2,
        .shanghai_more = 0,
        .turn = 2,
        .turn_now = 2,
        .index_game = 0,
};

Summon Lanqiu = {
        .index = 3,
        .name = "篮球",
        .yuansu = -1,
        .shanghai = 1,
        .shanghai_more = 0,
        .turn = 3,
        .turn_now = 3,
        .index_game = 0,
};

Summon Fire = {
        .index = 4,
        .name = "燃烧火焰",
        .yuansu = 0,
        .shanghai = 1,
        .shanghai_more = 0,
        .turn = 2,
        .turn_now = 1,
        .index_game = 0,
};

Summon Zhuwang = {
        .index = 5,
        .name = "触电蛛网",
        .yuansu = 1,
        .shanghai = 2,
        .shanghai_more = 0,
        .turn = 2,
        .turn_now = 2,
        .index_game = 0,
};

Summon Kelianba = {
        .index = 6,
        .name = "柯里安巴",
        .yuansu = 4,
        .shanghai = 2,
        .shanghai_more = 0,
        .turn = 2,
        .turn_now = 2,
        .index_game = 0,
};

Card bestfriend = {
        .index = 1,
        .name = "最好的伙伴！",
        .type = "事件牌",
        .num = 2,
        .message = "获得两个万能骰子",
        .if_same = false,
        .if_xuan = false,
        .Action = Action_1,
};

Card fengbu = {
        .index = 2,
        .name = "快快缝补术",
        .type = "事件牌",
        .num = 1,
        .message = "当前剩余次数最少的召唤物次数+1",
        .if_same = false,
        .if_xuan = false,
        .Action = Action_2,
};

Card hegui = {
        .index = 3,
        .name = "鹤归之时",
        .type = "事件牌",
        .num = 1,
        .message = "当前角色使用技能后，切换到下一个角色",
        .if_same = false,
        .if_xuan = false,
        .Action = Action_3,
};

Card huanban = {
        .index = 4,
        .name = "换班时间",
        .type = "事件牌",
        .num = 0,
        .message = "下次切换角色所需元素骰子-1",
        .if_same = false,
        .if_xuan = false,
        .Action = Action_4,
};

Card jiaogei = {
        .index = 5,
        .name = "交给我吧！",
        .type = "事件牌",
        .num = 0,
        .message = "下次切换角色为快速行动",
        .if_same = false,
        .if_xuan = false,
        .Action = Action_5,
};

Card xingtian = {
        .index = 6,
        .name = "星天之兆",
        .type = "事件牌",
        .num = 2,
        .message = "当前出战角色获得一点充能",
        .if_same = false,
        .if_xuan = false,
        .Action = Action_6,
};

Card yunchou = {
        .index = 7,
        .name = "运筹帷幄",
        .type = "事件牌",
        .num = 1,
        .message = "摸两张牌",
        .if_same = false,
        .if_xuan = false,
        .Action = Action_7,
};

Card tiantian = {
        .index = 8,
        .name = "甜甜花酿鸡",
        .type = "料理牌",
        .num = 0,
        .message = "当前角色恢复1点血量",
        .if_same = false,
        .if_xuan = false,
        .Action = Action_8,
};

Card jueyun = {
        .index = 9,
        .name = "绝云锅巴",
        .type = "料理牌",
        .num = 0,
        .message = "当前角色下次普通攻击伤害+1",
        .if_same = false,
        .if_xuan = false,
        .Action = Action_9,
};

Card lianhua = {
        .index = 10,
        .name = "莲花酥",
        .type = "料理牌",
        .num = 1,
        .message = "当前角色获得3点护盾",
        .if_same = false,
        .if_xuan = false,
        .Action = Action_10,
};

Card fotiao = {
        .index = 11,
        .name = "佛跳墙",
        .type = "料理牌",
        .num = 2,
        .message = "当前角色下次元素爆发伤害+3",
        .if_same = false,
        .if_xuan = false,
        .Action = Action_11,
};

Card tudou = {
        .index = 12,
        .name = "蒙德土豆饼",
        .type = "料理牌",
        .num = 1,
        .message = "当前角色恢复2点血量",
        .if_same = false,
        .if_xuan = false,
        .Action = Action_12,
};

SDL_Window *window;
SDL_Renderer *renderer;

Summon *summon_all[4] = {NULL};

int summon_index_we = 0;

Mix_Music *music;

int jihua;
int caoyuanhe;

int shanghai[5];  //0：对主对象造成的伤害；1：对后台造成的伤害；2：对主对象造成伤害的元素类型；3：对后台造成伤害的元素类型; 4: 主攻击对象
bool if_showkillblood;
int if_showhudun;

int shanghaimore[7];

Card *card_all[12] = {&bestfriend, &fengbu, &hegui, &huanban, &jiaogei,
                     &xingtian, &yunchou, &tiantian, &jueyun, &lianhua, &fotiao, &tudou};
Card *my_card[9];
int my_card_num;

int liaolijiashang[2];

bool if_kuaijie;
bool if_notusetou;
bool if_qiehuanjuese;

bool if_changemusic;

int if_showjiaxue[3];
Character *chara_toshow = &Alhaitham;

int main(int argc, char *argv[])
{
    //初始化

    window = SDL_CreateWindow("七圣召唤", 100, 100, WIDTH, HIGH, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    CharacterImageLoad();
    SummonImageLoad();
    CardImageLoad();

    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
    TTF_Init();
    Mix_Init(MIX_INIT_MP3);

    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
    SDL_RenderClear(renderer);

    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 2048);

    music = Mix_LoadMUS("./res/music/BGM1.mp3");

    int fadeInTime = 2000;
    Mix_FadeInMusic(music, -1, fadeInTime);

    MainPage();

    while (1)
    {
        if (if_changemusic)
        {
            int fadeOutTime = 800;
            Mix_FadeOutMusic(fadeOutTime);

            music = Mix_LoadMUS("./res/music/BGM1.mp3");

            Mix_FadeInMusic(music, -1, fadeInTime);

            if_changemusic = false;
        }

        int chooseone = MainchoosePage();

        if (chooseone == 2)
        {
            Tujian();
            continue;
        }
        else if (chooseone == 3)
        {
            Wanfa();
            continue;
        }

        for (int i = 0; i < 9; ++i)
        {
            my_card[i] = NULL;
        }
        my_card_num = 0;

        //角色初始化

        //chara1~3:敌方角色；chara4~6:我方角色
        Character chara1;
        Character chara2;
        Character chara3;
        Character chara4;
        Character chara5;
        Character chara6;

        memset(&chara1, 0, sizeof(chara1));
        memset(&chara2, 0, sizeof(chara2));
        memset(&chara3, 0, sizeof(chara3));


        bool choosewhichlevel = ChooseLevel(&chara1, &chara2, &chara3);
        if (!choosewhichlevel)
        {
            continue;
        }

        chara1.index_game = 1;
        chara2.index_game = 2;
        chara3.index_game = 3;

        memset(&chara4, 0, sizeof(chara4));
        memset(&chara5, 0, sizeof(chara5));
        memset(&chara6, 0, sizeof(chara6));

        //summon0~3:我方召唤物

        Summon summon0;
        Summon summon1;
        Summon summon2;
        Summon summon3;

        memset(&summon0, 0, sizeof(summon0));
        memset(&summon1, 0, sizeof(summon1));
        memset(&summon2, 0, sizeof(summon2));
        memset(&summon3, 0, sizeof(summon3));

        summon_all[0] = &summon0;
        summon_all[1] = &summon1;
        summon_all[2] = &summon2;
        summon_all[3] = &summon3;

        //选择角色
        if (!(ChooseCharacter(&chara4, &chara5, &chara6)))
        {
            continue;
        }

        Character *chara_now = NULL;
        Character *chara_enemy_now = &chara2;
        chara2.if_chu = 1;

        int count = 1;   //当前回合数
        jihua = 0;
        caoyuanhe = 0;
        summon_index_we = 0;

        int fadeOutTime = 800;
        Mix_FadeOutMusic(fadeOutTime);

        srand((unsigned int)time(NULL));
        int suiji = rand() % 2;
        if (suiji == 0)
        {
            music = Mix_LoadMUS("./res/music/BGM2.mp3");
        }
        else
        {
            music = Mix_LoadMUS("./res/music/BGM3.mp3");
        }

        Mix_FadeInMusic(music, -1, fadeInTime);

        Mix_PlayMusic(music, 20);

        //作战开始前选择出战角色

        BeginBattle(&chara1, &chara2, &chara3,
                    &chara4, &chara5, &chara6, &chara_now);

        int tou[6] = {0};
        int who_first = 1;  //默认一开始我方先行动

        SuijiChouka(3);

        while (1)  //每一次循环是一个回合
        {
            for (int i = 0; i < 6; ++i)  //骰子数清空
            {
                tou[i] = 0;
            }

            //随机掷骰子
            Touzi(tou, count, chara_now, who_first);

            //作战中
            int winorlose = InBattle(&count, &who_first, tou,
                                     &chara1, &chara2, &chara3,
                                     &chara4, &chara5, &chara6,
                                     &chara_now, &chara_enemy_now);

            if (winorlose == -1)  //进入下一回合
            {
                //回合后清算
                winorlose = AfterBattle(&count, &chara_now, &chara_enemy_now,
                            &chara1, &chara2, &chara3,
                            &chara4, &chara5, &chara6);
            }

            if(winorlose == 1)
            {
                //胜利
                WinBattle();
                break;
            }
            else if(winorlose == 0)
            {
                //失败
                LoseBattle();
                break;
            }
        }
    }

    return 0;
}

