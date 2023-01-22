/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   components.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:07:51 by mbachar           #+#    #+#             */
/*   Updated: 2023/01/22 22:55:40 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_detect_imposter(t_list *no)
{
	char	*str;
	int		i;
	int		imposter;

	str = no->mapone;
	i = 0;
	imposter = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' || str[i] == '0' || str[i] == '1' || str[i] == 'P'
			|| str[i] == 'E' || str[i] == 'C')
			i++;
		else
		{
			imposter++;
			i++;
		}
	}
	if (imposter != 0)
		return (0);
	return (1);
}

int	ft_missing_player(t_list *no)
{
	char	*str;
	int		i;
	int		player;

	str = no->mapone;
	i = 0;
	player = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'P')
			player++;
		i++;
	}
	if (player == 1)
		return (1);
	return (0);
}

int	ft_missing_exit(t_list *no)
{
	char	*str;
	int		i;
	int		exit;

	str = no->mapone;
	i = 0;
	exit = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'E')
			exit++;
		i++;
	}
	if (exit == 1)
		return (1);
	return (0);
}

int	ft_missing_collectibles_floor(t_list *no)
{
	char	*str;
	int		i;
	int		collectible;
	int		floor;

	str = no->mapone;
	i = 0;
	collectible = 0;
	floor = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'C')
			collectible++;
		else if (str[i] == '0')
			floor++;
		i++;
	}
	if (collectible == 0 || floor == 0)
		return (0);
	return (1);
}

int	ft_count_collectibles(t_list *no)
{
	char	*str;
	int		i;
	int		collectibles;

	str = no->mapone;
	i = 0;
	collectibles = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'C')
			collectibles++;
		i++;
	}
	return (collectibles);
}
