/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_renderer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <cjouenne@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 03:55:37 by cjouenne          #+#    #+#             */
/*   Updated: 2023/11/02 04:40:20 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void		map_render(t_map *map, t_loop_data *data)
{
	ssize_t	x;
	ssize_t	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			mlx_image_to_window(data->mlx, data->floor_img, x * I_SIZE, y * I_SIZE);
			if (map->map[y][x] == '1')
				mlx_image_to_window(data->mlx, data->fence_img, x * I_SIZE, y * I_SIZE);
			x++;
		}
		y++;
	}	
}
