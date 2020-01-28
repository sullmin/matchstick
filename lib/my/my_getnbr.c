/*
** EPITECH PROJECT, 2019
** my_getnbr.c
** File description:
** task05
*/

static int my_strlen3(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int my_getnbr(char const *str)
{
    int m = 1;
    int value = 0;
    int taille = my_strlen3(str) - 1;

    for (int v = taille; v >= 0; v--) {
        if (str[v] >= 48 && str[v] <= 57) {
            value = value + (str[v] - 48) * m;
            m = m * 10;
        }
        if (str[v] == '-' && value > 0)
            value = -value;
        if (str[v] >= 97 && str[v] <= 122) {
            value = 0;
            m = 1;
        }
    }
    if (m >= 10000000000)
        return (0);
    return (value);
}
