# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/25 15:22:45 by ndelhomm          #+#    #+#              #
#    Updated: 2019/05/12 14:35:35 by ndelhomm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ndelhomm.filler

HEADER	= filler.h

SRC		= src/main.c\
		  src/init_game.c\
		  src/parse_and_fill.c\
		  src/resolve_1.c\
		  src/resolve_2.c\
		  src/resolve_big_map.c\
		  src/display_and_play.c\

OBJ		= $(SRCS:.c=.o)

LIB = libft/libft.a

GCC = gcc

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

allclean: all clean

$(NAME): $(LIB) $(SRC) $(LIB)
	@$(CC) $(FLAGS) $(SRC) $(LIB) -o $(NAME)
	@printf "\n\033[032mFiller Compilation OK \033[0m\n"
	@printf "\n\033[032mYour player \"ndelhomm.filler\" has been created\033[0m\n"

$(LIB):
	@make -C libft

clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean:
	@make clean -C libft
	@rm -f $(NAME) $(OBJ)
	@printf "\n\033[032mPlayer \"ndelhomm.filler\" has been deleted\033[0m\n"

re: fclean all

norme:
	norminette $(SRC)
	norminette include/$(HEADER)
.PHONY : all clean fclean re
