/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 08:51:08 by mbachar           #+#    #+#             */
/*   Updated: 2023/01/13 22:21:58 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_errors(char *map)
{
	if (ft_check_map_extension(map) == 0)
		printf("Error : Map must end with (.ber) extension !\n");
	else if (ft_check_path(map) == -1)
		printf("Error : Map path is wrong !\n");
	else if (ft_read_map(map) == NULL)
		printf("Error : Map is empty !\n");
	else if (ft_closed_map_up_left(map) == 0)
		printf("Error : Top or left of map is not closed by walls !\n");
	else if (ft_closed_map_down_right(map) == 0)
		printf("Error : Bottom or right of map is not closed by walls !\n");
	else if (ft_rectangular(map) == 0)
		printf("Error : Map is not rectangular !\n");
	else if (ft_equal_lines(map) == 0)
		printf("Error : Map width are not equal !\n");
	else if (ft_detect_imposter(map) == 0)
		printf("Error : A different component in the map detected !\n");
	else if (ft_missing_player(map) == 0)
		printf("Error : Missing or multiple players in the map !\n");
	else if (ft_missing_exit(map) == 0)
		printf("Error : Missing or multiple exits in the map !\n");
	else if (ft_missing_collectibles(map) == 0)
		printf("Error : Missing collectibles in the map !\n");
	else if (ft_split_map(map) == 0)
		printf("Error : Player is unable to find a way to the exit !\n");
	return ;
}
