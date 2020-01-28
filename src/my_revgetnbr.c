/*
** EPITECH PROJECT, 2019
** my_getnbr.C rev
** File description:
** int to char
*/

#include <stdlib.h>

static int calc(int nb)
{
    int i;

    for (i = 0; nb > 0; i++)
        nb /= 10;
    return i + 2;
}

char *myrevgetnbr(int nb)
{
    int i = 1;
    int u = 0;
    char *tab = malloc(sizeof(char) * calc(nb));

    if (!tab)
        return NULL;
    (nb < 0) ? tab[u] = '-', nb = -nb, u++ : nb;
    if (nb == 0)
        tab[u] = 48;
    for (int p; nb >= i; p++)
        i = i * 10;
    i = i / 10;
    for (i = i; i > 0; u++) {
        tab[u] = (nb / i % 10 + '0');
        tab[u + 1] = '\0';
        i = i / 10;
    }
    tab[u + 1] = '\0';
    return (tab);
}