/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** matchstick
*/

#include <stdlib.h>
#include "my.h"

static void my_clear_map(char **map)
{
    for (int i = 1; map[i + 1] != NULL; i++) {
        for (int u = 1; map[i][u + 2] != '\0'; u++) {
            map[i][u] = ' ';
        }
    }
}

void my_stick_put(char **map, int *my_stick)
{
    int cnt = 0;
    int size = my_strlen(map[0]) - 2;

    my_clear_map(map);
    for (int i = 1; map[i + 1] != NULL; i++) {
        for (int u = 1; map[i][u + 2] != '\0'; u++) {
            if (u > size / 2 - 1 && cnt < my_stick[i]) {
                map[i][u] = '|';
                cnt++;
            }
        }
        cnt = 0;
        size -= 2;
    }
}