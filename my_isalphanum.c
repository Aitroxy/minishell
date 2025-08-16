/*
** EPITECH PROJECT, 2021
** B-PSU-101-RUN-1-1-minishell1-guillyann.ferrere
** File description:
** my_isalphanum.c
*/

#include <stdbool.h>
#include <stdio.h>

bool is_alpha(char c)
{
    if ((c >= 'A') && (c <= 'Z'))
        return true;
    if ((c >= 'a') && (c <= 'z'))
        return true;
    return false;
}

bool is_alpha_str(char *str)
{
    if (is_alpha(str[0]) == true)
        return true;
    if (str[0] == '_')
        return true;
    return false;
}

bool is_num_underscore(char c)
{
    if ((c >= '0') && (c <= '9'))
        return true;
    if (c == '_')
        return true;
    return false;
}

bool is_num(char *str)
{
    int i = 0;

    if (str == NULL)
        return false;
    for (; str[i] != '\0'; i++) {
        if (is_alpha(str[i]) == true)
            return false;
    }
    return true;
}

bool is_alphanum(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if ((is_alpha(str[i]) == false) &&
            (is_num_underscore(str[i]) == false))
            return false;
    }
    return true;
}
