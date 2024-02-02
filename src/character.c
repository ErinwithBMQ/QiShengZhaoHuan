//
// Created by Erin on 2024/1/13.
//

#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "character.h"
#include <summon.h>

void CharacterImageLoad()
{
    Alhaitham.image = IMG_LoadTexture(renderer, "./res/image/1.png");
    Alhaitham.image_choose = IMG_LoadTexture(renderer, "./res/image/1_xuan.png");
    Alhaitham.image_dead = IMG_LoadTexture(renderer, "./res/image/1_dead.png");
    Alhaitham.image_message = IMG_LoadTexture(renderer, "./res/image/1_message.png");
    Alhaitham.image_message_big = IMG_LoadTexture(renderer, "./res/image/1_message_big.png");
    Alhaitham.image_special = IMG_LoadTexture(renderer, "./res/image/1_special.png");

    Lingren.image = IMG_LoadTexture(renderer, "./res/image/2.png");
    Lingren.image_choose = IMG_LoadTexture(renderer, "./res/image/2_xuan.png");
    Lingren.image_dead = IMG_LoadTexture(renderer, "./res/image/2_dead.png");
    Lingren.image_message = IMG_LoadTexture(renderer, "./res/image/2_message.png");
    Lingren.image_message_big = IMG_LoadTexture(renderer, "./res/image/2_message_big.png");
    Lingren.image_special = IMG_LoadTexture(renderer, "./res/image/2_special.png");

    Huoxing.image = IMG_LoadTexture(renderer, "./res/image/3.png");
    Huoxing.image_choose = IMG_LoadTexture(renderer, "./res/image/3_xuan.png");
    Huoxing.image_dead = IMG_LoadTexture(renderer, "./res/image/3_dead.png");
    Huoxing.image_message = IMG_LoadTexture(renderer, "./res/image/3_message.png");
    Huoxing.image_message_big = IMG_LoadTexture(renderer, "./res/image/3_message_big.png");
    Huoxing.image_special = IMG_LoadTexture(renderer, "./res/image/3_special.png");

    Zihuang.image = IMG_LoadTexture(renderer, "./res/image/4.png");
    Zihuang.image_choose = IMG_LoadTexture(renderer, "./res/image/4_xuan.png");
    Zihuang.image_dead = IMG_LoadTexture(renderer, "./res/image/4_dead.png");
    Zihuang.image_message = IMG_LoadTexture(renderer, "./res/image/4_message.png");
    Zihuang.image_message_big = IMG_LoadTexture(renderer, "./res/image/4_message_big.png");
    Zihuang.image_special = IMG_LoadTexture(renderer, "./res/image/4_special.png");

    Antant.image = IMG_LoadTexture(renderer, "./res/image/5.png");
    Antant.image_choose = IMG_LoadTexture(renderer, "./res/image/5_xuan.png");
    Antant.image_dead = IMG_LoadTexture(renderer, "./res/image/5_dead.png");
    Antant.image_message = IMG_LoadTexture(renderer, "./res/image/5_message.png");
    Antant.image_message_big = IMG_LoadTexture(renderer, "./res/image/5_message_big.png");

    CXK.image = IMG_LoadTexture(renderer, "./res/image/6.jpg");
    CXK.image_choose = IMG_LoadTexture(renderer, "./res/image/6_xuan.jpg");
    CXK.image_dead = IMG_LoadTexture(renderer, "./res/image/6_dead.jpg");
    CXK.image_message = IMG_LoadTexture(renderer, "./res/image/6_message.png");
    CXK.image_message_big = IMG_LoadTexture(renderer, "./res/image/6_message_big.png");

    Chen.image = IMG_LoadTexture(renderer, "./res/image/7.png");
    Chen.image_choose = IMG_LoadTexture(renderer, "./res/image/7_xuan.png");
    Chen.image_dead = IMG_LoadTexture(renderer, "./res/image/7_dead.png");
    Chen.image_message = IMG_LoadTexture(renderer, "./res/image/7_message.png");
    Chen.image_message_big = IMG_LoadTexture(renderer, "./res/image/7_message_big.png");

    Ren.image = IMG_LoadTexture(renderer, "./res/image/9.png");
    Ren.image_choose = IMG_LoadTexture(renderer, "./res/image/9_xuan.png");
    Ren.image_dead = IMG_LoadTexture(renderer, "./res/image/9_dead.png");
    Ren.image_message = IMG_LoadTexture(renderer, "./res/image/9_message.png");
    Ren.image_message_big = IMG_LoadTexture(renderer, "./res/image/9_message_big.png");
    Ren.image_special = IMG_LoadTexture(renderer, "./res/image/9_special.png");

    Qiuqiuren.image = IMG_LoadTexture(renderer, "./res/image/13.png");
    Qiuqiuren.image_dead = IMG_LoadTexture(renderer, "./res/image/13_dead.png");
    Qiuqiuren.image_message = IMG_LoadTexture(renderer, "./res/image/13_message.png");

    MudunQiuqiu.image = IMG_LoadTexture(renderer, "./res/image/14.png");
    MudunQiuqiu.image_dead = IMG_LoadTexture(renderer, "./res/image/14_dead.png");
    MudunQiuqiu.image_message = IMG_LoadTexture(renderer, "./res/image/14_message.png");

    HuofuQiuqiu.image = IMG_LoadTexture(renderer, "./res/image/15.png");
    HuofuQiuqiu.image_dead = IMG_LoadTexture(renderer, "./res/image/15_dead.png");
    HuofuQiuqiu.image_message = IMG_LoadTexture(renderer, "./res/image/15_message.png");

    LeifuQiuqiu.image = IMG_LoadTexture(renderer, "./res/image/16.png");
    LeifuQiuqiu.image_dead = IMG_LoadTexture(renderer, "./res/image/16_dead.png");
    LeifuQiuqiu.image_message = IMG_LoadTexture(renderer, "./res/image/16_message.png");

    LeiQiuqiuShe.image = IMG_LoadTexture(renderer, "./res/image/17.png");
    LeiQiuqiuShe.image_dead = IMG_LoadTexture(renderer, "./res/image/17_dead.png");
    LeiQiuqiuShe.image_message = IMG_LoadTexture(renderer, "./res/image/17_message.png");

    HailuanguiHuo.image = IMG_LoadTexture(renderer, "./res/image/18.png");
    HailuanguiHuo.image_dead = IMG_LoadTexture(renderer, "./res/image/18_dead.png");
    HailuanguiHuo.image_message = IMG_LoadTexture(renderer, "./res/image/18_message.png");
    HailuanguiHuo.image_special = IMG_LoadTexture(renderer, "./res/image/18_special.png");

    HailuanguiLei.image = IMG_LoadTexture(renderer, "./res/image/19.png");
    HailuanguiLei.image_dead = IMG_LoadTexture(renderer, "./res/image/19_dead.png");
    HailuanguiLei.image_message = IMG_LoadTexture(renderer, "./res/image/19_message.png");
    HailuanguiLei.image_special = IMG_LoadTexture(renderer, "./res/image/19_special.png");

    Tewalin.image = IMG_LoadTexture(renderer, "./res/image/20.png");
    Tewalin.image_dead = IMG_LoadTexture(renderer, "./res/image/20_dead.png");
    Tewalin.image_message = IMG_LoadTexture(renderer, "./res/image/20_message.png");

    Shuichong.image = IMG_LoadTexture(renderer, "./res/image/21.png");
    Shuichong.image_dead = IMG_LoadTexture(renderer, "./res/image/21_dead.png");
    Shuichong.image_message = IMG_LoadTexture(renderer, "./res/image/21_message.png");

    Huochong.image = IMG_LoadTexture(renderer, "./res/image/22.png");
    Huochong.image_dead = IMG_LoadTexture(renderer, "./res/image/22_dead.png");
    Huochong.image_message = IMG_LoadTexture(renderer, "./res/image/22_message.png");

    Leichui.image = IMG_LoadTexture(renderer, "./res/image/23.png");
    Leichui.image_dead = IMG_LoadTexture(renderer, "./res/image/23_dead.png");
    Leichui.image_message = IMG_LoadTexture(renderer, "./res/image/23_message.png");
    Leichui.image_special = IMG_LoadTexture(renderer, "./res/image/23_special.png");
}

