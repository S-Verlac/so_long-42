/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:46:34 by mbachar           #+#    #+#             */
/*   Updated: 2023/01/06 22:37:15 by mbachar          ###   ########.fr       */
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
	return (y);
}

// int main()
// {
// 	printf("x = %d\n", ft_player_position_x("map.ber"));
// 	printf("y = %d\n", ft_player_position_y("map.ber"));
// }
