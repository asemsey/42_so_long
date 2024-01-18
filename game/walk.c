/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:39:17 by asemsey           #+#    #+#             */
/*   Updated: 2024/01/18 13:08:16 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_visible(t_objects *objects, char dir)
{
	if (dir != 'd')
		objects->dplayer_i->instances[0].enabled = false;
	if (dir == 'd')
		objects->dplayer_i->instances[0].enabled = true;
	if (dir != 'l')
		objects->lplayer_i->instances[0].enabled = false;
	if (dir == 'l')
		objects->lplayer_i->instances[0].enabled = true;
	if (dir != 'u')
		objects->uplayer_i->instances[0].enabled = false;
	if (dir == 'u')
		objects->uplayer_i->instances[0].enabled = true;
	if (dir != 'r')
		objects->rplayer_i->instances[0].enabled = false;
	if (dir == 'r')
		objects->rplayer_i->instances[0].enabled = true;
}

void	set_p(t_objects *objects)
{
	objects->p.y = objects->dplayer_i->instances[0].y / 64;
	objects->p.x = objects->dplayer_i->instances[0].x / 64;
}

void	set_coordinates(t_objects *objects, int y, int x)
{
	objects->dplayer_i->instances[0].y = y;
	objects->dplayer_i->instances[0].x = x;
	objects->uplayer_i->instances[0].y = y;
	objects->uplayer_i->instances[0].x = x;
	objects->lplayer_i->instances[0].y = y;
	objects->lplayer_i->instances[0].x = x;
	objects->rplayer_i->instances[0].y = y;
	objects->rplayer_i->instances[0].x = x;
	set_p(objects);
}

// left: y, x - 1
// right: y, x + 1
// up: y - 1, x
// down: y + 1, x
// y x are the coordinates in the map!!!
void	ft_walk(t_objects *objects, int y, int x, char dir)
{
	int	i;

	i = 0;
	if (objects->map[y][x] == '1')
		return ;
	if (objects->exit_i->instances[0].x == x * 64 && objects->exit_i->instances[0].y == y * 64)
	{
		if (objects->coins_left == 0)
			exit(0);
		return ;
	}
	while (objects->coin_i->instances[i].x > 0)
	{
		if (objects->coin_i->instances[i].x == x * 64 && objects->coin_i->instances[i].y == y * 64
			&& objects->coin_i->instances[i].enabled)
		{
			objects->coins_left--;
			objects->coin_i->instances[i].enabled = false;
		}
		i++;
	}
	objects->steps++;
	set_coordinates(objects, y * 64, x * 64);
	set_visible(objects, dir);
	ft_printf("steps:  %d\n", objects->steps);
}
