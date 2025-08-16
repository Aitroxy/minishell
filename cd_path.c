/*
** EPITECH PROJECT, 2021
** B-PSU-101-RUN-1-1-minishell1-guillyann.ferrere
** File description:
** cd_path.c
*/

#include "include/builtin.h"
#include "include/minishell.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

char *search_path(char **env, char *str)
{
    char *save_path = NULL;
    int i = 0;
    char *path = NULL;

    for (; env[i] != NULL; i++) {
        if (my_strncmp(env[i], str, my_strlen(str)) == 0) {
            save_path = my_strdup(env[i]);
        }
    }
    if (save_path == NULL)
        return NULL;
    path = my_strdup(save_path + my_strlen(str));
    free(save_path);
    return (path);
}

int file_check(char *arg)
{
    struct stat *check = malloc(sizeof(struct stat));

    stat(arg, check);
    if (check->st_mode & __S_IFREG) {
        free(check);
        return (0);
    }
    free(check);
    return (1);
}
