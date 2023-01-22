# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 08:42:22 by mbachar           #+#    #+#              #
#    Updated: 2023/01/22 23:37:25 by mbachar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
PRINTF = ./ft_printf/libftprintf.a
SRC_MANDATORY = ./mandatory/backtracking.c \
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

INCLUDE_MANDATORY = ./mandatory/so_long.h
CC = cc
OBJ_MANDATORY = $(SRC_MANDATORY:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

%.o : %.c $(INCLUDE_MANDATORY)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ_MANDATORY)
	$(CC) $(CFLAGS) $(OBJ_MANDATORY) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(PRINTF)

clean :
	rm -fr $(OBJ_MANDATORY)

fclean :
	rm -fr $(NAME)
	rm -fr $(OBJ_MANDATORY)

re : fclean all

.PHONY : re fclean clean