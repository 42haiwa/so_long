/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_exitable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:36:27 by cjouenne          #+#    #+#             */
/*   Updated: 2023/11/14 04:50:16 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_map_exitable(t_loop_data *data)
{
	ssize_t			i;
	t_flood_fill	fill;

	i = 0;
	fill.map = ft_calloc(data->map->height, sizeof(char *));
	while (i < data->map->height)
	{
		fill.map[i] = ft_calloc(data->map->width, sizeof(char));
		i++;
	}
	return (flood_fill(1, 1, data->map, &fill));
}
