//
// Created by Erin on 2024/1/13.
//

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
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
        .if_xuan = false,
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
        .if_xuan = false,
};

Character CXK = {
        .index = 11,
        .xue = 10,
        .hudun = 0,
        .name = {
                "坤坤",
                "你干嘛~",
                "唱跳rap篮球",
                "鸡你太美！",
        },
        .baofa_num = 3,
        .baofa_now = 0,
        .shanghai = {1,2,4},
        .yuansu = 'k',
        .yuansu_fu = {0,0,0,0,0},
        .zhuang = {0,0},
        .if_xuan = false,
};

Character Mars = {
        .index = 12,
        .xue = 10,
        .hudun = 0,
        .name = {
                "火星人",
                "日常破防",
                "代号一：主播",
                "代号二：火星人",
        },
        .baofa_num = 2,
        .baofa_now = 0,
        .shanghai = {2,4,6},
        .yuansu = 'h',
        .yuansu_fu = {0,0,0,0,0},
        .zhuang = {0,0},
        .if_xuan = false,
};

void PresentCharacterGame(Character *chara, int num, SDL_Renderer *renderer)
{
    if (!IfCharacterAlive(chara))
    {
        SDL_Surface *surface_character;

        if (chara -> index == 1)
        {
            surface_character = IMG_Load("./res/image/1_dead.png");
        }
        else if (chara -> index == 2)
        {
            surface_character = IMG_Load("./res/image/2_dead.png");
        }

        SDL_Texture *texture_character = SDL_CreateTextureFromSurface(renderer, surface_character);
        SDL_Rect rect = {.x = 400 + (num - 1) * 170, .y = 100};

        if (num > 3)
        {
            rect.y = 450;
            rect.x = 400 + (num - 4) * 170;
        }

        SDL_QueryTexture(texture_character, NULL, NULL, &rect.w, &rect.h);
        SDL_RenderCopy(renderer, texture_character, NULL, &rect);

        SDL_FreeSurface(surface_character);
        SDL_DestroyTexture(texture_character);
        return;
    }
    else
    {
        //人物图像展示
        SDL_Surface *surface_character;

        if (chara -> index == 1)
        {
            surface_character = IMG_Load("./res/image/1.png");
        }
        else if (chara -> index == 2)
        {
            surface_character = IMG_Load("./res/image/2.png");
        }


        SDL_Texture *texture_character = SDL_CreateTextureFromSurface(renderer, surface_character);

        SDL_Rect rect = {.x = 400 + (num - 1) * 170, .y = 100};
        SDL_Rect rect_xueliang = {.x = rect.x, .y = rect.y};
        if (num > 3)
        {
            rect.y = 450;
            rect.x = 400 + (num - 4) * 170;
            rect_xueliang.x = rect.x;
            rect_xueliang.y = rect.y;
        }

        if (chara->if_xuan && num <= 3)
        {
            rect.y += 20;
        }

        if (chara->if_xuan  && num > 3)
        {
            rect.y -= 20;
        }

        rect_xueliang.x += 4;
        rect_xueliang.y += 3;

        SDL_QueryTexture(texture_character, NULL, NULL, &rect.w, &rect.h);
        SDL_RenderCopy(renderer, texture_character, NULL, &rect);

        //血量展示
        int xueliang = chara->xue;
        char xueliang_print[3];
        if (xueliang == 10)
        {
            xueliang_print[0] = '1';
            xueliang_print[1] = '0';
            xueliang_print[2] = '\0';
        }
        else
        {
            xueliang_print[0] = xueliang + '0';
            xueliang_print[1] = '\0';
            rect_xueliang.x += 8;
        }

        TTF_Font *font_xue = TTF_OpenFont("./res/HYWH85W.ttf", 28);
        SDL_Color color_xue = {0x00, 0x00, 0x00, 0x00};
        SDL_Surface *surface_xue = TTF_RenderText_Blended(font_xue, xueliang_print, color_xue);
        SDL_Texture *texture_xue = SDL_CreateTextureFromSurface(renderer, surface_xue);

        SDL_QueryTexture(texture_xue, NULL, NULL, &rect_xueliang.w, &rect_xueliang.h);
        SDL_RenderCopy(renderer, texture_xue, NULL, &rect_xueliang);

        //附着元素展示
        int yuansu_count = 0;
        char yuansu[5];
        SDL_Surface *surface_yuansu = NULL;
        if (chara->yuansu_fu[0]) //火元素附着
        {
            surface_yuansu = IMG_Load("./res/image/fire_0.jpg");
        }
        else if (chara->yuansu_fu[1])
        {
            surface_yuansu = IMG_Load("./res/image/lei_1.png");
        }
        else if (chara->yuansu_fu[2])
        {
            surface_yuansu = IMG_Load("./res/image/shui_2.png");
        }
        else if (chara->yuansu_fu[3])
        {
            surface_yuansu = IMG_Load("./res/image/bing_3.png");
        }
        else if (chara->yuansu_fu[4])
        {
            surface_yuansu = IMG_Load("./res/image/cao_4.png");
        }

        if (surface_yuansu)
        {
            SDL_Texture *texture_yuansu = SDL_CreateTextureFromSurface(renderer, surface_yuansu);
            SDL_Rect rect_yuansu = {.x = rect.x + 48, .y = rect.y - 30};
            SDL_QueryTexture(texture_yuansu, NULL, NULL, &rect_yuansu.w, &rect_yuansu.h);
            SDL_RenderCopy(renderer, texture_yuansu, NULL, &rect_yuansu);

            SDL_DestroyTexture(texture_yuansu);
        }

        //护盾数展示
        SDL_Rect rect_hudun = {.x = rect.x + 97, .y = rect.y + 173};
        int hudun = chara->hudun;
        char hudun_print[] = {hudun + '0', '\0'};
        TTF_Font *font_hudun = TTF_OpenFont("./res/HYWH85W.ttf", 24);
        SDL_Color color_hudun = {0xff, 0xff, 0xff, 0xff};
        SDL_Surface *surface_hudun = TTF_RenderText_Blended(font_hudun, hudun_print, color_hudun);
        SDL_Texture *texture_hudun = SDL_CreateTextureFromSurface(renderer, surface_hudun);

        SDL_QueryTexture(texture_hudun, NULL, NULL, &rect_hudun.w, &rect_hudun.h);
        SDL_RenderCopy(renderer, texture_hudun, NULL, &rect_hudun);

        //有开就有关
        SDL_FreeSurface(surface_character);
        SDL_DestroyTexture(texture_character);
        SDL_FreeSurface(surface_yuansu);
        SDL_DestroyTexture(texture_xue);
        SDL_FreeSurface(surface_xue);
        SDL_DestroyTexture(texture_hudun);
        SDL_FreeSurface(surface_hudun);

        TTF_CloseFont(font_xue);
        TTF_CloseFont(font_hudun);
        return;

    }
}

