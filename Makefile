# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcatina <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 15:25:21 by fcatina           #+#    #+#              #
#    Updated: 2020/01/21 16:42:47 by fcatina          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROV = -Wall -Wextra -Werror
NAME = libftprintf.a
EXEC = program
SRC = main.c ft_putstr.c ft_printf.c ft_putnbr.c ft_putchar.c

.PHONY: all clean fclean re

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ): $(SRC)
	gcc $(PROV) -I. -c $(SRC)
	gcc $(OBJ) -o ft_printf

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
