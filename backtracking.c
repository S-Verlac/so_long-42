/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:46:34 by mbachar           #+#    #+#             */
/*   Updated: 2023/01/14 01:41:18 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_player_position_x(char *map)
{
	char	*str;
	int		i;
	int		x;

	str = ft_read_map(map);
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
	free (str);
	return (x);
}

int	ft_player_position_y(char *map)
{
	char	*str;
	int		i;
	int		y;

	str = ft_read_map(map);
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
	free (str);
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
	if (ft_backtracking(map, x - 1, y))
		return (1);
	if (ft_backtracking(map, x, y + 1))
		return (1);
	if (ft_backtracking(map, x + 1, y))
		return (1);
	return (0);
}

int	ft_split_map(char *map)
{
	char	**new;
	char	*map_var;
	int		y;
	int		x;
	int		i;

	map_var = ft_read_map(map);
	new = ft_split(map_var, '\n');
	x = ft_player_position_x("map.ber");
	y = ft_player_position_y("map.ber");
	i = 0;
	if (ft_backtracking(new, x, y) == 0)
		return (0);
	while (new[i])
	{
		free(new[i]);
		i++;
	}
	free (new);
	free(map_var);
	return (1);
}
