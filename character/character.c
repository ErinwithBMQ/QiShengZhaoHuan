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

void present_character_game(Character *chara, int num, SDL_Renderer *renderer)
{
    if (!if_character_alive(chara))
    {
        if (chara -> index == 0)
        {
            SDL_Texture *character = IMG_LoadTexture(renderer, "./res/image/0.jpg");

            SDL_Rect rect = {.x = 301 + (num - 1) * 217, .y = 57};
            if (num > 3)
            {
                rect.y = 471;
                rect.x = 301 + (num - 4) * 217;
            }

            if (chara->if_xuan && num <= 3)
            {
                rect.y += 10;
            }

            if (chara->if_xuan && num > 3)
            {
                rect.y -= 10;
            }

            SDL_QueryTexture(character, NULL, NULL, &rect.w, &rect.h);
            SDL_RenderCopy(renderer, character, NULL, &rect);
            SDL_DestroyTexture(character);
            return;
        }
    }
    else
    {
        if (chara -> index == 1)
        {
            SDL_Texture *character = IMG_LoadTexture(renderer, "./res/image/alhaitham.jpg");

            SDL_Rect rect = {.x = 301 + (num - 1) * 217, .y = 57};
            if (num > 3)
            {
                rect.y = 471;
                rect.x = 301 + (num - 4) * 217;
            }

            if (chara->if_xuan && num <= 3)
            {
                rect.y += 10;
            }

            if (chara->if_xuan  && num > 3)
            {
                rect.y -= 10;
            }

            SDL_QueryTexture(character, NULL, NULL, &rect.w, &rect.h);
            SDL_RenderCopy(renderer, character, NULL, &rect);
            SDL_DestroyTexture(character);
            return;
        }
    }
}

bool if_character_alive(Character *chara)
{
    if (chara->zhuang[0])
    {
        return false;
    }
    return true;
}

void change_character_shanghai(Character *chara, Character *enemy)
{

}

bool if_chongman(Character *chara)
{
    if (chara->baofa_now == chara->baofa_num)
    {
        return false;
    }
    return false;
}