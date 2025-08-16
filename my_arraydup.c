/*
** EPITECH PROJECT, 2021
** B-PSU-101-RUN-1-1-minishell1-guillyann.ferrere
** File description:
** my_arraydup.c
*/

#include "include/minishell.h"

char **my_arraydup(char **env)
{
    char **array = NULL;
    int i = 0;

    if (env == NULL)
        return NULL;
    array = malloc(sizeof(char *) * (array_len(env) + 1));
    for (; env[i] != NULL; i++) {
        array[i] = my_strdup(env[i]);
    }
    array[i] = NULL;
    return (array);
}
