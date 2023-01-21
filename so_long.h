/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 08:42:29 by mbachar           #+#    #+#             */
/*   Updated: 2023/01/21 02:54:13 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include "ft_printf/ft_printf.h"

typedef struct s_list
{
	void	*mlx;
	void	*window;
	void	*wall;
	void	*mario;
	void	*collectible;
	void	*floor;
	void	*exit;
	char	**map;
	int		x_win;
	int		y_win;
	int		collectibles;
	int		moves;
	int		yp;
	int		xp;
	int		x_move;
	int		y_move;
}	t_list;

	/* Parsing.c */
int		ft_rectangular(char *map); // Parsing.c
int		ft_equal_lines(char *map); // Parsing.c
int		ft_closed_map_up_left(char *map); // Parsing.c
int		ft_closed_map_down_right(char *map); // Parsing.c
	/* Mappings */
int		ft_check_path(char *map); // Mappings.c
int		ft_check_map_extension(char *map); // Mappings.c
char	*ft_read_map(char *map); // Mappings.c
int		ft_count_size_x(char *str); // Mappings.c
int		ft_count_size_y(char *str); // Mappings.c
	/* Components.c */
int		ft_detect_imposter(char *map); // Components.c
int		ft_missing_player(char *map); // Components.c
int		ft_missing_exit(char *map); // Components.c
int		ft_missing_collectibles(char *map); // Components.c
int		ft_count_collectibles(char *map); // Components.c
	/* Miscellaneous.c */
void	ft_scan(char *map); // Miscellaneous.c
int		ft_assign(char *map, t_list no); // Miscellaneous.c
void	ft_errors(char *map); // Miscellaneous.c
	/* Utils.c && Utils_bk.c */
char	*ft_strjoin(char *s1, char *s2); // Utils_bk.c
char	*ft_strdup(char *s1); // Utils_bk.c
char	*ft_substr(char *s, unsigned int start, size_t len); // Utils_bk.c
size_t	ft_strlen(char *s); // Utils.c
int		ft_strlen_n(char *s); // Utils.c
int		ft_strchr(char *s, int c); // Utils.c
int		ft_strncmp(const char	*s1, const char	*s2, size_t	n); // Utils.c
char	*ft_strrchr(char *s, char c); // Utils.c
	/* Backtracking.c && Backtracking_utils.c*/
char	**ft_split(char *s, char c); // Backtracking_utils.c
int		ft_player_position_x(char *map); // Backtracking.c
int		ft_player_position_y(char *map); // Backtracking.c
int		ft_split_map(char *map); // Backtracking.c
int		ft_backtracking(char **map, int x, int y); // Backtracking.c
	/* Movements.c */
int		key(int keycode, t_list *no);

#endif