/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:03:05 by cjouenne          #+#    #+#             */
/*   Updated: 2023/11/14 05:04:35 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood_fill(int x, int y, t_map *map, t_flood_fill *fill)
{
	int	result_right;
	int	result_left;
	int	result_down;
	int	result_up;

	result_right = 0;
	result_left = 0;
	result_down = 0;
	result_up = 0;
	if (x < 0 || x >= map->width || y < 0
		|| y >= map->height || fill->map[y][x] == '1')
		return (0);
	if (map->map[y][x] == 'E')
		return (1);
	fill->map[y][x] = '1';
	if (map->map[y][x + 1] != '1')
		result_right = flood_fill(x + 1, y, map, fill);
	if (map->map[y][x - 1] != '1')
		result_left = flood_fill(x - 1, y, map, fill);
	if (map->map[y + 1][x] != '1')
		result_down = flood_fill(x, y + 1, map, fill);
	if (map->map[y - 1][x] != '1')
		result_up = flood_fill(x, y - 1, map, fill);
	return (result_right || result_left || result_down || result_up);
}
