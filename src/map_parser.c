/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <cjouenne@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:14:01 by cjouenne          #+#    #+#             */
/*   Updated: 2023/11/01 21:39:14 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static ssize_t	get_width(char const *map_buf)
{
	ssize_t	i;

	i = 0;
	while (map_buf[i] && map_buf[i] != '\n')
		i++;
	return (i);
}

static ssize_t	get_height(char const *map_buf)
{
	ssize_t	i;
	ssize_t	n;

	i = 0;
	n = 0;
	while (map_buf[i])
	{
		if (map_buf[i] == '\n')
			n++;
		i++;
	}
	return (n);
}

static char	**map_split(char const *map_buf)
{
	return (ft_split(map_buf, '\n'));
}

void	map_parse(t_map *map, char const *map_buf)
{
	map->width = get_width(map_buf);
	map->height = get_height(map_buf);
	map->map = map_split(map_buf);
}