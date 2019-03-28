# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndelhomm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/25 15:22:45 by ndelhomm          #+#    #+#              #
#    Updated: 2019/03/25 17:29:30 by ndelhomm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ndelhomm.filler

HEADER	= filler.h

SRC		= parser.c\

OBJ		= $(SRCS:.c=.o)

LIB = libft/libft.a

GCC = gcc

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

allclean: all clean

$(NAME): $(LIB) $(SRC) $(LIB)
	@$(CC) $(FLAGS) $(SRC) $(LIB) -o $(NAME)
	@printf "\n\033[032mFiller Compilation OK \033[0m\n"
	@printf "\n\033[032mPlayer \"ndelhomm.filler\" Created\033[0m\n"

$(LIB):
	@make -C libft

clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean:
	@make clean -C libft
	@rm -f $(NAME) $(OBJ)
	@printf "\n\033[032mPlayer \"ndelhomm.filler\" Deleted\033[0m\n"

re: fclean all

norme:
	norminette $(SRC)
	norminette $(HEADER)
.PHONY : all clean fclean re
