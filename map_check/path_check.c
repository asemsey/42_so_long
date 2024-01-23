/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:14:35 by asemsey           #+#    #+#             */
/*   Updated: 2024/01/23 19:47:00 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**copy_map(char **map)
{
	t_point	size;
	char	**new;

	size = get_size(map);
	new = (char **)malloc(sizeof(char *) * (size.y + 1));
	if (!new)
		return (NULL);
	size.y = 0;
	while (map[size.y])
	{
		new[size.y] = ft_strdup(map[size.y]);
		if (!new[size.y])
		{
			free_all(new);
			return (NULL);
		}
		size.y++;
	}
	new[size.y] = NULL;
	return (new);
}

t_point	get_size(char **map)
{
	t_point	p;

	p.y = 0;
	while (map[p.y])
		p.y++;
	p.x = ft_strlen(map[0]);
	return (p);
}

t_point	get_begin(char **map, char start)
{
	t_point	p;

	p.y = 0;
	while (map[p.y])
	{
		p.x = 0;
		while (map[p.y][p.x])
		{
			if (map[p.y][p.x] == start)
				return (p);
			p.x++;
		}
		p.y++;
	}
	p.x = 0;
	p.y = 0;
	return (p);
}

int	bad_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P'
				&& map[i][j] != 'E' && map[i][j] != 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	valid_map(char **map)
{
	if (!map || !*map)
		return (0);
	if (!rectangle(map) || !characters(map) || !wall(map))
		return (0);
	if (!valid_path(map))
		return (0);
	return (1);
}
