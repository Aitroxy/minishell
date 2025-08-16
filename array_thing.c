/*
** EPITECH PROJECT, 2021
** B-PSU-101-RUN-1-1-minishell1-guillyann.ferrere
** File description:
** tab_add.c
*/

#include "include/builtin.h"
#include "include/minishell.h"
#include <string.h>

int check_array(char **env)
{
    int compt = 0;

    for (int i = 0; env[i] != NULL; i++)
        compt++;
    return (compt);
}

int check_arg(char **array)
{
    int compt = 0;

    for (int i = 0; array[i] != NULL; i++) {
        compt++;
    }
    return (compt);
}

int check_env_exist(char **env, char *arg)
{
    int index = 0;

    if (env == NULL)
        return (-2);
    if (arg == NULL)
        return (-2);
    for (; env[index] != NULL; index++) {
        if (my_strncmp(env[index], arg, my_strlen(arg)) == 0) {
            return (index);
        }
    }
    return (-1);
}

char **replace_env(char **env, char *arg, int index)
{
    int i = 0;

    if (env == NULL)
        return NULL;
    for (; env[i] != NULL; i++) {
        if (i == index) {
            env[i] = my_strdup(arg);
            continue;
        }
    }
    return (env);
}

char **array_add(char **env, char *arg)
{
    char **cpy_env = NULL;
    int i = 0;

    cpy_env = malloc(sizeof(char *) * (check_array(env) + 2));
    for (; env[i] != NULL; i++)
        cpy_env[i] = my_strdup(env[i]);
    cpy_env[i] = my_strdup(arg);
    cpy_env[i + 1] = NULL;
    free_array(env);
    return (cpy_env);
}
