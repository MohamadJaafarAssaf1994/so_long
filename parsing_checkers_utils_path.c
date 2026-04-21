/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_checkers_utils_path.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 12:21:09 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/21 16:23:20 by mohassaf         ###   ########.fr       */
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
			if (map[i][j] == 'C' || map[i][j] == 'E' || map[i][j] == 'P')
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

	i = 0;
	map_length = tab_len(map);
	map_copy = (char **)malloc((sizeof(char *) * map_length) + 1);
	while (map[i] != NULL)
	{
		map_copy[i] = ft_strdup(map[i]);
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

void	map_fill(char **map)
{
	int		nb_rows;
	int		nb_columns;
	t_point	start;

	nb_rows = tab_len(map);
	nb_columns = ft_strlen(map[0]);
	init_start(map, &start);
	fill(map, start, '2', nb_rows, nb_columns);
}

void	fill(char **map, t_point curr, char to_fill, int nb_rows,
		int nb_columns)
{
	if (curr.x < 1 || curr.x == nb_rows - 1|| curr.y < 1 || curr.y == nb_columns - 1
		|| map[curr.x][curr.y] == '1' || map[curr.x][curr.y] == '2')
		return ;
	map[curr.x][curr.y] = '2';
	fill(map, (t_point){curr.x, curr.y + 1}, to_fill, nb_rows, nb_columns);
	fill(map, (t_point){curr.x, curr.y - 1}, to_fill, nb_rows, nb_columns);
	fill(map, (t_point){curr.x + 1, curr.y}, to_fill, nb_rows, nb_columns);
	fill(map, (t_point){curr.x - 1, curr.y}, to_fill, nb_rows, nb_columns);
}
