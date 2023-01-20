/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:52:54 by mbachar           #+#    #+#             */
/*   Updated: 2023/01/20 22:10:45 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key(int keycode, t_list *no)
{
	int		x;
	int		y;
	int		i;

	x = no->xp / 64;
	y = no->yp / 64;
	i = 0;
	if (keycode == 53)
		exit(0);
	if (keycode == 124)
	{
		x++;
		if (no->map[y][x] == 'C' || no->map[y][x] == '0' || no->map[y][x] == 'P')
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
		if (no->map[y][x] == 'C' || no->map[y][x] == '0' || no->map[y][x] == 'P')
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
		if (no->map[y][x] == 'C' || no->map[y][x] == '0' || no->map[y][x] == 'P')
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
		if (no->map[y][x] == 'C' || no->map[y][x] == '0' || no->map[y][x] == 'P')
		{
			mlx_put_image_to_window(no->mlx, no->window, no->floor, no->xp, no->yp);
			mlx_put_image_to_window(no->mlx, no->window, no->mario, no->xp, no->yp - 64);
			no->yp -= 64;
			printf("%d\n", ++no->moves);
			y = (no->yp / 64);
		}
	}
	return (0);
}
