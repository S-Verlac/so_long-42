/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:52:54 by mbachar           #+#    #+#             */
/*   Updated: 2023/01/23 09:49:27 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_right(t_list *no)
{
	no->x_move++;
	if (no->map[no->y_move][no->x_move] == 'E' && no->collectibles == 0)
		won_and_ext();
	if (no->map[no->y_move][no->x_move] == 'C'
		|| no->map[no->y_move][no->x_move] == '0'
		|| no->map[no->y_move][no->x_move] == 'P')
	{
		mlx_put_image_to_window(no->mlx, no->win,
			no->floor, no->xp, no->yp);
		mlx_put_image_to_window(no->mlx, no->win,
			no->play, no->xp + 64, no->yp);
		if (no->map[no->y_move][no->x_move] == 'C')
		{
			no->map[no->y_move][no->x_move] = '0';
			no->collectibles--;
			if (no->collectibles == 1)
				change_collectible(no);
		}
		no->xp += 64;
		ft_printf("Player Moves : %d\n", ++no->moves);
		no->x_move = (no->xp / 64);
	}
}

void	key_left(t_list *no)
{
	no->x_move--;
	if (no->map[no->y_move][no->x_move] == 'E' && no->collectibles == 0)
		won_and_ext();
	if (no->map[no->y_move][no->x_move] == 'C'
		|| no->map[no->y_move][no->x_move] == '0'
		|| no->map[no->y_move][no->x_move] == 'P')
	{
		mlx_put_image_to_window(no->mlx, no->win,
			no->floor, no->xp, no->yp);
		mlx_put_image_to_window(no->mlx, no->win,
			no->plale, no->xp - 64, no->yp);
		if (no->map[no->y_move][no->x_move] == 'C')
		{
			no->map[no->y_move][no->x_move] = '0';
			no->collectibles--;
			if (no->collectibles == 1)
				change_collectible(no);
		}
		no->xp -= 64;
		ft_printf("Player Moves : %d\n", ++no->moves);
		no->x_move = (no->xp / 64);
	}
}

void	key_down(t_list *no)
{
	no->y_move++;
	if (no->map[no->y_move][no->x_move] == 'E' && no->collectibles == 0)
		won_and_ext();
	if (no->map[no->y_move][no->x_move] == 'C'
		|| no->map[no->y_move][no->x_move] == '0'
		|| no->map[no->y_move][no->x_move] == 'P')
	{
		mlx_put_image_to_window(no->mlx, no->win,
			no->floor, no->xp, no->yp);
		mlx_put_image_to_window(no->mlx, no->win,
			no->play, no->xp, no->yp + 64);
		if (no->map[no->y_move][no->x_move] == 'C')
		{
			no->map[no->y_move][no->x_move] = '0';
			no->collectibles--;
			if (no->collectibles == 1)
				change_collectible(no);
		}
		no->yp += 64;
		ft_printf("Player Moves : %d\n", ++no->moves);
		no->y_move = (no->yp / 64);
	}
}

void	key_up(t_list *no)
{
	no->y_move--;
	if (no->map[no->y_move][no->x_move] == 'E' && no->collectibles == 0)
		won_and_ext();
	if (no->map[no->y_move][no->x_move] == 'C'
		|| no->map[no->y_move][no->x_move] == '0'
		|| no->map[no->y_move][no->x_move] == 'P')
	{
		mlx_put_image_to_window(no->mlx, no->win,
			no->floor, no->xp, no->yp);
		mlx_put_image_to_window(no->mlx, no->win,
			no->play, no->xp, no->yp - 64);
		if (no->map[no->y_move][no->x_move] == 'C')
		{
			no->map[no->y_move][no->x_move] = '0';
			no->collectibles--;
			if (no->collectibles == 1)
				change_collectible(no);
		}
		no->yp -= 64;
		ft_printf("Player Moves : %d\n", ++no->moves);
		no->y_move = (no->yp / 64);
	}
}

int	key(int keycode, t_list *no)
{
	int		i;

	no->x_move = no->xp / 64;
	no->y_move = no->yp / 64;
	i = 0;
	if (keycode == 53)
		exit(0);
	if (keycode == 124)
		key_right(no);
	if (keycode == 123)
		key_left(no);
	if (keycode == 125)
		key_down(no);
	if (keycode == 126)
		key_up(no);
	return (0);
}
