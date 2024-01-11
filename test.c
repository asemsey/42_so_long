/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 15:39:37 by asemsey           #+#    #+#             */
/*   Updated: 2024/01/09 18:03:35 by asemsey          ###   ########.fr       */
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
		// if ((ft_strlen(line) < 4 && ft_strchr(line, '\n')) || (ft_strlen(line) < 3 && !ft_strchr(line, '\n')))
		// {
		// 	free(line);
		// 	i = -1;
		// 	break;
		// }
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
	int	i;

	i = 0;
	while (map[i])
	{
		ft_putstr_fd(map[i], 1);
		write(1, "\n", 1);
		i++;
	}
}

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

void	leak()
{
	system("leaks so_long");
}

int	main(int argc, char const *argv[])
{
	char	**map;

	// atexit(leak);
	if (argc != 2)
		return (EXIT_FAILURE);
	map = read_map(argv[1]);
	if (!map)
		return (EXIT_FAILURE);
	remove_n(map);
	if (!valid_map(map))
	{
		free_all(map);
		return (1);
	}
	print_map(map);
	free_all(map);
	return (0);
}
