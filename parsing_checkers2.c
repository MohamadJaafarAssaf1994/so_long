/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_checkers2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 12:01:53 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/24 19:21:51 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_has_valid_path(char **map)
{
	char	**map_copy1;
	char	**map_copy2;

	map_copy1 = copy_map(map);
	map_copy2 = copy_map(map);
	map_fill(map_copy1, '2');
	map_fill(map_copy2, 'E');
	if (map_contain_char(map_copy1, 'C') == 1 || map_contain_char(map_copy1,
			'P') == 1 || map_contain_char(map_copy1, 'E') == 1
		|| map_contain_char(map_copy2, 'C') == 1 || map_contain_char(map_copy2,
			'P') == 1)
	{
		ft_free_all(map_copy1);
		ft_free_all(map_copy2);
		ft_printf("Error\nThe map does not contain valid path.\n");
		return (1);
	}
	ft_free_all(map_copy1);
	ft_free_all(map_copy2);
	return (0);
}
