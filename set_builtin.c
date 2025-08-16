/*
** EPITECH PROJECT, 2021
** B-PSU-101-RUN-1-1-minishell1-guillyann.ferrere
** File description:
** building.c
*/

#include "include/builtin.h"
#include "include/minishell.h"
#include "include/my_printf.h"

int get_built(minishell_t *init)
{
    const building_t name_funct[] = {
        {"cd", &cd_built}, {"exit", &exit_built},
        {"setenv", &setenv_built}, {"unsetenv", &unsetenv_built},
        {"env", &env_built}, {NULL, NULL}
    };

    for (int i = 0; name_funct[i].name != NULL; i++) {
        if (my_strcmp(init->array[0], name_funct[i].name) == 0) {
            return (i);
        }
    }
    return (-1);
}

int run_built(minishell_t *init, int check)
{
    const building_t name_funct[] = {
        {"cd", &cd_built}, {"exit", &exit_built},
        {"setenv", &setenv_built}, {"unsetenv", &unsetenv_built},
        {"env", &env_built}, {NULL, NULL}
    };

    name_funct[check].print_built(init);
    return (0);
}
