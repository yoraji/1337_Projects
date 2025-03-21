/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoraji <yoraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:29:44 by yoraji            #+#    #+#             */
/*   Updated: 2025/03/17 06:15:30 by yoraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	empty_line(t_game *game)
{
	if (game->map.height == 0 || game->map.width == 0)
		return (0);
	return (1);
}

void	flood_fill(char **tmp, int x, int y)
{
	if (tmp[x][y] == '1' || tmp[x][y] == 'V' || tmp[x][y] == 'B')
		return ;
	tmp[x][y] = 'V';
	flood_fill(tmp, x - 1, y);
	flood_fill(tmp, x + 1, y);
	flood_fill(tmp, x, y - 1);
	flood_fill(tmp, x, y + 1);
}

int	is_map_rectangle(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->map.height - 1)
	{
		if (strlen_line(game->map.map[y]) != game->map.width)
			return (0);
		y++;
	}
	if (strlen_line(game->map.map[y]) == game->map.width
		|| strlen_line(game->map.map[y]) == game->map.width - 1)
		return (1);
	return (0);
}
