/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:46:56 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/23 16:36:26 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		error_exit("Error\nUsage:./so_long map_name.ber\n");
    parse_game(&game, argv[1]);
    start_game(&game);
    //ft_printf("%d\n", game.player_point.x);
    //ft_printf("%d\n", game.player_point.y);
	return (0);
}
