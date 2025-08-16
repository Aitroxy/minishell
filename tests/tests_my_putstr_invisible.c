/*
** EPITECH PROJECT, 2021
** B-PSU-100-RUN-1-1-myprintf-guillyann.ferrere
** File description:
** tests_my_putstr_invisible.c
*/

#include "my_criterion.h"
#include "../include/my_printf.h"

Test(my_putstr_invisible, invisible_char, .init = redirect_all_std)
{
    my_putstr_invisible("\atoto\n");
    cr_assert_stdout_eq_str("\\007toto\\012");
}

Test(my_putstr_invisible, only_invisible_char, .init = redirect_all_std)
{
    my_putstr_invisible("\a\n");
    cr_assert_stdout_eq_str("\\007\\012");
}

Test(my_putstr_invisible, another_invisible_char, .init = redirect_all_std)
{
    char s[] = {7, 8, 9, 31, 127, 128, 0};

    my_putstr_invisible(s);
    cr_assert_stdout_eq_str("\\007\\010\\011\\037\\177\\200");
}