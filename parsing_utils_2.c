/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 18:16:22 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/24 19:37:43 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_file(char *path, char *filename, t_map *map)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(path);
		free(map);
		ft_printf("Error\n");
		perror(filename);
		exit(1);
	}
	return (fd);
}

void	set_map_dimensions(t_map *map)
{
	map->wi = tab_len(map->map_array);
	map->length = ft_strlen(map->map_array[0]);
}

int	name_extension_check(char *filename)
{
	char	**tab;

	tab = ft_split(filename, '.');
	if (tab_len(tab) != 2 || ft_strlen(tab[1]) != 3 || ft_strncmp(tab[1], "ber",
			3) != 0)
	{
		ft_free_all(tab);
		return (1);
	}
	ft_free_all(tab);
	return (0);
}
