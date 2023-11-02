/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <cjouenne@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 03:42:40 by cjouenne          #+#    #+#             */
/*   Updated: 2023/11/02 03:47:35 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_loop_data *data)
{
	data->player.y -= I_SIZE;
	mlx_image_to_window(data->mlx, data->player.img,
		data->player.x, data->player.y);
}

void	right(t_loop_data *data)
{
	data->player.x += I_SIZE;
	mlx_image_to_window(data->mlx, data->player.img,
		data->player.x, data->player.y);
}

void	down(t_loop_data *data)
{
	data->player.y += I_SIZE;
	mlx_image_to_window(data->mlx, data->player.img,
		data->player.x, data->player.y);
}

void	left(t_loop_data *data)
{
	data->player.x -= I_SIZE;
	mlx_image_to_window(data->mlx, data->player.img,
		data->player.x, data->player.y);
}
