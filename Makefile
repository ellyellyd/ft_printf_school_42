# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcatina <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 15:25:21 by fcatina           #+#    #+#              #
#    Updated: 2020/02/03 20:34:50 by fcatina          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -g
NAME = libftprintf.a
EXEC = program
SRC = main.c \
	  10_in_8.c \
	  ft_putstr.c \
	  ft_printf.c \
	  ft_putnbr.c \
	  ft_putchar.c \
	  ft_itoa_base.c \
	  X_ft_itoa_base.c\
	  ft_itoa_unsigned_base.c\
		ft_test_itoa_unsigned_base.c

.PHONY: all clean fclean re

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ): $(SRC)
	gcc $(CFLAGS) -I. -c $(SRC)
	gcc $(OBJ) -o ft_printf

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
