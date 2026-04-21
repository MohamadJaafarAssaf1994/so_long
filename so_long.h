/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:02:09 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/21 17:52:51 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fcntl.h"
#include "libft/libft.h"

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct s_map
{
	char **map_array;
	int	width;
	int	heigth;
}		t_map;

t_map	*file_to_map(char *filename);
void	print_tab(char **tab);
void	check_invalid_characters(char **map);
int		tab_len(char **tab);
void	check_is_rectangular(char **map);
int		ends_with_new_line(char *line);
int		map_contain_char(char **map, char c);
void	check_start_exit_coll(char **map);
int		is_valid_char(char c);
void	check_is_empty(char **map);
void	check_walls(char **map);
int		has_right_wall(char **map, int *message_flag);
int		has_left_wall(char **map, int *message_flag);
int		has_upper_wall(char **map, int *message_flag);
int		has_lower_wall(char **map, int *message_flag);
void	check_has_valid_path(char **map);
char	**copy_map(char **map);
void	map_fill(char **map);
void	init_start(char **map, t_point *start);
void	fill(char **tab, t_point curr, char to_fill, int nb_rows,
			int nb_columns);
