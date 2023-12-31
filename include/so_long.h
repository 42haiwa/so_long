/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <cjouenne@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:13:38 by cjouenne          #+#    #+#             */
/*   Updated: 2023/11/14 06:47:44 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# include "MLX42/MLX42.h"

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

# define I_SIZE 48
# define TITLE "so_long"

typedef struct s_map
{
	ssize_t	width;
	ssize_t	height;
	char	**map;
}	t_map;

typedef struct s_player
{
	int			x;
	int			y;
	mlx_image_t	*img;
}	t_player;

typedef struct s_flood_fill
{
	char	**map;
}	t_flood_fill;

typedef struct s_loop_data
{
	mlx_t			*mlx;
	t_map			*map;
	t_player		player;
	mlx_texture_t	*floor_texture;
	mlx_image_t		*floor_img;
	mlx_texture_t	*fence_texture;
	mlx_image_t		*fence_img;
	mlx_texture_t	*egg_texture;
	mlx_image_t		*egg_img;
	mlx_texture_t	*exit_texture;
	mlx_image_t		*exit_img;
}	t_loop_data;

// map_checker.c
int			check_element2(char const c, int *has_item,
				int	*has_exit, int *has_spawn);
int			check_element(char const *map_buf);
int			is_lines_equals(char const *map_buf);

// map_checker2.c
int			is_map_closed(char const *map_buf);

// map_parser.c
void		map_free(t_map *map);
void		map_parse(t_map *map, char const *map_buf);

// utils.c
void		ft_hook(void *param);
void		ft_key_hook(mlx_key_data_t key, void *param);
void		ft_exit(t_loop_data *data);
void		ft_coin(t_loop_data *data);

// player_utils.c
void		get_player_pos(int *p_x, int *p_y, t_map *map);

// player.c
void		up(t_loop_data *data, int *n);
void		right(t_loop_data *data, int *n);
void		down(t_loop_data *data, int *n);
void		left(t_loop_data *data, int *n);

// map_renderer.c
void		map_render(t_map *map, t_loop_data *data);

// alloc_image_tex.c
void		alloc_image_tex(t_loop_data *data, mlx_texture_t **texture);

// map_exitable.c
int			is_map_exitable(t_loop_data *data);

// bfs.c
int			flood_fill(int x, int y, t_map *map, t_flood_fill *fill);
#endif
