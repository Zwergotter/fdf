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
SRC = main.c\
	  parsing.c\
	  drawing.c\
	  init.c\
	  error.c\
	  keycodes.c\
	  modifications.c\
	  colors.c\
	  controls.c\

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
	@echo ""
	@echo "   \x1b[0;33m       (\x1b[m\033[0;35m**\x1b[0;33m)                                             (\x1b[m\033[0;35m**\x1b[0;33m)"
	@echo "          IIII                                             IIII"
	@echo "          ####                                             ####"
	@echo "          HHHH                                             HHHH"
	@echo "          HHHH                                             HHHH"
	@echo "          ####                                             ####"
	@echo "       ___IIII___                                       ___IIII___"
	@echo "    .-\`_._\"**\"_._\`-.                                 .-\`_._\"**\"_._\`-."
	@echo "   |/\`\`  .\`\/\`.  \`\`\|                               |/\`\`  .\`\/\`.  \`\`\|"
	@echo "   \`\x1b[m     \x1b[0;90m}    {\x1b[m     \x1b[0;33m'\x1b[m                               \x1b[0;33m\`\x1b[m     \x1b[0;90m}    {     \x1b[0;33m'\x1b[m"
	@echo "         \x1b[0;90m) \x1b[0;37m() \x1b[0;90m(                                           ) \x1b[0;37m() \x1b[0;90m("
	@echo "         \x1b[0;90m( \x1b[0;37m::\x1b[0;90m )      ▄████████ ████████▄     ▄████████    ( \x1b[0;37m::\x1b[0;90m )"
	@echo "         | \x1b[0;37m::\x1b[0;90m |     ███    ███ ███   ▀███   ███    ███    | \x1b[0;37m::\x1b[0;90m |"
	@echo "         | \x1b[0;37m)(\x1b[0;90m |     ███    █▀  ███    ███   ███    █▀     | \x1b[0;37m)(\x1b[0;90m |"
	@echo "         | \x1b[0;37m||\x1b[0;90m |     ███    █▀  ███    ███   ███    █▀     | \x1b[0;37m||\x1b[0;90m |"
	@echo "         | \x1b[0;37m||\x1b[0;90m |    ▄███▄▄▄     ███    ███  ▄███▄▄▄        | \x1b[0;37m||\x1b[0;90m |"
	@echo "         | \x1b[0;37m||\x1b[0;90m |   ▀▀███▀▀▀     ███    ███ ▀▀███▀▀▀        | \x1b[0;37m||\x1b[0;90m |"
	@echo "         | \x1b[0;37m||\x1b[0;90m |     ███        ███    ███   ███           | \x1b[0;37m||\x1b[0;90m |"
	@echo "         | \x1b[0;37m||\x1b[0;90m |     ███        ███   ▄███   ███           | \x1b[0;37m||\x1b[0;90m |"
	@echo "         ( \x1b[0;37m()\x1b[0;90m )     ███        ████████▀    ███           ( \x1b[0;37m()\x1b[0;90m )"
	@echo "          \  /                                             \  /"
	@echo "           \/                                               \/"
	@echo ""
	@echo "   \x1b[0;35m                                                     © edeveze"

                           

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