void CharacterImageDestroy()
{
    SDL_DestroyTexture(Alhaitham.image);
    SDL_DestroyTexture(Alhaitham.image_choose);
    SDL_DestroyTexture(Alhaitham.image_dead);
    SDL_DestroyTexture(Alhaitham.image_message);
    SDL_DestroyTexture(Alhaitham.image_message_big);
    SDL_DestroyTexture(Alhaitham.image_special);

    SDL_DestroyTexture(Lingren.image);
    SDL_DestroyTexture(Lingren.image_dead);
    SDL_DestroyTexture(Lingren.image_choose);
    SDL_DestroyTexture(Lingren.image_message);
    SDL_DestroyTexture(Lingren.image_message_big);
    SDL_DestroyTexture(Lingren.image_special);

    SDL_DestroyTexture(Huoxing.image);
    SDL_DestroyTexture(Huoxing.image_dead);
    SDL_DestroyTexture(Huoxing.image_choose);
    SDL_DestroyTexture(Huoxing.image_message);
    SDL_DestroyTexture(Huoxing.image_message_big);
    SDL_DestroyTexture(Huoxing.image_special);

    SDL_DestroyTexture(Zihuang.image);
    SDL_DestroyTexture(Zihuang.image_dead);
    SDL_DestroyTexture(Zihuang.image_choose);
    SDL_DestroyTexture(Zihuang.image_message);
    SDL_DestroyTexture(Zihuang.image_message_big);
    SDL_DestroyTexture(Zihuang.image_special);

    SDL_DestroyTexture(Antant.image);
    SDL_DestroyTexture(Antant.image_dead);
    SDL_DestroyTexture(Antant.image_choose);
    SDL_DestroyTexture(Antant.image_message);
    SDL_DestroyTexture(Antant.image_message_big);
    SDL_DestroyTexture(Antant.image_special);

    SDL_DestroyTexture(CXK.image);
    SDL_DestroyTexture(CXK.image_dead);
    SDL_DestroyTexture(CXK.image_choose);
    SDL_DestroyTexture(CXK.image_message);
    SDL_DestroyTexture(CXK.image_message_big);
    SDL_DestroyTexture(CXK.image_special);

    SDL_DestroyTexture(Chen.image);
    SDL_DestroyTexture(Chen.image_dead);
    SDL_DestroyTexture(Chen.image_choose);
    SDL_DestroyTexture(Chen.image_message);
    SDL_DestroyTexture(Chen.image_message_big);
    SDL_DestroyTexture(Chen.image_special);

    SDL_DestroyTexture(Ren.image);
    SDL_DestroyTexture(Ren.image_choose);
    SDL_DestroyTexture(Ren.image_dead);
    SDL_DestroyTexture(Ren.image_message);
    SDL_DestroyTexture(Ren.image_message_big);
    SDL_DestroyTexture(Ren.image_special);

    SDL_DestroyTexture(Qiuqiuren.image);
    SDL_DestroyTexture(Qiuqiuren.image_dead);
    SDL_DestroyTexture(Qiuqiuren.image_message);
    SDL_DestroyTexture(Qiuqiuren.image_message_big);
    SDL_DestroyTexture(Qiuqiuren.image_choose);
    SDL_DestroyTexture(Qiuqiuren.image_special);

    SDL_DestroyTexture(MudunQiuqiu.image);
    SDL_DestroyTexture(MudunQiuqiu.image_dead);
    SDL_DestroyTexture(MudunQiuqiu.image_message);
    SDL_DestroyTexture(MudunQiuqiu.image_message_big);
    SDL_DestroyTexture(MudunQiuqiu.image_choose);
    SDL_DestroyTexture(MudunQiuqiu.image_special);

    SDL_DestroyTexture(HuofuQiuqiu.image);
    SDL_DestroyTexture(HuofuQiuqiu.image_dead);
    SDL_DestroyTexture(HuofuQiuqiu.image_message);
    SDL_DestroyTexture(HuofuQiuqiu.image_message_big);
    SDL_DestroyTexture(HuofuQiuqiu.image_choose);
    SDL_DestroyTexture(HuofuQiuqiu.image_special);

    SDL_DestroyTexture(LeifuQiuqiu.image);
    SDL_DestroyTexture(LeifuQiuqiu.image_dead);
    SDL_DestroyTexture(LeifuQiuqiu.image_message);
    SDL_DestroyTexture(LeifuQiuqiu.image_message_big);
    SDL_DestroyTexture(LeifuQiuqiu.image_choose);
    SDL_DestroyTexture(LeifuQiuqiu.image_special);

    SDL_DestroyTexture(LeiQiuqiuShe.image);
    SDL_DestroyTexture(LeiQiuqiuShe.image_dead);
    SDL_DestroyTexture(LeiQiuqiuShe.image_message);
    SDL_DestroyTexture(LeiQiuqiuShe.image_message_big);
    SDL_DestroyTexture(LeiQiuqiuShe.image_choose);
    SDL_DestroyTexture(LeiQiuqiuShe.image_special);

    SDL_DestroyTexture(HailuanguiHuo.image);
    SDL_DestroyTexture(HailuanguiHuo.image_dead);
    SDL_DestroyTexture(HailuanguiHuo.image_message);
    SDL_DestroyTexture(HailuanguiHuo.image_message_big);
    SDL_DestroyTexture(HailuanguiHuo.image_choose);
    SDL_DestroyTexture(HailuanguiHuo.image_special);

    SDL_DestroyTexture(HailuanguiLei.image);
    SDL_DestroyTexture(HailuanguiLei.image_dead);
    SDL_DestroyTexture(HailuanguiLei.image_message);
    SDL_DestroyTexture(HailuanguiLei.image_message_big);
    SDL_DestroyTexture(HailuanguiLei.image_choose);
    SDL_DestroyTexture(HailuanguiLei.image_special);

    SDL_DestroyTexture(Tewalin.image);
    SDL_DestroyTexture(Tewalin.image_dead);
    SDL_DestroyTexture(Tewalin.image_message);
    SDL_DestroyTexture(Tewalin.image_message_big);
    SDL_DestroyTexture(Tewalin.image_choose);
    SDL_DestroyTexture(Tewalin.image_special);

    SDL_DestroyTexture(Huochong.image);
    SDL_DestroyTexture(Huochong.image_dead);
    SDL_DestroyTexture(Huochong.image_message);
    SDL_DestroyTexture(Huochong.image_message_big);
    SDL_DestroyTexture(Huochong.image_choose);
    SDL_DestroyTexture(Huochong.image_special);

    SDL_DestroyTexture(Shuichong.image);
    SDL_DestroyTexture(Shuichong.image_dead);
    SDL_DestroyTexture(Shuichong.image_message);
    SDL_DestroyTexture(Shuichong.image_message_big);
    SDL_DestroyTexture(Shuichong.image_choose);
    SDL_DestroyTexture(Shuichong.image_special);

    SDL_DestroyTexture(Leichui.image);
    SDL_DestroyTexture(Leichui.image_dead);
    SDL_DestroyTexture(Leichui.image_message);
    SDL_DestroyTexture(Leichui.image_message_big);
    SDL_DestroyTexture(Leichui.image_choose);
    SDL_DestroyTexture(Leichui.image_special);
}

