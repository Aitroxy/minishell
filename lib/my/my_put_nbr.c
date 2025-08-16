/*
** EPITECH PROJECT, 2021
** compter nombre ecrire
** File description:
** task07 day03
*/
#include "../../include/my_printf.h"

void my_put_nbr_sign(int *length, int *nb)
{
    if (*nb < 0) {
        *length += my_putchar('-');
        *nb = *nb * -1;
    }
}

int my_put_nbr(int nb)
{
    int n = 1;
    int length = 0;

    my_put_nbr_sign(&length, &nb);
    if (nb < 10) {
        length += my_putchar(nb + 48);
        return (0);
    }
    while (nb / n != 0)
        n = n * 10;
    n = n / 10;
    while (n > 0) {
        length += my_putchar((nb / n) + 48);
        nb = nb % n;
        n = n / 10;
    }
    return (length);
}
