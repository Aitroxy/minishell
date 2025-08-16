/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** lib
*/

int my_getnbr(char const *str)
{
    int nb = 0;
    int isnig = 1;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = str[i] - 48 + (nb * 10);
        }
        if (str[i] != '-' && (str[i + 1] < '0' || str[i + 1] > '9')) {
            return (nb * isnig);
        }
        isnig = ((str[i] == '-') ? -isnig : isnig);
        i = i + 1;
    }
    return (nb * isnig);
}
