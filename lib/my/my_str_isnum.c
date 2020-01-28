/*
** EPITECH PROJECT, 2019
** my_str_isnum.c
** File description:
** task13
*/

int my_str_isnum(char const *str)
{
    if (str[0] == '\0')
        return (1);
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] >= 48 && str[i] <= 57))
            return (0);
    }
    return (1);
}
