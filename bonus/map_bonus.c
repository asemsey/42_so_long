/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:35:03 by asemsey           #+#    #+#             */
/*   Updated: 2024/01/23 14:51:42 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

int	valid_map_b(char **map)
{
	if (!map || !*map)
		return (0);
	if (!rectangle(map) || !characters(map) || !wall(map))
		return (0);
	if (!valid_path_b(map))
		return (0);
	return (1);
}
