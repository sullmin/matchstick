/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** matchstick
*/

#include <stdlib.h>
#include <stdbool.h>
#include "my.h"
#include "matchstick.h"

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

static void how_play(int *my_stick, int max_nb, int *line, int *nb)
{
    int grundy_val;

    for (int i = 1; my_stick[i] != -1 && *nb == -1 && *line == -1; i++) {
        for (int u = 1; u <= my_stick[i] && u <= max_nb; u++) {
            my_stick[i] -= u;
            grundy_val = grundy(my_stick);
            my_stick[i] += u;
            if (grundy_val == 1) {
                *line = i;
                *nb = u;
                break;
            }
        }
    }
}

void ai_for_ia(int *my_stick, int max_nb)
{
    int nb = -1;
    int line = -1;

    //my_putstr("\nAI's turn...\n");
    how_play(my_stick, max_nb, &line, &nb);
    if (nb == -1 || line == -1)
        error_gest_no_value(my_stick, max_nb, &line, &nb);
    //my_putstr("AI removed ");
    //my_put_nbr(nb);
    //my_putstr(" match(es) from line ");
    //my_put_nbr(line);
    //my_putchar('\n');
    rm_stick(my_stick, line, nb);
}