//
// Created by Erin on 2024/1/14.
//
#include "action.h"

void CardImageLoad()
{
    bestfriend.image = IMG_LoadTexture(renderer, "./res/image/action_1");
    fengbu.image = IMG_LoadTexture(renderer, "./res/image/action_2");
    hegui.image = IMG_LoadTexture(renderer, "./res/image/action_3");
    huanban.image = IMG_LoadTexture(renderer, "./res/image/action_4");
    jiaogei.image = IMG_LoadTexture(renderer, "./res/image/action_5");
    xingtian.image = IMG_LoadTexture(renderer, "./res/image/action_6");
    yunchou.image = IMG_LoadTexture(renderer, "./res/image/action_7");
    tiantian.image = IMG_LoadTexture(renderer, "./res/image/action_8");
    jueyun.image = IMG_LoadTexture(renderer, "./res/image/action_9");
}

void CardImageDestroy()
{
    SDL_DestroyTexture(bestfriend.image);
    SDL_DestroyTexture(fengbu.image);
    SDL_DestroyTexture(hegui.image);
    SDL_DestroyTexture(huanban.image);
    SDL_DestroyTexture(jiaogei.image);
    SDL_DestroyTexture(xingtian.image);
    SDL_DestroyTexture(yunchou.image);
    SDL_DestroyTexture(tiantian.image);
    SDL_DestroyTexture(jueyun.image);
}

void Action_1(Character *chara, int yuansu1, int yuansu2, int yuansu3, int tou[])
{
    int num = 2;
    for (int i = 0; i < 5; ++i)
    {
        if (i != yuansu1 && i != yuansu2 && i != yuansu3)
        {
            if (tou[i] > 0)
            {
                tou[i]--;
                num--;
                if (tou[i] > 0 && num > 0)
                {
                    tou[i]--;
                    num--;
                }
                if (num == 0)
                {
                    break;
                }
            }
        }
    }

    if (num > 0)
    {
        for (int i = 0; i < 5; ++i)
        {
            if (i == yuansu1 || i == yuansu2 || i == yuansu3)
            {
                if (tou[i] > 0)
                {
                    tou[i]--;
                    num--;
                    if (tou[i] > 0 && num > 0)
                    {
                        tou[i]--;
                        num--;
                    }
                    if (num == 0)
                    {
                        break;
                    }
                }
            }
        }
    }

    if (num > 0)
    {
        tou[5] -= num;
    }

    tou[5] += 2;
}

void Action_2(Character *chara, int yuansu1, int yuansu2, int yuansu3, int tou[])
{
    int num = 1;
    for (int i = 0; i < 5; ++i)
    {
        if (i != yuansu1 && i != yuansu2 && i != yuansu3)
        {
            if (tou[i] > 0)
            {
                tou[i]--;
                num--;
                break;
            }
        }
    }

    if (num > 0)
    {
        for (int i = 0; i < 6; ++i)
        {
            if (tou[i] > 0)
            {
                tou[i]--;
                num--;
                break;
            }
        }
    }

    for (int i = 0; i <= summon_index_we; ++i)
    {
        if (summon_all[i] != NULL)
        {
            if (summon_all[i]->turn_now == 1)
            {
                summon_all[i]->turn_now++;
                return;
            }
        }
    }

    if (summon_all[0] != NULL)
    {
        summon_all[0]->turn_now++;
    }
}

void Action_3(Character *chara, int yuansu1, int yuansu2, int yuansu3, int tou[])
{
    int num = 1;
    for (int i = 0; i < 5; ++i)
    {
        if (i != yuansu1 && i != yuansu2 && i != yuansu3)
        {
            if (tou[i] > 0)
            {
                tou[i]--;
                num--;
                break;
            }
        }
    }

    if (num > 0)
    {
        for (int i = 0; i < 6; ++i)
        {
            if (tou[i] > 0)
            {
                tou[i]--;
                num--;
                break;
            }
        }
    }

    if_qiehuanjuese = true;
}

void Action_4(Character *chara, int yuansu1, int yuansu2, int yuansu3, int tou[])
{
    if_notusetou = true;
}

void Action_5(Character *chara, int yuansu1, int yuansu2, int yuansu3, int tou[])
{
    if_kuaijie = true;
}

void Action_6(Character *chara, int yuansu1, int yuansu2, int yuansu3, int tou[])
{
    int num = 2;
    for (int i = 0; i < 5; ++i)
    {
        if (i != yuansu1 && i != yuansu2 && i != yuansu3)
        {
            if (tou[i] > 0)
            {
                tou[i]--;
                num--;
                if (tou[i] > 0 && num > 0)
                {
                    tou[i]--;
                    num--;
                }
                if (num == 0)
                {
                    break;
                }
            }
        }
    }

    if (num > 0)
    {
        for (int i = 0; i < 5; ++i)
        {
            if (i == yuansu1 || i == yuansu2 || i == yuansu3)
            {
                if (tou[i] > 0)
                {
                    tou[i]--;
                    num--;
                    if (tou[i] > 0 && num > 0)
                    {
                        tou[i]--;
                        num--;
                    }
                    if (num == 0)
                    {
                        break;
                    }
                }
            }
        }
    }

    if (num > 0)
    {
        tou[5] -= num;
    }

    if (chara->baofa_now < chara->baofa_num)
    {
        chara->baofa_now++;
    }
}

void Action_7(Character *chara, int yuansu1, int yuansu2, int yuansu3, int tou[])
{

}

void Action_8(Character *chara, int yuansu1, int yuansu2, int yuansu3, int tou[])
{
    if (chara->xue < 10)
    {
        chara->xue++;
    }

    chara->if_bao = true;
}

void Action_9(Character *chara, int yuansu1, int yuansu2, int yuansu3, int tou[])
{
    chara->shanghai_more[0]++;
    chara->if_bao = true;
}

void ShowMyCard()
{
    SDL_Rect rect_image = {.x = 315, .y = 687};
    for (int i = 0; i < my_card_num; ++i)
    {
        if (my_card[i] != NULL)
        {
            SDL_QueryTexture(my_card[i]->image, NULL, NULL, &rect_image.w, &rect_image.h);
            SDL_RenderCopy(renderer, my_card[i]->image, NULL, &rect_image);
            rect_image.x += 67;
        }
    }
}

void ShowCardFunction(Card card)
{
    SDL_Rect rect_message = {.x = 50, .y = 150};

    TTF_Font *font_message = TTF_OpenFont("./res/HYWH85W.ttf", 25);
    SDL_Color color_message = {0x00, 0x00, 0x00, 0x00};
    SDL_Surface *surface_message = TTF_RenderText_Blended(font_message, card.name, color_message);
    SDL_Texture *texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);

    SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
    SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

    rect_message.y += 30;
    surface_message = TTF_RenderText_Blended(font_message, card.type, color_message);
    texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);

    SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
    SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

    rect_message.y += 30;
    surface_message = TTF_RenderText_Blended(font_message, card.message, color_message);
    texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);

    SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
    SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

    SDL_RenderPresent(renderer);

    SDL_FreeSurface(surface_message);
    SDL_DestroyTexture(texture_message);
    TTF_CloseFont(font_message);
}
