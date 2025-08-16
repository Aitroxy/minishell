/*
** EPITECH PROJECT, 2021
** B-PSU-100-RUN-1-1-myprintf-guillyann.ferrere
** File description:
** display_base_bis.c
*/
#include "../../include/my_printf.h"

int display_hex_plus(va_list ap)
{
    int stock_return;

    stock_return = my_putstr("0x");
    stock_return += my_put_base(
        va_arg(ap, unsigned long long int), "0123456789abcdef");
    return (stock_return);
}
