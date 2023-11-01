/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <cjouenne@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:12:05 by cjouenne          #+#    #+#             */
/*   Updated: 2023/11/01 19:58:00 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_element(char const c)
{
	if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
		return (0);
	return (1);
}

int	check_element2(char const c, int *has_item,
	int *has_exit, int *has_spawn)
{
	if (c == 'C')
		*has_item = 1;
	if (c == 'P')
	{
		if (*has_spawn)
			return (0);
		*has_spawn = 1;
	}
	if (c == 'E')
	{
		if (*has_exit)
			return (0);
		*has_exit = 1;
	}
	return (1);
}

int	check_element(char const *map_buf)
{
	ssize_t	i;
	int		has_item;
	int		has_spawn;
	int		has_exit;

	i = 0;
	has_exit = 0;
	has_spawn = 0;
	has_item = 0;
	while (map_buf[i])
	{
		if (!check_element2(map_buf[i], &has_item, &has_spawn, &has_exit)
			|| (!is_valid_element(map_buf[i]) && map_buf[i] != '\n'))
		{
			ft_printf("map error !\n");
			return (0);
		}
		i++;
	}
	if (has_exit && has_spawn && has_item)
		return (1);
	return (0);
}

static int	is_lines_equals2(char c, ssize_t *line_len,
	ssize_t *last_line_len, int *n)
{
	if (c == '\n' && *n > 0)
		if (*last_line_len != *line_len)
			return (0);
	if (c == '\n')
	{
		*last_line_len = *line_len;
		*line_len = 0;
		(*n)++;
	}
	else
		(*line_len)++;
	return (1);
}

int	is_lines_equals(char const *map_buf)
{
	ssize_t	line_len;
	ssize_t	last_line_len;
	ssize_t	i;
	int		n;

	line_len = 0;
	last_line_len = 0;
	n = 0;
	i = 0;
	while (map_buf[i])
	{
		if (!is_lines_equals2(map_buf[i], &line_len, &last_line_len, &n))
		{
			ft_printf("Error !\n");
			return (0);
		}
		i++;
	}
	return (1);
}
