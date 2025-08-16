/*
** EPITECH PROJECT, 2021
** B-PSU-101-RUN-1-1-minishell1-guillyann.ferrere
** File description:
** strtok.c
*/

#include "include/minishell.h"
#include "include/builtin.h"
#include "include/my_printf.h"
#include <stdbool.h>

int count_word(char *str, char c)
{
    int count = 1;

    if (str == NULL)
        return -1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0')
            count++;
    }
    return (count);
}

void remove_n_char(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            str[i] = '\0';
    }
}

char **strtok_split_on_space(char *str)
{
    int count = 0;
    char **array = NULL;
    int i = 1;

    count = count_word(str, ' ');
    if (count == -1)
        return NULL;
    array = malloc(sizeof(char *) * (count + 1));
    remove_n_char(str);
    array[0] = strtok(str, " \t");
    for (; i < (count + 1); i++)
        array[i] = strtok(NULL, " \t");
    return (array);
}

char **strtok_split_on_colon(char *str)
{
    int count = 0;
    char **array = 0;
    int i = 1;

    if (str == NULL)
        return NULL;
    count = count_word(str, ':');
    if (count == -1)
        return NULL;
    array = malloc(sizeof(char *) * (count + 1));
    remove_n_char(str);
    array[0] = my_strdup(strtok(str, ":"));
    for (; i < (count + 1); i++)
        array[i] = my_strdup(strtok(NULL, ":"));
    return (array);
}

char **strtok_split_on_equal(char *str)
{
    int count = 0;
    char **array = NULL;
    int i = 1;

    count = count_word(str, '=');
    array = malloc(sizeof(char *) * (count + 1));
    remove_n_char(str);
    array[0] = my_strdup(strtok(str, "="));
    for (; i < (count + 1); i++)
        array[i] = my_strdup(strtok(NULL, "="));
    return (array);
}
