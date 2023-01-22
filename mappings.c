/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mappings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:06:12 by mbachar           #+#    #+#             */
/*   Updated: 2023/01/22 23:02:45 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_path(char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	return (fd);
}

int	ft_check_map_extension(char *map)
{
	if (ft_strncmp(map + (ft_strlen(map) - 4), ".ber", 4) == 0)
		return (1);
	return (0);
}

char	*ft_read_map(char *map)
{
	char	*stash;
	char	*buff;
	int		i;
	int		fd;

	i = 1;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		print_and_exit();
	buff = malloc(BUFFER_SIZE + 1);
	stash = malloc(BUFFER_SIZE + 1);
	if (!stash || !buff)
		return (NULL);
	while (i > 0 && !ft_strchr(stash, '\0'))
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i < 0 || (i == 0 && !stash)
			|| (i == 0 && stash[0] == 0))
			return (free(buff), free(stash), NULL);
		buff[i] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	return (free(buff), stash);
}

int	ft_count_size_x(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0' && str[x] != '\n')
		x++;
	return (x);
}

int	ft_count_size_y(char *str)
{
	int	x;
	int	y;

	x = 0;
	y = 1;
	while (str[x] != '\0')
	{
		if (str[x] == '\n')
			y++;
		x++;
	}
	return (y);
}
