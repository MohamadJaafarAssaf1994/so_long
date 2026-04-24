/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_design.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 17:37:58 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/24 19:39:23 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_tile(t_game *game, char tile, int x, int y)
{
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall.img, x * 64, y
			* 64);
	if (tile == '0')
		mlx_put_image_to_window(game->mlx, game->win, game->floor.img, x * 64, y
			* 64);
	if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit_img.img, x
			* 64, y * 64);
	if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->collectible_img.img,
			x * 64, y * 64);
}

void	render_map(t_game *g)
{
	int		x;
	int		y;
	char	*score;

	x = 0;
	while (x < g->map->wi)
	{
		y = 0;
		while (y < g->map->length)
		{
			draw_tile(g, g->map->map_array[x][y], y, x);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(g->mlx, g->win, g->sc_img.img, 0, g->map->wi * 64);
	mlx_put_image_to_window(g->mlx, g->win,
		g->player_frames[g->cu_fr_ch][g->cu_fr_sa].img, g->p_pt.y * 64,
		g->p_pt.x * 64);
	mlx_put_image_to_window(g->mlx, g->win, g->enemy_frames[g->en_frame].img,
		g->enemy_player.e_pt.y * 64, g->enemy_player.e_pt.x * 64);
	score = ft_itoa(g->moves);
	mlx_string_put(g->mlx, g->win, 28, g->map->wi * 64 + 40, 0x000000, score);
	free(score);
}

void	load_textures(t_game *game, t_img *img, char *path)
{
	img->img = mlx_xpm_file_to_image(game->mlx, path, &img->wi, &img->length);
	if (!img->img)
	{
		cleanup(game);
		error_exit("Error\nTexture failed\n");
	}
}

void	load_all_textures(t_game *game)
{
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
	load_textures(game, &game->enemy_frames[0], "textures/enemy_0.xpm");
	load_textures(game, &game->enemy_frames[1], "textures/enemy_1.xpm");
	load_textures(game, &game->sc_img, "textures/moves.xpm");
}
