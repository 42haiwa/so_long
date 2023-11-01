/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <cjouenne@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:23:56 by cjouenne          #+#    #+#             */
/*   Updated: 2023/11/01 16:47:22 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "MLX42/MLX42.h"

int	main(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(400, 200, "so_long", 0);
	if (!mlx)
		return (1);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
