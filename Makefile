# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 08:42:22 by mbachar           #+#    #+#              #
#    Updated: 2023/01/22 23:15:20 by mbachar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
PRINTF = ./ft_printf/libftprintf.a
SRC = 	./mandatory/backtracking.c \
		./mandatory/backtracking_utils.c \
		./mandatory/components.c \
		./mandatory/errors.c \
		./mandatory/mappings.c \
		./mandatory/miscellaneous.c \
		./mandatory/movements.c \
		./mandatory/parsing.c \
		./mandatory/so_long.c \
		./mandatory/utils_bk.c \
		./mandatory/utils.c

INCLUDE = so_long.h
CC = cc
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

%.o : %.c $(INCLUDE)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(PRINTF)

clean :
	rm -rf $(OBJ)

fclean :
	rm -rf $(NAME)
	rm -fr $(OBJ)

re : fclean all

.PHONY : re fclean clean