/*
** EPITECH PROJECT, 2021
** allocates memory copies string
** File description:
** task01
*/

#include <unistd.h>
#include <stdlib.h>
#include "include/my_printf.h"
#include "include/minishell.h"

char *my_strdup(char const *src)
{
    char *str = NULL;

    if (src == NULL)
        return (NULL);
    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    my_strcpy(str, src);
    return (str);
}
