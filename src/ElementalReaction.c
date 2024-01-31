//
// Created by Erin on 2024/1/30.
//

#include <ElementalReaction.h>

void ChooseWhichReaction(Character *chara, Character **enemy, Character *chara1, Character *chara2, Character *chara3)
{
    int yuansu_we = chara->yuansu;
    int yuansu_enemy = -1;
    for (int i = 0; i < 5; ++i)
    {
        if ((*enemy)->yuansu_fu[i] == true)
        {
            yuansu_enemy = i;
            break;
        }
    }

    if ((yuansu_we == 0 && yuansu_enemy == 1) || (yuansu_we == 1 && yuansu_enemy == 0)) // 超载
    {
        ChaoZai(enemy, chara1, chara2, chara3);
    }
    else if ((yuansu_we == 0 && yuansu_enemy == 4) || (yuansu_we == 4 && yuansu_enemy == 0)) //燃烧
    {
        RanShao();
    }
    else if ((yuansu_we == 1 && yuansu_enemy == 2) || (yuansu_we == 2 && yuansu_enemy == 1)) //感电
    {
        GanDian(chara1, chara2, chara3);
    }
    else if ((yuansu_we == 1 && yuansu_enemy == 4) || (yuansu_we == 4 && yuansu_enemy == 1)) //激化
    {
        JiHua();
    }
    else if ((yuansu_we == 2 && yuansu_enemy == 4) || (yuansu_we == 4 && yuansu_enemy == 2)) //绽放
    {
        ZhanFang();
    }
    else if (yuansu_we == 3 && yuansu_enemy >= 0 && yuansu_enemy != 3)  //扩散
    {
        KuoSan(chara, chara1, chara2, chara3, yuansu_enemy);
    }
    else if (yuansu_enemy == 3 && yuansu_we != 3)  //扩散
    {
        KuoSan(chara, chara1, chara2, chara3, yuansu_we);
    }
}

void JiHua()
{
    jihua += 2;
}

void ZhanFang()
{
    caoyuanhe += 1;
}

void RanShao()
{
    for (int i = 0; i < 4; ++i)
    {
        if (summon_all[i]->index == 4)
        {
            summon_all[i]->turn_now = 2;
            return;
        }
    }
    *(summon_all[summon_index_we]) = Fire;
    summon_all[summon_index_we]->turn_now = 1;
    summon_all[summon_index_we]->index_game = summon_index_we;
    summon_index_we++;
}

void GanDian(Character *chara1, Character *chara2, Character *chara3)
{
    shanghai[1]++;
    if (chara1->if_chu == 1)
    {
        if (chara2->hudun > 0)
        {
            chara2->hudun--;
        }
        else if (chara2->xue > 0)
        {
            chara2->xue--;
        }

        if (chara3->hudun > 0)
        {
            chara3->hudun--;
        }
        else if (chara3->xue > 0)
        {
            chara3->xue--;
        }
        return;
    }

    if (chara2->if_chu == 1)
    {
        if (chara1->hudun > 0)
        {
            chara1->hudun--;
        }
        else if (chara1->xue > 0)
        {
            chara1->xue--;
        }

        if (chara3->hudun > 0)
        {
            chara3->hudun--;
        }
        else if (chara3->xue > 0)
        {
            chara3->xue--;
        }
        return;
    }

    if (chara3->if_chu == 1)
    {
        if (chara2->hudun > 0)
        {
            chara2->hudun--;
        }
        else if (chara2->xue > 0)
        {
            chara2->xue--;
        }

        if (chara1->hudun > 0)
        {
            chara1->hudun--;
        }
        else if (chara1->xue > 0)
        {
            chara1->xue--;
        }
        return;
    }
}

void ChaoZai(Character **enemy, Character *chara1, Character *chara2, Character *chara3)
{
    if (chara1->if_chu)
    {
        if (chara2->xue > 0)
        {
            chara1->if_chu = false;
            chara2->if_chu = true;
            *enemy = chara2;
            return;
        }
        else if (chara3->xue > 0)
        {
            chara1->if_chu = false;
            chara3->if_chu = true;
            *enemy = chara3;
            return;
        }
        return;
    }

    if (chara2->if_chu)
    {
        if (chara3->xue > 0)
        {
            chara2->if_chu = false;
            chara3->if_chu = true;
            *enemy = chara3;
            return;
        }
        else if (chara1->xue > 0)
        {
            chara2->if_chu = false;
            chara1->if_chu = true;
            *enemy = chara1;
            return;
        }
        return;
    }

    if (chara3->if_chu)
    {
        if (chara1->xue > 0)
        {
            chara3->if_chu = false;
            chara1->if_chu = true;
            *enemy = chara1;
            return;
        }
        else if (chara2->xue > 0)
        {
            chara3->if_chu = false;
            chara2->if_chu = true;
            *enemy = chara2;
            return;
        }
        return;
    }
}

