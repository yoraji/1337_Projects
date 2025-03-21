/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoraji <yoraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 20:04:40 by yoraji            #+#    #+#             */
/*   Updated: 2025/03/17 03:43:42 by yoraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_window(t_game *game, t_map *map)
{
	game->win = mlx_new_window(game->mlx, (map->width - 1) * TILE_SIZE,
			map->height * TILE_SIZE, "so_long");
}

void	load_images(t_game *game, t_map *map)
{
	(void)map;
	game->img_background = mlx_xpm_file_to_image(game->mlx,
			"./textures/backgroud/black.xpm", &game->img_width,
			&game->img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"./textures/wall/wall_00.xpm", &game->img_width, &game->img_height);
	game->img_player_up = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/ship_up.xpm", &game->img_width,
			&game->img_height);
	game->img_player_down = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/ship_down.xpm", &game->img_width,
			&game->img_height);
	game->img_player_left = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/ship_left.xpm", &game->img_width,
			&game->img_height);
	game->img_player_right = mlx_xpm_file_to_image(game->mlx,
			"./textures/player/ship_right.xpm", &game->img_width,
			&game->img_height);
	game->img_door = mlx_xpm_file_to_image(game->mlx, "./textures/goal/tv.xpm",
			&game->img_width, &game->img_height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"./textures/rewards/reward.xpm", &game->img_width,
			&game->img_height);
}

void	game_img_init(t_game *game, t_map *map)
{
	init_window(game, map);
	load_images(game, map);
	if (!game->img_background || !game->img_wall || !game->img_player_up
		|| !game->img_player_down || !game->img_player_left
		|| !game->img_player_right || !game->img_door || !game->img_collectible)
		exit_game(game, map);
}
