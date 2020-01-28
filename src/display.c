/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** matchstick
*/

#include "my.h"
#include "matchstick.h"

void display_player_text(int *my_stick, int line, int stick)
{
    rm_stick(my_stick, line, stick);
    my_putstr("Player removed ");
    my_put_nbr(stick);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}

int exit_error_matches(int nb_max, int stick, int v_line)
{
    if (stick > nb_max) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(nb_max);
        my_putstr(" matches per turn\n");
    }
    if (stick == 0)
        my_putstr("Error: you have to remove at least one match\n");
    if (stick < 0)
        my_putstr("Error: invalid input (positive number expected)\n");
    if (stick > v_line)
        my_putstr("Error: not enough matches on this line\n");
    return 84;
}

int exit_error_line(int line)
{
    if (line < 0) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return 84;
    }
    my_putstr("Error: this line is out of range\n");
    return 84;
}