/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <cjouenne@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:23:56 by cjouenne          #+#    #+#             */
/*   Updated: 2023/11/01 21:38:37 by cjouenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_map_in_buffer(char **map_buf, char const *path)
{
	int		map_fd;
	char	*line;
	char	*tmp;

	map_fd = open(path, O_RDONLY);
	*map_buf = ft_calloc(sizeof(char), 1);
	while (1)
	{
		line = get_next_line(map_fd);
		if (line == NULL)
			break ;
		tmp = ft_strdup(*map_buf);
		free(*map_buf);
		*map_buf = ft_strjoin(tmp, line);
		free(line);
		free(tmp);
	}
}

int	main(int argc, char *argv[])
{
	char	*map_buf;
	t_map	map;

	ft_bzero(&map, sizeof(t_map));
	if (argc != 2)
	{
		ft_printf("Usage: ./so_long <map>\n");
		return (0);
	}
	load_map_in_buffer(&map_buf, argv[1]);
	if (!check_element(map_buf))
		return (0);
	ft_printf("Check element : ✅\n");
	if (!is_lines_equals(map_buf))
		return (0);
	ft_printf("Is lines equals : ✅\n");
	if (!is_map_closed(map_buf))
		return (0);
	ft_printf("Is map closed : ✅\n");
	map_parse(&map, map_buf);
	free(map_buf);
}
