/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoraji <yoraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:30:25 by marvin            #+#    #+#             */
/*   Updated: 2025/03/17 08:52:30 by yoraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_map_dimensions(char *filename, t_map *map)
{
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), 0);
	map->width = ft_strlen(line);
	while (line)
	{
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (1);
}

void	free_map_i(t_map *map, int last)
{
	int	i;

	if (!map || !map->map)
		return ;
	i = 0;
	while (i < last)
	{
		if (map->map[i])
		{
			free(map->map[i]);
		}
		i++;
	}
	free(map->map);
}

int	ft_copy_map(char *filename, t_map *map)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (free(line), free_map(map), free(filename), 0);
	while (line != NULL)
	{
		map->map[i] = malloc(strlen_line(line) + 1);
		if (!(map->map[i]))
			return (free_map_i(map, i), free(line), 0);
		ft_strncpy(map->map[i], line, strlen_line(line));
		map->map[i][strlen_line(line)] = '\0';
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (1);
}

int	read_map(char *filename, t_map *map)
{
	int	i;

	i = 0;
	if (!get_map_dimensions(filename, map))
		return (0);
	map->map = malloc(map->height * sizeof(char *));
	if (!map->map)
		return (0);
	if (!ft_copy_map(filename, map))
		return (free_map(map), 0);
	return (1);
}
