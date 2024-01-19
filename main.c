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
        .shanghai = {2,3,5},
        .shanghai_more = {0, 0, 0},
        .yuansu = 4,
        .yuansu_fu = {0,1,0,0,0},
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
                "溯因反绎法",
                "显像",
                "束缚",
        },
        .baofa_num = 2,
        .baofa_now = 0,
        .shanghai = {2,3,5},
        .shanghai_more = {0, 0, 0},
        .yuansu = 2,
        .yuansu_fu = {0,1,0,0,0},
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

        Character chara1 = Lingren;
        Character chara2 = Lingren;
        Character chara3 = Lingren;
        Character chara4 = Alhaitham;
        Character chara5 = Alhaitham;
        Character chara6 = Alhaitham;
        Character *chara_now = NULL;
        Character *chara_enemy_now = &chara2;
        chara2.if_chu = 1;
        chara1.xue = 0;
        chara3.xue = 0;

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