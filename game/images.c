/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:14:36 by asemsey           #+#    #+#             */
/*   Updated: 2024/01/18 13:20:51 by asemsey          ###   ########.fr       */
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
	objects->uplayer_i = mlx_texture_to_image(objects->mlx, objects->uplayer);
	if (!objects->uplayer_i)
		exit(1);
	objects->lplayer_i = mlx_texture_to_image(objects->mlx, objects->lplayer);
	if (!objects->lplayer_i)
		exit(1);
	objects->dplayer_i = mlx_texture_to_image(objects->mlx, objects->dplayer);
	if (!objects->dplayer_i)
		exit(1);
	objects->rplayer_i = mlx_texture_to_image(objects->mlx, objects->rplayer);
	if (!objects->rplayer_i)
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
	objects->uplayer = mlx_load_png("assets/link/link_u.png");
	if (!objects->uplayer)
		exit(1);
	objects->lplayer = mlx_load_png("assets/link/link_l.png");
	if (!objects->lplayer)
		exit(1);
	objects->dplayer = mlx_load_png("assets/link/link_d.png");
	if (!objects->dplayer)
		exit(1);
	objects->rplayer = mlx_load_png("assets/link/link_r.png");
	if (!objects->rplayer)
		exit(1);
	to_image(objects);
}

void	free_pngs(t_objects *objects)
{
	mlx_delete_image(objects->mlx, objects->floor_i);
	mlx_delete_image(objects->mlx, objects->exit_i);
	mlx_delete_image(objects->mlx, objects->wall_i);
	mlx_delete_image(objects->mlx, objects->coin_i);
	mlx_delete_image(objects->mlx, objects->uplayer_i);
	mlx_delete_image(objects->mlx, objects->lplayer_i);
	mlx_delete_image(objects->mlx, objects->dplayer_i);
	mlx_delete_image(objects->mlx, objects->rplayer_i);
	mlx_delete_texture(objects->floor);
	mlx_delete_texture(objects->exit);
	mlx_delete_texture(objects->wall);
	mlx_delete_texture(objects->coin);
	mlx_delete_texture(objects->uplayer);
	mlx_delete_texture(objects->lplayer);
	mlx_delete_texture(objects->dplayer);
	mlx_delete_texture(objects->rplayer);
}

void	player_to_window(t_objects *objects, t_point p)
{
	mlx_image_to_window(objects->mlx, objects->dplayer_i, p.x * 64, p.y * 64);
	mlx_image_to_window(objects->mlx, objects->uplayer_i, p.x * 64, p.y * 64);
	mlx_image_to_window(objects->mlx, objects->lplayer_i, p.x * 64, p.y * 64);
	mlx_image_to_window(objects->mlx, objects->rplayer_i, p.x * 64, p.y * 64);
	set_p(objects);
	set_visible(objects, 'd');
}
