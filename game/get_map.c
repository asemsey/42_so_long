/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:23:41 by asemsey           #+#    #+#             */
/*   Updated: 2024/01/24 10:44:17 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// count lines in the given file
int	count_lines(const char *filename)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		i++;
		free(line);
		line = NULL;
	}
	close(fd);
	return (i);
}

// return lines stored in file as array
char	**read_map(const char *filename)
{
	int		lines;
	int		fd;
	char	**map;

	lines = count_lines(filename);
	if (lines < 3)
		return (NULL);
	map = (char **)malloc(sizeof(char *) * (lines + 1));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	lines = 0;
	while (1)
	{
		map[lines] = get_next_line(fd);
		if (!map[lines])
			break ;
		lines++;
	}
	return (map);
}

void	print_map(char **map)
{
	int		i;
	char	c;

	i = 0;
	while (map[i])
	{
		c = i + '0';
		write(1, &c, 1);
		write(1, "   ", 3);
		ft_putstr_fd(map[i], 1);
		write(1, "\n", 1);
		i++;
	}
}

// remove \n from all lines
void	remove_n(char **map)
{
	int		i;
	char	*m;

	i = 0;
	while (map[i])
	{
		m = map[i];
		while (*m)
		{
			if (*m == '\n')
				*m = '\0';
			m++;
		}
		i++;
	}
	i--;
	while (map[i] && *map[i] == '\0')
	{
		free(map[i]);
		map[i] = NULL;
		i--;
	}
}
