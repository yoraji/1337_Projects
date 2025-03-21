/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoraji <yoraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:46:55 by yoraji            #+#    #+#             */
/*   Updated: 2025/03/17 06:51:10 by yoraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_collectibles_map(t_map *map)
{
	int	count;
	int	y;
	int	x;

	count = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width - 1)
		{
			if (map->map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

int	cheack_input_path(char **argv)
{
	int	i;

	i = 0;
	if (ft_strlen(argv[1]) < 4)
		return (0);
	while (argv[1][i] && argv[1][i] != '.')
		i++;
	if (argv[1][i] != 'b' && argv[1][i + 1] != 'e' && argv[1][i + 2] != 'r'
		&& argv[1][i + 3] != '\0')
		return (0);
	return (1);
}

int	ft_exit_game(t_game *game)
{
	exit_game(game, &game->map);
	return (0);
}
