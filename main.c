#include <stdio.h>

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
        .ysbf = Lingren_ysbf,
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

SDL_Window *window;
SDL_Renderer *renderer;

Summon *summon_all[6] = {NULL};

int summon_index_we = 0;
int summon_index_enemy = 3;

bool if_all_attack = false;

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

    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
    SDL_RenderClear(renderer);

    atexit(&quit_delete);
    atexit(&CharacterImageDestroy);
    atexit(&SummonImageDestroy);

    while (1)
    {
        MainPage();

        //角色初始化

        //chara1~3:敌方角色；chara4~6:我方角色

        Character chara1 = Huoxing;
        Character chara2 = Zihuang;
        Character chara3 = Alhaitham;
        Character chara4;
        Character chara5;
        Character chara6;

        memset(&chara4, 0, sizeof(chara4));
        memset(&chara5, 0, sizeof(chara5));
        memset(&chara6, 0, sizeof(chara6));

        //summon0~3:我方召唤物

        Summon summon0;
        Summon summon1;
        Summon summon2;
        Summon summon3;
        Summon summon4;
        Summon summon5;

        memset(&summon0, 0, sizeof(summon0));
        memset(&summon1, 0, sizeof(summon1));
        memset(&summon2, 0, sizeof(summon2));
        memset(&summon3, 0, sizeof(summon3));
        memset(&summon4, 0, sizeof(summon4));
        memset(&summon5, 0, sizeof(summon5));

        summon_all[0] = &summon0;
        summon_all[1] = &summon1;
        summon_all[2] = &summon2;
        summon_all[3] = &summon3;
        summon_all[4] = &summon4;
        summon_all[5] = &summon5;

        //选择角色
        if (!(ChooseCharacter(&chara4, &chara5, &chara6)))
        {
            continue;
        }

        Character *chara_now = NULL;
        Character *chara_enemy_now = &chara2;
        chara2.if_chu = 1;

        int count = 1;   //当前回合数

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
            Touzi(tou, count, chara_now);

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

