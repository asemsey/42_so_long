/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:39:17 by asemsey           #+#    #+#             */
/*   Updated: 2024/01/24 11:00:00 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// change the player sprite
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

// objects->p is the player position
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

void	coin_check(t_objects *objects, int y, int x)
{
	int32_t	i;

	i = objects->coinmap[y][x];
	if (i > -1 && objects->coin_i->instances[i].enabled)
	{
		objects->coins_left--;
		objects->coin_i->instances[i].enabled = false;
	}
}

// check for coin or exit then step in given direction
void	ft_walk(t_objects *objects, int y, int x, char dir)
{
	int	i;

	i = 0;
	if (objects->map[y][x] == '1')
		return ;
	if (objects->exit_i->instances[0].x == x * 64
		&& objects->exit_i->instances[0].y == y * 64)
	{
		if (objects->coins_left == 0)
		{
			ft_printf("steps:  %d\n", objects->steps + 1);
			exit(0);
		}
		return ;
	}
	coin_check(objects, y, x);
	objects->steps++;
	set_coordinates(objects, y * 64, x * 64);
	set_visible(objects, dir);
	ft_printf("steps:  %d\n", objects->steps);
}
