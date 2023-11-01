/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <cjouenne@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 23:18:40 by cjouenne          #+#    #+#             */
/*   Updated: 2023/11/01 23:22:39 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	_close_by_x(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_loop_end(vars->mlx);
	return (0);
}

void	hook_manager(t_vars *vars)
{
	mlx_hook(vars->win, 17, 0, _close_by_x, vars);
}
