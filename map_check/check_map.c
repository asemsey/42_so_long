/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:28:38 by asemsey           #+#    #+#             */
/*   Updated: 2024/01/23 19:47:16 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	rectangle(char **map)
{
	int	i;

	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
		{
			write(2, "Error\nmap is not rectangular\n", 29);
			return (0);
		}
		i++;
	}
	return (1);
}

int	count_char(char **map, char c)
{
	int	i;
	int	j;
	int	result;

	i = 0;
	j = 0;
	result = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				result++;
			j++;
		}
		i++;
	}
	return (result);
}

int	characters(char **map)
{
	if (count_char(map, 'P') != 1
		|| count_char(map, 'E') != 1
		|| count_char(map, 'C') < 1
		|| bad_chars(map))
	{
		write(2, "Error\nincorrect characters in map\n", 34);
		return (0);
	}
	return (1);
}

int	only_c(char *str, char c)
{
	while (str && *str)
	{
		if (*str != c)
			return (0);
		str++;
	}
	return (1);
}

int	wall(char **map)
{
	int	i;
	int	size[2];

	i = 0;
	size[0] = 0;
	size[1] = ft_strlen(map[0]);
	while (map[size[0]])
		size[0]++;
	if (!only_c(map[0], '1') || !only_c(map[size[0] - 1], '1'))
	{
		write(2, "Error\nmap must be surrounded by walls\n", 38);
		return (0);
	}
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][size[1] - 1] != '1')
		{
			write(2, "Error\nmap must be surrounded by walls\n", 38);
			return (0);
		}
		i++;
	}
	return (1);
}
