/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoraji <yoraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:47:52 by marvin            #+#    #+#             */
/*   Updated: 2025/03/17 06:50:35 by yoraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	render_tile(t_game *game, int x, int y, char tile)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img_background, x
		* TILE_SIZE, y * TILE_SIZE);
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'P' || (tile == 'E' && game->vars.player_x == x
			&& game->vars.player_y == y
			&& game->collected < game->total_collectibles))
		mlx_put_image_to_window(game->mlx, game->win, game->img_player, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img_door, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img_collectible, x
			* TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_game *game, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width - 1)
		{
			render_tile(game, x, y, map->map[y][x]);
			x++;
		}
		y++;
	}
}

void	fun_hooks(t_game *game)
{
	mlx_hook(game->win, 17, 1L << 17, ft_exit_game, game);
	mlx_hook(game->win, 2, 1, key_hook, game);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_map	map;

	game = (t_game){0};
	map = (t_map){0};
	if (argc != 2 || cheack_input_path(argv))
		return (write(2, "Error\n", 6), exit_game(&game,
				&game.map), 1);
	if (!read_map(argv[1], &game.map))
		return (write(2, "Error\n", 6), free_game(&game), 1);
	if (!check_map(&game, &game.map))
		return (write(2, "Error\n", 6), exit_game(&game, &map), 0);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (write(2, "Error\n", 6), exit_game(&game, &game.map), 1);
	game_img_init(&game, &game.map);
	game.img_player = game.img_player_down;
	game.total_collectibles = count_collectibles_map(&game.map);
	render_map(&game, &game.map);
	fun_hooks(&game);
	mlx_loop(game.mlx);
	free_vars(&game.vars);
	exit_game(&game, &game.map);
}
