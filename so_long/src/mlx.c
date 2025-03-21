/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoraji <yoraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:28:09 by yoraji            #+#    #+#             */
/*   Updated: 2025/03/17 06:57:18 by yoraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	is_one_player(t_map *map)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width - 1)
		{
			if (map->map[y][x] == 'P')
				count++;
			x++;
		}
		y++;
	}
	if (count != 1)
		return (0);
	return (1);
}

static void	free_s(char **s, int height)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (i < height)
	{
		if (s[i])
			free(s[i]);
		i++;
	}
	free(s);
	s = NULL;
}

static char	**copy_map(t_game *game)
{
	char	**tmp;
	int		y;

	tmp = malloc(sizeof(char *) * game->map.height);
	if (!tmp)
		return (NULL);
	y = 0;
	while (y < game->map.height)
	{
		tmp[y] = malloc(game->map.width);
		if (!tmp[y])
			return (free_s(tmp, y), NULL);
		ft_memcpy(tmp[y], game->map.map[y], game->map.width - 1);
		y++;
	}
	return (tmp);
}

static int	cheack_reached_col(t_game *game)
{
	char	**tmp;
	int		x;
	int		y;

	tmp = copy_map(game);
	if (!tmp)
		return (0);
	flood_fill(tmp, game->map.player_y, game->map.player_x);
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width - 1)
		{
			if (tmp[y][x] == 'C')
			{
				free_s(tmp, game->map.height);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (free_s(tmp, game->map.height), 1);
}

int	check_map(t_game *game, t_map *map)
{
	if (empty_line(game) == 0)
		return (0);
	if (is_surrended_by_wall(game) == 1 || count_collectibles_game(game) < 1)
		return (0);
	if (count_exits(game) != 1)
		return (0);
	if (is_map_rectangle(game) == 0)
		return (0);
	if (is_one_player(map) != 1 || cheack_elements(game) == 0)
		return (0);
	find_player_position(map, &game->vars);
	if (!cheack_reached_col(game))
		return (0);
	return (1);
}
