/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:52:36 by asemsey           #+#    #+#             */
/*   Updated: 2024/01/23 18:54:39 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	enemy_check(t_objects *objects, int y, int x)
{
	if (objects->map[y][x] == 'B')
	{
		write(1, "GAME OVER\n", 10);
		exit(0);
	}
}

void	ft_walk_b(t_objects *objects, int y, int x, char dir)
{
	int	i;

	i = 0;
	if (objects->map[y][x] == '1')
		return ;
	if (objects->exit_i->instances[0].x == x * 64
		&& objects->exit_i->instances[0].y == y * 64)
	{
		if (objects->coins_left == 0)
			exit(0);
		return ;
	}
	coin_check(objects, y, x);
	enemy_check(objects, y, x);
	objects->steps++;
	set_coordinates(objects, y * 64, x * 64);
	set_visible(objects, dir);
	ft_printf("steps:  %d\n", objects->steps);
}