void PresentCharacterGame(Character *chara, int num)
{
    if (!IfCharacterAlive(chara))
    {
        SDL_Rect rect = {.x = 400 + (num - 1) * 170, .y = 100};

        if (num > 3)
        {
            rect.y = 450;
            rect.x = 400 + (num - 4) * 170;
        }

        SDL_QueryTexture(chara->image_dead, NULL, NULL, &rect.w, &rect.h);
        SDL_RenderCopy(renderer, chara->image_dead, NULL, &rect);

        return;
    }
    else
    {
        SDL_Rect rect = {.x = 400 + (num - 1) * 170, .y = 100};
        SDL_Rect rect_xueliang = {.x = rect.x, .y = rect.y};
        if (num > 3)
        {
            rect.y = 450;
            rect.x = 400 + (num - 4) * 170;
        }

        if (chara->if_chu && num <= 3)
        {
            rect.y += 30;
        }

        if (chara->if_chu && num > 3)
        {
            rect.y -= 30;
        }

        rect_xueliang.x = rect.x + 4;
        rect_xueliang.y = rect.y + 3;


        if (!chara->if_xuan)
        {
            SDL_QueryTexture(chara->image, NULL, NULL, &rect.w, &rect.h);
            SDL_RenderCopy(renderer, chara->image, NULL, &rect);
        }
        else
        {
            SDL_QueryTexture(chara->image_choose, NULL, NULL, &rect.w, &rect.h);
            SDL_RenderCopy(renderer, chara->image_choose, NULL, &rect);
        }

        //血量展示
        int xueliang = chara->xue;
        char xueliang_print[3];
        if (xueliang >= 10)
        {
            itoa(xueliang, xueliang_print, 10);
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
            surface_yuansu = IMG_Load("./res/image/fire_0.png");
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
            surface_yuansu = IMG_Load("./res/image/feng_3.png");
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

        //充能数展示
        int chongneng = chara->baofa_now;
        SDL_Rect rect_star = {.x = rect.x + 120, .y = rect.y - 27};
        SDL_Texture *texture_star = IMG_LoadTexture(renderer, "./res/image/star.png");
        SDL_QueryTexture(texture_star, NULL, NULL, &rect_star.w, &rect_star.h);
        for (int i = 1; i <= chongneng; ++i)
        {
            rect_star.y += 27;
            SDL_RenderCopy(renderer, texture_star, NULL, &rect_star);
        }

        int special_num = chara->special_state;
        if (special_num > 0 && special_num != 10)
        {
            SDL_Rect rect_special = {.x = rect.x + 2, .y = rect.y + 175};
            SDL_QueryTexture(chara->image_special, NULL, NULL, &rect_special.w, &rect_special.h);
            SDL_RenderCopy(renderer, chara->image_special, NULL, &rect_special);

            TTF_Font *font_specialnum = TTF_OpenFont("./res/HYWH85W.ttf", 24);
            SDL_Color color_specialnum = {0xff, 0xff, 0xff, 0xff};
            char specialnum[2] = {special_num + '0', '\0'};
            rect_special.x += 30;
            SDL_Surface *surface_specialnum = TTF_RenderText_Blended(font_specialnum, specialnum, color_specialnum);
            SDL_Texture *texture_specialnum = SDL_CreateTextureFromSurface(renderer, surface_specialnum);

            SDL_QueryTexture(texture_specialnum, NULL, NULL, &rect_special.w, &rect_special.h);
            SDL_RenderCopy(renderer, texture_specialnum, NULL, &rect_special);

            TTF_CloseFont(font_specialnum);
            SDL_FreeSurface(surface_specialnum);
            SDL_DestroyTexture(texture_specialnum);
        }

        if (chara->if_chu && chara->index_game >= 4)
        {
            bool if_both = false;
            if (jihua > 0)
            {
                if_both = true;
                SDL_Texture *texture_jihua = IMG_LoadTexture(renderer, "./res/image/jihua.png");
                SDL_Rect rect_jihua = {.x = rect.x, .y = rect.y + 205};
                SDL_QueryTexture(texture_jihua, NULL, NULL, &rect_jihua.w, &rect_jihua.h);
                SDL_RenderCopy(renderer, texture_jihua, NULL, &rect_jihua);

                TTF_Font *font_jihuanum = TTF_OpenFont("./res/HYWH85W.ttf", 24);
                SDL_Color color_jihuanum = {0xff, 0xff, 0xff, 0xff};
                char jihuanum[2] = {jihua + '0', '\0'};
                rect_jihua.x += 30;
                SDL_Surface *surface_jihuanum = TTF_RenderText_Blended(font_jihuanum, jihuanum, color_jihuanum);
                SDL_Texture *texture_jihuanum = SDL_CreateTextureFromSurface(renderer, surface_jihuanum);
                SDL_QueryTexture(texture_jihuanum, NULL, NULL, &rect_jihua.w, &rect_jihua.h);
                SDL_RenderCopy(renderer, texture_jihuanum, NULL, &rect_jihua);

                SDL_DestroyTexture(texture_jihuanum);
                SDL_DestroyTexture(texture_jihua);
                SDL_FreeSurface(surface_jihuanum);
                TTF_CloseFont(font_jihuanum);
            }

            if (caoyuanhe > 0)
            {
                SDL_Texture *texture_he = IMG_LoadTexture(renderer, "./res/image/caoyuanhe.png");
                SDL_Rect rect_he = {.x = rect.x, .y = rect.y + 205};
                if (if_both)
                {
                    rect_he.x += 60;
                }
                SDL_QueryTexture(texture_he, NULL, NULL, &rect_he.w, &rect_he.h);
                SDL_RenderCopy(renderer, texture_he, NULL, &rect_he);

                TTF_Font *font_henum = TTF_OpenFont("./res/HYWH85W.ttf", 24);
                SDL_Color color_henum = {0xff, 0xff, 0xff, 0xff};
                char henum[2] = {caoyuanhe + '0', '\0'};
                rect_he.x += 30;
                SDL_Surface *surface_henum = TTF_RenderText_Blended(font_henum, henum, color_henum);
                SDL_Texture *texture_henum = SDL_CreateTextureFromSurface(renderer, surface_henum);
                SDL_QueryTexture(texture_henum, NULL, NULL, &rect_he.w, &rect_he.h);
                SDL_RenderCopy(renderer, texture_henum, NULL, &rect_he);

                SDL_DestroyTexture(texture_henum);
                SDL_DestroyTexture(texture_he);
                SDL_FreeSurface(surface_henum);
                TTF_CloseFont(font_henum);
            }

        }

        //有开就有关
        SDL_FreeSurface(surface_yuansu);
        SDL_DestroyTexture(texture_xue);
        SDL_FreeSurface(surface_xue);
        SDL_DestroyTexture(texture_hudun);
        SDL_FreeSurface(surface_hudun);
        SDL_DestroyTexture(texture_star);

        TTF_CloseFont(font_xue);
        TTF_CloseFont(font_hudun);
        return;

    }
}

bool IfCharacterAlive(Character *chara)
{
    if (!chara->xue)
    {
        return false;
    }
    return true;
}

void CharacterDeadOrAlive(Character *chara1, Character *chara2, Character *chara3,
                          Character *chara4, Character *chara5, Character *chara6)
{
    if (chara1->xue == 0)
    {
        chara1->zhuang[0] = true;
    }
    if (chara2->xue == 0)
    {
        chara2->zhuang[0] = true;
    }
    if (chara3->xue == 0)
    {
        chara3->zhuang[0] = true;
    }
    if (chara4->xue == 0)
    {
        chara4->zhuang[0] = true;
    }
    if (chara5->xue == 0)
    {
        chara5->zhuang[0] = true;
    }
    if (chara6->xue == 0)
    {
        chara6->zhuang[0] = true;
    }
}

bool IfChongMan(Character *chara)
{
    if (chara->baofa_now == chara->baofa_num)
    {
        return true;
    }
    return false;
}

bool IfCharacterChoose(Character *chara)
{
    SDL_Event event;
    while (1)
    {
        TTF_Font *font_message = TTF_OpenFont("./res/HYWH85W.ttf", 32);
        SDL_Color color_message = {0xff, 0xff, 0xff, 0xff};

        SDL_Surface *surface_message = TTF_RenderUTF8_Solid(font_message, "是否选择该角色：", color_message);
        SDL_Texture *texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);
        SDL_Rect rect_message = {.x = 430, .y = 380};
        SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
        SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

        SDL_Texture *texture_change = IMG_LoadTexture(renderer, "./res/image/change.png");
        SDL_Rect rect_change = {.x = 1050, .y = 570};
        SDL_QueryTexture(texture_change, NULL, NULL, &rect_change.w, &rect_change.h);
        SDL_RenderCopy(renderer, texture_change, NULL, &rect_change);

        SDL_Surface *surface_yesno = TTF_RenderUTF8_Solid(font_message, chara->name[0], color_message);
        SDL_Texture *texture_yesno = SDL_CreateTextureFromSurface(renderer, surface_yesno);
        SDL_Rect rect_yesno = {.x = 680, .y = 380};
        SDL_QueryTexture(texture_yesno, NULL, NULL, &rect_yesno.w, &rect_yesno.h);
        SDL_RenderCopy(renderer, texture_yesno, NULL, &rect_yesno);

        ShowCharacterMessage(chara);

        SDL_RenderPresent(renderer);

        TTF_CloseFont(font_message);
        SDL_FreeSurface(surface_message);
        SDL_DestroyTexture(texture_message);
        SDL_DestroyTexture(texture_change);
        SDL_FreeSurface(surface_yesno);
        SDL_DestroyTexture(texture_yesno);

        while (SDL_PollEvent(&event))
        {

            switch (event.type) {
                case SDL_QUIT:
                    CharacterImageDestroy();
                    SummonImageDestroy();
                    quit_delete();
                    exit(0);

                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                    {
                        chara->if_xuan = false;
                        SDL_RenderClear(renderer);
                        return false;
                    }
                    else if (event.key.keysym.sym == SDLK_SPACE)
                    {
                        chara->if_xuan = false;
                        chara->if_chu = true;
                        return true;
                    }
                case SDL_MOUSEBUTTONDOWN: //鼠标左键
                    if (event.button.button == SDL_BUTTON_LEFT)
                    {
                        int x = event.button.x;
                        int y = event.button.y;

                        if (x >= 1060 && x <= 1140 && y >= 580 && y <= 660)
                        {
                            chara->if_xuan = false;
                            chara->if_chu = true;
                            return true;
                        }
                        else
                        {
                            chara->if_xuan = false;
                            SDL_RenderClear(renderer);
                            return false;
                        }
                    }
                    break;
                default:
                    break;
            }
        }
        SDL_Delay(3);
    }
}

void ShowCharacterMessage(Character *chara)
{
    SDL_Rect rect_message = {.x = 0, .y = 230};
    SDL_QueryTexture(chara->image_message, NULL, NULL, &rect_message.w, &rect_message.h);
    SDL_RenderCopy(renderer, chara->image_message, NULL, &rect_message);
}

bool IfFirstChooseCharacter(Character *chara)
{
    SDL_Rect rect_chara = {.x = 475, .y = 20};
    SDL_QueryTexture(chara->image_message_big, NULL, NULL, &rect_chara.w, &rect_chara.h);
    SDL_RenderCopy(renderer, chara->image_message_big, NULL, &rect_chara);

    SDL_RenderPresent(renderer);

    SDL_Event event_choose;
    while (SDL_WaitEvent(&event_choose))
    {
        switch (event_choose.type)
        {
            case SDL_KEYDOWN:
                if (event_choose.key.keysym.sym == SDLK_ESCAPE)
                {
                    return false;
                }
                else if (event_choose.key.keysym.sym == SDLK_SPACE)
                {
                    return true;
                }
        }
    }
}

void quit_delete()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    Mix_FreeMusic(music);

    IMG_Quit();
    SDL_Quit();
    TTF_Quit();
    Mix_Quit();
}