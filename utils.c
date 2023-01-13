/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                              :+:      :+:    :+:   			  */
/*                                                    +:+ +:+         +:+     */
/*   By: mbachar <mbachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:41:06 by mbachar           #+#    #+#             */
/*   Updated: 2023/01/05 20:41:26 by mbachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(char *s)
{
	size_t		i;

	i = 0;
	if (!s)
		return (0);
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

int	ft_strlen_n(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (*s != '\0' && *s != '\n')
	{
		i++;
		s++;
	}
	return (i);
}

int	ft_strchr(char *s, int c)
{
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strncmp(const char	*s1, const char	*s2, size_t	n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((str1[i] != '\0' || (str2[i] != '\0')) && i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		substr = malloc(((ft_strlen(s) - start) + 1) * sizeof(char));
	else
		substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (0);
	while (s[start] && i < len)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}
