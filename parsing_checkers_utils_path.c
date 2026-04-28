/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_checkers_utils_path.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 12:21:09 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/28 12:27:13 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_start(char **map, t_point *start)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
			{
				start->x = i;
				start->y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

char	**copy_map(char **map)
{
	char	**map_copy;
	int		map_length;
	int		i;

	if (!map)
		return (NULL);
	i = 0;
	map_length = tab_len(map);
	map_copy = (char **)malloc(sizeof(char *) * (map_length + 1));
	if (!map_copy)
		return (NULL);
	while (map[i] != NULL)
	{
		map_copy[i] = ft_strdup(map[i]);
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

void	map_fill(char **map, char to_fill)
{
	t_point	start;

	if (!map)
		return ;
	init_start(map, &start);
	fill(map, start, to_fill);
}

void	fill(char **map, t_point curr, char to_fill)
{
	int	nb_rows;
	int	nb_columns;

	if (!map)
		return ;
	nb_rows = tab_len(map);
	nb_columns = ft_strlen(map[0]);
	if (curr.x < 0 || curr.x >= nb_rows || curr.y < 0 || curr.y >= nb_columns)
		return ;
	if (!map[curr.x])
		return ;
	if (map[curr.x][curr.y] == '1' || map[curr.x][curr.y] == to_fill)
		return ;
	map[curr.x][curr.y] = to_fill;
	fill(map, (t_point){curr.x, curr.y + 1}, to_fill);
	fill(map, (t_point){curr.x, curr.y - 1}, to_fill);
	fill(map, (t_point){curr.x + 1, curr.y}, to_fill);
	fill(map, (t_point){curr.x - 1, curr.y}, to_fill);
}
