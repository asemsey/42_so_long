/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:06:16 by asemsey           #+#    #+#             */
/*   Updated: 2024/01/23 17:31:04 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	load_enemies(t_objects *objects)
{
	objects->enemy0 = mlx_load_png("assets/enemies/blob0.png");
	if (!objects->enemy0)
		exit(1);
	objects->enemy1 = mlx_load_png("assets/enemies/blob1.png");
	if (!objects->enemy1)
		exit(1);
	objects->enemy2 = mlx_load_png("assets/enemies/blob2.png");
	if (!objects->enemy2)
		exit(1);
	objects->enemy3 = mlx_load_png("assets/enemies/blob3.png");
	if (!objects->enemy3)
		exit(1);
	objects->enemy4 = mlx_load_png("assets/enemies/blob4.png");
	if (!objects->enemy4)
		exit(1);
}

void	to_image_enemies(t_objects *objects)
{
	objects->enemy0_i = mlx_texture_to_image(objects->mlx, objects->enemy0);
	if (!objects->enemy0_i)
		exit(1);
	objects->enemy1_i = mlx_texture_to_image(objects->mlx, objects->enemy1);
	if (!objects->enemy1_i)
		exit(1);
	objects->enemy2_i = mlx_texture_to_image(objects->mlx, objects->enemy2);
	if (!objects->enemy2_i)
		exit(1);
	objects->enemy3_i = mlx_texture_to_image(objects->mlx, objects->enemy3);
	if (!objects->enemy3_i)
		exit(1);
	objects->enemy4_i = mlx_texture_to_image(objects->mlx, objects->enemy4);
	if (!objects->enemy4_i)
		exit(1);
}

void	load_pngs_b(t_objects *objects)
{
	load_pngs(objects);
	load_enemies(objects);
	to_image(objects);
	to_image_enemies(objects);
}

void	delete_images(t_objects *objects)
{
	mlx_delete_image(objects->mlx, objects->floor_i);
	mlx_delete_image(objects->mlx, objects->exit_i);
	mlx_delete_image(objects->mlx, objects->wall_i);
	mlx_delete_image(objects->mlx, objects->coin_i);
	mlx_delete_image(objects->mlx, objects->uplayer_i);
	mlx_delete_image(objects->mlx, objects->lplayer_i);
	mlx_delete_image(objects->mlx, objects->dplayer_i);
	mlx_delete_image(objects->mlx, objects->rplayer_i);
	mlx_delete_image(objects->mlx, objects->enemy0_i);
	mlx_delete_image(objects->mlx, objects->enemy1_i);
	mlx_delete_image(objects->mlx, objects->enemy2_i);
	mlx_delete_image(objects->mlx, objects->enemy3_i);
	mlx_delete_image(objects->mlx, objects->enemy4_i);
}

void	free_pngs_b(t_objects *objects)
{
	delete_images(objects);
	mlx_delete_texture(objects->floor);
	mlx_delete_texture(objects->exit);
	mlx_delete_texture(objects->wall);
	mlx_delete_texture(objects->coin);
	mlx_delete_texture(objects->uplayer);
	mlx_delete_texture(objects->lplayer);
	mlx_delete_texture(objects->dplayer);
	mlx_delete_texture(objects->rplayer);
	mlx_delete_texture(objects->enemy0);
	mlx_delete_texture(objects->enemy1);
	mlx_delete_texture(objects->enemy2);
	mlx_delete_texture(objects->enemy3);
	mlx_delete_texture(objects->enemy4);
	free_all_int(objects->coinmap, get_size(objects->map));
	free_all(objects->map);
	mlx_terminate(objects->mlx);
	free(objects);
}
