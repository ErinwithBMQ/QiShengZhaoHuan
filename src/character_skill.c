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

void Lingren_yszj(Character *chara1, Character *chara2, Character *chara3, Character *chara)
{
    chara->special_state = 3;
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

void Lingren_SpecialAdditon(Character *chara)
{
    chara->if_pugongfumo = true;
    chara->shanghai_more[0] += 1;
}

void QingliuSkill(Character *chara4, Character *chara5, Character *chara6)
{
    for (int i = 0; i <= summon_index_we; ++i)
    {
        if (summon_all[i]->index == 2)
        {
            chara4->shanghai_more[0] += 1;
            chara5->shanghai_more[0] += 1;
            chara6->shanghai_more[0] += 1;
        }
    }
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

void CXK_ysbf(Character *chara1, Character *chara2, Character *chara3, Character *chara)
{
    Mix_HaltMusic();
    music = Mix_LoadMUS("./res/music/Chicken.mp3");
    Mix_PlayMusic(music, 20);
}

void CXK_SpecialAddition(Character *chara)
{
    for (int i = 0; i <= summon_index_we; ++i)
    {
        if (summon_all[i]->index == 3)
        {
            chara->shanghai_more[2] += 2;
        }
    }
}

void Chen_yszj(Character *chara1, Character *chara2, Character *chara3, Character *chara)
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

void Chen_ysbf(Character *chara1, Character *chara2, Character *chara3, Character *chara)
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

void Alhaitham_yszj(Character *chara1, Character *chara2, Character *chara3, Character *chara)
{
    chara->special_state = 2;
}

void Alhaitham_ysbf(Character *chara1, Character *chara2, Character *chara3, Character *chara)
{
    if (chara->special_state > 0)
    {
        chara->special_state = 0;
    }
    else
    {
        chara->special_state = 2;
    }
}

void Alhaitham_SpecialAdditon(Character *chara)
{
    chara->if_pugongfumo = true;
    chara->shanghai_more[0] += 1;
    chara->shanghai_more[2] += 2;
}

void SpecialAdditionReduceTurn(Character *chara4, Character *chara5, Character *chara6)
{
    if (chara4->special_state > 0 && chara4->huiorcount == 1)
    {
        chara4->special_state--;
    }
    if (chara5->special_state > 0 && chara5->huiorcount == 1)
    {
        chara5->special_state--;
    }
    if (chara6->special_state > 0 && chara6->huiorcount == 1)
    {
        chara6->special_state--;
    }
}

void SpecialAdditionReduceCountPu(Character *chara)
{
    if (chara->special_state > 0 && chara->huiorcount == 2)
    {
        chara->special_state--;
    }
}

void SpecialAdditionReduceCountAll(Character *chara)
{
    if (chara->special_state > 0 && chara->huiorcount == 3)
    {
        chara->special_state--;
    }
}