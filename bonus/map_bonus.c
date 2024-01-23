/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:35:03 by asemsey           #+#    #+#             */
/*   Updated: 2024/01/23 19:49:28 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	bad_chars_b(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P'
				&& map[i][j] != 'E' && map[i][j] != 'C' && map[i][j] != 'B')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	**floodfill_b(char **map, int y, int x, char dir)
{
	if (y < 0 || x < 0 || !map[y] || !map[y][x]
		|| map[y][x] == '1' || map[y][x] == 'F' || map[y][x] == 'B')
		return (map);
	map[y][x] = 'F';
	if (dir != 'd')
		map = floodfill_b(map, y - 1, x, 'u');
	if (dir != 'u')
		map = floodfill_b(map, y + 1, x, 'd');
	if (dir != 'r')
		map = floodfill_b(map, y, x - 1, 'l');
	if (dir != 'l')
		map = floodfill_b(map, y, x + 1, 'r');
	return (map);
}

int	valid_path_b(char **map)
{
	char	**copy;
	t_point	start;
	t_point	size;

	copy = copy_map(map);
	if (!copy)
		return (0);
	start = get_begin(copy, 'P');
	size = get_size(copy);
	copy = floodfill_b(copy, start.y, start.x, ' ');
	if (!count_char(copy, 'E') && !count_char(copy, 'C'))
	{
		free_all(copy);
		return (1);
	}
	write(2, "Error\nno path found\n", 20);
	free_all(copy);
	return (0);
}

int	characters_b(char **map)
{
	if (count_char(map, 'P') != 1
		|| count_char(map, 'E') != 1
		|| count_char(map, 'C') < 1
		|| bad_chars_b(map))
	{
		write(2, "Error\nincorrect characters in map\n", 34);
		return (0);
	}
	return (1);
}

int	valid_map_b(char **map)
{
	if (!map || !*map)
		return (0);
	if (!rectangle(map) || !characters_b(map) || !wall(map))
		return (0);
	if (!valid_path_b(map))
		return (0);
	return (1);
}
