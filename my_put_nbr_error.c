/*
** EPITECH PROJECT, 2021
** compter nombre ecrire
** File description:
** task07 day03
*/

#include "include/minishell.h"
#include "include/builtin.h"

void my_putchar_error(char c)
{
    write(2, &c, 1);
}

int my_put_nbr_error(int nb)
{
    int n = 1;

    if (nb < 0) {
        my_putchar_error('-');
        nb = nb * -1;
    }
    if (nb < 10 && nb >= 0) {
        my_putchar_error(nb + 48);
        return (0);
    }
    while (nb / n != 0)
        n = n * 10;
    n = n / 10;
    while (n > 0) {
        my_putchar_error((nb / n) + 48);
        nb = nb % n;
        n = n / 10;
    }
    return (0);
}
