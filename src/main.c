/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** matchstick
*/

#include <time.h>
#include <stdlib.h>
#include "matchstick.h"
#include "my.h"

static void free_all(char **map, int *my_stick)
{
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
    free(my_stick);
}

static int game_init(int size, int max_nb)
{
    int end;
    int *my_stick = get_my_stick(size);
    char **map = get_map(size);

    if (!map || !my_stick)
        return 84;
    end = game_loop(map, my_stick, max_nb);
    free_all(map, my_stick);
    return end;
}

int main(int ac, char **av)
{
    int max_nb;
    int end;
    int size;

    srand(time(NULL));
    if (ac != 3)
        return 84;
    size = my_getnbr(av[1]);
    max_nb = my_getnbr(av[2]);
    if (size <= 1 || max_nb <= 0 || size >= 100)
        return 84;
    end = game_init(size, max_nb);
    if (end == -1)
        return 0;
    if (end == 1)
        my_putstr("I lost... snif... but I'll get you next time!!\n");
    if (end == 2)
        my_putstr("You lost, too bad...\n");
    return end;
}