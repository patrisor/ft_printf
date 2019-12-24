# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: patrisor <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/10 00:34:18 by patrisor          #+#    #+#              #
#    Updated: 2019/12/19 05:01:28 by patrisor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRC		= *.c #./src/*.c ./libft/*.c ./src/handlers/*.c
OBJ		= $(SRC:.c=.o)
HEADER  = ./includes/
OBJ_DIR = ./obj/

CFLAG	= -Wall -Wextra -Werror -g 
CFLAGS	+= -O3 -march=native -pipe

all: $(NAME)

$(NAME):
	mkdir $(OBJ_DIR)
	gcc $(CFLAG) -c -I$(HEADER) -I ./libft $(SRC)
	ar rc $(NAME) *.o
	ranlib $(NAME)
	mv *.o $(OBJ_DIR)

clean:
	rm -Rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
