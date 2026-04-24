/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 18:32:37 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/24 19:36:29 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_player_images(t_game *game)
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

int	key_press(int keycode, void *param)
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
	game->enemy_player.e_pt.y = game->enemy_player.e_pt.y
		+ game->enemy_player.dir;
	game->en_frame = (game->en_frame + 1) % 2;
	check_enemy_collision(game);
	render_map(game);
}

void	setup_hooks(t_game *game)
{
	mlx_key_hook(game->win, key_press, game);
	mlx_loop_hook(game->mlx, (void *)enemy_loop, game);
	mlx_hook(game->win, 17, 0, (void *)close_game, game);
}
