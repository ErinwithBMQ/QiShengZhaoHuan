//
// Created by Erin on 2024/1/26.
//

#include <character_skill.h>

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
