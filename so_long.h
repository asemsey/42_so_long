/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:35:06 by asemsey           #+#    #+#             */
/*   Updated: 2024/01/18 13:06:26 by asemsey          ###   ########.fr       */
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
	int				steps;
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
	mlx_image_t		*floor_i;
	mlx_image_t		*exit_i;
	mlx_image_t		*wall_i;
	mlx_image_t		*coin_i;
	mlx_image_t		*uplayer_i;
	mlx_image_t		*lplayer_i;
	mlx_image_t		*dplayer_i;
	mlx_image_t		*rplayer_i;
}	t_objects;

// map
void	print_map(char **map);
int		valid_map(char **map);
int		valid_path(char **map);
int		count_char(char **map, char c);
int		characters(char **map);
int		rectangle(char **map);
int		wall(char **map);
t_point	get_size(char **map);
t_point	get_begin(char **map, char start);
char	**copy_map(char **map);

// game
void	init_game(char **map);
void	load_pngs(t_objects *objects);
void	free_pngs(t_objects *objects);
void	load_map(t_objects *objects);
void	set_p(t_objects *objects);
void	set_visible(t_objects *objects, char dir);
void	ft_walk(t_objects *objects, int y, int x, char dir);

#endif