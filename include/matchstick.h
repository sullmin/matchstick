/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** task02
*/

#ifndef MATCHSTICK_H
#define MATCHSTICK_H

#include <curses.h>

char **get_map(int size_y);
int *get_my_stick(int size);
void my_stick_put(char **map, int *my_stick);
int rm_stick(int *my_stick, int line, int nb_stick);
int end_gest(int *my_stick);
int game_loop(char **map, int *my_stick, int max_nb);
void ai_played(int *my_stick, int max_nb);
void display_player_text(int *my_stick, int line, int stick);
int exit_error_matches(int nb_max, int stick, int v_line);
int exit_error_line(int line);
char *myrevgetnbr(int nb);
void display_nbr(int nb);

#endif