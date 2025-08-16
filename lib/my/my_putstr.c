/*
** EPITECH PROJECT, 2021
** writ one by one char
** File description:
** task02
*/
#include "../../include/my_printf.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    if (str != NULL) {
        return (write(1, str, my_strlen(str)));
    }
    return (my_putstr("(null)"));
}
