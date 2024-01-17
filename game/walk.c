/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:39:17 by asemsey           #+#    #+#             */
/*   Updated: 2024/01/17 19:40:54 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_go_up(t_objects *objects)
{
	int	i;

	i = 0;
	if (objects->map[objects->player_i->instances[0].y / 64 - 1]
		[objects->player_i->instances[0].x / 64] == '1')
		return ;
	if (objects->exit_i->instances[0].x == objects->player_i->instances[0].x
			&& objects->exit_i->instances[0].y == objects->player_i->instances[0].y - 64)
			exit(1);
	while (objects->coin_i->instances[i].x > 0)
	{
		if (objects->coin_i->instances[i].x == objects->player_i->instances[0].x
			&& objects->coin_i->instances[i].y == objects->player_i->instances[0].y - 64)
				objects->coin_i->instances[i].enabled = false;
		i++;
	}
	objects->player_i->instances[0].y -= 64;
}

void	ft_go_left(t_objects *objects)
{
	int	i;

	i = 0;
	if (objects->map[objects->player_i->instances[0].y / 64]
		[objects->player_i->instances[0].x / 64 - 1] == '1')
		return ;
	if (objects->exit_i->instances[0].x == objects->player_i->instances[0].x - 64
			&& objects->exit_i->instances[0].y == objects->player_i->instances[0].y)
			exit(1);
	while (objects->coin_i->instances[i].x > 0)
	{
		if (objects->coin_i->instances[i].x == objects->player_i->instances[0].x - 64
			&& objects->coin_i->instances[i].y == objects->player_i->instances[0].y)
				objects->coin_i->instances[i].enabled = false;
		i++;
	}
	objects->player_i->instances[0].x -= 64;
}

void	ft_go_down(t_objects *objects)
{
	int	i;

	i = 0;
	if (objects->map[objects->player_i->instances[0].y / 64 + 1]
		[objects->player_i->instances[0].x / 64] == '1')
		return ;
	if (objects->exit_i->instances[0].x == objects->player_i->instances[0].x
			&& objects->exit_i->instances[0].y == objects->player_i->instances[0].y + 64)
			exit(1);
	while (objects->coin_i->instances[i].x > 0)
	{
		if (objects->coin_i->instances[i].x == objects->player_i->instances[0].x
			&& objects->coin_i->instances[i].y == objects->player_i->instances[0].y + 64)
				objects->coin_i->instances[i].enabled = false;
		i++;
	}
	objects->player_i->instances[0].y += 64;
}

void	ft_go_right(t_objects *objects)
{
	int	i;

	i = 0;
	if (objects->map[objects->player_i->instances[0].y / 64]
		[objects->player_i->instances[0].x / 64 + 1] == '1')
		return ;
	if (objects->exit_i->instances[0].x == objects->player_i->instances[0].x + 64
			&& objects->exit_i->instances[0].y == objects->player_i->instances[0].y)
			exit(1);
	while (objects->coin_i->instances[i].x > 0)
	{
		if (objects->coin_i->instances[i].x == objects->player_i->instances[0].x + 64
			&& objects->coin_i->instances[i].y == objects->player_i->instances[0].y)
				objects->coin_i->instances[i].enabled = false;
		i++;
	}
	objects->player_i->instances[0].x += 64;
}
