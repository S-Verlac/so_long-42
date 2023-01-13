/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 09:06:00 by mbachar           #+#    #+#             */
/*   Updated: 2023/01/13 22:22:28 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	*map;

	if (argc == 2)
	{
		map = argv[1];
		if (ft_check_path(map) != -1 && ft_check_map_extension(map) != 0
			&& ft_read_map(map) != NULL && ft_rectangular(map) != 0
			&& ft_equal_lines(map) != 0 && ft_closed_map_up_left(map) == 1
			&& ft_detect_imposter(map) != 0 && ft_missing_exit(map) != 0
			&& ft_missing_player(map) != 0 && ft_missing_collectibles(map) != 0
			&& ft_closed_map_down_right(map) == 1 && ft_split_map(map) != 0)
			ft_scan(map);
		else
		{
			ft_errors(map);
			exit (0);
		}
	}
	else
		printf("Error : Map path is missing !\n");
	exit (0);
}
