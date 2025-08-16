/*
** EPITECH PROJECT, 2021
** B-PSU-100-RUN-1-1-myprintf-guillyann.ferrere
** File description:
** tests_my_put_nbr.c
*/

#include "my_criterion.h"
#include "../include/my_printf.h"

Test(my_put_nbr, simple_nbr, .init = redirect_all_std)
{
    my_put_nbr(5);
    cr_assert_stdout_eq_str("5");
}

Test(my_put_nbr, nbr_zero, .init = redirect_all_std)
{
    my_put_nbr(0);
    cr_assert_stdout_eq_str("0");
}

Test(my_put_nbr, nbr, .init = redirect_all_std)
{
    my_put_nbr(11);
    cr_assert_stdout_eq_str("11");
}

Test(my_put_nbr, nbr_neg, .init = redirect_all_std)
{
    my_put_nbr(-1);
    cr_assert_stdout_eq_str("-1");
}

Test(my_put_nbr, nb_10_less, .init = redirect_all_std)
{
    my_put_nbr(8);
    cr_assert_stdout_eq_str("8");
}

Test(my_put_nbr, nb_neg_10, .init = redirect_all_std)
{
    my_put_nbr(-10);
    cr_assert_stdout_eq_str("-10");
}

Test(my_put_nbr, nb_neg_11, .init = redirect_all_std)
{
    my_put_nbr(-11);
    cr_assert_stdout_eq_str("-11");
}