# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcatina <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 15:25:21 by fcatina           #+#    #+#              #
#    Updated: 2020/02/12 01:32:19 by slisandr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
NAME = ft_printf
SRC = \
	main.c \
	10_in_8.c \
	ft_printf.c \
	ft_itoa_base.c \
	X_ft_itoa_base.c\
	ft_itoa_unsigned_base.c \
	ft_test_itoa_unsigned_base.c \
	handle_minus.c \
	handle_c.c \
	handle_s.c \
	handle_p.c \
	handle_o.c \
	fix_s.c

.PHONY: all clean fclean re

OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	@ gcc $(OBJ) -L "libft/" -lft -o $(NAME)

$(OBJ): $(SRC)
	@ gcc $(CFLAGS) -I . -I "libft/includes/" -c $(SRC)

clean:
	@ rm -f $(OBJ)

fclean: clean
	@ rm -f $(NAME)

re: fclean all
