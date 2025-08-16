/*
** EPITECH PROJECT, 2021
** write strlen digits
** File description:
** task03
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int a = 0;

    if (str == NULL)
        return 0;
    while (str[a] != '\0') {
        a = a + 1;
    }
    return (a);
}
