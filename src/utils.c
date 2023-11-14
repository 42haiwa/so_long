/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <cjouenne@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 02:48:26 by cjouenne          #+#    #+#             */
/*   Updated: 2023/11/07 14:42:34 by cjouenne         ###   ########.fr       */
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
	mlx_terminate(data->mlx);
	exit(0);
}

static size_t	get_current_egg(t_loop_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->egg_img->count)
	{
		if (data->player.x == data->egg_img->instances[i].x
			&& data->player.y == data->egg_img->instances[i].y)
			return (i);
		i++;
	}
	return (0);
}

void	ft_coin(t_loop_data *data)
{
	int	p_x;
	int	p_y;

	(void) data;
	p_x = (data->player.x) / I_SIZE;
	p_y = (data->player.y) / I_SIZE;
	data->map->map[p_y][p_x] = '0';
	data->egg_img->instances[get_current_egg(data)].enabled = 0;
	ft_printf("coin !\n");
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
