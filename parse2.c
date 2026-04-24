/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:09:31 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/24 18:17:31 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ends_with_new_line(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		return (1);
	return (0);
}

int	is_valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'C' || c == 'P' || c == 'E')
		return (1);
	return (0);
}
