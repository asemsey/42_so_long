/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:14:36 by asemsey           #+#    #+#             */
/*   Updated: 2024/01/17 19:41:13 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	to_image(t_objects *objects)
{
	objects->floor_i = mlx_texture_to_image(objects->mlx, objects->floor);
	if (!objects->floor_i)
		exit(1);
	objects->exit_i = mlx_texture_to_image(objects->mlx, objects->exit);
	if (!objects->exit_i)
		exit(1);
	objects->wall_i = mlx_texture_to_image(objects->mlx, objects->wall);
	if (!objects->wall_i)
		exit(1);
	objects->coin_i = mlx_texture_to_image(objects->mlx, objects->coin);
	if (!objects->coin_i)
		exit(1);
	objects->player_i = mlx_texture_to_image(objects->mlx, objects->player);
	if (!objects->player_i)
		exit(1);
}

void	load_pngs(t_objects *objects)
{
	objects->floor = mlx_load_png("assets/dungeon/floor.png");
	if (!objects->floor)
		exit(1);
	objects->exit = mlx_load_png("assets/dungeon/exit.png");
	if (!objects->exit)
		exit(1);
	objects->wall = mlx_load_png("assets/dungeon/wall.png");
	if (!objects->wall)
		exit(1);
	objects->coin = mlx_load_png("assets/items/g_rupee.png");
	if (!objects->coin)
		exit(1);
	objects->player = mlx_load_png("assets/link/link_d.png");
	if (!objects->player)
		exit(1);
	to_image(objects);
}

void	free_pngs(t_objects *objects)
{
	mlx_delete_image(objects->mlx, objects->floor_i);
	mlx_delete_image(objects->mlx, objects->exit_i);
	mlx_delete_image(objects->mlx, objects->wall_i);
	mlx_delete_image(objects->mlx, objects->coin_i);
	mlx_delete_image(objects->mlx, objects->player_i);
	mlx_delete_texture(objects->floor);
	mlx_delete_texture(objects->exit);
	mlx_delete_texture(objects->wall);
	mlx_delete_texture(objects->coin);
	mlx_delete_texture(objects->player);
}

void	load_map(t_objects *objects)
{
	t_point	p;
	t_point	player;

	p.y = 0;
	while (objects->map[p.y])
	{
		p.x = 0;
		while (objects->map[p.y][p.x])
		{
			if (objects->map[p.y][p.x] == '1')
				mlx_image_to_window(objects->mlx, objects->wall_i, p.x * 64, p.y * 64);
			if (objects->map[p.y][p.x] == '0' || objects->map[p.y][p.x] == 'P' 
				|| objects->map[p.y][p.x] == 'C')
				mlx_image_to_window(objects->mlx, objects->floor_i, p.x * 64, p.y * 64);
			if (objects->map[p.y][p.x] == 'C')
				mlx_image_to_window(objects->mlx, objects->coin_i, p.x * 64, p.y * 64);
			if (objects->map[p.y][p.x] == 'E')
				mlx_image_to_window(objects->mlx, objects->exit_i, p.x * 64, p.y * 64);
			if (objects->map[p.y][p.x] == 'P')
				player = p;
			p.x++;
		}
		p.y++;
	}
	mlx_image_to_window(objects->mlx, objects->player_i, player.x * 64, player.y * 64);
}
