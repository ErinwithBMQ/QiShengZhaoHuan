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

void CharacterImageLoad(SDL_Renderer *renderer)
{
    Alhaitham.image = IMG_LoadTexture(renderer, "./res/image/1.png");
    Alhaitham.image_choose = IMG_LoadTexture(renderer, "./res/image/1_xuan.png");
    Alhaitham.image_dead = IMG_LoadTexture(renderer, "./res/image/1_dead.png");

    Lingren.image = IMG_LoadTexture(renderer, "./res/image/2.png");
    Lingren.image_choose = IMG_LoadTexture(renderer, "./res/image/2_xuan.png");
    Lingren.image_dead = IMG_LoadTexture(renderer, "./res/image/2_dead.png");
}

void CharacterImageDestroy()
{
    SDL_DestroyTexture(Alhaitham.image);
    SDL_DestroyTexture(Alhaitham.image_choose);
    SDL_DestroyTexture(Alhaitham.image_dead);

    SDL_DestroyTexture(Lingren.image);
    SDL_DestroyTexture(Lingren.image_dead);
    SDL_DestroyTexture(Lingren.image_choose);
}

void PresentCharacterGame(Character *chara, int num, SDL_Renderer *renderer)
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
            rect.y += 20;
        }

        if (chara->if_chu && num > 3)
        {
            rect.y -= 20;
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

bool IfCharacterChoose(SDL_Renderer *renderer, SDL_Window *window, Character *chara)
{
    SDL_Event event;
    while (1)
    {
        TTF_Font *font_message = TTF_OpenFont("./res/HYWH85W.ttf", 32);
        SDL_Color color_message = {0x00, 0x00, 0x00, 0x00};

        SDL_Surface *surface_message = TTF_RenderUTF8_Solid(font_message, "是否选择该角色", color_message);
        SDL_Texture *texture_message = SDL_CreateTextureFromSurface(renderer, surface_message);
        SDL_Rect rect_message = {.x = 500, .y = 330};
        SDL_QueryTexture(texture_message, NULL, NULL, &rect_message.w, &rect_message.h);
        SDL_RenderCopy(renderer, texture_message, NULL, &rect_message);

        SDL_Surface *surface_yesno = TTF_RenderUTF8_Solid(font_message, "按space选中，按esc取消选择", color_message);
        SDL_Texture *texture_yesno = SDL_CreateTextureFromSurface(renderer, surface_yesno);
        SDL_Rect rect_yesno = {.x = 400, .y = 380};
        SDL_QueryTexture(texture_yesno, NULL, NULL, &rect_yesno.w, &rect_yesno.h);
        SDL_RenderCopy(renderer, texture_yesno, NULL, &rect_yesno);

        ShowCharacterMessage(renderer, chara);

        SDL_RenderPresent(renderer);

        while (SDL_PollEvent(&event))
        {

            switch (event.type) {
                case SDL_QUIT:
                    CharacterImageDestroy();

                    SDL_DestroyTexture(texture_message);
                    SDL_FreeSurface(surface_message);

                    SDL_DestroyWindow(window);
                    SDL_DestroyRenderer(renderer);
                    TTF_CloseFont(font_message);

                    IMG_Quit();
                    SDL_Quit();
                    TTF_Quit();
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
                    break;
                default:
                    break;
            }
        }
        SDL_Delay(3);
    }
}

void ShowCharacterMessage(SDL_Renderer *renderer, Character *chara)
{
    TTF_Font *font_message = TTF_OpenFont("./res/HYWH85W.ttf", 24);
    SDL_Color color_message = {0x00, 0x00, 0x00, 0x00};

    SDL_Surface *surface_name = TTF_RenderUTF8_Solid(font_message, chara->name[0], color_message);
    SDL_Texture *texture_name = SDL_CreateTextureFromSurface(renderer, surface_name);
    SDL_Rect rect_name = {.x = 10, .y = 200};
    SDL_QueryTexture(texture_name, NULL, NULL, &rect_name.w, &rect_name.h);
    SDL_RenderCopy(renderer, texture_name, NULL, &rect_name);

    surface_name = TTF_RenderUTF8_Solid(font_message, "普通攻击：", color_message);
    texture_name = SDL_CreateTextureFromSurface(renderer, surface_name);
    rect_name.y =  230;
    SDL_QueryTexture(texture_name, NULL, NULL, &rect_name.w, &rect_name.h);
    SDL_RenderCopy(renderer, texture_name, NULL, &rect_name);

    surface_name = TTF_RenderUTF8_Solid(font_message, chara->name[1], color_message);
    texture_name = SDL_CreateTextureFromSurface(renderer, surface_name);
    rect_name.x =  120;
    SDL_QueryTexture(texture_name, NULL, NULL, &rect_name.w, &rect_name.h);
    SDL_RenderCopy(renderer, texture_name, NULL, &rect_name);

    surface_name = TTF_RenderUTF8_Solid(font_message, "伤害：", color_message);
    texture_name = SDL_CreateTextureFromSurface(renderer, surface_name);
    rect_name.x =  10;
    rect_name.y =  260;
    SDL_QueryTexture(texture_name, NULL, NULL, &rect_name.w, &rect_name.h);
    SDL_RenderCopy(renderer, texture_name, NULL, &rect_name);

    char arr[10];
    itoa(chara->shanghai[0], arr, 10);
    surface_name = TTF_RenderUTF8_Solid(font_message, arr, color_message);
    texture_name = SDL_CreateTextureFromSurface(renderer, surface_name);
    rect_name.x =  75;
    rect_name.y =  260;
    SDL_QueryTexture(texture_name, NULL, NULL, &rect_name.w, &rect_name.h);
    SDL_RenderCopy(renderer, texture_name, NULL, &rect_name);

    surface_name = TTF_RenderUTF8_Solid(font_message, "元素战技：", color_message);
    texture_name = SDL_CreateTextureFromSurface(renderer, surface_name);
    rect_name.x =  10;
    rect_name.y =  290;
    SDL_QueryTexture(texture_name, NULL, NULL, &rect_name.w, &rect_name.h);
    SDL_RenderCopy(renderer, texture_name, NULL, &rect_name);

    surface_name = TTF_RenderUTF8_Solid(font_message, chara->name[2], color_message);
    texture_name = SDL_CreateTextureFromSurface(renderer, surface_name);
    rect_name.x =  120;
    rect_name.y =  290;
    SDL_QueryTexture(texture_name, NULL, NULL, &rect_name.w, &rect_name.h);
    SDL_RenderCopy(renderer, texture_name, NULL, &rect_name);

    surface_name = TTF_RenderUTF8_Solid(font_message, "伤害：", color_message);
    texture_name = SDL_CreateTextureFromSurface(renderer, surface_name);
    rect_name.x =  10;
    rect_name.y =  320;
    SDL_QueryTexture(texture_name, NULL, NULL, &rect_name.w, &rect_name.h);
    SDL_RenderCopy(renderer, texture_name, NULL, &rect_name);

    itoa(chara->shanghai[1], arr, 10);
    surface_name = TTF_RenderUTF8_Solid(font_message, arr, color_message);
    texture_name = SDL_CreateTextureFromSurface(renderer, surface_name);
    rect_name.x =  75;
    rect_name.y =  320;
    SDL_QueryTexture(texture_name, NULL, NULL, &rect_name.w, &rect_name.h);
    SDL_RenderCopy(renderer, texture_name, NULL, &rect_name);
}
