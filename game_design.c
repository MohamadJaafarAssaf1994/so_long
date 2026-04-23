/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_design.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 17:37:58 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/23 19:27:12 by mohassaf         ###   ########.fr       */
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
void	render_map(t_game *game)
{
	int		x;
	int		y;
	char	tile;

	x = 0;
	while (x < game->map->width)
	{
		y = 0;
		while (y < game->map->length)
		{
			tile = game->map->map_array[x][y];
			draw_tile(game, tile, y, x);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->win,
		game->player_frames[game->current_frame_change][game->current_frame_same].img, game->player_point.y * 64,
		game->player_point.x * 64);
}
void	load_textures(t_game *game, t_img *img, char *path)
{
	img->img = mlx_xpm_file_to_image(game->mlx, path, &img->width,
			&img->length);
	if (!img->img)
		error_exit("Error\nTexture failed\n");
}
