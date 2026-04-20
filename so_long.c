/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:46:56 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/20 18:19:36 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void error_exit(char *message)
{
    ft_printf(message);
    exit(1);
}
int main(int argc, char *argv[])
{
    char **map;
    if (argc != 2)
        error_exit("Error\nUsage:./so_long map_name.ber\n");
    map = file_to_map(argv[1]);
    print_tab(map);
    //ft_printf("%d\n", tab_len(map));
    return (0);
}