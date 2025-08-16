/*
** EPITECH PROJECT, 2021
** 18
** File description:
** int
*/

#include <unistd.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if ((s1 == NULL) || (s2 == NULL))
        return 1;
    if (!s1 || !s2)
        return (1);
    for (; s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]; i++);
    return (s1[i] - s2[i]);
}

int my_strcmp_equal(char const *s1, char const *s2)
{
    int i = 0;

    if (!s1 || !s2)
        return (1);
    for (; s1[i] != '=' && s2[i] != '=' && s1[i] == s2[i]; i++);
    return (s1[i] - s2[i]);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if ((s1 == NULL) || (s2 == NULL))
        return 1;
    if (!s1 || !s2)
        return (1);
    for (; i < n -1 && s1[i] == s2[i]; i++);
    return (s1[i] - s2[i]);
}
