#include <stdio.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include <character.h>
#include <action.h>
#include <page.h>
#include <battle.h>

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
};

void quit_delete();

SDL_Window *window;
SDL_Renderer *renderer;

int main(int argc, char *argv[])
{
    window = SDL_CreateWindow("Hello world", 100, 100, WIDTH, HIGH, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    CharacterImageLoad();

    SDL_Init(SDL_INIT_VIDEO); //初始化
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);
    TTF_Init();

    SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
    SDL_RenderClear(renderer);

    atexit(&quit_delete);
    atexit(&CharacterImageDestroy);

    while (1)
    {
        MainPage();

        Character chara1 = Huoxing;
        Character chara2 = Zihuang;
        Character chara3 = Alhaitham;
        Character chara4;
        Character chara5;
        Character chara6;

        memset(&chara4, 0, sizeof(chara4));
        memset(&chara5, 0, sizeof(chara5));
        memset(&chara6, 0, sizeof(chara6));


        if (!(ChooseCharacter(&chara4, &chara5, &chara6)))
        {
            continue;
        }

        Character *chara_now = NULL;
        Character *chara_enemy_now = &chara2;
        chara2.if_chu = 1;

        int count = 1;

        BeginBattle(&chara1, &chara2, &chara3,
                    &chara4, &chara5, &chara6, &chara_now);

        int tou[6] = {0};
        int who_first = 1;

        while (1)
        {
            for (int i = 0; i < 6; ++i)
            {
                tou[i] = 0;
            }

            Touzi(tou, count, chara_now);
            int winorlose = InBattle(&count, &who_first, tou,
                                     &chara1, &chara2, &chara3,
                                     &chara4, &chara5, &chara6,
                                     &chara_now, &chara_enemy_now);
            if (winorlose == -1)
            {
                AfterBattle(&count,
                            &chara1, &chara2, &chara3,
                            &chara4, &chara5, &chara6);
            }
            else if(winorlose == 1)
            {
                WinBattle();
                break;
            }
            else if(winorlose == 0)
            {
                LoseBattle();
                break;
            }
        }
    }

    return 0;
}

void quit_delete()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();
    TTF_Quit();
}