/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:00:01 by asemsey           #+#    #+#             */
/*   Updated: 2024/01/24 11:01:16 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	enemy_to_window(t_objects *objects, int y, int x)
{
	int	i;

	mlx_image_to_window(objects->mlx, objects->enemy0_i, x * 64, y * 64);
	i = mlx_image_to_window(objects->mlx, objects->enemy1_i, x * 64, y * 64);
	objects->enemy1_i->instances[i].enabled = false;
	i = mlx_image_to_window(objects->mlx, objects->enemy2_i, x * 64, y * 64);
	objects->enemy2_i->instances[i].enabled = false;
	i = mlx_image_to_window(objects->mlx, objects->enemy3_i, x * 64, y * 64);
	objects->enemy3_i->instances[i].enabled = false;
	i = mlx_image_to_window(objects->mlx, objects->enemy4_i, x * 64, y * 64);
	objects->enemy4_i->instances[i].enabled = false;
}

void	object_to_window_b(t_objects *objects, int y, int x)
{
	if (objects->map[y][x] == '1')
		mlx_image_to_window(objects->mlx, objects->wall_i, x * 64, y * 64);
	if (objects->map[y][x] == '0' || objects->map[y][x] == 'P'
		|| objects->map[y][x] == 'C' || objects->map[y][x] == 'B')
		mlx_image_to_window(objects->mlx, objects->floor_i, x * 64, y * 64);
	if (objects->map[y][x] == 'C')
	{
		objects->coinmap[y][x] = mlx_image_to_window(objects->mlx, \
			objects->coin_i, x * 64, y * 64);
	}
	if (objects->map[y][x] == 'B')
		enemy_to_window(objects, y, x);
	if (objects->map[y][x] == 'E')
		mlx_image_to_window(objects->mlx, objects->exit_i, x * 64, y * 64);
}

void	load_map_b(t_objects *objects)
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
			object_to_window_b(objects, p.y, p.x);
			if (objects->map[p.y][p.x] == 'P')
				player = p;
			p.x++;
		}
		p.y++;
	}
	player_to_window(objects, player);
}

void	key_hook_b(mlx_key_data_t keydata, void *param)
{
	t_objects	*objects;

	objects = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		ft_walk_b(objects, objects->p.y - 1, objects->p.x, 'u');
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		ft_walk_b(objects, objects->p.y, objects->p.x - 1, 'l');
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		ft_walk_b(objects, objects->p.y + 1, objects->p.x, 'd');
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		ft_walk_b(objects, objects->p.y, objects->p.x + 1, 'r');
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		exit(0);
}

// prepare game and open the window
void	init_game_b(char **map)
{
	t_point			size;
	t_objects		*objects;

	objects = malloc(sizeof(t_objects));
	if (!objects)
		return ;
	size = get_size(map);
	objects->coins_left = count_char(map, 'C');
	objects->enemies = count_char(map, 'B');
	objects->map = map;
	objects->steps = 0;
	objects->mlx = mlx_init(size.x * 64, size.y * 64, "SO_LONG", false);
	if (!objects->mlx)
		return ;
	load_pngs_b(objects);
	load_map_b(objects);
	mlx_key_hook(objects->mlx, key_hook_b, objects);
	mlx_loop_hook(objects->mlx, ft_loop_hook, objects);
	mlx_loop(objects->mlx);
	free_pngs_b(objects);
}
