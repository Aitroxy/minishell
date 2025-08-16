##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC = 	minishell.c \
		my_strcat.c \
		my_strcpy.c \
		my_strncmp.c \
		my_array_len.c \
		my_strdup.c \
		exit_builtin.c\
		cd_builtin.c \
		cd_path.c \
		env_builtin.c \
		set_builtin.c \
		array_thing.c \
		strtok.c \
		free.c \
		parse_env.c \
		my_isalphanum.c \
		unset_env_add.c \
		my_arraydup.c \
		my_put_nbr_error.c \
		my_getnbr.c \
		error_builtin.c \
		my_strlen_env.c

OBJ = $(SRC:.c=.o)

LFLAGS = -L./lib/my -lmy

CFLAGS = -W -Werror -Wall -Wextra -I./include -g3

NAME = mysh

all : $(NAME)

$(NAME): $(OBJ)
	make -C lib/my re
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LFLAGS)

tests_run:
	make -C lib/my tests_run

clean :
	make -C lib/my clean
	rm -f $(OBJ)
	rm -f #*
	rm -f *~
	rm -f unit_tests*

fclean : clean
	make -C lib/my fclean
	rm -f $(NAME)

re : fclean all
