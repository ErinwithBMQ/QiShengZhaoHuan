//
// Created by Erin on 2024/1/26.
//

#include <character_skill.h>
#include <battle.h>

void Antant_yszj(Character *chara1, Character *chara2, Character *chara3, Character *chara)
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

void Antant_ysbf(Character *chara1, Character *chara2, Character *chara3, Character *chara)
{
    for (int i = 0; i < 4; ++i)
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
    for (int i = 0; i < 4; ++i)
    {
        if (summon_all[i]->index == 2)
        {
            summon_all[i]->turn_now = 2;
            return;
        }
    }
    *(summon_all[summon_index_we]) = Qingjing;
    summon_all[summon_index_we]->index_game = summon_index_we;
    summon_index_we++;
}

void Lingren_SpecialAddition(Character *chara)
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
    for (int i = 0; i < 4; ++i)
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
    int fadeOutTime = 800;
    int fadeInTime = 800;
    Mix_FadeOutMusic(fadeOutTime);

    music = Mix_LoadMUS("./res/music/Chicken.mp3");

    Mix_FadeInMusic(music, -1, fadeInTime);
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

void Chen_ysbf(Character *chara1, Character *chara2, Character *chara3, Character *chara)
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

void Alhaitham_yszj(Character *chara1, Character *chara2, Character *chara3, Character *chara)
{
    chara->special_state = 2;
}

void Alhaitham_ysbf(Character *chara1, Character *chara2, Character *chara3, Character *chara)
{
    if (chara->special_state == 2)
    {
        chara->special_state = 0;
    }
    else if (chara->special_state == 0)
    {
        chara->special_state = 2;
    }
}

void Alhaitham_SpecialAddition(Character *chara)
{
    chara->if_pugongfumo = true;
    chara->shanghai_more[0] += 1;
    if (chara->special_state == 1)
    {
        chara->shanghai_more[2] += 1;
    }
    else if (chara->special_state == 2)
    {
        chara->shanghai_more[2] += 2;
    }
}

void Huoxing_yszj(Character *chara1, Character *chara2, Character *chara3, Character *chara)
{
    chara->special_state = 2;
}

void Huoxing_ysbf(Character *chara1, Character *chara2, Character *chara3, Character *chara)
{
    if (chara->special_state > 0)
    {
        chara->xue += 2;
        if_showjiaxue[0] = 0;
        if_showjiaxue[1] = 2;
        if_showjiaxue[2] = 3;
        chara_toshow = chara;
        if (chara->xue > 10)
        {
            chara->xue = 10;
        }
    }
}

void Huoxing_SpecialAddition(Character *chara)
{
    chara->if_pugongfumo = true;
    chara->shanghai_more[0] += 1;
    chara->shanghai_more[2] += 3;
}

void Zihuang_yszj(Character *chara1, Character *chara2, Character *chara3, Character *chara)
{
    chara->special_state = 3;
}

void Zihuang_ysbf(Character *chara1, Character *chara2, Character *chara3, Character *chara)
{
    if (chara->special_state > 0)
    {
        int left = chara->xue - 6;
        if (left > 0)
        {
            if_showjiaxue[0] = 1;
            if_showjiaxue[1] = left;
            if_showjiaxue[2] = 3;
            chara_toshow = chara;
        }
        else if (left < 0)
        {
            if_showjiaxue[0] = 0;
            if_showjiaxue[1] = -left;
            if_showjiaxue[2] = 3;
            chara_toshow = chara;
        }
        chara->xue = 6;
    }
}

void Zihuang_SpecialAddition(Character *chara)
{
    if (chara->xue == 9 || chara->xue == 6)
    {
        chara->shanghai_more[0] += 3;
        chara->shanghai_more[1] += 3;
        chara->shanghai_more[2] += 3;
    }
}

void Shierteer_ysbf(Character *chara1, Character *chara2, Character *chara3, Character *chara)
{
    chara->xue -= 2;
    if (chara->xue <= 0)
    {
        chara->xue = 1;
    }
    chara->special_state = 3;
    chara->zhuang[1] = 1;
    if_showjiaxue[0] = 1;
    if_showjiaxue[1] = 2;
    if_showjiaxue[2] = 3;
    chara_toshow = chara;
}

void Shierteer_SpecialAddition(Character *chara)
{
    chara->if_pugongfumo = true;
    chara->shanghai_more[0] += 2;
}

