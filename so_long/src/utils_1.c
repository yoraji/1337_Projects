/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoraji <yoraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:32:52 by yoraji            #+#    #+#             */
/*   Updated: 2025/03/17 03:37:30 by yoraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	strlen_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

void	find_player_position(t_map *map, t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width - 1)
		{
			if (map->map[y][x] == 'P')
			{
				map->player_x = x;
				map->player_y = y;
				vars->player_x = x;
				vars->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	is_surrended_by_wall(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width - 1)
		{
			if (y == 0 || y == game->map.height - 1 || x == 0
				|| x == game->map.width - 2)
			{
				if (game->map.map[y][x] != '1')
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	count_collectibles_game(t_game *game)
{
	int	count;
	int	x;
	int	y;

	y = 0;
	count = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width - 1)
		{
			if (game->map.map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}
