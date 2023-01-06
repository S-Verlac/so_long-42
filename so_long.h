/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 08:42:29 by mbachar           #+#    #+#             */
/*   Updated: 2023/01/06 20:31:46 by mbachar          ###   ########.fr       */
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

typedef struct s_list
{
	void	*mlx;
	void	*window;
	void	*wall;
	void	*mario;
	void	*collectible;
	void	*floor;
	void	*exit;
	int		x_win;
	int		y_win;
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
	/* Miscellaneous.c */
void	*ft_scan(char *map); // Miscellaneous.c
void	*ft_assign(char *map, t_list no); // Miscellaneous.c
void	ft_errors(char *map); // Miscellaneous.c
	/* Utils.c && Utils_bk.c */
char	*ft_strjoin(char *s1, char *s2); // Utils_bk.c
char	*ft_strdup(char *s1); // Utils_bk.c
size_t	ft_strlen(char *s); // Utils.c
int		ft_strlen_n(char *s); // Utils.c
int		ft_strchr(char *s, int c); // Utils.c
int		ft_strncmp(const char	*s1, const char	*s2, size_t	n); // Utils.c
	/* Backtracking.c */
int		ft_player_position_x(char *map);
int		ft_player_position_y(char *map);

#endif