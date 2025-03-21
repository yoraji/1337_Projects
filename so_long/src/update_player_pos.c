/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoraji <yoraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:01:06 by marvin            #+#    #+#             */
/*   Updated: 2025/03/20 19:45:51 by yoraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	handle_tile_interaction(t_game *game, int new_x, int new_y)
{
	if (game->map.map[new_y][new_x] == 'C')
	{
		game->collected++;
		game->map.map[new_y][new_x] = '0';
	}
	else if (game->map.map[new_y][new_x] == 'E')
	{
		if (game->collected == game->total_collectibles)
		{
			ft_printf("You Win in %d Moves!!\n", game->mov + 1);
			exit_game(game, &game->map);
		}
	}
	if (game->map.map[game->vars.player_y][game->vars.player_x] != 'E')
		game->map.map[game->vars.player_y][game->vars.player_x] = '0';
	else if (game->collected < game->total_collectibles)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_door,
			game->vars.player_x * TILE_SIZE, game->vars.player_y * TILE_SIZE);
	}
}

int	is_in(int keycode)
{
	if (keycode == 'w' || keycode == KEY_UP || keycode == 's'
		|| keycode == KEY_DOWN || keycode == 'a'
		|| keycode == KEY_LEFT || keycode == 'd'
		|| keycode == KEY_RIGHT)
		return (1);
	return (0);
}

void	update_player_position(t_game *game, int new_x, int new_y, int keycode)
{
	handle_tile_interaction(game, new_x, new_y);
	if (keycode == 'w' || keycode == KEY_UP)
		game->img_player = game->img_player_up;
	else if (keycode == KEY_DOWN || keycode == 's')
		game->img_player = game->img_player_down;
	else if (keycode == KEY_LEFT || keycode == 'a')
		game->img_player = game->img_player_left;
	else if (keycode == KEY_RIGHT || keycode == 'd')
		game->img_player = game->img_player_right;
	game->vars.player_x = new_x;
	game->vars.player_y = new_y;
	if (game->map.map[new_y][new_x] != 'E')
	{
		game->map.map[new_y][new_x] = 'P';
		if (is_in(keycode))
		{
			ft_printf("Movements: %d\n", ++(game->mov));
		}
	}
}
