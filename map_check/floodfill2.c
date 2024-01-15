/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:13:03 by asemsey           #+#    #+#             */
/*   Updated: 2024/01/15 11:24:02 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	floodfill(char **copy, t_point start, t_point p)
{
	return ;
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

	copy = copy_map(map);
	if (!copy)
		return (0);
	start = get_begin(copy, 'P');
	floodfill(copy, start, start);
	if (is_connected(copy, start))
	{
		free_all(copy);
		return (1);
	}
	free_all(copy);
	return (0);
}
