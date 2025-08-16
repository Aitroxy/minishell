/*
** EPITECH PROJECT, 2021
** B-PSU-101-RUN-1-1-minishell1-guillyann.ferrere
** File description:
** free.c
*/

#include "include/minishell.h"
#include "include/builtin.h"
#include "include/my_printf.h"

void free_array(char **array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
    array = NULL;
}

void command_null(char *com, char *command, minishell_t *init)
{
    write(2, com, my_strlen(com));
    write(2, ": Command not found.\n", 21);
    init->status = 84;
    free(command);
}

void free_all(char **array, char *path)
{
    free_array(array);
    free(path);
}
