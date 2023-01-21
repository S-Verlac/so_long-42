# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 08:42:22 by mbachar           #+#    #+#              #
#    Updated: 2023/01/20 23:48:54 by mbachar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
INCLUDE = so_long.h
PRINTF = ./ft_printf/libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRC = backtracking.c backtracking_utils.c components.c errors.c mappings.c miscellaneous.c movements.c parsing.c so_long.c utils_bk.c utils.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	@ $(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(PRINTF)

%.o : %.c $(INCLUDE)
	@ $(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
	@ rm -rf $(OBJ)

fclean : clean
	@ rm -rf $(NAME)

re : fclean all

.PHONY : re fclean clean