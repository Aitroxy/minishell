/*
** EPITECH PROJECT, 2021
** B-PSU-101-RUN-1-1-minishell1-guillyann.ferrere
** File description:
** parse_env.c
*/

#include "include/builtin.h"
#include "include/minishell.h"

char *loop(char **env, char *save_path)
{
    int i = 0;

    if (env == NULL)
        return NULL;
    for (; env[i] != NULL; i++) {
        if (my_strcmp_equal(env[i], "PATH=") == 0)
            save_path = my_strdup(env[i] + 5);
    }
    return save_path;
}

char *parse_env(char **env, char **array)
{
    char *save_path = NULL;
    char **command = NULL;
    char *tmp = NULL;

    if (access(array[0], X_OK) == 0)
        return (array[0]);
    if (env == NULL)
        return NULL;
    save_path = loop(env, save_path);
    if ((command = strtok_split_on_colon(save_path)) == NULL)
        return NULL;
    free(save_path);
    for (int i = 0; command[i] != NULL; i++) {
        if (access((tmp = concat_env(command[i], "/", array[0])), X_OK) == 0)
            return free_array(command), (tmp);
    }
    free_array(command);
    return (NULL);
}
