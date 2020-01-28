/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** matchstick
*/

int end_gest(int *my_stick)
{
    for (int i = 1; my_stick[i] != -1; i++)
        if (my_stick[i] != 0)
            return 0;
    return 1;
}