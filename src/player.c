/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <cjouenne@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 03:42:40 by cjouenne          #+#    #+#             */
/*   Updated: 2023/11/02 16:51:07 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_loop_data *data, int *n)
{
	int	l_x;
	int	l_y;

	l_x = (data->player.x) / I_SIZE;
	l_y = (data->player.y) / I_SIZE;
	if (data->map->map[l_y - 1][l_x] == '1')
		return ;
	data->player.y -= I_SIZE;
	data->player.img->instances[0].y = data->player.y - I_SIZE;
	(*n)++;
	ft_printf("movements: %d\n", *n);
}

void	right(t_loop_data *data, int *n)
{
	int	l_x;
	int	l_y;

	l_x = (data->player.x) / I_SIZE;
	l_y = (data->player.y) / I_SIZE;
	if (data->map->map[l_y][l_x + 1] == '1')
		return ;
	data->player.x += I_SIZE;
	data->player.img->instances[0].x = data->player.x - I_SIZE;
	(*n)++;
	ft_printf("movements: %d\n", *n);
}

void	down(t_loop_data *data, int *n)
{
	int	l_x;
	int	l_y;

	l_x = (data->player.x) / I_SIZE;
	l_y = (data->player.y) / I_SIZE;
	if (data->map->map[l_y + 1][l_x] == '1')
		return ;
	data->player.y += I_SIZE;
	data->player.img->instances[0].y = data->player.y - I_SIZE;
	(*n)++;
	ft_printf("movements: %d\n", *n);
}

void	left(t_loop_data *data, int *n)
{
	int	l_x;
	int	l_y;

	l_x = (data->player.x) / I_SIZE;
	l_y = (data->player.y) / I_SIZE;
	if (data->map->map[l_y][l_x - 1] == '1')
		return ;
	data->player.x -= I_SIZE;
	data->player.img->instances[0].x = data->player.x - I_SIZE;
	(*n)++;
	ft_printf("movements: %d\n", *n);
}
