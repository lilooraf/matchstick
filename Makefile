##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	main.c	\
		ftc_map.c	\
		ftc_matchstick.c	\
		matchstick.c

OBJ	=	$(foreach source, $(SRC), obj/$(source:.c=.o))

NAME	=	matchstick

CFLAGS	=	-g -Wall -Wextra -Iinclude

LIB	=	lib/my/libmy.a

LDFLAGS	=	-Llib/my -lmy

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	gcc -o $@ $(OBJ) $(LDFLAGS)

obj/%.o: src/%.c
	gcc -c $< -o $@ $(CFLAGS)

$(LIB):
	make -C ./lib/my
clean:
	make clean -C ./lib/my/
	rm -f $(OBJ)

fclean:	clean
	make fclean -C ./lib/my/
	rm -f $(NAME)

re:	fclean all
