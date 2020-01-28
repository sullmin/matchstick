/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** matchstick
*/

#include <time.h>
#include <stdlib.h>
#include <unistd.h>
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

static void init(void)
{
    WINDOW *my_w = initscr();

    keypad(stdscr, TRUE);
    cbreak();
    nodelay(my_w, TRUE);
    curs_set(0);
}

static bool menu_gest(int *size, int *max_nb, bool *pos, int ch)
{
    (*pos) = ((*pos) && ch == KEY_RIGHT) ? false : (*pos);
    (*pos) = (!(*pos) && ch == KEY_LEFT) ? true : (*pos);
    if (ch == KEY_DOWN && (*pos)) {
        (*size)++;
        return true;
    }
    if (ch == KEY_UP && (*size) > 0 && (*pos)) {
        (*size)--;
        return true;
    }
    if (ch == KEY_DOWN && !(*pos)) {
        (*max_nb)++;
        return true;
    }
    if (ch == KEY_UP && (*max_nb) > 0 && !(*pos)) {
        (*max_nb)--;
        return true;
    }
    return false;
}

static void menu_init(int *size, int *max_nb)
{
    bool pos = true;
    bool stat = true;
    int ch = 0;
    char *temp;

    while (ch != 32) {
        ch = getch();
        if (stat) {
            erase();
            printw("size : ");
            temp = myrevgetnbr(*size);
            printw(temp);
            free(temp);
            printw("                    max stick : ");
            temp = myrevgetnbr(*max_nb);
            printw(temp);
            free(temp);
            refresh();
        }
        stat = menu_gest(size, max_nb, &pos, ch);
    }
}

static void you_lose(void)
{
    char *tab[] =  {"@@@ @@@   @@@@@@   @@@  @@@     @@@        @@@@@@    @@@@@@   @@@@@@@@\n",
                    "@@@ @@@  @@@@@@@@  @@@  @@@     @@@       @@@@@@@@  @@@@@@@   @@@@@@@@\n",
                    "@@! !@@  @@!  @@@  @@!  @@@     @@!       @@!  @@@  !@@       @@!     \n",
                    "!@! @!!  !@!  @!@  !@!  @!@     !@!       !@!  @!@  !@!       !@!     \n",
                    " !@!@!   @!@  !@!  @!@  !@!     @!!       @!@  !@!  !!@@!!    @!!!:!  \n",
                    "  @!!!   !@!  !!!  !@!  !!!     !!!       !@!  !!!   !!@!!!   !!!!!:  \n",
                    "  !!:    !!:  !!!  !!:  !!!     !!:       !!:  !!!       !:!  !!:     \n",
                    "  :!:    :!:  !:!  :!:  !:!      :!:      :!:  !:!      !:!   :!:     \n",
                    "  ::    ::::: ::  ::::: ::      :: ::::  ::::: ::  :::: ::    :: :::: \n",
                    "   :      : :  :    : :  :      : :: : :   : :  :   :: : :    : :: :: \n",
                    NULL };

    erase();
    for (int i = 0; tab[i]; i++)
        mvprintw(LINES / 2 - 5 + i, COLS / 2 - 35, tab[i]);
    refresh();
    sleep(3);

}

static void you_win(void)
{
    char *tab[] =  {"  ___    ___ ________  ___  ___          ___       __   ___  ________\n",
                    " |\\  \\  /  /|\\   __  \\|\\  \\|\\  \\        |\\  \\     |\\  \\|\\  \\|\\   ___  \\    \n",
                    " \\ \\  \\/  / | \\  \\|\\  \\ \\  \\\\\\  \\       \\ \\  \\    \\ \\  \\ \\  \\ \\  \\\\ \\  \\   \n",
                    "  \\ \\    / / \\ \\  \\\\\\  \\ \\  \\\\\\  \\       \\ \\  \\  __\\ \\  \\ \\  \\ \\  \\\\ \\  \\  \n",
                    "   \\/  /  /   \\ \\  \\\\\\  \\ \\  \\\\\\  \\       \\ \\  \\|\\__\\_\\  \\ \\  \\ \\  \\\\ \\  \\ \n",
                    " __/  / /      \\ \\_______\\ \\_______\\       \\ \\____________\\ \\__\\ \\__\\\\ \\__\\\n",
                    "|\\___/ /        \\|_______|\\|_______|        \\|____________|\\|__|\\|__| \\|__|\n",
                    "\\|___|/                                                                    \n",
                    NULL };
                                                                           
            

    erase();
    for (int i = 0; tab[i]; i++)
        mvprintw(LINES / 2 - 4 + i, COLS / 2 - 35, tab[i]);
    refresh();
    sleep(3);

}

int game(void)
{
    int max_nb = 0;
    int end = 2;
    int size = 0;

    menu_init(&size, &max_nb);
    if (size <= 1 || max_nb <= 0 || size >= 100) {
        endwin();
        return 84;
    }
    end = game_init(size, max_nb);
    if (end == 2)
        you_lose();
    if (end == 1)
        you_win();
    return end;
}

static bool restart_or_no(void)
{
    bool choice = true;
    int ch = 0;

    erase();
    while (ch != 32) {
        ch = getch();
        if (ch == KEY_DOWN || ch == KEY_UP)
            choice = (choice) ? false : true;
        if (choice)
            mvprintw(LINES / 2, COLS / 2 - 2, "PLAY");
        else mvprintw(LINES / 2, COLS / 2 - 2, "EXIT");
    }
    return choice;
}

int main(int ac, __attribute__((unused))char **av)
{
    int end = 0;

    if (ac != 1)
        return 84;
    init();
    while (restart_or_no())
        end = game();
    endwin();
    return end;
}