/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** matchstick
*/

#include <stdlib.h>

static void map_filler(char **tab, int size_x, int size_y)
{
    for (int i = 0; i < size_y + 2; i++) {
        for (int u = 0; u < size_x + 2; u++) {
            if (i == 0 || i == size_y + 1)
                tab[i][u] = '*';
            else if (u == 0 || u == size_x + 1)
                tab[i][u] = '*';
            else tab[i][u] = ' ';
        }
    }
}

char **get_map(int size_y)
{
    int size_x = 1;
    char **tab = malloc(sizeof(char *) * (size_y + 3));

    if (!tab)
        return NULL;
    tab[size_y + 2] = NULL;
    for (int i = 1; i < size_y; i++)
        size_x += 2;
    for (int i = 0; i < size_y + 2; i++) {
        tab[i] = malloc(sizeof(char) * (size_x + 3));
        if (!tab[i])
            return NULL;
        tab[i][size_x + 2] = '\0';
    }
    map_filler(tab, size_x, size_y);
    return tab;
}