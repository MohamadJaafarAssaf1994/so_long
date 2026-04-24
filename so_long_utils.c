/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 18:01:09 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/24 19:37:19 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_all(char **arr)
{
	int	i;

	i = 0;
	if (arr == NULL)
		return ;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	print_tab(char **tab)
{
	int	i;
	int	j;

	if (!(tab))
	{
		ft_printf("The array is null");
		return ;
	}
	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			ft_printf("%c", tab[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	error_exit(char *message)
{
	ft_printf(message);
	exit(1);
}

void	destroy_enemy_images(t_game *game)
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
	if (game->sc_img.img)
		mlx_destroy_image(game->mlx, game->sc_img.img);
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
