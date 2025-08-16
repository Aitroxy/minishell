##
## EPITECH PROJECT, 2021
## makefiles
## File description:
## Makefile
##

CC = gcc

SRC =	my_putchar.c \
	my_put_nbr.c \
	my_putstr.c \
	display.c \
	display_base.c \
	display_base_bis.c \
	my_revstr.c \
	my_strlen.c \
	my_printf.c \
	put_str_invisible.c \
	my_put_base.c

OBJ =  $(SRC:.c=.o)

NAME = libmy.a

CFLAGS = -W -Werror -Wall -Wextra -I./../../include

TESTS_SRC = tests/tests_my_printf.c \
		tests/tests_my_put_nbr.c \
		tests/my_criterion.c \
		tests/tests_my_putstr_invisible.c

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

tests_run : re
	gcc -o unit_tests $(SRC) $(TESTS_SRC) $(CFLAGS) -lcriterion --coverage
	./unit_tests
clean :
	rm -f $(OBJ)
	rm -f *~
	rm -f *#
	rm -f *gcda
	rm -f *gcno
	rm -f unit_tests

fclean : clean
	rm -f $(NAME)

re : fclean all
