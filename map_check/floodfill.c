/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:13:03 by asemsey           #+#    #+#             */
/*   Updated: 2024/01/15 14:56:03 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**floodfill(char **map, int y, int x, char dir)
{
	if (y < 0 || x < 0 || !map[y] || !map[y][x] || map[y][x] == '1' || map[y][x] == 'F')
		return (map);
	map[y][x] = 'F';
	if (dir != 'd')
		map = floodfill(map, y - 1, x, 'u');//up
	if (dir != 'u')
		map = floodfill(map, y + 1, x, 'd');//down
	if (dir != 'r')
		map = floodfill(map, y, x - 1, 'l');//left
	if (dir != 'l')
		map = floodfill(map, y, x + 1, 'r');//right
	return (map);
}

int	is_connected(char **map, t_point begin)
{
	if (map[begin.y] && map[begin.y][begin.x + 1] && map[begin.y][begin.x + 1] == 'F')
		return (1);
	if (map[begin.y] && map[begin.y][begin.x - 1] && map[begin.y][begin.x - 1] == 'F')
		return (1);
	if (map[begin.y + 1] && map[begin.y + 1][begin.x] && map[begin.y + 1][begin.x] == 'F')
		return (1);
	if (map[begin.y - 1] && map[begin.y - 1][begin.x] && map[begin.y - 1][begin.x] == 'F')
		return (1);
	return (0);
}

int	valid_path(char **map)
{
	char	**copy;
	t_point	start;
	t_point	size;
	t_point	exit;

	copy = copy_map(map);
	if (!copy)
		return (0);
	start = get_begin(copy, 'P');
	size = get_size(copy);
	exit = get_begin(copy, 'E');
	copy = floodfill(copy, start.y, start.x, ' ');
	// write(1, "map floodfilled:\n", 17);
	// print_map(copy);
	if (is_connected(copy, exit))
	{
		free_all(copy);
		return (1);
	}
	write(2, "no path found\n", 14);
	free_all(copy);
	return (0);
}
