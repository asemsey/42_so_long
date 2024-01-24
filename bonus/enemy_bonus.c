/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:08:45 by asemsey           #+#    #+#             */
/*   Updated: 2024/01/24 11:01:37 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_enemy(t_objects *objects, int i, int loop)
{
	if (loop == 0)
	{
		objects->enemy0_i->instances[i].enabled = false;
		objects->enemy1_i->instances[i].enabled = true;
	}
	else if (loop == 1)
	{
		objects->enemy1_i->instances[i].enabled = false;
		objects->enemy2_i->instances[i].enabled = true;
	}
	else if (loop == 2)
	{
		objects->enemy2_i->instances[i].enabled = false;
		objects->enemy3_i->instances[i].enabled = true;
	}
	else if (loop == 3)
	{
		objects->enemy3_i->instances[i].enabled = false;
		objects->enemy4_i->instances[i].enabled = true;
	}
	else if (loop == 4)
	{
		objects->enemy4_i->instances[i].enabled = false;
		objects->enemy0_i->instances[i].enabled = true;
	}
}

// enemy animation
void	ft_loop_hook(void *param)
{
	t_objects	*objects;
	static int	loop;
	int			i;

	objects = param;
	i = 0;
	while (i < objects->enemies)
	{
		if (loop % 10 == 0)
			set_enemy(objects, i, loop / 10);
		i++;
	}
	if (loop >= 40)
		loop = 0;
	else
		loop++;
}
