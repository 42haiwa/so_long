/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <cjouenne@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 02:48:26 by cjouenne          #+#    #+#             */
/*   Updated: 2023/11/02 17:10:19 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hook(void *param)
{
	const t_loop_data	*data = param;
	(void) data;
}

void	ft_exit(t_loop_data *data)
{
	mlx_delete_image(data->mlx, data->egg_img);
	mlx_delete_texture(data->egg_texture);
	mlx_delete_image(data->mlx, data->fence_img);
	mlx_delete_texture(data->fence_texture);
	mlx_delete_image(data->mlx, data->floor_img);
	mlx_delete_texture(data->floor_texture);
	mlx_delete_image(data->mlx, data->player.img);
	//mlx_delete_texture(texture);
	mlx_terminate(data->mlx);
	exit(0);
}

void	ft_key_hook(mlx_key_data_t key, void *param)
{
	static int	n = 0;
	t_loop_data	*data;

	data = param;
	if (key.key == 256 && key.action == MLX_RELEASE)
		ft_exit(data);
	if (key.key == 87 && key.action == MLX_PRESS)
		up(data, &n);
	if (key.key == 68 && key.action == MLX_PRESS)
		right(data, &n);
	if (key.key == 65 && key.action == MLX_PRESS)
		left(data, &n);
	if (key.key == 83 && key.action == MLX_PRESS)
		down(data, &n);
}
