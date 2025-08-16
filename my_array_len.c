/*
** EPITECH PROJECT, 2021
** my
** File description:
** my_array_len.c
*/

int array_len(char **array)
{
    int i = 0;

    while (array[i])
        i = i + 1;
    return i;
}
