/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:07:58 by asemsey           #+#    #+#             */
/*   Updated: 2024/01/18 13:06:51 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_objects	*objects;

	objects = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		ft_walk(objects, objects->p.y - 1, objects->p.x, 'u');
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		ft_walk(objects, objects->p.y, objects->p.x - 1, 'l');
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		ft_walk(objects, objects->p.y + 1, objects->p.x, 'd');
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		ft_walk(objects, objects->p.y, objects->p.x + 1, 'r');
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(0);
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
	objects->coins_left = count_char(map, 'C');
	objects->map = map;
	objects->steps = 0;
	objects->mlx = mlx_init(size.x * 64, size.y * 64, "SO_LONG",false);
	if (!objects->mlx)
		return ;
	load_pngs(objects);
	load_map(objects);
	mlx_loop_hook(objects->mlx, ft_hook, objects->mlx);
	mlx_key_hook(objects->mlx, key_hook, objects);
	mlx_loop(objects->mlx);
	free(objects);
	free_pngs(objects);
}
