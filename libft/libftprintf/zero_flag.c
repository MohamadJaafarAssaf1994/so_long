/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohassaf <mohassaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 13:30:33 by mohassaf          #+#    #+#             */
/*   Updated: 2026/04/24 19:45:51 by mohassaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	zero_flag(t_flags list, int len)
{
	int	count;

	count = list.width;
	if (list.zero == 0 || list.precision != -1 || list.minus != 0
		|| list.width == 0)
		return (0);
	if (count < len)
		return (0);
	else
		while (count-- - len)
			ft_putchar_fd('0', 1);
	return (list.width - len);
}
