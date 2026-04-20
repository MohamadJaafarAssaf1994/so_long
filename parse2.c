/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 17:09:31 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/20 18:29:45 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ends_with_new_line(char *line)
{
    int len;

    len = ft_strlen(line);
    if (line[len - 1] == '\n')
        return (1);
    return (0);
}
int is_valid_char(char c)
{
    if (c == '1' || c == '0' || c == 'C' || c == 'P' || c == 'E')
        return (1);
    return (0);
}
void check_invalid_characters(char **map)
{
    int i;
    int j;

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
void check_is_rectangular(char **map)
{
    int len;
    int i;

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