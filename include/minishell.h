/*
** EPITECH PROJECT, 2021
** B-PSU-101-RUN-1-1-minishell1-guillyann.ferrere
** File description:
** minishell.h
*/

#ifndef MINISHELL_H_
    #define MINISHELL_H_

    #include <unistd.h>
    #include "my_printf.h"
    #include <stdlib.h>
    #include <string.h>
    #include <stdio.h>
    #include <signal.h>
    #include <sys/types.h>
    #include <wait.h>
    #include <stdbool.h>

char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
int my_strncmp(char const *s1, char const *s2, int n);
int array_len(char **array);
char *my_strdup(char const *src);
char **my_arraydup(char **env);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char **strtok_split_on_colon(char *str);
void free_array(char **array);
char **strtok_split_on_colon(char *str);
char **strtok_split_on_space(char *str);
void free_all(char **array, char *path);
char *parse_env(char **env, char **array);
char *concat_env(char *s1, char *separator, char *s2);
int my_strlen_env(char *str);
bool is_alphanum(char *str);
bool is_alpha(char c);
bool is_alpha_str(char *str);
int my_put_nbr_error(int nb);
int is_num(char *str);
int my_getnbr(char const *str);

typedef struct minishell_s {
    char **array;
    char **env;
    char *save_path;
    char *com;
    int status;
} minishell_t;

#endif
