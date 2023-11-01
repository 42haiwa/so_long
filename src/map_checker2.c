/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <cjouenne@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 20:06:27 by cjouenne          #+#    #+#             */
/*   Updated: 2023/11/01 20:51:43 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_first_line(char const *map_buf, ssize_t *i)
{
	while (map_buf[*i] && map_buf[*i] != '\n')
	{
		if (map_buf[*i] != '1')
		{
			ft_printf("Error !\n");
			return (0);
		}
		(*i)++;
	}
	return (1);
}

static int	check_last_line(char const *map_buf, ssize_t *i)
{
	while ((*i) - 2 >= 0 && map_buf[(*i) - 2] != '\n')
	{
		if (map_buf[(*i) - 2] != '1')
		{
			ft_printf("Error !\n");
			return (0);
		}
		(*i)--;
	}
	return (1);
}

int	is_map_closed(char const *map_buf)
{
	ssize_t	i;

	i = 0;
	if (!check_first_line(map_buf, &i))
		return (0);
	while (map_buf[i])
	{
		if (i > 0 && map_buf[i - 1] == '\n' && map_buf[i] != '1')
		{
			ft_printf("Error !\n");
			return (0);
		}
		if (map_buf[i] == '\n' && map_buf[i - 1] != '1')
		{
			ft_printf("Error !\n");
			return (0);
		}
		i++;
	}
	if (!check_last_line(map_buf, &i))
		return (0);
	return (1);
}
