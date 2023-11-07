/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <cjouenne@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 03:42:40 by cjouenne          #+#    #+#             */
/*   Updated: 2023/11/07 12:42:50 by cjouenne         ###   ########.fr       */
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
	if (data->map->map[l_y - 1][l_x] == 'E')
		ft_exit(data);
	if (data->map->map[l_y - 1][l_x] == 'C')
		ft_coin(data);
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
	if (data->map->map[l_y][l_x + 1] == 'E')
		ft_exit(data);
	if (data->map->map[l_y][l_x + 1] == 'C')
		ft_coin(data);
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
	if (data->map->map[l_y + 1][l_x] == 'E')
		ft_exit(data);
	if (data->map->map[l_y + 1][l_x] == 'C')
		ft_coin(data);
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
	if (data->map->map[l_y][l_x - 1] == 'E')
		ft_exit(data);
	if (data->map->map[l_y][l_x - 1] == 'C')
		ft_coin(data);
}
