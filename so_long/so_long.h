/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoraji <yoraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 16:01:39 by marvin            #+#    #+#             */
/*   Updated: 2025/03/17 06:16:36 by yoraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h"
# include "/usr/include/minilibx-linux/mlx.h"
# include "./printf/ft_printf.h"
# include <stdlib.h>

# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307
# define TILE_SIZE 32

typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
	int		player_x;
	int		player_y;
}			t_map;

typedef struct s_vars
{
	int		player_x;
	int		player_y;
	int		moves;
}			t_vars;

typedef struct s_game
{
	t_map	map;
	t_vars	vars;
	int		total_collectibles;
	int		collected;
	void	*mlx;
	void	*win;
	void	*img_door;
	void	*img_background;
	void	*img_wall;
	void	*img_player_up;
	void	*img_player_down;
	void	*img_player_left;
	void	*img_player_right;
	void	*img_player;
	void	*img_collectible;
	int		img_width;
	int		img_height;
	int		mov;
}			t_game;

void		up(t_game *game);
void		down(t_game *game);
void		left(t_game *game);
void		right(t_game *game);
int			cheack_elements(t_game *game);
void		exit_game(t_game *game, t_map *map);
void		render_map(t_game *game, t_map *map);
char		*find_starting_position(t_map *map);
void		find_player_position(t_map *map, t_vars *vars);
void		update_player_position(t_game *game, int new_x, int new_y,
				int keycode);
int			count_collectibles_map(t_map *map);
int			key_hook(int keycode, t_game *game);
int			read_map(char *filename, t_map *map);
int			check_map(t_game *game, t_map *map);
int			count_exits(t_game *game);
int			count_collectibles_game(t_game *game);
void		flood_fill(char **tmp, int x, int y);
void		free_vars(t_vars *vars);
void		*ft_memcpy(void *dst, const void *src, size_t n);
size_t		ft_strlen(const char *str);
char		*ft_strncpy(char *dest, char *src, unsigned int n);
int			is_surrended_by_wall(t_game *game);
void		free_map(t_map *map);
void		free_game(t_game *game);
int			cheack_input_path(char **argv);
void		game_img_init(t_game *game, t_map *map);
int			strlen_line(char *line);
int			ft_exit_game(t_game *game);
int			is_map_rectangle(t_game *game);
int			empty_line(t_game *game);
#endif
