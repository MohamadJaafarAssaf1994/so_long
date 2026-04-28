/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:01:35 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/28 14:46:46 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_game(t_game *game, char *filename)
{
	game->map = file_to_map(filename);
	game->p_pt = find_coordinates_by_char(game, 'P');
	game->exit_point = find_coordinates_by_char(game, 'E');
	game->collectibles = count_coll_by_char(game);
	game->enemy_player.e_pt = find_coordinates_enemy(game);
	game->moves = 0;
	game->collected = 0;
	game->cu_fr_ch = 0;
	game->cu_fr_sa = 0;
	game->frame_delay = 0;
	game->en_frame = 0;
	game->enemy_counter = 1;
	game->enemy_player.dir = 1;
}

static int	check(char **map)
{
	if (check_is_empty(map))
		return (1);
	if (check_is_rectangular(map))
		return (1);
	if (check_walls(map))
		return (1);
	if (check_invalid_characters(map))
		return (1);
	if (check_start_exit_coll(map))
		return (1);
	if (check_has_valid_path(map))
		return (1);
	return (0);
}

static char	*clean_line(char *line)
{
	char	*clean;

	if (ends_with_new_line(line))
		clean = ft_substr(line, 0, ft_strlen(line) - 1);
	else
		clean = ft_strdup(line);
	free(line);
	return (clean);
}

static char	**get_map(int fd, char *file_path)
{
	char	*line;
	char	**result;
	int		i;

	i = 0;
	result = (char **)malloc((lines_count(file_path) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		result[i++] = clean_line(line);
		line = get_next_line(fd);
	}
	close(fd);
	get_next_line(-1);
	result[i] = NULL;
	if (check(result) == 1)
	{
		ft_free_all(result);
		return (NULL);
	}
	return (result);
}

t_map	*file_to_map(char *filename)
{
	int		fd;
	char	*file_path;
	t_map	*map;

	if (name_extension_check(filename) == 1)
		error_exit("Error\nInvalid filename (abc.ber required)\n");
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	file_path = ft_strdup(filename);
	fd = open_file(file_path, filename, map);
	map->map_array = get_map(fd, file_path);
	free(file_path);
	if (map->map_array == NULL)
	{
		free(map);
		exit(1);
	}
	set_map_dimensions(map);
	return (map);
}
