/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_checkers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 09:33:45 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/21 11:55:57 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_is_empty(char **map)
{
	if (map[0] == NULL)
	{
		ft_printf("Error\nThe tab must not be empty.");
		exit(1);
	}
}

void	check_walls(char **map)
{
	int	message_flag;

	message_flag = 0;
	if (!(has_right_wall(map, &message_flag) && has_left_wall(map, &message_flag) && has_upper_wall(map, &message_flag) && has_lower_wall(map, &message_flag)))
	{
		if (message_flag == 1)
			ft_printf("Error\nThe map must be enclosed/surrounded by right wall.\n");
		if (message_flag == 2)
			ft_printf("Error\nThe map must be enclosed/surrounded by left wall.\n");
		if (message_flag == 3)
			ft_printf("Error\nThe map must be enclosed/surrounded by upper wall.\n");
		if (message_flag == 4)
			ft_printf("Error\nThe map must be enclosed/surrounded by lower wall.\n");
		exit(1);
	}
}
void	check_invalid_characters(char **map)
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
			if (!is_valid_char(map[i][j]))
			{
				ft_printf("Error\nThe map has invalid character(s)");
				exit(1);
			}
			j++;
		}
		i++;
	}
}
void	check_is_rectangular(char **map)
{
	size_t	len;
	int		i;

	i = 0;
	if (!map || !map[0] || !map[1])
	{
		ft_printf("Error\nThe map must be rectangular");
		exit(1);
	}
	len = ft_strlen(map[0]);
	while (map[i] != NULL)
	{
		if (ft_strlen(map[i]) != len)
		{
			ft_printf("Error\nThe map must be rectangular");
			exit(1);
		}
		i++;
	}
}

void	check_start_exit_coll(char **map)
{
	if (map_contain_char(map, 'E') == 0 || map_contain_char(map, 'C') == 0
		|| map_contain_char(map, 'P') == 0)
	{
		ft_printf("Error\nThe map must contain 1 exit, 1 starting position and at least 1 collectible.");
		exit(1);
	}
}
