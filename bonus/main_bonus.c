/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:18:47 by asemsey           #+#    #+#             */
/*   Updated: 2024/01/23 16:22:23 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	leak(void)
{
	system("leaks so_long");
}

int	main(int argc, char const *argv[])
{
	char	**map;

	atexit(leak);
	if (argc != 2)
		return (EXIT_FAILURE);
	map = read_map(argv[1]);
	if (!map)
	{
		write(2, "Error\ncouldn't create map\n", 26);
		return (EXIT_FAILURE);
	}
	remove_n(map);
	if (!valid_map_b(map))
	{
		free_all(map);
		return (EXIT_FAILURE);
	}
	init_game_b(map);
	return (EXIT_SUCCESS);
}
