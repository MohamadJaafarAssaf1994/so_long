/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 19:14:15 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/23 20:24:43 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_hits_collectible(t_game *game, int y, int x_coll,
		int y_coll)
{
	game->collected++;
	game->map->map_array[x_coll][y_coll] = 'P';
	game->map->map_array[game->player_point.x][game->player_point.y] = '0';
	game->player_point.x = x_coll;
	game->player_point.y = y_coll;
	if ((y == -1 && game->current_frame_change == 1) || ( y == 1 && game->current_frame_change == 0))
		game->current_frame_same = (game->current_frame_same + 1) % 4;
	else if ((y == 1 && game->current_frame_change == 1) || (y == -1 && game->current_frame_change == 0))
		game->current_frame_change = (game->current_frame_change + 1) % 2;
	render_map(game);
}
static void	player_free_go(t_game *game, int y, int next_pos_x,
		int next_pos_y)
{
	game->map->map_array[game->player_point.x][game->player_point.y] = '0';
	game->map->map_array[next_pos_x][next_pos_y] = 'P';
	game->player_point.x = next_pos_x;
	game->player_point.y = next_pos_y;
	if ((y == -1 && game->current_frame_change == 1) || ( y == 1 && game->current_frame_change == 0))
		game->current_frame_same = (game->current_frame_same + 1) % 4;
	else if ((y == 1 && game->current_frame_change == 1) || (y == -1 && game->current_frame_change == 0))
		game->current_frame_change = (game->current_frame_change + 1) % 2;
	render_map(game);
}

static void	player_hits_exit(t_game *game, int y, int next_pos_x,
		int next_pos_y)
{
	if (game->collected != game->collectibles)
		return ;
	ft_printf("finished");
	game->map->map_array[game->player_point.x][game->player_point.y] = '0';
	game->map->map_array[next_pos_x][next_pos_y] = 'P';
	game->player_point.x = next_pos_x;
	game->player_point.y = next_pos_y;
	if ((y == -1 && game->current_frame_change == 1) || ( y == 1 && game->current_frame_change == 0))
		game->current_frame_same = (game->current_frame_same + 1) % 4;
	else if ((y == 1 && game->current_frame_change == 1) || (y == -1 && game->current_frame_change == 0))
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
	{
		ft_printf("W pressed\n");
		move_player(game, -1, 0);
	}
	else if (keycode == S)
	{
		ft_printf("S pressed\n");
		move_player(game, 1, 0);
	}
	else if (keycode == A)
	{
		ft_printf("A pressed\n");
		move_player(game, 0, -1);
	}
	else if (keycode == D)
	{
		ft_printf("D pressed\n");
		move_player(game, 0, 1);
	}
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
void	setup_hooks(t_game *game)
{
	mlx_key_hook(game->win, key_press, game);
/*#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-function-type"*/
	mlx_hook(game->win, 17, 0, (void *)close_game, game);
/*#pragma GCC diagnostic pop*/
}

void	start_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit("Error\nmlx_init failed: run from a graphical X11 session.\n");
	game->win = mlx_new_window(game->mlx, game->map->length * 64,
			game->map->width * 64, "so_long");
	if (!game->win)
		error_exit("Error\nmlx_new_window failed\n");
	load_textures(game, &game->wall, "textures/wall.xpm");
	load_textures(game, &game->floor, "textures/floor.xpm");
	load_textures(game, &game->player_frames[0][0], "textures/player_D_0.xpm");
	load_textures(game, &game->player_frames[0][1], "textures/player_D_1.xpm");
	load_textures(game, &game->player_frames[0][2], "textures/player_D_2.xpm");
	load_textures(game, &game->player_frames[0][3], "textures/player_D_3.xpm");
	load_textures(game, &game->player_frames[1][0], "textures/player_A_0.xpm");
	load_textures(game, &game->player_frames[1][1], "textures/player_A_1.xpm");
	load_textures(game, &game->player_frames[1][2], "textures/player_A_2.xpm");
	load_textures(game, &game->player_frames[1][3], "textures/player_A_3.xpm");
	load_textures(game, &game->exit_img, "textures/exit.xpm");
	load_textures(game, &game->collectible_img, "textures/collectible.xpm");
	// load_textures(game, &game->enemy_img, "textures/enemy.xpm");
	render_map(game);
	setup_hooks(game);
	mlx_loop(game->mlx);
}

static void	destroy_player_images(t_game *game)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < 2)
	{
		y = 0;
		while (y < 4)
		{
			if(game->player_frames[x][y].img)
				mlx_destroy_image(game->mlx, game->player_frames[x][y].img);
			y++;
		}
		x++;
	}
}
void	cleanup(t_game *game)
{
	destroy_player_images(game);
	if(game->wall.img)
		mlx_destroy_image(game->mlx, game->wall.img);
	if(game->floor.img)
		mlx_destroy_image(game->mlx, game->floor.img);
	if(game->exit_img.img)
		mlx_destroy_image(game->mlx, game->exit_img.img);
	if(game->collectible_img.img)
		mlx_destroy_image(game->mlx, game->collectible_img.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	ft_free_all(game->map->map_array);
	if(game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}
