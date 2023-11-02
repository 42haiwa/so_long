/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <cjouenne@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 02:48:26 by cjouenne          #+#    #+#             */
/*   Updated: 2023/11/02 16:51:33 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hook(void *param)
{
	const t_loop_data	*data = param;
	(void) data;
}

void	ft_key_hook(mlx_key_data_t key, void *param)
{
	static int	n = 0;
	t_loop_data	*data;

	data = param;
	if (key.key == 87 && key.action == MLX_PRESS)
		up(data, &n);
	if (key.key == 68 && key.action == MLX_PRESS)
		right(data, &n);
	if (key.key == 65 && key.action == MLX_PRESS)
		left(data, &n);
	if (key.key == 83 && key.action == MLX_PRESS)
		down(data, &n);
}
