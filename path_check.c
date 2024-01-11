/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:14:35 by asemsey           #+#    #+#             */
/*   Updated: 2024/01/11 15:15:53 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(char **map)
{
	t_point	size;
	int		len;
	char	**new;

	size = get_size(map);
	new = (char **)malloc(sizeof(char *) * (size.y + 1));
	if (!new)
		return (NULL);
	len = 0;
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
	p.y--;
	p.x = ft_strlen(map[0]) - 1;
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
