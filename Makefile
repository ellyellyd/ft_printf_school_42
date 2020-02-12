# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcatina <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 15:25:21 by fcatina           #+#    #+#              #
#    Updated: 2020/02/12 05:46:42 by slisandr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re libft exec

CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
EXEC = ft_printf

SRC_DIR = src
SRC_RAW = \
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
	handle_u.c \
	handle_X.c \
	handle_id.c \
	fix_s.c
SRC = $(addprefix $(SRC_DIR)/,$(SRC_RAW))

MAIN_RAW = main.c
MAIN = $(addprefix $(SRC_DIR)/,$(MAIN_RAW))

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC_RAW:.c=.o))




all: $(NAME)

$(EXEC): $(NAME)
	@ gcc $(CFLAGS) -o $(EXEC) $(MAIN) -I "includes/" -I "libft/includes/" -L . -lftprintf -L "libft/" -lft 
	@ echo "$(NAME): $(GREEN)$(EXEC) was created$(RESET)"

$(NAME): libft $(OBJ_DIR) $(OBJ)
	@ echo "$(NAME): $(GREEN)object files were created$(RESET)"
	@ cp ./libft/libft.a $(NAME)
	@ echo "$(NAME): $(GREEN)libft.a library was copied to the root$(RESET)"
	@ ar -rc $(NAME) $(OBJ)
	@ echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"
	@ ranlib $(NAME)
libft:
	@ make -C libft/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@ gcc $(CFLAGS) -I "includes/" -I "libft/includes/" -c $< -o $@
$(OBJ_DIR):
	@ mkdir -p $(OBJ_DIR)
	@ echo "$(NAME): $(GREEN)$(OBJ_DIR) folder was created$(RESET)"


exec: $(EXEC)

clean:
	@ rm -rf $(OBJ_DIR)
	@ echo "$(NAME): $(RED)object files were deleted$(RESET)"
	@ echo "$(NAME): $(RED)$(OBJ_DIR) folder was deleted$(RESET)"
	@ make -C libft/ clean
fclean: clean
	@ rm -f $(NAME)
	@ echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"
	@ make -C libft/ fclean
re: fclean all
