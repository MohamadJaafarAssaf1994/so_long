/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:02:09 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/28 18:09:14 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "fcntl.h"
# include "libft/libft.h"
# include "mlx.h"
# include <string.h>
# include <errno.h>

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_map
{
	char	**map_array;
	int		wi;
	int		length;
}			t_map;

typedef struct s_img
{
	void	*img;
	int		length;
	int		wi;
}			t_img;

typedef struct s_enemy
{
	t_point	e_pt;
	int		dir;
}			t_enemy;

typedef struct s_game
{
	void	*mlx;
	void	*win;

	t_map	*map;

	t_point	p_pt;

	int		moves;
	int		collectibles;
	int		collected;

	t_point	exit_point;

	t_img	wall;
	t_img	floor;
	t_img	player_img;
	t_img	exit_img;
	t_img	collectible_img;
	t_img	enemy_img;
	t_img	sc_img;

	t_img	player_frames[2][4];
	int		cu_fr_ch;
	int		cu_fr_sa;
	int		frame_delay;

	t_enemy	enemy_player;

	t_img	enemy_frames[2];
	int		en_frame;
	int		enemy_counter;

}			t_game;

void		parse_game(t_game *game, char *filename);
void		start_game(t_game *game);
t_map		*file_to_map(char *filename);
void		print_tab(char **tab);
int			check_invalid_characters(char **map);
int			tab_len(char **tab);
int			check_is_rectangular(char **map);
int			ends_with_new_line(char *line);
int			map_contain_char(char **map, char c);
int			check_start_exit_coll(char **map);
int			is_valid_char(char c);
int			check_is_empty(char **map);
int			check_walls(char **map);
int			has_right_wall(char **map, int *message_flag);
int			has_left_wall(char **map, int *message_flag);
int			has_upper_wall(char **map, int *message_flag);
int			has_lower_wall(char **map, int *message_flag);
int			check_has_valid_path(char **map);
char		**copy_map(char **map);
void		map_fill(char **map, char to_fill);
void		init_start(char **map, t_point *start);
void		fill(char **map, t_point curr, char to_fill);
void		ft_free_all(char **arr);
int			lines_count(char *file_path);
t_point		find_coordinates_by_char(t_game *game, char c);
int			count_coll_by_char(t_game *game);
t_point		find_coordinates_enemy(t_game *game);
void		error_exit(char *message);
void		load_textures(t_game *game, t_img *img, char *path);
void		render_map(t_game *game);
void		setup_hooks(t_game *game);
void		draw_tile(t_game *game, char tile, int x, int y);
int			close_game(void *param);
void		cleanup(t_game *game);
void		load_all_textures(t_game *game);
int			open_file(char *path, char *filename, t_map *map);
void		set_map_dimensions(t_map *map);
void		destroy_enemy_images(t_game *game);
void		destroy_player_images(t_game *game);
int			key_press(int keycode, void *param);
void		move_player(t_game *game, int x, int y);
int			name_extension_check(char *filename);
void		check_enemy_collision(t_game *game);

#endif
