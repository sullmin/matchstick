/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** matchstick
*/

#include <stdlib.h>
#include "matchstick.h"
#include "my.h"

static int grundy(int *my_stick)
{
    int val = 0;

    for (int i = 1; my_stick[i] != -1; i++)
        val = val ^ my_stick[i];
    return val;
}

static void error_gest_no_value(int *my_stick, int max_nb, int *line, int *nb)
{
    for (int i = 1; my_stick[i] != -1 && *nb == -1 && *line == -1; i++) {
        if (my_stick[i] <= max_nb && my_stick[i] != 0) {
            *line = i;
            *nb = my_stick[i];
        }
        else if (my_stick[i] > max_nb && my_stick[i] != 0) {
            *line = i;
            *nb = max_nb;
        }
    }
}

static int how_play(int *my_stick, int max_nb, int *line, int *nb, int val)
{
    int grundy_val;

    for (int i = val; my_stick[i] != -1 && *nb == -1 && *line == -1; i++) {
        for (int u = 1; u <= my_stick[i] && u <= max_nb; u++) {
            my_stick[i] -= u;
            grundy_val = grundy(my_stick);
            my_stick[i] += u;
            if (grundy_val == 1) {
                *line = i;
                *nb = u;
                return i;
            }
        }
    }
    return 0;
}

static int who_win(int *my_stick, int max_nb)
{
    while (end_gest(my_stick) == 0) {
        ai_for_ia(my_stick, max_nb);
        if (end_gest(my_stick) != 0)
            return 2;
        ai_for_ia(my_stick, max_nb);
    }
    return 1;
}

static int *my_int_dup(int *tab)
{
    int *ret;
    int size;

    for (size = 0; tab[size] != -1; size++);
    ret = malloc(sizeof(int) * (size + 1));
    if (!ret)
        return NULL;
    for (size = 0; tab[size] != -1; size++)
        ret[size] = tab[size];
    ret[size] = -1;
    return ret;
}

void ai_played(int *my_stick, int max_nb)
{
    int stat = 2;
    int temp = 1;
    int line = -1;
    int nb = -1;
    int *tab;

    while (stat == 2 && my_stick[temp] != -1) {
        tab = my_int_dup(my_stick);
        temp = how_play(tab, max_nb, &line, &nb, temp);
        if (nb == -1 || line == -1)
            error_gest_no_value(tab, max_nb, &line, &nb);
        rm_stick(tab, line, nb);
        stat = who_win(tab, max_nb);
        free(tab);
        if (temp == 0)
            stat = -2;
    }
    if (my_stick[temp] == -1 || stat == -2)
        error_gest_no_value(my_stick, max_nb, &line, &nb);

    my_putstr("\nAI's turn...\n");
    my_putstr("AI removed ");
    my_put_nbr(nb);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
    rm_stick(my_stick, line, nb);
}