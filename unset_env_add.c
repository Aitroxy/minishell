/*
** EPITECH PROJECT, 2021
** B-PSU-101-RUN-1-1-minishell1-guillyann.ferrere
** File description:
** unset_env_add.c
*/

#include "include/minishell.h"
#include "include/builtin.h"

void loop_unset(char **env, char *arg, int j, int compt)
{
    for (j = 0; env[j] != NULL; j++) {
        if (my_strncmp(env[j], arg, my_strlen(arg)) == 0)
            compt++;
    }
}

int check_unset(char **env, char **arg)
{
    int i = 0;
    int compt = 0;
    int j = 0;

    for (i = 1; arg[i] != NULL; i++) {
        loop_unset(env, arg[i], j, compt);
    }
    return (compt);
}

int check(char **arg, char *env)
{
    for (int j = 1; arg[j] != NULL; j++) {
        if (my_strncmp(arg[j], env, my_strlen(arg[j])) == 0) {
            return 0;
        }
    }
    return (1);
}

char **cpy_unsetenv(char **env, char **arg)
{
    int i = 0;
    int index = 0;
    char **cpy_env = malloc(sizeof(char *)
        * (check_array(env) - check_unset(env, arg)) + 1);

    for (; env[i] != NULL; i++) {
        if (check(arg, env[i]) == 0)
            continue;
        cpy_env[index] = my_strdup(env[i]);
        index++;
    }
    cpy_env[index] = NULL;
    free_array(env);
    return (cpy_env);
}