void KuoSan(Character *chara, Character *chara1, Character *chara2, Character *chara3, int yuansu)
{
    shanghai[1]++;
    shanghai[3] = yuansu;

    if (chara1->if_chu == 1)
    {
        if (chara2->hudun > 0)
        {
            chara2->hudun--;
        }
        else if (chara2->xue > 0)
        {
            chara2->xue--;
        }
        KuosanJiashang(yuansu, chara2);

        if (chara3->hudun > 0)
        {
            chara3->hudun--;
        }
        else if (chara3->xue > 0)
        {
            chara3->xue--;
        }
        KuosanJiashang(yuansu, chara3);
        return;
    }

    if (chara2->if_chu == 1)
    {
        if (chara1->hudun > 0)
        {
            chara1->hudun--;
        }
        else if (chara1->xue > 0)
        {
            chara1->xue--;
        }
        KuosanJiashang(yuansu, chara1);

        if (chara3->hudun > 0)
        {
            chara3->hudun--;
        }
        else if (chara3->xue > 0)
        {
            chara3->xue--;
        }
        KuosanJiashang(yuansu, chara3);
        return;
    }

    if (chara3->if_chu == 1)
    {
        if (chara2->hudun > 0)
        {
            chara2->hudun--;
        }
        else if (chara2->xue > 0)
        {
            chara2->xue--;
        }
        KuosanJiashang(yuansu, chara2);

        if (chara1->hudun > 0)
        {
            chara1->hudun--;
        }
        else if (chara1->xue > 0)
        {
            chara1->xue--;
        }
        KuosanJiashang(yuansu, chara1);
        return;
    }
}

void JihuaAddition(Character *chara)
{
    if (jihua > 0)
    {
        if (chara->yuansu == 1 || chara->yuansu == 4)
        {
            if (chara->if_pugongfumo)
            {
                chara->shanghai_more[0] += 1;
            }
            chara->shanghai_more[1] += 1;
            chara->shanghai_more[2] += 1;
        }
    }
}

void CaoyuanheAddition(Character *chara)
{
    if (caoyuanhe > 0)
    {
        if (chara->yuansu == 0 || chara->yuansu == 1)
        {
            if (chara->if_pugongfumo)
            {
                chara->shanghai_more[0] += 2;
            }
            chara->shanghai_more[1] += 2;
            chara->shanghai_more[2] += 2;
        }
    }
}

void JihuaReduce(Character *chara)
{
    if (jihua > 0)
    {
        if (chara->yuansu == 1 || chara->yuansu == 4)
        {
            jihua--;
        }
    }
}

void CaoyuanheReduce(Character *chara)
{
    if (caoyuanhe > 0)
    {
        if (chara->yuansu == 0 || chara->yuansu == 1)
        {
            caoyuanhe--;
        }
    }
}

void KuosanJiashang(int yuansu, Character *enemy)
{
    int yuansu_enemy = -1;
    for (int i = 0; i < 5; ++i)
    {
        if (enemy->yuansu_fu[i])
        {
            yuansu_enemy = i;
            break;
        }
    }

    if ((yuansu == 0 && yuansu_enemy == 1) || (yuansu == 1 && yuansu_enemy == 0) ||
            (yuansu == 0 && yuansu_enemy == 2) || (yuansu == 2 && yuansu_enemy == 0)) //超载和蒸发
    {
        if (enemy->hudun >= 2)
        {
            enemy->hudun -= 2;
        }
        else if (enemy->xue > 0)
        {
            int left = 2 - enemy->hudun;
            enemy->hudun = 0;
            enemy->xue -= left;
            if (enemy->xue < 0)
            {
                enemy->xue = 0;
            }
        }
        enemy->yuansu_fu[yuansu_enemy] = false;
        shanghaimore[enemy->index_game] += 2;
    }
    else if ((yuansu == 1 && yuansu_enemy == 2) || (yuansu == 2 && yuansu_enemy == 1) || (yuansu > 0 && yuansu_enemy == 3)) //感电和再次扩散，仅加伤害
    {
        if (enemy->hudun > 0)
        {
            enemy->hudun--;
        }
        else if (enemy->xue > 0)
        {
            enemy->xue--;
        }
        enemy->yuansu_fu[yuansu_enemy] = false;
        shanghaimore[enemy->index_game] += 1;
    }
    else if ((yuansu == 1 && yuansu_enemy == 4) || (yuansu == 4 && yuansu_enemy == 1)) //激化
    {
        if (enemy->hudun > 0)
        {
            enemy->hudun--;
        }
        else if (enemy->xue > 0)
        {
            enemy->xue --;
        }
        jihua += 2;
        enemy->yuansu_fu[yuansu_enemy] = false;
        shanghaimore[enemy->index_game] += 1;
    }
    else if ((yuansu == 2 && yuansu_enemy == 4) || (yuansu == 4 && yuansu_enemy == 2)) //绽放
    {
        if (enemy->hudun > 0)
        {
            enemy->hudun--;
        }
        else if (enemy->xue > 0)
        {
            enemy->xue --;
        }
        caoyuanhe += 1;
        enemy->yuansu_fu[yuansu_enemy] = false;
        shanghaimore[enemy->index_game] += 1;
    }

    if (yuansu_enemy == -1)
    {
        enemy->yuansu_fu[yuansu] = true;
    }
}