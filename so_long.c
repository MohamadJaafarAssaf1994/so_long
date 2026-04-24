/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:46:56 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/24 20:05:56 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_game *game)
{
	if (!game || !game->map || !game->map->map_array)
		return ;
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		cleanup(game);
		error_exit("Error\nmlx_init failed: \
			run from a graphical X11 session.\n");
	}
	game->win = mlx_new_window(game->mlx, game->map->length * 64,
			(game->map->wi + 1) * 64, "so_long");
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

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		error_exit("Error\nUsage:./so_long map_name.ber\n");
	ft_bzero(&game, sizeof(t_game));
	parse_game(&game, argv[1]);
	start_game(&game);
	return (0);
}
