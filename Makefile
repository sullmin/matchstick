##
## EPITECH PROJECT, 2019
## Makefile doop
## File description:
## task02
##

SRC	=	src/main.c	\
		src/display.c	\
		src/end.c	\
		src/game.c	\
		src/ia2.c	\
		src/my_revgetnbr.c	\
		src/get_map/get_map.c	\
		src/stick_get/get_my_stick.c	\
		src/stick_get/put_stick.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

CFLAGS	+=	-Wall	-Wextra	-I./include -g

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -o	$(NAME)	$(OBJ) -I ./include -L./lib/my -lmy -lncurses

clean:
	rm	-f 	$(OBJ)

fclean: clean
	rm	-f	$(NAME)

re:	fclean	all
