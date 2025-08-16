/*
** EPITECH PROJECT, 2021
** B-PSU-101-RUN-1-1-minishell1-guillyann.ferrere
** File description:
** struct.h
*/

#ifndef BUILTIN_H_
    #define BUILTIN_H_

    #include "minishell.h"

typedef void(*pointer_funct_t)(minishell_t *init);
typedef struct building_s {
    char *name;
    pointer_funct_t print_built;
} building_t;

int get_built(minishell_t *init);
void cd_built(minishell_t *init);
void exit_built(minishell_t *init);
void setenv_built(minishell_t *init);
void env_built(minishell_t *init);
void unsetenv_built(minishell_t *init);
int run_built(minishell_t *init, int check);
int check_array(char **env);
char **array_add(char **env, char *arg);
char *concat_string(char *s1, char *s2);
int check_arg(char **array);
char **array_sub(char **env, char *str);
int my_strcmp_equal(char const *s1, char const *s2);
int check_env_exist(char **env, char *arg);
char **replace_env(char **env, char *arg, int index);
char **cpy_unsetenv(char **env, char **arg);
char **strtok_split_on_equal(char *str);
int file_check(char *arg);
char *search_path(char **env, char *str);
int check_arg(char **array);
int exit_in_tty(int value);
void command_null(char *com, char *command, minishell_t *init);
void error_setenv_begin_arg(minishell_t *init);
void error_setenv_contain_char(minishell_t *init);
void error_cd_arg(minishell_t *init);

#endif
