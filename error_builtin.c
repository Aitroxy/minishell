/*
** EPITECH PROJECT, 2021
** B-PSU-101-RUN-1-1-minishell1-guillyann.ferrere
** File description:
** error_env.c
*/

#include "include/minishell.h"
#include "include/builtin.h"

void error_setenv_begin_arg(minishell_t *init)
{
    write(2, init->array[0], my_strlen(init->array[0]));
    write(2, ": Variable name must begin with a letter.\n", 42);
    init->status = 84;
}

void error_setenv_contain_char(minishell_t *init)
{
    write(2, init->array[0], my_strlen(init->array[0]));
    write(2, ": Variable ", 11);
    write(2, "name must contain alphanumeric characters.\n", 43);
    init->status = 84;
}

void error_cd_arg(minishell_t *init)
{
    write(2, "cd: Too many arguments.\n", 24);
    init->status = 84;
}
