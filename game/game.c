/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:07:58 by asemsey           #+#    #+#             */
/*   Updated: 2024/01/24 10:48:48 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// coinmap stores the index of a coin object at the correct coordinates
void	get_coinmap(t_objects *objects)
{
	t_point	size;
	t_point	i;

	size = get_size(objects->map);
	i.y = 0;
	objects->coinmap = malloc((size.y + 1) * sizeof(int32_t *));
	if (!objects->coinmap)
		exit(1);
	while (i.y < size.y)
	{
		objects->coinmap[i.y] = (int32_t *)malloc(size.x * sizeof(int32_t));
		if (!objects->coinmap[i.y])
			exit(1);
		i.x = 0;
		while (i.x < size.x)
		{
			objects->coinmap[i.y][i.x] = -2;
			i.x++;
		}
		i.y++;
	}
	objects->coinmap[i.y] = NULL;
}

void	object_to_window(t_objects *objects, int y, int x)
{
	if (objects->map[y][x] == '1')
		mlx_image_to_window(objects->mlx, objects->wall_i, x * 64, y * 64);
	if (objects->map[y][x] == '0' || objects->map[y][x] == 'P'
		|| objects->map[y][x] == 'C')
		mlx_image_to_window(objects->mlx, objects->floor_i, x * 64, y * 64);
	if (objects->map[y][x] == 'C')
	{
		objects->coinmap[y][x] = mlx_image_to_window(objects->mlx, \
			objects->coin_i, x * 64, y * 64);
	}
	if (objects->map[y][x] == 'E')
		mlx_image_to_window(objects->mlx, objects->exit_i, x * 64, y * 64);
}

// displays all images according to the map
void	load_map(t_objects *objects)
{
	t_point	p;
	t_point	player;

	get_coinmap(objects);
	p.y = 0;
	while (objects->map[p.y])
	{
		p.x = 0;
		while (objects->map[p.y][p.x])
		{
			object_to_window(objects, p.y, p.x);
			if (objects->map[p.y][p.x] == 'P')
				player = p;
			p.x++;
		}
		p.y++;
	}
	player_to_window(objects, player);
}

// walk with WASD, exit with ESC
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

// prepare game and open the window
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
	objects->mlx = mlx_init(size.x * 64, size.y * 64, "SO_LONG", false);
	if (!objects->mlx)
		return ;
	load_pngs(objects);
	load_map(objects);
	mlx_key_hook(objects->mlx, key_hook, objects);
	mlx_loop(objects->mlx);
	free_pngs(objects);
}
