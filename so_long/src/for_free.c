/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoraji <yoraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:21:42 by yoraji            #+#    #+#             */
/*   Updated: 2025/03/17 03:40:46 by yoraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	exit_game(t_game *game, t_map *map)
{
	if (map->map != game->map.map)
		free_map(map);
	free_map(&game->map);
	free_game(game);
	exit(0);
}

int	cheack_elements(t_game *game)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width - 1)
		{
			if (game->map.map[y][x] == 'P' || game->map.map[y][x] == 'E'
				|| game->map.map[y][x] == 'C' || game->map.map[y][x] == '1'
				|| game->map.map[y][x] == '0')
				count++;
			x++;
		}
		y++;
	}
	if (count != (game->map.width - 1) * game->map.height)
		return (0);
	return (1);
}

void	free_game(t_game *game)
{
	if (game->img_background)
		mlx_destroy_image(game->mlx, game->img_background);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_player_up)
		mlx_destroy_image(game->mlx, game->img_player_up);
	if (game->img_player_down)
		mlx_destroy_image(game->mlx, game->img_player_down);
	if (game->img_player_left)
		mlx_destroy_image(game->mlx, game->img_player_left);
	if (game->img_player_right)
		mlx_destroy_image(game->mlx, game->img_player_right);
	if (game->img_door)
		mlx_destroy_image(game->mlx, game->img_door);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (i < map->height)
	{
		if (map->map[i])
			free(map->map[i]);
		i++;
	}
	free(map->map);
	map->map = NULL;
}
