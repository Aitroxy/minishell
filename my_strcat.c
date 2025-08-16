/*
** EPITECH PROJECT, 2021
** write concatenates two strings
** File description:
** task02
*/

#include "include/my_printf.h"
#include "include/minishell.h"

char *concat_string(char *s1, char *s2)
{
    char *result = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 2));
    char *equal = "=";

    my_strcpy(result, s1);
    my_strcat(result, equal);
    my_strcat(result, s2);
    return (result);
}

char *concat_env(char *s1, char *separator, char *s2)
{
    char *result = NULL;

    if (s2 == NULL) {
        s2 = malloc(sizeof(char) * 1);
        s2[0] = '\0';
    }
    result = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2)
        + my_strlen(separator) + 1));
    my_strcpy(result, s1);
    my_strcat(result, separator);
    my_strcat(result, s2);
    return (result);
}

char *my_strcat(char *dest, char const *src)
{
    int i = my_strlen(dest);
    int b = 0;

    if (dest == NULL || src == NULL)
        return NULL;
    while (src[b] != '\0') {
        dest[i] = src[b];
        i = i + 1;
        b = b + 1;
    }
    dest[i] = '\0';
    return (dest);
}
