/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:35:06 by asemsey           #+#    #+#             */
/*   Updated: 2024/01/17 15:20:17 by asemsey          ###   ########.fr       */
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

typedef struct s_objects
{
	mlx_t			*mlx;
	mlx_texture_t	*floor;
	mlx_texture_t	*exit;
	mlx_texture_t	*wall;
	mlx_texture_t	*coin;
	mlx_texture_t	*player;
	mlx_image_t		*floor_i;
	mlx_image_t		*exit_i;
	mlx_image_t		*wall_i;
	mlx_image_t		*coin_i;
	mlx_image_t		*player_i;
}	t_objects;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

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

// rest
void	init_game(char **map);

#endif