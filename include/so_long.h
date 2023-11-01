/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <cjouenne@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:13:38 by cjouenne          #+#    #+#             */
/*   Updated: 2023/11/01 21:46:41 by cjouenne         ###   ########.fr       */
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

typedef struct	s_map 
{
	ssize_t	width;
	ssize_t	height;
	char	**map;
}	t_map;

// map_checker.c
int	check_element2(char const c, int *has_item,
		int *has_exit, int *has_spawn);
int	check_element(char const *map_buf);
int	is_lines_equals(char const *map_buf);

// map_checker2.c
int	is_map_closed(char const *map_buf);

// map_parser.c
void	map_free(t_map *map);
void	map_parse(t_map *map, char const *map_buf);
#endif
