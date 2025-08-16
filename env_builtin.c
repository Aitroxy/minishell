/*
** EPITECH PROJECT, 2021
** B-PSU-101-RUN-1-1-minishell1-guillyann.ferrere
** File description:
** building.c
*/

#include "include/minishell.h"
#include "include/builtin.h"
#include <errno.h>

void env_built(minishell_t *init)
{
    if (init->env != NULL)
        for (int i = 0; init->env[i] != NULL; i++)
            my_printf("%s\n", init->env[i]);
}

void setenv_loop(int compt, minishell_t *init, char *tmp, int index)
{
    if (compt > 3) {
        write(2, "setenv: Too many arguments.\n", 28);
        init->status = 84;
    }
    if (compt == 1)
        env_built(init);
    if (init->array[1] == NULL)
        return;
    if ((index = check_env_exist(init->env, init->array[1])) >= 0) {
        tmp = concat_string(init->array[1], "");
        init->env = replace_env(init->env, tmp, index);
    } else {
        tmp = concat_string(init->array[1], "");
        init->env = array_add(init->env, tmp);
    }
}

void setenv_three_arg(int compt, int index, minishell_t *init, char *tmp)
{
    if (compt == 3) {
        if ((index = check_env_exist(init->env, init->array[1])) >= 0) {
            tmp = concat_string(init->array[1], init->array[2]);
            init->env = replace_env(init->env, tmp, index);
        } else {
            tmp = concat_string(init->array[1], init->array[2]);
            init->env = array_add(init->env, tmp);
        }
    }
}

void setenv_built(minishell_t *init)
{
    int compt = check_arg(init->array);
    char *tmp = NULL;
    int index = 0;

    if (compt == 2 || compt == 3) {
        if ((is_alpha_str(init->array[1]) == false)) {
            error_setenv_begin_arg(init);
            return;
        }
    }
    if ((compt == 2 && (is_alphanum(init->array[1]) == false)) ||
        (compt == 3 && (is_alphanum(init->array[1]) == false))) {
        error_setenv_contain_char(init);
        return;
    }
    setenv_loop(compt, init, tmp, index);
    setenv_three_arg(compt, index, init, tmp);
}

void unsetenv_built(minishell_t *init)
{
    int compt = check_arg(init->array);

    if (compt < 2) {
        write(2, "unsetenv: Too few arguments.\n", 29);
        init->status = 84;
    } else {
        init->env = cpy_unsetenv(init->env, init->array);
    }
}
