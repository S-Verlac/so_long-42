/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscellaneous_bk.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 06:42:09 by mbachar           #+#    #+#             */
/*   Updated: 2023/01/23 09:55:13 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	click(void)
{
	exit (0);
}

void	print_and_exit(void)
{
	ft_printf("Error : Map path not found !\n");
	exit(0);
}

void	won_and_ext(void)
{
	ft_printf("You won !\n");
	exit(0);
}

void	images_protection(void)
{
	ft_printf("Error : Images path not found !");
	exit (0);
}

void	change_collectible(t_list *no)
{
	int	x;
	int	y;

	x = 0;
	y = 1;
	while (no->map[y])
	{
		while (no->map[y][x] != '\0')
		{
			if (no->map[y][x] == 'C')
			{
				mlx_put_image_to_window(no->mlx, no->win,
					no->floor, x * 64, y * 64);
				mlx_put_image_to_window(no->mlx, no->win,
					no->coll2, x * 64, y * 64);
			}
			x++;
		}
		x = 0;
		y++;
	}
}
