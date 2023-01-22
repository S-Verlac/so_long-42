/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 08:51:08 by mbachar           #+#    #+#             */
/*   Updated: 2023/01/22 22:52:56 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_errors(char *map, t_list *no)
{
	if (ft_check_map_extension(map) == 0)
		ft_printf("Error : Map must end with (.ber) extension !\n");
	else if (ft_check_path(map) == -1)
		ft_printf("Error : Map path is wrong !\n");
	else if (ft_read_map(map) == NULL)
		ft_printf("Error : Map is empty !\n");
	else if (ft_closed_map_up_left(no) == 0)
		ft_printf("Error : Top or left of map is not closed by walls !\n");
	else if (ft_closed_map_down_right(no) == 0)
		ft_printf("Error : Bottom or right of map is not closed by walls !\n");
	else if (ft_rectangular(no) == 0)
		ft_printf("Error : Map is not rectangular !\n");
	else if (ft_equal_lines(no) == 0)
		ft_printf("Error : Map width are not equal !\n");
	else if (ft_detect_imposter(no) == 0)
		ft_printf("Error : A different component in the map detected !\n");
	else if (ft_missing_player(no) == 0)
		ft_printf("Error : Missing or multiple players in the map !\n");
	else if (ft_missing_exit(no) == 0)
		ft_printf("Error : Missing or multiple exits in the map !\n");
	else if (ft_missing_collectibles_floor(no) == 0)
		ft_printf("Error : Missing collectibles or floor in the map !\n");
	else if (ft_split_map(no) == 0)
		ft_printf("Error : Player is unable to find a way to the exit !\n");
	return ;
}

void	print_and_exit(void)
{
	ft_printf("Error : Map path not found !\n");
	exit(0);
}
