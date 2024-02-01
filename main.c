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
#include <record.h>
#include <summon.h>
#include <character_skill.h>
#include <ElementalReaction.h>

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
        .SpecialAddition = Alhaitham_SpecialAdditon,
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
        .SpecialAddition = Lingren_SpecialAdditon,
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
        .SpecialAddition = Huoxing_SpecialAdditon,
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
        .SpecialAddition = Zihuang_SpecialAdditon,
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
        .shanghai = {2,3,3},
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
        .baofa_num = 3,
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

Character Ren = {
        .index = 9,
        .xue = 10,
        .hudun = 0,
        .name = {
                "刃",
                "支离剑",
                "地狱变",
                "大辟万死",
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
        },
        .baofa_num = 2,
        .baofa_now = 0,
        .shanghai = {2,3,6},
        .shanghai_more = {0, 0, 0},
        .yuansu = 0,
        .yuansu_fu = {0,0,0,0,0},
        .zhuang = {0,0},
        .if_xuan = false,
        .if_chu = false,
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
        },
        .baofa_num = 2,
        .baofa_now = 0,
        .shanghai = {2,3,6},
        .shanghai_more = {0, 0, 0},
        .yuansu = 1,
        .yuansu_fu = {0,0,0,0,0},
        .zhuang = {0,0},
        .if_xuan = false,
        .if_chu = false,
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
        .turn = 3,
        .turn_now = 3,
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

SDL_Window *window;
SDL_Renderer *renderer;

Summon *summon_all[4] = {NULL};

int summon_index_we = 0;

Mix_Music *music;

int jihua;
int caoyuanhe;

int shanghai[5];  //0：对主对象造成的伤害；1：对后台造成的伤害；2：对主对象造成伤害的元素类型；3：对后台造成伤害的元素类型; 4: 主攻击对象
bool if_showkillblood;

int shanghaimore[7];

int main(int argc, char *argv[])
{
    //初始化

    window = SDL_CreateWindow("七圣召唤", 100, 100, WIDTH, HIGH, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    CharacterImageLoad();
    SummonImageLoad();

    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
    TTF_Init();
    Mix_Init(MIX_INIT_MP3);

    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
    SDL_RenderClear(renderer);

    atexit(&quit_delete);
    atexit(&CharacterImageDestroy);
    atexit(&SummonImageDestroy);

    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 2048);

    while (1)
    {
        music = Mix_LoadMUS("./res/music/BGM1.mp3");

        Mix_PlayMusic(music, 20);

        MainPage();

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


        music = Mix_LoadMUS("./res/music/BGM2.mp3");

        Mix_PlayMusic(music, 20);

        //作战开始前选择出战角色

        BeginBattle(&chara1, &chara2, &chara3,
                    &chara4, &chara5, &chara6, &chara_now);

        int tou[6] = {0};
        int who_first = 1;  //默认一开始我方先行动

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

