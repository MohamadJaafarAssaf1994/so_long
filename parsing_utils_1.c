/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 18:01:57 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/24 19:37:43 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	find_coordinates_by_char(t_game *game, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!game || !game->map || !game->map->map_array)
		return ((t_point){-1, -1});
	while (game->map->map_array[i])
	{
		j = 0;
		while (game->map->map_array[i][j])
		{
			if (game->map->map_array[i][j] == c)
				return ((t_point){i, j});
			j++;
		}
		i++;
	}
	return ((t_point){-1, -1});
}

t_point	find_coordinates_enemy(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	if (!game || !game->map || !game->map->map_array)
		return ((t_point){-1, -1});
	if (game->map->length < 5)
		return ((t_point){-1, -1});
	while (i < game->map->wi - 1)
	{
		j = 1;
		while (j < game->map->length - 3)
		{
			if (game->map->map_array[i][j] == '0' && game->map->map_array[i][j
				+ 1] == '0' && game->map->map_array[i][j + 2] == '0')
				return ((t_point){i, j});
			j++;
		}
		i++;
	}
	return ((t_point){-1, -1});
}

int	count_coll_by_char(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	if (!game || !game->map || !game->map->map_array)
		return (0);
	while (i < game->map->wi)
	{
		j = 0;
		while (j < game->map->length)
		{
			if (game->map->map_array[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	tab_len(char **tab)
{
	int	count;

	if (!tab || !tab[0])
		return (0);
	count = 0;
	while (tab[count] != NULL)
		count++;
	return (count);
}

int	lines_count(char *file_path)
{
	char	*line;
	int		count;
	int		fd;

	count = 0;
	fd = open(file_path, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}
