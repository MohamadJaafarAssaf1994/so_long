/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_checkers2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 12:01:53 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/24 14:21:26 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_has_valid_path(char **map)
{
	char	**map_copy;

	map_copy = copy_map(map);
	map_fill(map_copy);
	if (map_contain_char(map_copy, 'C') == 1 || map_contain_char(map_copy, 'P') == 1 || map_contain_char(map_copy, 'E') == 1)
	{
		ft_free_all(map_copy);
		ft_printf("Error\nThe map does not contain valid path\n");
		return(1);
	}
	ft_free_all(map_copy);
	return (0);
}