void ShierteerKouXue(Character *chara4, Character *chara5, Character *chara6)
{
    if (chara4->index == 8 && chara4->special_state > 0)
    {
        chara4->xue -= 2;
        if (chara4->xue <= 0)
        {
            chara4->xue = 1;
        }
        if_showjiaxue[0] = 1;
        if_showjiaxue[1] = 2;
        if_showjiaxue[2] = 2;
        chara_toshow = chara4;
    }

    if (chara5->index == 8 && chara5->special_state > 0)
    {
        chara5->xue -= 2;
        if (chara5->xue <= 0)
        {
            chara5->xue = 1;
        }
        if_showjiaxue[0] = 1;
        if_showjiaxue[1] = 2;
        if_showjiaxue[2] = 2;
        chara_toshow = chara5;
    }

    if (chara6->index == 8 && chara6->special_state > 0)
    {
        chara6->xue -= 2;
        if (chara6->xue <= 0)
        {
            chara6->xue = 1;
        }
        if_showjiaxue[0] = 1;
        if_showjiaxue[1] = 2;
        if_showjiaxue[2] = 2;
        chara_toshow = chara6;
    }

}

void Ren_yszj(Character *chara1, Character *chara2, Character *chara3, Character *chara)
{
    chara->special_state = 2;
}

void Ren_ysbf(Character *chara1, Character *chara2, Character *chara3, Character *chara)
{
    int left = chara->xue - 5;
    if (left > 0)
    {
        if_showjiaxue[0] = 1;
        if_showjiaxue[1] = left;
        if_showjiaxue[2] = 3;
        chara_toshow = chara;
    }
    else if (left < 0)
    {
        if_showjiaxue[0] = 0;
        if_showjiaxue[1] = -left;
        if_showjiaxue[2] = 3;
        chara_toshow = chara;
    }

    chara->xue = 5;
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

void Ren_SpecialAddition(Character *chara)
{
    chara->if_pugongfumo = true;
    chara->shanghai_more[0] += 1;
}

void RenPuHuiXue(Character *chara)
{
    if (chara->index == 9)
    {
        if (chara->special_state > 0)
        {
            if (chara->xue < 10)
            {
                chara->xue++;
                if_showjiaxue[0] = 0;
                if_showjiaxue[1] = 1;
                if_showjiaxue[2] = 3;
                chara_toshow = chara;
            }
        }
    }
}

void Kafuka_yszj(Character *chara1, Character *chara2, Character *chara3, Character *chara)
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

void Kafuka_ysbf(Character *chara1, Character *chara2, Character *chara3, Character *chara)
{
    for (int i = 0; i < 4; ++i)
    {
        if (summon_all[i]->index == 5)
        {
            summon_all[i]->turn_now = 2;
            return;
        }
    }
    *(summon_all[summon_index_we]) = Zhuwang;
    summon_all[summon_index_we]->index_game = summon_index_we;
    summon_index_we++;
}

void Kelai_ysbf(Character *chara1, Character *chara2, Character *chara3, Character *chara)
{
    for (int i = 0; i < 4; ++i)
    {
        if (summon_all[i]->index == 6)
        {
            summon_all[i]->turn_now = 2;
            return;
        }
    }
    *(summon_all[summon_index_we]) = Kelianba;
    summon_all[summon_index_we]->index_game = summon_index_we;
    summon_index_we++;
}

void Tewalin_yszj(Character *chara1, Character *chara2, Character *chara3, Character *chara)
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

void Tewalin_ysbf(Character *chara1, Character *chara2, Character *chara3, Character *chara)
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

void Hai_yszj(Character *chara1, Character *chara2, Character *chara3, Character *chara)
{
    chara->special_state = 3;
}

void Hai_SpecialAddition(Character *chara)
{
    chara->if_pugongfumo = true;
    chara->shanghai_more[0] += 1;
}

void Leichui_yszj(Character *chara1, Character *chara2, Character *chara3, Character *chara)
{
    chara->special_state = 2;
}

void Leichui_ysbf(Character *chara1, Character *chara2, Character *chara3, Character *chara)
{
    chara->hudun += 3;
    if_showhudun = 2;
}

void Leichui_SpecialAddition(Character *chara)
{
    chara->if_pugongfumo = true;
    chara->shanghai_more[0] += 1;
}

void Mudun_yszj(Character *chara1, Character *chara2, Character *chara3, Character *chara)
{
    chara->hudun += 2;
    if_showhudun = 2;
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
    if (chara->index == 4)
    {
        if (chara->xue == 9 || chara->xue == 6)
        {
            if (chara->special_state > 0 && chara->huiorcount == 3)
            {
                chara->special_state--;
            }
        }
        return;
    }

    if (chara->special_state > 0 && chara->huiorcount == 3)
    {
        chara->special_state--;
    }
}