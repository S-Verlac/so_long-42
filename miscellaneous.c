/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscellaneous.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:07:45 by mbachar           #+#    #+#             */
/*   Updated: 2023/01/21 00:36:38 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_assign(char *map, t_list no)
{
	char	*str;
	int		x;
	int		y;
	int		i;

	x = 0;
	i = 0;
	y = 0;
	str = ft_read_map(map);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			y += 64;
			x = 0;
		}
		if (str[i] == '0')
		{
			mlx_put_image_to_window(no.mlx, no.window, no.floor, x, y);
			x += 64;
		}
		if (str[i] == '1')
		{
			mlx_put_image_to_window(no.mlx, no.window, no.wall, x, y);
			x += 64;
		}
		if (str[i] == 'P')
		{
			mlx_put_image_to_window(no.mlx, no.window, no.mario, x, y);
			x += 64;
		}
		if (str[i] == 'C')
		{
			mlx_put_image_to_window(no.mlx, no.window, no.collectible, x, y);
			x += 64;
		}
		if (str[i] == 'E')
		{
			mlx_put_image_to_window(no.mlx, no.window, no.exit, x, y);
			x += 64;
		}
		i++;
	}
	return (free(str), 0);
}

void	ft_scan(char *map)
{
	t_list	no;
	char	*str;
	int		x;
	int		y;

	str = ft_read_map(map);
	no.x_win = ft_count_size_x(str);
	no.y_win = ft_count_size_y(str);
	no.mlx = mlx_init();
	no.window = mlx_new_window(no.mlx, no.x_win * 64, no.y_win * 64, "so_long");
	no.wall = mlx_xpm_file_to_image(no.mlx, "./imgs/wall.xpm", &x, &y);
	no.floor = mlx_xpm_file_to_image(no.mlx, "./imgs/floor.xpm", &x, &y);
	no.mario = mlx_xpm_file_to_image(no.mlx, "./imgs/mario.xpm", &x, &y);
	no.collectible = mlx_xpm_file_to_image(no.mlx, "./imgs/patrol.xpm", &x, &y);
	no.exit = mlx_xpm_file_to_image(no.mlx, "./imgs/exit.xpm", &x, &y);
	no.xp = ft_player_position_x("map.ber") * 64;
	no.yp = ft_player_position_y("map.ber") * 64;
	ft_assign(map, no);
	ft_printf("Player Moves : %d\n", no.moves = 0);
	no.map = ft_split(str, '\n');
	no.collectibles = ft_count_collectibles(map);
	mlx_hook(no.window, 2, 1L << 0, key, &no);
	mlx_string_put(no.mlx, no.window, 20, 20, 0xFFFFFF, "911");
	mlx_loop(no.mlx);
	free(str);
}
