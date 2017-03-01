# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edeveze <edeveze@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/24 21:39:34 by edeveze           #+#    #+#              #
#    Updated: 2017/02/24 14:20:58 by edeveze          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable
NAME = fdf

# Includes
INC = -I includes -I libft/includes -I minilibx/

# Files
SRC = fdf.c\
	  parsing.c\
	  drawing.c\
	  init.c\
	  error.c\
	  keycodes.c\
	  modifications.c\

# Objects
OBJ = $(SRC:.c=.o)

# Compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
PRGFLAGS = -L libft/ -L minilibx/ -lmlx -framework OpenGL -framework AppKit minilibx/libmlx.a libft/libft.a

# Rules

all : minilibx $(NAME)

minilibx : lib
	@make -C minilibx/ clean
	@make -C minilibx

lib:
	@make -C libft/ fclean
	@make -C libft

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(PRGFLAGS) -o $@ $(OBJ)

%.o: %.c libft/libft.a minilibx/libmlx.a
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean :
	@rm -rf $(OBJ)
	@make -C libft clean
	@make -C minilibx clean

fclean : clean
	@rm -rf $(NAME)
	@make -C libft fclean
	@make -C minilibx clean

re : fclean all

.PHONY: all clean fclean re
