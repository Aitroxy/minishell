/*
** EPITECH PROJECT, 2021
** B-PSU-100-RUN-1-1-myprintf-guillyann.ferrere
** File description:
** my_put_hex.c
*/
#include "../../include/my_printf.h"
#include <stdlib.h>

int my_put_base(unsigned long long int nb, char const *base)
{
    int i = 0;
    int res = 0;
    int len = my_strlen(base);
    char malloc_res[65] = {0};

    if (nb == 0)
        malloc_res[i] = '0';
    for (; nb > 0; i++) {
        res = nb % len;
        nb = nb / len;
        malloc_res[i] = base[res];
    }
    my_revstr(malloc_res);
    return (my_putstr(malloc_res));
}
