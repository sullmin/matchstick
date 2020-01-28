##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## task01
##

SRC	=	my_getnbr.c	\
	my_put_nbr.c	\
	my_putstr.c	\
	my_str_isnum.c	\
	my_putchar.c	\
	my_strlen.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar	rc	$(NAME)	$(OBJ)
	rm *.o
	cp	libmy.a ../libmy.a
	cp	my.h ../../include/my.h

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean	all

auteur:
	echo $(USER) > auteur

.PHONY: all clean fclean
