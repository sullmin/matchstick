/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** task07
*/

#include "my.h"

int my_put_nbr(int nb)
{
    long int i = 1;

    if (nb == -2147483648)
        my_putstr("-2147483648");
    else {
        if (nb < 0) {
            my_putchar('-');
            nb = -nb;
        }
        if (nb == 0)
            my_putchar(48);
        for (int p; nb >= i; p++)
            i = i * 10;
        i = i / 10;
        while (i > 0) {
            my_putchar (nb / i % 10 + '0');
            i = i / 10;
        }
    }
    return (0);
}
