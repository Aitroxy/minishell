/*
** EPITECH PROJECT, 2021
** B-PSU-100-RUN-1-1-myprintf-guillyann.ferrere
** File description:
** test_my_printf.c
*/

#include "my_criterion.h"
#include "../include/my_printf.h"

Test(my_printf, simple_string, .init = redirect_all_std)
{
    my_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test(my_printf, flag_d, .init = redirect_all_std)
{
    my_printf("hello world %d", 12);
    cr_assert_stdout_eq_str("hello world 12");
}

Test(my_printf, flag_d_neg, .init = redirect_all_std)
{
    my_printf("hello world %d", -12);
    cr_assert_stdout_eq_str("hello world -12");
}


Test(my_printf, flag_i_neg, .init = redirect_all_std)
{
    my_printf("hello world %i", -1900);
    cr_assert_stdout_eq_str("hello world -1900");
}

Test(my_printf, flag_i, .init = redirect_all_std)
{
    my_printf("hello world %i", -1900);
    cr_assert_stdout_eq_str("hello world -1900");
}

Test(my_printf, flag_c, .init = redirect_all_std)
{
    my_printf("hello world %c", 'l');
    cr_assert_stdout_eq_str("hello world l");
}

Test(my_printf, flag_C, .init = redirect_all_std)
{
    my_printf("hello world %C", 'm');
    cr_assert_stdout_eq_str("hello world m");
}

Test(my_printf, flag_str, .init = redirect_all_std)
{
    my_printf("hello world %s", "toto");
    cr_assert_stdout_eq_str("hello world toto");
}

Test(my_printf, flag_b, .init = redirect_all_std)
{
    my_printf("hello world %b", 12345);
    cr_assert_stdout_eq_str("hello world 11000000111001");
}

Test(my_printf, flag_big_S, .init = redirect_all_std)
{
    my_printf("hello world %S", "\atoto\n");
    cr_assert_stdout_eq_str("hello world \\007toto\\012");
}

Test(my_printf, flag_x, .init = redirect_all_std)
{
    my_printf("hello world %x", 123456);
    cr_assert_stdout_eq_str("hello world 1e240");
}

Test(my_printf, flag_X, .init = redirect_all_std)
{
    my_printf("hello world %X", 123456);
    cr_assert_stdout_eq_str("hello world 1E240");
}

Test(my_printf, flag_percent, .init = redirect_all_std)
{
    my_printf("hello world %%s", "toto");
    cr_assert_stdout_eq_str("hello world %s");
}

Test(my_putstr, str, .init = redirect_all_std)
{
    my_putstr(NULL);
    cr_assert_stdout_eq_str("(null)");
}

Test(my_printf, flag_u, .init = redirect_all_std)
{
    my_printf("hello world %u", -12);
    cr_assert_stdout_eq_str("hello world 4294967284");
}

Test(my_printf, flag_o, .init = redirect_all_std)
{
    my_printf("hello world %o", 123456);
    cr_assert_stdout_eq_str("hello world 361100");
}

Test(my_printf, flag_p, .init = redirect_all_std)
{
    my_printf("hello world %p", 123456);
    cr_assert_stdout_eq_str("hello world 0x1e240");
}

Test(my_printf, flag_zero, .init = redirect_all_std)
{
    my_printf("hello world %0", NULL);
    cr_assert_stdout_eq_str("hello world NULL");
}

Test(my_printf, percent)
{
    my_printf("%");
}

Test(my_printf, tests_null_lot, .init = redirect_all_std)
{
    my_printf("%d%s%d%s%s%p%%%s%%%d", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
    cr_assert_stdout_eq_str("0(null)0(null)(null)0x0%(null)%0");
}