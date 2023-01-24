/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 09:06:00 by mbachar           #+#    #+#             */
/*   Updated: 2023/01/24 11:08:41 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	*map;
	t_list	no;

	if (argc == 2)
	{
		map = argv[1];
		no.mapone = ft_read_map(map);
		if (ft_check_map_extension(map) != 0 && ft_check_path(map) != -1
			&& no.mapone != NULL && ft_rectangular(&no) != 0
			&& ft_equal_lines(&no) != 0 && ft_closed_map_up_left(&no) == 1
			&& ft_detect_imposter(&no) != 0 && ft_missing_exit(&no) != 0
			&& ft_missing_player(&no) != 0
			&& ft_missing_collectibles_floor(&no) != 0
			&& ft_closed_map_down_right(&no) == 1 && ft_split_map(&no) != 0)
			ft_scan(map);
		else
		{
			ft_errors(map, &no);
			exit (0);
			free(no.mapone);
		}
	}
	else
		ft_printf("Error : Map path is missing !\n");
	exit (0);
}
