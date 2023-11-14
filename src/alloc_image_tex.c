/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_image_tex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:59:38 by cjouenne          #+#    #+#             */
/*   Updated: 2023/11/14 04:57:58 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	alloc_image_tex2(t_loop_data *data)
{
	data->fence_texture = mlx_load_png("assets/t012.png");
	if (!data->fence_texture)
		exit(1);
	data->fence_img = mlx_texture_to_image(data->mlx, data->fence_texture);
	if (!data->fence_img)
		exit(1);
	data->egg_texture = mlx_load_png("assets/egg.png");
	if (!data->egg_texture)
		exit(1);
	data->egg_img = mlx_texture_to_image(data->mlx, data->egg_texture);
	if (!data->egg_img)
		exit(1);
	data->exit_texture = mlx_load_png("assets/exit.png");
	if (!data->exit_texture)
		exit(1);
	data->exit_img = mlx_texture_to_image(data->mlx, data->exit_texture);
	if (!data->exit_img)
		exit(1);
}

void	alloc_image_tex(t_loop_data *data, mlx_texture_t **texture)
{
	if (!data->mlx)
		exit(1);
	*texture = mlx_load_png("assets/p00.png");
	if (!texture)
		exit(1);
	data->player.img = mlx_texture_to_image(data->mlx, *texture);
	if (!data->player.img)
		exit(1);
	data->floor_texture = mlx_load_png("assets/t023.png");
	if (!data->floor_texture)
		exit(1);
	data->floor_img = mlx_texture_to_image(data->mlx, data->floor_texture);
	if (!data->floor_img)
		exit(1);
	alloc_image_tex2(data);
}
