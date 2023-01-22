/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:46:34 by mbachar           #+#    #+#             */
/*   Updated: 2023/01/22 23:04:06 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_player_position_x(t_list *no)
{
	char	*str;
	int		i;
	int		x;

	str = no->mapone;
	i = 0;
	x = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			x = -1;
		i++;
		x++;
		if (str[i] == 'P')
			break ;
	}
	return (x);
}

int	ft_player_position_y(t_list *no)
{
	char	*str;
	int		i;
	int		y;

	str = no->mapone;
	i = 0;
	y = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			y++;
		i++;
		if (str[i] == 'P')
			break ;
	}
	return (y);
}

int	ft_backtracking(char **map, int x, int y)
{
	if (map[x][y] == 'E')
		return (1);
	if (map[x][y] == '1')
		return (0);
	map[x][y] = '1';
	if (ft_backtracking(map, x, y - 1))
		return (1);
	if (ft_backtracking(map, x, y + 1))
		return (1);
	if (ft_backtracking(map, x + 1, y))
		return (1);
	if (ft_backtracking(map, x - 1, y))
		return (1);
	return (0);
}

int	ft_split_map(t_list *no)
{
	char	**new;
	char	*map_var;
	int		y;
	int		x;
	int		i;

	map_var = no->mapone;
	new = ft_split(map_var, '\n');
	x = ft_player_position_x(no);
	y = ft_player_position_y(no);
	i = 0;
	if (ft_backtracking(new, x, y) == 0)
		return (0);
	while (new[i])
	{
		free(new[i]);
		i++;
	}
	return (free(new), 1);
}
