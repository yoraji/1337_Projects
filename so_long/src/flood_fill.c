/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoraji <yoraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:00:48 by marvin            #+#    #+#             */
/*   Updated: 2025/03/17 03:37:05 by yoraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_hook(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->vars.player_x;
	new_y = game->vars.player_y;
	if (keycode == 'w' || keycode == KEY_UP)
		new_y--;
	else if (keycode == 's' || keycode == KEY_DOWN)
		new_y++;
	else if (keycode == 'a' || keycode == KEY_LEFT)
		new_x--;
	else if (keycode == 'd' || keycode == KEY_RIGHT)
		new_x++;
	else if (keycode == KEY_ESC)
		exit_game(game, &game->map);
	if (game->map.map[new_y][new_x] != '1')
	{
		update_player_position(game, new_x, new_y, keycode);
		render_map(game, &game->map);
	}
	return (0);
}

int	count_exits(t_game *game)
{
	int	count;
	int	y;
	int	x;

	y = 0;
	count = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width - 1)
		{
			if (game->map.map[y][x] == 'E')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

char	*find_starting_position(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		if (map->map[y] == NULL)
			continue ;
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'P')
			{
				map->player_x = x;
				map->player_y = y;
				return (&map->map[y][x]);
			}
			x++;
		}
		y++;
	}
	return (NULL);
}

void	free_vars(t_vars *vars)
{
	if (vars != NULL)
	{
		vars->player_x = 0;
		vars->player_y = 0;
		vars->moves = 0;
	}
}
