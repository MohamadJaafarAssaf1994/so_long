/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 19:14:15 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/24 13:52:24 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_enemy_collision(t_game *game)
{
	if (game->player_point.x == game->enemy_player.enemy_point.x
		&& game->player_point.y == game->enemy_player.enemy_point.y)
	{
		ft_printf("Game Over\n");
		close_game(game);
	}
}
static void	player_hits_collectible(t_game *game, int y, int x_coll, int y_coll)
{
	game->moves++;
	game->collected++;
	game->map->map_array[x_coll][y_coll] = 'P';
	game->map->map_array[game->player_point.x][game->player_point.y] = '0';
	game->player_point.x = x_coll;
	game->player_point.y = y_coll;
	if ((y == -1 && game->current_frame_change == 1) || (y == 1
			&& game->current_frame_change == 0))
		game->current_frame_same = (game->current_frame_same + 1) % 4;
	else if ((y == 1 && game->current_frame_change == 1) || (y == -1
			&& game->current_frame_change == 0))
		game->current_frame_change = (game->current_frame_change + 1) % 2;
	render_map(game);
}
static void	player_free_go(t_game *game, int y, int next_pos_x, int next_pos_y)
{
	game->moves++;
	game->map->map_array[game->player_point.x][game->player_point.y] = '0';
	game->map->map_array[next_pos_x][next_pos_y] = 'P';
	game->player_point.x = next_pos_x;
	game->player_point.y = next_pos_y;
	if ((y == -1 && game->current_frame_change == 1) || (y == 1
			&& game->current_frame_change == 0))
		game->current_frame_same = (game->current_frame_same + 1) % 4;
	else if ((y == 1 && game->current_frame_change == 1) || (y == -1
			&& game->current_frame_change == 0))
		game->current_frame_change = (game->current_frame_change + 1) % 2;
	check_enemy_collision(game);
	render_map(game);
}

static void	player_hits_exit(t_game *game, int y, int next_pos_x,
		int next_pos_y)
{
	if (game->collected != game->collectibles)
		return ;
	game->moves++;
	ft_printf("You win!\n");
	close_game(game);
	game->map->map_array[game->player_point.x][game->player_point.y] = '0';
	game->map->map_array[next_pos_x][next_pos_y] = 'P';
	game->player_point.x = next_pos_x;
	game->player_point.y = next_pos_y;
	if ((y == -1 && game->current_frame_change == 1) || (y == 1
			&& game->current_frame_change == 0))
		game->current_frame_same = (game->current_frame_same + 1) % 4;
	else if ((y == 1 && game->current_frame_change == 1) || (y == -1
			&& game->current_frame_change == 0))
		game->current_frame_change = (game->current_frame_change + 1) % 2;
	render_map(game);
}
static void	move_player(t_game *game, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = game->player_point.x + x;
	new_y = game->player_point.y + y;
	if (game->map->map_array[new_x][new_y] == '1')
		return ;
	else if (game->map->map_array[new_x][new_y] == 'C')
		player_hits_collectible(game, y, new_x, new_y);
	else if (game->map->map_array[new_x][new_y] == '0')
		player_free_go(game, y, new_x, new_y);
	else if (game->map->map_array[new_x][new_y] == 'E')
		player_hits_exit(game, y, new_x, new_y);
}

static int	key_press(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == ESC)
		close_game(game);
	else if (keycode == W)
		move_player(game, -1, 0);
	else if (keycode == S)
		move_player(game, 1, 0);
	else if (keycode == A)
		move_player(game, 0, -1);
	else if (keycode == D)
		move_player(game, 0, 1);
	return (0);
}
int	close_game(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	cleanup(game);
	exit(0);
	return (0);
}
void	enemy_loop(t_game *game)
{
	game->frame_delay++;
	if (game->frame_delay < 40000)
		return ;
	game->frame_delay = 0;
	if (game->enemy_counter % 3 == 0)
	{
		game->enemy_player.dir = game->enemy_player.dir * (-1);
		game->enemy_counter++;
	}
	game->enemy_counter++;
	game->enemy_player.enemy_point.y = game->enemy_player.enemy_point.y
		+ game->enemy_player.dir;
	game->enemy_current_frame = (game->enemy_current_frame + 1) % 2;
	check_enemy_collision(game);
	render_map(game);
}

void	setup_hooks(t_game *game)
{
	mlx_key_hook(game->win, key_press, game);
	/*#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wcast-function-type"*/
	mlx_loop_hook(game->mlx, (void *)enemy_loop, game);
	mlx_hook(game->win, 17, 0, (void *)close_game, game);
	/*#pragma GCC diagnostic pop*/
}

void	start_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit("Error\nmlx_init failed: run from a graphical X11 session.\n");
	game->win = mlx_new_window(game->mlx, game->map->length * 64,
			(game->map->width + 1) * 64, "so_long");
	if (!game->win)
	{
		cleanup(game);
		error_exit("Error\nmlx_new_window failed\n");
	}
	load_all_textures(game);
	render_map(game);
	setup_hooks(game);
	mlx_loop(game->mlx);
}

static void	destroy_player_images(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < 2)
	{
		y = 0;
		while (y < 4)
		{
			if (game->player_frames[x][y].img)
				mlx_destroy_image(game->mlx, game->player_frames[x][y].img);
			y++;
		}
		x++;
	}
}

static void	destroy_enemy_images(t_game *game)
{
	int	x;

	x = 0;
	while (x < 2)
	{
		if (game->enemy_frames[x].img)
			mlx_destroy_image(game->mlx, game->enemy_frames[x].img);
		x++;
	}
}
void	cleanup(t_game *game)
{
	destroy_player_images(game);
	destroy_enemy_images(game);
	if (game->wall.img)
		mlx_destroy_image(game->mlx, game->wall.img);
	if (game->floor.img)
		mlx_destroy_image(game->mlx, game->floor.img);
	if (game->exit_img.img)
		mlx_destroy_image(game->mlx, game->exit_img.img);
	if (game->collectible_img.img)
		mlx_destroy_image(game->mlx, game->collectible_img.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->score_back.img)
		mlx_destroy_image(game->mlx, game->score_back.img);
	if (game->map)
		ft_free_all(game->map->map_array);
	if (game->map)
		free(game->map);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}
