# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edeveze <edeveze@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/24 21:39:34 by edeveze           #+#    #+#              #
#    Updated: 2017/01/24 22:13:38 by edeveze          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable
NAME = fdf

# Includes
INC = -I includes -I libft/includes -I minilibx/

# Files
SRC = fdf.c\

# Objects
OBJ = $(SRC:.c=.o)

# Compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror
FRAME = -L libft/ -lft -lmlx -framework OpenGL -framework AppKit


# Rules

all : minilibx $(NAME)

minilibx : lib
	@make -C minilibx/ clean
	@make -C minilibx

lib:
	@make -C libft/ fclean
	@make -C libft

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(FRAME) -o $@ $(OBJ)

$(OBJ) : %.o:%.c libft/libft.a minilibx/libmlx.a
	@$(CC) -c $(CFLAGS) $(INC) $(SRC) -o $@

clean :
	@rm -rf $(OBJ)
	@make -C libft clean
	@make -C minilibx clean

fclean : clean
	@rm -rf $(NAME)
	@make -C libft clean
	@make -C minilibx clean

re : fclean all

.PHONY: all clean fclean re
