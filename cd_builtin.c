/*
** EPITECH PROJECT, 2021
** B-PSU-101-RUN-1-1-minishell1-guillyann.ferrere
** File description:
** cd_builting.c
*/

#include "include/builtin.h"
#include "include/minishell.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

void change_pwd(int index, minishell_t *init, char *old_pwd, int size)
{
    index = (check_env_exist(init->env, "PWD="));
    if (index >= 0) {
        init->env = replace_env(init->env,
        concat_env("PWD=", "", getcwd(NULL, size)), index);
        index = 0;
    }
    index = (check_env_exist(init->env, "OLDPWD="));
    if (index >= 0)
        init->env = replace_env(init->env, old_pwd, index);
}

void error_case(minishell_t *init, char **env, char *old_pwd, int index)
{
    int size = 0;
    (void)env;

    index = 0;
    if (chdir(init->array[1]) == -1) {
        write(2, init->array[1], my_strlen(init->array[1]));
        write(2, ": ", 2);
        write(2, strerror(errno), my_strlen(strerror(errno)));
        write(2, ".\n", 2);
        init->status = 84;
    } else {
        change_pwd(index, init, old_pwd, size);
        return;
    }
}

void cd_sub(int compt, int index, minishell_t *init, char *old_pwd)
{
    int size = 0;

    if ((compt == 2 && my_strcmp(init->array[1], "-") == 0)) {
        old_pwd = concat_env("OLDPWD=", "", getcwd(NULL, size));
        chdir(search_path(init->env, "OLDPWD="));
        index = check_env_exist(init->env, "PWD=");
        if (index >= 0) {
            init->env = replace_env(init->env,
            concat_env("PWD=", "", getcwd(NULL, size)), index);
            index = 0;
        }
        index = (check_env_exist(init->env, "OLDPWD="));
        if (index >= 0) {
            init->env = replace_env(init->env, old_pwd, index);
        }
    }
}

void cd_to_home(minishell_t *init, char *old_pwd, int index, int size)
{
    char *path = search_path(init->env, "HOME=");

    if (path == NULL) {
        write(2, "No $home variable set.\n", 23);
        init->status = 84;
        return;
    }
    old_pwd = concat_env("OLDPWD=", "", getcwd(NULL, size));
    chdir(path);
    index = (check_env_exist(init->env, "PWD="));
    if (index >= 0) {
        init->env = replace_env(init->env,
        concat_env("PWD=", "", getcwd(NULL, size)), index);
        index = 0;
    }
    index = (check_env_exist(init->env, "OLDPWD="));
    if (index >= 0) {
        init->env = replace_env(init->env, old_pwd, index);
    }
}

void cd_built(minishell_t *init)
{
    int compt = check_arg(init->array);
    int index = 0;
    char *old_pwd = NULL;

    if (compt > 2) {
        error_cd_arg(init);
        return;
    }
    if (init->env == NULL)
        return;
    if ((compt == 1) || (compt == 2 && my_strcmp(init->array[1], "~") == 0)) {
        cd_to_home(init, old_pwd, index, 0);
        return;
    }
    if ((compt == 2 && my_strcmp(init->array[1], "-") == 0)) {
        cd_sub(compt, index, init, old_pwd);
        return;
    }
    old_pwd = concat_env("OLDPWD=", "", getcwd(NULL, 0));
    error_case(init, init->env, old_pwd, index);
}
