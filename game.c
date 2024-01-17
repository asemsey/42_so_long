/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:07:58 by asemsey           #+#    #+#             */
/*   Updated: 2024/01/17 16:07:08 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_pngs(t_objects *objects)
{
	objects->floor = mlx_load_png("assets/dungeon/floor.png");
	objects->exit = mlx_load_png("assets/dungeon/exit.png");
	objects->wall = mlx_load_png("assets/dungeon/wall.png");
	objects->coin = mlx_load_png("assets/items/g_rupee.png");
	objects->player = mlx_load_png("assets/link/link.png");
	objects->floor_i = mlx_texture_to_image(objects->mlx, objects->floor);
	objects->exit_i = mlx_texture_to_image(objects->mlx, objects->exit);
	objects->wall_i = mlx_texture_to_image(objects->mlx, objects->wall);
	objects->coin_i = mlx_texture_to_image(objects->mlx, objects->coin);
	objects->player_i = mlx_texture_to_image(objects->mlx, objects->player);
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

void	load_map(t_objects *objects, char **map)
{
	t_point	p;

	p.y = 0;
	while (map[p.y])
	{
		p.x = 0;
		while (map[p.y][p.x])
		{
			if (map[p.y][p.x] == '1')
				mlx_image_to_window(objects->mlx, objects->wall_i, p.x * 64, p.y * 64);
			if (map[p.y][p.x] == '0' || map[p.y][p.x] == 'P' || map[p.y][p.x] == 'C')
				mlx_image_to_window(objects->mlx, objects->floor_i, p.x * 64, p.y * 64);
			if (map[p.y][p.x] == 'C')
				mlx_image_to_window(objects->mlx, objects->coin_i, p.x * 64, p.y * 64);
			if (map[p.y][p.x] == 'E')
				mlx_image_to_window(objects->mlx, objects->exit_i, p.x * 64, p.y * 64);
			if (map[p.y][p.x] == 'P')
				mlx_image_to_window(objects->mlx, objects->player_i, p.x * 64, p.y * 64);
			p.x++;
		}
		p.y++;
	}
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_objects	*objects;

	objects = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		objects->player_i->instances[0].y -= 64;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		objects->player_i->instances[0].x -= 64;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		objects->player_i->instances[0].y += 64;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		objects->player_i->instances[0].x += 64;
}

static void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	(void)mlx;
}

void	init_game(char **map)
{
	t_point			size;
	t_objects		*objects;

	objects = malloc(sizeof(t_objects));
	if (!objects)
		return ;
	size = get_size(map);
	objects->mlx = mlx_init(size.x * 64, size.y * 64, "SO_LONG",false);
	if (!objects->mlx)
		return ;
	load_pngs(objects);
	load_map(objects, map);
	mlx_loop_hook(objects->mlx, ft_hook, objects->mlx);
	mlx_key_hook(objects->mlx, key_hook, objects);
	mlx_loop(objects->mlx);
	free(objects);
	free_pngs(objects);
}
