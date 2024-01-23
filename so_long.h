/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:35:06 by asemsey           #+#    #+#             */
/*   Updated: 2024/01/23 19:51:54 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "./gnl/get_next_line_bonus.h"
# include "./libft/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_objects
{
	char			**map;
	int32_t			**coinmap;
	int				steps;
	int				enemies;
	int				coins_left;
	t_point			p;
	mlx_t			*mlx;
	mlx_texture_t	*floor;
	mlx_texture_t	*exit;
	mlx_texture_t	*wall;
	mlx_texture_t	*coin;
	mlx_texture_t	*uplayer;
	mlx_texture_t	*lplayer;
	mlx_texture_t	*dplayer;
	mlx_texture_t	*rplayer;
	mlx_texture_t	*enemy0;
	mlx_texture_t	*enemy1;
	mlx_texture_t	*enemy2;
	mlx_texture_t	*enemy3;
	mlx_texture_t	*enemy4;
	mlx_image_t		*floor_i;
	mlx_image_t		*exit_i;
	mlx_image_t		*wall_i;
	mlx_image_t		*coin_i;
	mlx_image_t		*uplayer_i;
	mlx_image_t		*lplayer_i;
	mlx_image_t		*dplayer_i;
	mlx_image_t		*rplayer_i;
	mlx_image_t		*enemy0_i;
	mlx_image_t		*enemy1_i;
	mlx_image_t		*enemy2_i;
	mlx_image_t		*enemy3_i;
	mlx_image_t		*enemy4_i;
}	t_objects;

// map
char	**read_map(const char *filename);
void	print_map(char **map);
int		valid_map(char **map);
int		valid_path(char **map);
int		count_lines(const char *filename);
void	remove_n(char **map);
int		count_char(char **map, char c);
int		bad_chars(char **map);
int		characters(char **map);
int		rectangle(char **map);
int		wall(char **map);
t_point	get_size(char **map);
t_point	get_begin(char **map, char start);
char	**copy_map(char **map);

// game
void	init_game(char **map);
void	load_pngs(t_objects *objects);
void	to_image(t_objects *objects);
void	free_pngs(t_objects *objects);
void	free_all_int(int32_t **ints, t_point size);
void	load_map(t_objects *objects);
void	get_coinmap(t_objects *objects);
void	coin_check(t_objects *objects, int y, int x);
void	player_to_window(t_objects *objects, t_point p);
void	set_coordinates(t_objects *objects, int y, int x);
void	set_p(t_objects *objects);
void	set_visible(t_objects *objects, char dir);
void	ft_walk(t_objects *objects, int y, int x, char dir);

// bonus
int		valid_path_b(char **map);
int		valid_map_b(char **map);
void	init_game_b(char **map);
void	ft_loop_hook(void *param);
void	ft_walk_b(t_objects *objects, int y, int x, char dir);
void	load_pngs_b(t_objects *objects);
void	free_pngs_b(t_objects *objects);

#endif