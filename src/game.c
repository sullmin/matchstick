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
#include <curses.h>
#include "matchstick.h"
#include "my.h"

static void color_init(void)
{
    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_GREEN);
    init_pair(2, COLOR_CYAN, COLOR_BLUE);
    init_pair(3, COLOR_BLACK, COLOR_WHITE);
}

static void display_map(char **map, int *my_stick)
{
    my_stick_put(map, my_stick);
    erase();
    for (int i = 0; map[i] != NULL; i++)
        for (int u = 0; map[i][u] != '\0'; u++) {
            if (map[i][u] == '*')
                attron(COLOR_PAIR(3));
            if (map[i][u] == ' ')
                attron(COLOR_PAIR(1));
            if (map[i][u] == '|')
                attron(COLOR_PAIR(2));
            addch(map[i][u]);
            if (map[i][u] == '*')
                attroff(COLOR_PAIR(3));
            if (map[i][u] == ' ')
                attroff(COLOR_PAIR(1));
            if (map[i][u] == '|')
                attroff(COLOR_PAIR(2));
        }
    refresh();
}

static int terminal_read(const char *str, char **map, int *my_stick, int max_nb)
{
    bool stat = true;
    int move = 0;
    int ch = 0;
    char *temp;

    while (ch != 32) {
        ch = getch();
        if (ch == KEY_UP && move > 0) {
            move--;
            stat = true;
        }
        if (ch == KEY_DOWN && (move < my_stick[0] || move < max_nb)) {
            move++;
            stat = true;
        }
        if (stat) {
            display_map(map, my_stick);
            printw(str);
            temp = myrevgetnbr(move);
            printw(temp);
            free(temp);
            refresh();
        }
        stat = false;
    }
    return move;
}

static int matches_gest(int *my_stick, int max_nb, int line, char **map)
{
    int stick;

    stick = terminal_read("Matches: ", map, my_stick, max_nb);
    if (stick <= 0 || stick > my_stick[line] || stick > max_nb)
        return exit_error_matches(max_nb, stick, my_stick[line]);
    display_player_text(my_stick, line, stick);
    return 0;
}

static int stick_gest(int *my_stick, int max_nb, char **map)
{
    int line;

    line = terminal_read("Line: ", map, my_stick, max_nb);
    if (line <= 0 || line > my_stick[0] + 1)
        return exit_error_line(line);
    return matches_gest(my_stick, max_nb, line, map);
}

int game_loop(char **map, int *my_stick, int max_nb)
{
    int ret = 84;

    color_init();
    while (end_gest(my_stick) == 0) {
        erase();
        printw("\nYour turn:\n");
        refresh();
        sleep(2);
        while (ret == 84) {
            ret = stick_gest(my_stick, max_nb, map);
            if (ret == 48)
                return -1;
        }
        ret = 84;
        display_map(map, my_stick);
        if (end_gest(my_stick) != 0)
            return 2;
        ai_played(my_stick, max_nb);
        refresh();
        sleep(4);
        display_map(map, my_stick);
    }
    return 1;
}