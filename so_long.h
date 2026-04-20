/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:02:09 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/20 18:24:50 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fcntl.h"

char **file_to_map(char *filename);
void print_tab(char **tab);
void check_invalid_characters(char **map);
int tab_len(char **tab);
void check_is_rectangular(char **map);
int ends_with_new_line(char *line);