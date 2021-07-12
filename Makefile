##
## EPITECH PROJECT, 2020
## CPool_Day10_2020
## File description:
## Makefile
##

SRC	=	main.c	\
		get_arg.c	\
		change_map_type.c	\
		execute_bsq.c	\
		special_cases.c	\
		check_special_cases.c	\
		check_map.c	\
		lib/my/my_getnbr.c	\
		lib/my/my_strlen.c	\
		lib/my/my_putchar.c	\
		lib/my/my_put_nbr.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	bsq

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc $(SRC) -o $(NAME) -I ./include -L ./lib/my -g3

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