bool IfCharacterAlive(Character *chara)
{
    if (!chara->xue)
    {
        chara->zhuang[0] = 1;
        return false;
    }
    return true;
}

void ChangeCharacterShanghai(Character *chara, Character *enemy) //底层基础伤害的元素反应加成
{
    if (enemy->yuansu_fu[0]) //如果对方是火元素附着
    {
        if (chara->yuansu == 's') //水系角色
        {
            chara->shanghai[1] += 2;
            chara->shanghai[2] += 2;
        }
        else if (chara->yuansu == 'l')  //雷系角色
        {
            chara->shanghai[1] += 2;
            chara->shanghai[2] += 2;
        }
        else if (chara->yuansu == 'c') //草系角色
        {
            chara->shanghai[1] += 1;
            chara->shanghai[2] += 1;
        }
    }
    else if (enemy->yuansu_fu[1]) //雷元素附着
    {
        if (chara->yuansu == 's') //水系角色
        {
            chara->shanghai[1] += 1;
            chara->shanghai[2] += 1;
        }
        else if (chara->yuansu == 'h')  //火系角色
        {
            chara->shanghai[1] += 2;
            chara->shanghai[2] += 2;
        }
        else if (chara->yuansu == 'c') //草系角色
        {
            chara->shanghai[1] += 1;
            chara->shanghai[2] += 1;
        }
    }
    else if (enemy->yuansu_fu[2]) //水元素附着
    {
        if (chara->yuansu == 'l') //雷系角色
        {
            chara->shanghai[1] += 1;
            chara->shanghai[2] += 1;
        }
        else if (chara->yuansu == 'h')  //火系角色
        {
            chara->shanghai[1] += 2;
            chara->shanghai[2] += 2;
        }
        else if (chara->yuansu == 'c') //草系角色
        {
            chara->shanghai[1] += 1;
            chara->shanghai[2] += 1;
        }
    }
    else if (enemy->yuansu_fu[4]) //草元素附着
    {
        if (chara->yuansu == 's') //水系角色
        {
            chara->shanghai[1] += 1;
            chara->shanghai[2] += 1;
        }
        else if (chara->yuansu == 'h')  //火系角色
        {
            chara->shanghai[1] += 1;
            chara->shanghai[2] += 1;
        }
        else if (chara->yuansu == 'c') //雷系角色
        {
            chara->shanghai[1] += 1;
            chara->shanghai[2] += 1;
        }
    }
}

bool IfChongMan(Character *chara)
{
    if (chara->baofa_now == chara->baofa_num)
    {
        return false;
    }
    return false;
}