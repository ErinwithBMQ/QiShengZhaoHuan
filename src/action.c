//
// Created by Erin on 2024/1/14.
//
#include <action.h>
#include <battle.h>
#include <summon.h>


void CardImageLoad()
{
    bestfriend.image = IMG_LoadTexture(renderer, "./res/image/action_1.png");
    fengbu.image = IMG_LoadTexture(renderer, "./res/image/action_2.png");
    hegui.image = IMG_LoadTexture(renderer, "./res/image/action_3.png");
    huanban.image = IMG_LoadTexture(renderer, "./res/image/action_4.png");
    jiaogei.image = IMG_LoadTexture(renderer, "./res/image/action_5.png");
    xingtian.image = IMG_LoadTexture(renderer, "./res/image/action_6.png");
    yunchou.image = IMG_LoadTexture(renderer, "./res/image/action_7.png");
    tiantian.image = IMG_LoadTexture(renderer, "./res/image/action_8.png");
    jueyun.image = IMG_LoadTexture(renderer, "./res/image/action_9.png");
    lianhua.image = IMG_LoadTexture(renderer, "./res/image/action_10.png");
    fotiao.image = IMG_LoadTexture(renderer, "./res/image/action_11.png");
    tudou.image = IMG_LoadTexture(renderer, "./res/image/action_12.png");
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
    SDL_DestroyTexture(lianhua.image);
    SDL_DestroyTexture(fotiao.image);
    SDL_DestroyTexture(tudou.image);
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

    SuijiChouka(2);
}

void Action_8(Character *chara, int yuansu1, int yuansu2, int yuansu3, int tou[])
{
    if (chara->xue < 10)
    {
        chara->xue++;
    }
}

void Action_9(Character *chara, int yuansu1, int yuansu2, int yuansu3, int tou[])
{
    liaolijiashang[0] = 1;
    liaolijiashang[1] = 1;
}

void Action_10(Character *chara, int yuansu1, int yuansu2, int yuansu3, int tou[])
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

    chara->hudun += 3;
}

void Action_11(Character *chara, int yuansu1, int yuansu2, int yuansu3, int tou[])
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

    liaolijiashang[0] = 3;
    liaolijiashang[1] = 3;
}

void Action_12(Character *chara, int yuansu1, int yuansu2, int yuansu3, int tou[])
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
    chara->xue += 2;
    if (chara->xue > 10)
    {
        chara->xue = 10;
    }
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

void ShowCardFunction(Card *card)
{
    SDL_Rect rect_message = {.x = 50, .y = 150};

    TTF_Font *font_message = TTF_OpenFont("./res/HYWH85W.ttf", 25);
    SDL_Color color_message = {0xff, 0xff, 0xff, 0xff};
    SDL_Surface *surface_message = TTF_RenderUTF8_Solid(font_message, card->name, color_message);
    SDL_Texture *texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);

    SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
    SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

    rect_message.y += 30;
    surface_message = TTF_RenderUTF8_Solid(font_message, card->type, color_message);
    texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);

    SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
    SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

    rect_message.y += 30;
    surface_message = TTF_RenderUTF8_Solid(font_message, "消耗  个元素骰", color_message);
    texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);
    SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
    SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

    char num[2];
    itoa(card->num, num, 10);
    rect_message.x = 100;
    surface_message = TTF_RenderUTF8_Solid(font_message, num, color_message);
    texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);
    SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
    SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

    rect_message.y += 30;
    rect_message.x = 50;
    surface_message = TTF_RenderUTF8_Solid(font_message, card->message, color_message);
    texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);

    SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
    SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

    SDL_RenderPresent(renderer);

    SDL_FreeSurface(surface_message);
    SDL_DestroyTexture(texture_message);
    TTF_CloseFont(font_message);
}

bool if_choosecard(Card *card, int index, int tou[],int yuansu, int yuansu1, int yuansu2, int yuansu3)
{
    SDL_Texture *texture_choose = IMG_LoadTexture(renderer, "./res/image/xuanzhong.png");
    SDL_Rect rect_choose = {.x = 320 + index * 67, .y = 719};
    SDL_QueryTexture(texture_choose, NULL, NULL, &rect_choose.w, &rect_choose.h);
    SDL_RenderCopy(renderer, texture_choose, NULL, &rect_choose);

    TTF_Font *font_message = TTF_OpenFont("./res/HYWH85W.ttf", 25);
    SDL_Color color_message = {0xff, 0xff, 0xff, 0xff};
    SDL_Surface *surface_message = TTF_RenderUTF8_Solid(font_message, "再次点击该牌即可使用", color_message);
    SDL_Texture *texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);
    SDL_Rect rect_message = {.x = 520, .y = 330};
    SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
    SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

    surface_message = TTF_RenderUTF8_Solid(font_message, "按space可转变元素骰", color_message);
    texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);
    rect_message.y += 50;
    SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
    SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

    ShowCardFunction(card);

    SDL_DestroyTexture(texture_choose);

    int total = 0;
    for (int i = 0; i < 6; ++i)
    {
        total += tou[i];
    }

    SDL_Event event_card;
    while (SDL_WaitEvent(&event_card))
    {
        switch (event_card.type)
        {
            case SDL_QUIT:
                quit_delete();
                exit(0);
            case SDL_KEYDOWN:
                if (event_card.key.keysym.sym == SDLK_ESCAPE)
                {
                    return false;
                }
                if (event_card.key.keysym.sym == SDLK_SPACE)
                {
                    for (int i = 0; i < 5; ++i)
                    {
                        if (i != yuansu1 && i != yuansu2 && i != yuansu3)
                        {
                            if (tou[i] > 0)
                            {
                                tou[i]--;
                                tou[yuansu]++;
                                UseMyCard(index);
                                return false;
                            }
                        }
                    }

                    for (int i = 0; i < 5; ++i)
                    {
                        if (i != yuansu)
                        {
                            if (tou[i] > 0)
                            {
                                tou[i]--;
                                tou[yuansu]++;
                                UseMyCard(index);
                                return false;
                            }
                        }
                    }
                    return false;
                }
                break;
            case SDL_MOUSEBUTTONDOWN: //鼠标左键
                if (event_card.button.button == SDL_BUTTON_LEFT)
                {
                    int x = event_card.button.x;
                    int y = event_card.button.y;

                    if (x >= 315 + 67 * index && x <= 380 + 67 * index && y >= 687 && y < 800)
                    {
                        if (total < card->num)
                        {
                            PrintTouNotEnough();
                            return false;
                        }
                        else
                        {
                            return true;
                        }
                    }
                    else
                    {
                        return false;
                    }
                }
        }
    }
}

void UseMyCard(int index)
{
    for (int i = index; i < my_card_num - 1; ++i)
    {
        my_card[i] = my_card[i + 1];
    }
    my_card[my_card_num - 1] = NULL;
    my_card_num--;
}

void ActionLiaoliJiaShang(Character *chara)
{
    if (liaolijiashang[1] != 0)
    {
        chara->shanghai_more[liaolijiashang[0] - 1] += liaolijiashang[1];
    }
}
