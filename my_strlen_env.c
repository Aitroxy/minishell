/*
** EPITECH PROJECT, 2021
** B-PSU-101-RUN-1-1-minishell1-guillyann.ferrere
** File description:
** my_strlen_env.c
*/

int my_strlen_env(char *str)
{
    int i = 0;

    while (str[i] != '=') {
        i++;
    }
    i++;
    return i;
}
