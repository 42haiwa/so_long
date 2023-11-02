/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <cjouenne@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 02:48:26 by cjouenne          #+#    #+#             */
/*   Updated: 2023/11/02 04:35:22 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hook(void *param)
{
	const t_loop_data	*data = param;

	ft_printf("player x: %d, y: %d\n", data->player.x, data->player.y);
}

void	ft_key_hook(mlx_key_data_t key, void *param)
{
	t_loop_data	*data;

	data = param;
	if (key.key == 87 && key.action == MLX_PRESS)
		up(data);
	if (key.key == 68 && key.action == MLX_PRESS)
		right(data);
	if (key.key == 65 && key.action == MLX_PRESS)
		left(data);
	if (key.key == 83 && key.action == MLX_PRESS)
		down(data);
}
