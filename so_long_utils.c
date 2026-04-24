/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 18:01:09 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/24 13:48:39 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_free_all(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

void	print_tab(char **tab)
{
	int	i;
	int	j;

	if (!(tab))
	{
		ft_printf("The array is null");
		return ;
	}
	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j] != '\0')
		{
			ft_printf("%c", tab[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	error_exit(char *message)
{
	ft_printf(message);
	exit(1);
}
