##
## Makefile for makefile in /home/durand_u/rendu/elcrypt
## 
## Made by Rémi DURAND
## Login   <durand_u@epitech.net>
## 
## Started on  Sat Mar 14 09:35:26 2015 Rémi DURAND
## Last update Sat Mar 14 09:40:00 2015 Rémi DURAND
##

SRC	=	elcrypt.c

CC	=	gcc

RM	=	rm -f

OBJ	=	$(SRC:.c=.o)

NAME	=	elcrypt

CFLAGS	+=	-W -Wall -ansi -pedantic

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
