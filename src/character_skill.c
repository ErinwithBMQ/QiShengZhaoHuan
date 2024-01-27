//
// Created by Erin on 2024/1/26.
//

#include <character_skill.h>

void Antant_yszj(Character *chara1, Character *chara2, Character *chara3, Character *chara)
{
    if_all_attack = true;
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

void Antant_ysbf(Character *chara1, Character *chara2, Character *chara3, Character *chara)
{
    for (int i = 0; i < 3; ++i)
    {
        if (summon_all[i]->index == 1)
        {
            summon_all[i]->turn_now = 3;
            return;
        }
    }
    *(summon_all[summon_index_we]) = Zhujiao;
    summon_all[summon_index_we]->index_game = summon_index_we;
    summon_index_we++;
}

void Lingren_ysbf(Character *chara1, Character *chara2, Character *chara3, Character *chara)
{
    for (int i = 0; i < 3; ++i)
    {
        if (summon_all[i]->index == 2)
        {
            summon_all[i]->turn_now = 3;
            return;
        }
    }
    *(summon_all[summon_index_we]) = Qingjing;
    summon_all[summon_index_we]->index_game = summon_index_we;
    summon_index_we++;
}

void CXK_yszj(Character *chara1, Character *chara2, Character *chara3, Character *chara)
{
    for (int i = 0; i < 3; ++i)
    {
        if (summon_all[i]->index == 3)
        {
            summon_all[i]->turn_now = 3;
            return;
        }
    }

    *(summon_all[summon_index_we]) = Lanqiu;
    summon_all[summon_index_we]->index_game = summon_index_we;
    summon_index_we++;
}