/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:28:43 by asemsey           #+#    #+#             */
/*   Updated: 2024/01/11 15:38:56 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**fill(char **tab, t_point spot, t_point size, char dir)
{
	if (!tab[spot.y] || !tab[spot.y][spot.x] || tab[spot.y][spot.x] == '1' || tab[spot.y][spot.x] == 'F')
		return (tab);
	ft_printf("%d %d dir:%c char:%c\n", spot.y, spot.x, dir, tab[spot.y][spot.x]);
	tab[spot.y][spot.x] = 'F';
	if (spot.y > 0 && spot.y < size.y && spot.x < size.x && dir != 'd')
	{
		spot.y--;
		ft_printf("up\n");
		tab = fill(tab, spot, size, 'u');//up
	}
	if (spot.y < size.y - 1 && spot.x < size.x && dir != 'u')
	{
		spot.y++;
		ft_printf("down\n");
		tab = fill(tab, spot, size, 'd');//down
	}
	if (spot.x > 0 && spot.y < size.y && spot.x < size.x && dir != 'r')
	{
		spot.x--;
		ft_printf("left\n");
		tab = fill(tab, spot, size, 'l');//left
	}
	if (spot.y < size.y && spot.x < size.x - 1 && dir != 'l')
	{
		spot.x++;
		ft_printf("right\n");
		tab = fill(tab, spot, size, 'r');//right
	}
	return (tab);
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

int	flood_fill(char **tab, t_point size, t_point begin)
{
	char	**copy;

	print_map(tab);
	copy = copy_map(tab);
	if (!copy)
		return (0);
	print_map(copy);
	copy = fill(copy, begin, size, ' ');
	print_map(copy);
	if (is_connected(copy, begin))
	{
		free_all(copy);
		return (1);
	}
	free_all(copy);
	return (0);
}
