//
// Created by Erin on 2024/1/25.
//

#include <summon.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

void SummonImageLoad()
{
    Zhujiao.image = IMG_LoadTexture(renderer, "./res/image/zhujiao.png");
    Qingjing.image = IMG_LoadTexture(renderer, "./res/image/qingjing.png");
    Lanqiu.image = IMG_LoadTexture(renderer, "./res/image/lanqiu.png");
    Fire.image = IMG_LoadTexture(renderer, "./res/image/ranshao.png");
    Zhuwang.image = IMG_LoadTexture(renderer, "./res/image/zhuwang.png");
    Kelianba.image = IMG_LoadTexture(renderer, "./res/image/kelianba.png");
}

void SummonImageDestroy()
{
    SDL_DestroyTexture(Zhujiao.image);
    SDL_DestroyTexture(Qingjing.image);
    SDL_DestroyTexture(Lanqiu.image);
    SDL_DestroyTexture(Fire.image);
    SDL_DestroyTexture(Zhuwang.image);
    SDL_DestroyTexture(Kelianba.image);
}

void PresentSummonGame(Summon *summon)
{
    int index = summon->index_game;
    if (index < 2)
    {
        SDL_Rect rect_summon = {.x = 965 + index * 115, .y = 475};
        SDL_QueryTexture(summon->image, NULL, NULL, &rect_summon.w, &rect_summon.h);
        SDL_RenderCopy(renderer, summon->image, NULL, &rect_summon);

        char num[2];
        itoa(summon->turn_now, num, 10);
        rect_summon.x += 85;
        rect_summon.y += 5;
        TTF_Font *font_summon = TTF_OpenFont("./res/HYWH85W.ttf", 20);
        SDL_Color color_summon = {0x00, 0x00, 0x00, 0x00};
        SDL_Surface *surface_turn = TTF_RenderText_Blended(font_summon, num, color_summon);
        SDL_Texture *texture_turn = SDL_CreateTextureFromSurface(renderer, surface_turn);

        SDL_QueryTexture(texture_turn, NULL, NULL, &rect_summon.w, &rect_summon.h);
        SDL_RenderCopy(renderer, texture_turn, NULL, &rect_summon);

        SDL_RenderPresent(renderer);

        TTF_CloseFont(font_summon);
        SDL_FreeSurface(surface_turn);
        SDL_DestroyTexture(texture_turn);
    }
    else
    {
        index -= 2;
        SDL_Rect rect_summon = {.x = 965 + index * 115, .y = 600};
        SDL_QueryTexture(summon->image, NULL, NULL, &rect_summon.w, &rect_summon.h);
        SDL_RenderCopy(renderer, summon->image, NULL, &rect_summon);

        char num[2];
        itoa(summon->turn_now, num, 10);
        rect_summon.x += 85;
        rect_summon.y += 5;
        TTF_Font *font_summon = TTF_OpenFont("./res/HYWH85W.ttf", 20);
        SDL_Color color_summon = {0x00, 0x00, 0x00, 0x00};
        SDL_Surface *surface_turn = TTF_RenderText_Blended(font_summon, num, color_summon);
        SDL_Texture *texture_turn = SDL_CreateTextureFromSurface(renderer, surface_turn);

        SDL_QueryTexture(texture_turn, NULL, NULL, &rect_summon.w, &rect_summon.h);
        SDL_RenderCopy(renderer, texture_turn, NULL, &rect_summon);

        SDL_RenderPresent(renderer);

        TTF_CloseFont(font_summon);
        SDL_FreeSurface(surface_turn);
        SDL_DestroyTexture(texture_turn);
    }
}

void ChangeSummonShanghai(Summon *summon, Character *enemy)
{
    int yuansu = summon->yuansu;

    if (yuansu == 5)
    {
        srand((unsigned int)time(NULL));
        yuansu = rand() % 5;

        if (yuansu == 3)
        {
            return;
        }
        summon->yuansu = yuansu;
    }

    summon->shanghai_more = 0;

    if (yuansu == -1)
    {
        return;
    }

    if (enemy->yuansu_fu[0]) //如果对方是火元素附着
    {
        if (yuansu == 2) //水系角色
        {
            summon->shanghai_more += 2;
            enemy->yuansu_fu[0] = false;
        }
        else if (yuansu == 1)  //雷系角色
        {
            summon->shanghai_more += 2;
            enemy->yuansu_fu[0] = false;
        }
        else if (yuansu == 4) //草系角色
        {
            summon->shanghai_more += 1;
            enemy->yuansu_fu[0] = false;
        }
        return;
    }
    else if (enemy->yuansu_fu[1]) //雷元素附着
    {
        if (yuansu == 2) //水系角色
        {
            summon->shanghai_more += 1;
            enemy->yuansu_fu[1] = false;
        }
        else if (yuansu == 0)  //火系角色
        {
            summon->shanghai_more += 2;
            enemy->yuansu_fu[1] = false;
        }
        else if (yuansu == 4) //草系角色
        {
            summon->shanghai_more += 1;
            enemy->yuansu_fu[1] = false;
        }
        return;
    }
    else if (enemy->yuansu_fu[2]) //水元素附着
    {
        if (yuansu == 1) //雷系角色
        {
            summon->shanghai_more += 1;
            enemy->yuansu_fu[2] = false;
        }
        else if (yuansu == 0)  //火系角色
        {
            summon->shanghai_more += 2;
            enemy->yuansu_fu[2] = false;
        }
        else if (yuansu == 4) //草系角色
        {
            summon->shanghai_more += 1;
            enemy->yuansu_fu[2] = false;
        }
        return;
    }
    else if (enemy->yuansu_fu[4]) //草元素附着
    {
        if (yuansu == 2) //水系角色
        {
            summon->shanghai_more += 1;
            enemy->yuansu_fu[4] = false;
        }
        else if (yuansu == 0)  //火系角色
        {
            summon->shanghai_more += 1;
            enemy->yuansu_fu[4] = false;
        }
        else if (yuansu == 1) //雷系角色
        {
            summon->shanghai_more += 1;
            enemy->yuansu_fu[4] = false;
        }
        return;
    }

    enemy->yuansu_fu[yuansu] = true;
}

void SummonKillBlood(Summon *summon, Character *enemy)
{
    summon->turn_now--;
    int shanghai;
    shanghai = summon->shanghai + summon->shanghai_more;
    if (enemy->hudun >= shanghai)
    {
        enemy->hudun -= shanghai;
        return;
    }
    if (enemy->hudun < shanghai)
    {
        shanghai -= enemy->hudun;
        enemy->hudun = 0;
        enemy->xue -= shanghai;
        if (enemy->xue < 0)
        {
            enemy->xue = 0;
        }
        return;
    }
}

bool SummonDestroy(Summon *summon)
{
    if (summon->turn_now == 0)
    {
        int index = summon->index_game;
        if (summon->turn_now == 0)
        {
            memset(summon, 0, sizeof(*summon));
        }

        for (int i = index + 1; i <= 3; ++i)
        {
            summon_all[i]->index_game--;
            summon_all[i - 1] = summon_all[i];
        }
        summon_index_we--;
        return 1;

    }

    return 0;

}