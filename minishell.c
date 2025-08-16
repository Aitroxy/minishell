/*
** EPITECH PROJECT, 2021
** B-PSU-101-RUN-1-1-minishell1-guillyann.ferrere
** File description:
** minishell.c
*/

#include <unistd.h>
#include "include/my_printf.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "include/minishell.h"
#include <signal.h>
#include <sys/types.h>
#include <wait.h>
#include "include/builtin.h"

void set_signal(int status)
{
    int signal = WTERMSIG(status);
    char *all_signal[] = {"", "Hangup", "", "Quit", "Illegal instruction",
        "Trace/BPT trap", "Abort", "Bus error", "Floating exception", "Killed",
        "User signal 1", "Segmentation fault", "User signal 2", "Broken pipe",
        "Alarm clock", "Terminated", "Stack limit exceeded"};

    if (signal == 0 || signal > 16) {
        write(2, "Unknown signal ", 15);
        my_put_nbr_error(signal);
        write(2, "\n", 1);
        return;
    }
    if ((__WCOREDUMP(status) == 128)) {
        write(2, all_signal[signal], my_strlen(all_signal[signal]));
        write(2, " (core dumped)\n", 15);
    } else {
        write(2, all_signal[signal], my_strlen(all_signal[signal]));
        write(2, "\n", 1);
    }
}

void duplicate_exec(minishell_t *init)
{
    pid_t child_pid = 0;
    int status = 0;

    child_pid = fork();
    if (child_pid == 0) {
        execve(init->com, init->array, init->env);
    } else {
        waitpid(child_pid, &status, 0);
        if (WIFSIGNALED(status) == true)
            set_signal(status);
    }
}

int get_usr_intput(minishell_t *init)
{
    size_t size = 0;

    if (init->com == NULL)
        free(init->com);
    (isatty(0) ? my_printf("$> ") : 0);
    if (getline(&init->save_path, &size, stdin) == -1) {
        (isatty(0) ? my_printf("exit\n") : 0);
        free_all(init->env, init->save_path);
        return (-1);
    }
    init->array = strtok_split_on_space(init->save_path);
    init->status = 0;
    return (0);
}

int shell(minishell_t *init, int check)
{
    while (1) {
        if (get_usr_intput(init) == -1)
            return (init->status);
        if (init->array[0] == NULL)
            continue;
        if ((check = get_built(init)) >= 0) {
            run_built(init, check);
            continue;
        }
        if ((init->com = parse_env(init->env, init->array)) == NULL) {
            command_null(init->array[0], init->com, init);
            continue;
        }
        duplicate_exec(init);
    }
    return (0);
}

int main(int ac, char **av, char **env)
{
    minishell_t init = {NULL, my_arraydup(env), NULL, NULL, 0};
    (void)av;
    int check = 0;

    if (ac != 1)
        return (84);
    shell(&init, check);
    return (init.status);
}
