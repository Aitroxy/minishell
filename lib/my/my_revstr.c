/*
** EPITECH PROJECT, 2021
** write reverse string
** File description:
** task03
*/

int my_strlen(char const *str);

char *my_strdup(char const *src);

char *my_revstr(char *str)
{
    int i = 0;
    char save = 0;
    int lenght = my_strlen(str) - 1;

    while (i <= lenght) {
        save = str[i];
        str[i] = str[lenght];
        str[lenght] = save;
        i = i + 1;
        lenght = lenght - 1;
    }
    return (str);
}
