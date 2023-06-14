##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## compile 102_architect
##

SRC    =	102archi.c		\
			display.c


OBJ    =    $(SRC:.c=.o)

NAME	=	102architect

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -lm

clean:
		rm $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all
