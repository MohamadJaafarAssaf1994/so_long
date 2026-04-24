/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_checkers_utils_walls.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 11:05:58 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/24 18:25:26 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	has_right_wall(char **map, int *message_flag)
{
	int		i;
	char	last_char_in_row;

	i = 0;
	while (map[i] != NULL)
	{
		last_char_in_row = map[i][ft_strlen(map[i]) - 1];
		if (last_char_in_row != '1')
		{
			*message_flag = 1;
			return (0);
		}
		i++;
	}
	return (1);
}

int	has_left_wall(char **map, int *message_flag)
{
	int		i;
	char	first_char_in_row;

	i = 0;
	while (map[i] != NULL)
	{
		first_char_in_row = map[i][0];
		if (first_char_in_row != '1')
		{
			*message_flag = 2;
			return (0);
		}
		i++;
	}
	return (1);
}

int	has_upper_wall(char **map, int *message_flag)
{
	int	j;

	j = 0;
	while (map[0][j] != '\0')
	{
		if (map[0][j] != '1')
		{
			*message_flag = 3;
			return (0);
		}
		j++;
	}
	return (1);
}

int	has_lower_wall(char **map, int *message_flag)
{
	int	j;
	int	index_last_row;

	j = 0;
	index_last_row = tab_len(map) - 1;
	while (map[index_last_row][j] != '\0')
	{
		if (map[index_last_row][j] != '1')
		{
			*message_flag = 4;
			return (0);
		}
		j++;
	}
	return (1);
}
