/*
** EPITECH PROJECT, 2021
** B-PSU-100-RUN-1-1-myprintf-guillyann.ferrere
** File description:
** put_str_invisible.c
*/
#include <unistd.h>
#include "../../include/my_printf.h"

void invisible(unsigned char c, int *length)
{
    char const octal[] = "01234567";

    if (c <= 7)
        my_putstr("00");
    else if (c <= 31)
        my_putstr("0");
    *length += my_put_base(c, octal);
}

int my_putstr_invisible(char const *str)
{
    int i = 0;
    int length = 0;

    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] >= 127) {
            length += my_putchar('\\');
            invisible(str[i], &length);
        } else {
            length += my_putchar(str[i]);
        }
        i++;
    }
    return (length);
}
