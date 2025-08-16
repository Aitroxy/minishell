/*
** EPITECH PROJECT, 2021
** B-PSU-101-RUN-1-1-minishell1-guillyann.ferrere
** File description:
** commande_builting.c
*/

#include "include/builtin.h"
#include "include/minishell.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <wait.h>

bool is_first_num(char c)
{
    if ((c >= '0') && (c <= '9'))
        return true;
    return false;
}

void exit_built(minishell_t *init)
{
    if (check_arg(init->array) == 1)
        exit(0);
    if ((is_num(init->array[1] + 1) == false)) {
        write(2, "exit: Badly formed number.\n", 27);
        init->status = 84;
    } else if ((is_first_num(init->array[1][0]) == false) ||
        (check_arg(init->array) > 2)) {
        write(2, "exit: Expression Syntax.\n", 25);
        init->status = 84;
    } else {
        my_printf("exit");
        init->status = my_getnbr(init->array[1]);
        exit(init->status);
    }
}

int exit_in_tty(int value)
{
    if (isatty(0) == 1)
        return 0;
    exit(value);
}
