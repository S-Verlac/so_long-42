# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 08:42:22 by mbachar           #+#    #+#              #
#    Updated: 2023/01/23 09:46:24 by mbachar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
PRINTF = ./ft_printf/libftprintf.a
SRC = backtracking.c \
				backtracking_utils.c \
				components.c \
				errors.c \
				mappings.c \
				miscellaneous_bk.c \
				miscellaneous.c \
				movements.c \
				parsing.c \
				so_long.c \
				utils_bk.c \
				utils.c

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
	rm -fr $(OBJ)

fclean :
	rm -fr $(NAME)
	rm -fr $(OBJ)

re : fclean all

.PHONY : re fclean clean