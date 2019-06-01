##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	my_getnbr.c	\
		my_putchar.c	\
		my_put_nbr.c	\
		my_putstr.c	\
		my_putstrn.c	\
		my_strlen.c	\
		my_calloc.c	\
		check_num.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp my.h ../../include/

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
