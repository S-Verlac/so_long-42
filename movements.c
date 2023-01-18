/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:52:54 by mbachar           #+#    #+#             */
/*   Updated: 2023/01/18 18:36:37 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key(int keycode, t_list *no)
{
	char	*mapp;
	char	**map;
	int		x;
	int		y;
	int		i;

	mapp = ft_read_map("map.ber");
	map = ft_split(mapp, '\n');
	x = no->xp / 64;
	y = no->yp / 64;
	i = 0;
	if (keycode == 53)
		exit(0);
	if (keycode == 124)
	{
		x++;
		if (map[y][x] == 'C' || map[y][x] == '0' || map[y][x] == 'P')
		{
			mlx_put_image_to_window(no->mlx, no->window, no->floor, no->xp, no->yp);
			mlx_put_image_to_window(no->mlx, no->window, no->mario, no->xp + 64, no->yp);
			no->xp += 64;
			printf("%d\n", ++no->moves);
			x = (no->xp / 64);
		}
	}
	if (keycode == 123)
	{
		x--;
		if (map[y][x] == 'C' || map[y][x] == '0' || map[y][x] == 'P')
		{
			mlx_put_image_to_window(no->mlx, no->window, no->floor, no->xp, no->yp);
			mlx_put_image_to_window(no->mlx, no->window, no->mario, no->xp - 64, no->yp);
			no->xp -= 64;
			printf("%d\n", ++no->moves);
			x = (no->xp / 64);
		}
	}
	if (keycode == 125)
	{
		y++;
		if (map[y][x] == 'C' || map[y][x] == '0' || map[y][x] == 'P')
		{
			mlx_put_image_to_window(no->mlx, no->window, no->floor, no->xp, no->yp);
			mlx_put_image_to_window(no->mlx, no->window, no->mario, no->xp, no->yp + 64);
			no->yp += 64;
			printf("%d\n", ++no->moves);
			y = (no->yp / 64);
		}
	}
	if (keycode == 126)
	{
		y--;
		if (map[y][x] == 'C' || map[y][x] == '0' || map[y][x] == 'P')
		{
			mlx_put_image_to_window(no->mlx, no->window, no->floor, no->xp, no->yp);
			mlx_put_image_to_window(no->mlx, no->window, no->mario, no->xp, no->yp - 64);
			no->yp -= 64;
			printf("%d\n", ++no->moves);
			y = (no->yp / 64);
		}
	}
	while (map[i])
		free(map[i++]);
	return (free(mapp), free(map), 0);
}
