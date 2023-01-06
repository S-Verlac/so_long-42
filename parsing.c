/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:48:00 by mbachar           #+#    #+#             */
/*   Updated: 2023/01/06 17:37:51 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_rectangular(char *map)
{
	char	*str;
	int		x;
	int		y;
	int		i;

	x = 0;
	y = 1;
	i = 0;
	str = ft_read_map(map);
	while (str[i] != '\n')
	{
		i++;
		x++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			y++;
		i++;
	}
	if (x == y)
		return (0);
	return (1);
}

int	ft_equal_lines(char *map)
{
	char	*tmp;
	int		reference;
	int		i;

	tmp = ft_read_map(map);
	reference = ft_strlen_n(tmp);
	i = 0;
	while (*tmp != '\0')
	{
		if (*tmp == '\0' || *tmp == '\n')
		{
			if (i != reference)
				return (0);
			i = 0;
			tmp++;
		}
		else
		{
			i++;
			tmp++;
		}
	}
	if (i != reference)
		return (0);
	return (1);
}

int	ft_closed_map_up_left(char *map)
{
	char	*str;
	int		i;

	str = ft_read_map(map);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			i++;
			if (str[i] != '1')
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_closed_map_down_right(char *map)
{
	char	*str;
	int		i;

	str = ft_read_map(map);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			i--;
			if (str[i] != '1')
				return (0);
			i++;
		}
		i++;
	}
	i = ft_strlen(str) - 1;
	while (str[i] != '\n')
	{
		if (str[i] != '1')
			return (0);
		i--;
	}
	return (1);
}
