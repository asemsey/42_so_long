/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:39:37 by asemsey           #+#    #+#             */
/*   Updated: 2024/01/08 15:42:38 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			break;
		i++;
		free(line);
		line = NULL;
	}
	close(fd);
	return (i);
}

char	**read_map(const char *filename)
{
	int		lines;
	int		fd;
	char	**map;

	lines = count_lines(filename);
	if (lines < 1)
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
	int	i;

	i = 0;
	while (map[i])
	{
		ft_putstr_fd(map[i], 1);
		i++;
	}
}

int	main(int argc, char const *argv[])
{
	char	**map;

	if (argc != 2)
		return (EXIT_FAILURE);
	map = read_map(argv[1]);
	if (!map)
		return (EXIT_FAILURE);
	print_map(map);
	free_all(map);
	return (0);
}
