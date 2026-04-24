/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 19:14:15 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/24 20:23:34 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_hits_collectible(t_game *game, int y, int x_coll, int y_coll)
{
	game->moves++;
	game->collected++;
	game->map->map_array[x_coll][y_coll] = 'P';
	game->map->map_array[game->p_pt.x][game->p_pt.y] = '0';
	game->p_pt.x = x_coll;
	game->p_pt.y = y_coll;
	if ((y == -1 && game->cu_fr_ch == 1) || (y == 1 && game->cu_fr_ch == 0))
		game->cu_fr_sa = (game->cu_fr_sa + 1) % 4;
	else if ((y == 1 && game->cu_fr_ch == 1) || (y == -1
			&& game->cu_fr_ch == 0))
		game->cu_fr_ch = (game->cu_fr_ch + 1) % 2;
	render_map(game);
}

static void	player_free_go(t_game *game, int y, int next_pos_x, int next_pos_y)
{
	game->moves++;
	game->map->map_array[game->p_pt.x][game->p_pt.y] = '0';
	game->map->map_array[next_pos_x][next_pos_y] = 'P';
	game->p_pt.x = next_pos_x;
	game->p_pt.y = next_pos_y;
	if ((y == -1 && game->cu_fr_ch == 1) || (y == 1 && game->cu_fr_ch == 0))
		game->cu_fr_sa = (game->cu_fr_sa + 1) % 4;
	else if ((y == 1 && game->cu_fr_ch == 1) || (y == -1
			&& game->cu_fr_ch == 0))
		game->cu_fr_ch = (game->cu_fr_ch + 1) % 2;
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
	game->map->map_array[game->p_pt.x][game->p_pt.y] = '0';
	game->map->map_array[next_pos_x][next_pos_y] = 'P';
	game->p_pt.x = next_pos_x;
	game->p_pt.y = next_pos_y;
	if ((y == -1 && game->cu_fr_ch == 1) || (y == 1 && game->cu_fr_ch == 0))
		game->cu_fr_sa = (game->cu_fr_sa + 1) % 4;
	else if ((y == 1 && game->cu_fr_ch == 1) || (y == -1
			&& game->cu_fr_ch == 0))
		game->cu_fr_ch = (game->cu_fr_ch + 1) % 2;
	render_map(game);
}

void	move_player(t_game *game, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = game->p_pt.x + x;
	new_y = game->p_pt.y + y;
	if (game->map->map_array[new_x][new_y] == '1')
		return ;
	else if (game->map->map_array[new_x][new_y] == 'C')
		player_hits_collectible(game, y, new_x, new_y);
	else if (game->map->map_array[new_x][new_y] == '0')
		player_free_go(game, y, new_x, new_y);
	else if (game->map->map_array[new_x][new_y] == 'E')
		player_hits_exit(game, y, new_x, new_y);
}
