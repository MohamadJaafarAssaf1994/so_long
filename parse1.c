/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:01:35 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/23 19:26:37 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_game(t_game *game, char *filename)
{
	game->map = file_to_map(filename);
	game->player_point = find_coordinates_by_char(game, 'P');
	game->exit_point = find_coordinates_by_char(game, 'E');
	game->collectibles = count_coll_by_char(game);
	game->enemy_player.enemy_point = find_coordinates_enemy(game);
	game->moves = 0;
	game->collected = 0;
	game->current_frame_change = 0;
	game->current_frame_same = 0;
	game->frame_delay = 0;
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

static void	check(char **map)
{
	check_is_empty(map);
	check_is_rectangular(map);
	check_walls(map);
	check_invalid_characters(map);
	check_start_exit_coll(map);
	check_has_valid_path(map);
}

static char	**get_map(int fd, char *file_path)
{
	char	*line;
	char	**result;
	int		i;

	i = 0;
	result = (char **)malloc(lines_count(file_path) * sizeof(char *) + 1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (ends_with_new_line(line))
			result[i] = ft_substr(line, 0, ft_strlen(line) - 1);
		else
			result[i] = ft_strdup(line);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	result[i] = NULL;
	check(result);
	return (result);
}

t_map	*file_to_map(char *filename)
{
	int		fd;
	char	*file_path;
	t_map	*map;

	map = malloc(sizeof(t_map));
	file_path = ft_strjoin("maps/", filename);
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		free(file_path);
		ft_printf("Error\n");
		perror(filename);
		exit(1);
	}
	if (name_extension_check(filename) == 1)
	{
		free(file_path);
		ft_printf("Error\nThe filename is not correct. Correct example: \'abc.ber\'\n");
		exit(1);
	}
	map->map_array = get_map(fd, file_path);
	map->width = tab_len(map->map_array);
	map->length = (int)ft_strlen(map->map_array[0]);
	free(file_path);
	return (map);
}
