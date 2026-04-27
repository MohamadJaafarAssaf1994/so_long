/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 18:16:22 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/27 17:00:11 by mohassaf         ###   ########.fr       */
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
		ft_printf("Error\n%s: %s\n.", filename, strerror(errno));
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
	char	*base_name;
	char	*dot;

	base_name = ft_strrchr(filename, '/');
	if (base_name)
		base_name++;
	else
		base_name = filename;
	if (*base_name == '\0' || *base_name == '.')
		return (1);
	dot = ft_strrchr(base_name, '.');
	if (!dot || dot == base_name)
		return (1);
	if (ft_strncmp(dot, ".ber", 5) != 0)
		return (1);
	if (ft_strchr(dot + 1, '.'))
		return (1);
	return (0);
}
