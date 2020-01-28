/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** matchstick
*/

#include <stdlib.h>

int *get_my_stick(int size)
{
    int val = 1;
    int *my_stick = malloc(sizeof(int) * (size + 2));

    if (!my_stick)
        return NULL;
    my_stick[0] = size;
    my_stick[size + 1] = -1;
    for (int i = 1; i <= size; i++) {
        my_stick[i] = val;
        val += 2;
    }
    return my_stick;
}

int rm_stick(int *my_stick, int line, int nb_stick)
{
    int cmp;

    if (line <= 0 || line > my_stick[0])
        return 84;
    cmp = my_stick[line] - nb_stick;
    if (cmp < 0)
        return 84;
    my_stick[line] = cmp;
    return 1;
}