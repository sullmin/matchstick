/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** matchstick
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "matchstick.h"
#include "my.h"

static char *terminal_read(const char *str)
{
    char *line = NULL;
    size_t size;
    int read_val;

    my_putstr(str);
    read_val = getline(&line, &size, stdin);
    if (read_val <= 0 || !line)
        return NULL;
    if (line[read_val - 1] == '\n')
        line[read_val - 1] = '\0';
    else line[read_val] = '\0';
    return line;
}

static int matches_gest(int *my_stick, int max_nb, int line)
{
    int stick;
    char *temp;

    temp = terminal_read("Matches: ");
    if (!temp)
        return 48;
    if (my_str_isnum(temp) == 0)
        return exit_error_matches(max_nb, -1, my_stick[line]);
    stick = my_getnbr(temp);
    free(temp);
    if (stick <= 0 || stick > my_stick[line] || stick > max_nb)
        return exit_error_matches(max_nb, stick, my_stick[line]);
    display_player_text(my_stick, line, stick);
    return 0;
}

static int stick_gest(int *my_stick, int max_nb)
{
    int line;
    char *temp;

    temp = terminal_read("Line: ");
    if (!temp)
        return 48;
    line = my_getnbr(temp);
    if (my_str_isnum(temp) == 0)
        return exit_error_line(-1);
    free(temp);
    if (line <= 0 || line > my_stick[0] + 1)
        return exit_error_line(line);
    return matches_gest(my_stick, max_nb, line);
}

static void display_map(char **map, int *my_stick)
{
    my_stick_put(map, my_stick);
    for (int i = 0; map[i] != NULL; i++) {
        my_putstr(map[i]);
        my_putchar('\n');
    }
}

int game_loop(char **map, int *my_stick, int max_nb)
{
    int ret = 84;

    display_map(map, my_stick);
    while (end_gest(my_stick) == 0) {
        my_putstr("\nYour turn:\n");
        while (ret == 84) {
            ret = stick_gest(my_stick, max_nb);
            if (ret == 48)
                return -1;
        }
        ret = 84;
        display_map(map, my_stick);
        if (end_gest(my_stick) != 0)
            return 2;
        ai_played(my_stick, max_nb);
        display_map(map, my_stick);
    }
    return 1;
}