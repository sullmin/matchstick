/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** matchstick
*/

#include <unistd.h>
#include "my.h"
#include "matchstick.h"

void display_player_text(int *my_stick, int line, int stick)
{
    erase();
    rm_stick(my_stick, line, stick);
    printw("Player removed ");
    display_nbr(stick);
    printw(" match(es) from line ");
    display_nbr(line);
    printw("\n");
    refresh();
    sleep(2);
}

int exit_error_matches(int nb_max, int stick, int v_line)
{
    erase();
    if (stick > nb_max) {
        printw("Error: you cannot remove more than ");
        display_nbr(nb_max);
        printw(" matches per turn\n");
    }
    if (stick == 0)
        printw("Error: you have to remove at least one match\n");
    if (stick < 0)
        printw("Error: invalid input (positive number expected)\n");
    if (stick > v_line)
        printw("Error: not enough matches on this line\n");
    refresh();
    sleep(2);
    return 84;
}

int exit_error_line(int line)
{
    erase();
    if (line < 0) {
        printw("Error: invalid input (positive number expected)\n");
        refresh();
        sleep(2);
        return 84;
    }
    printw("Error: this line is out of range\n");
    refresh();
    sleep(2);
    return 84;
}