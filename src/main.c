/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjouenne <cjouenne@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:23:56 by cjouenne          #+#    #+#             */
/*   Updated: 2023/11/02 13:33:34 by cjouenne         ###   ########.fr       */
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

static void	map_init(t_map *map, int argc, char *argv[])
{
	char	*map_buf;

	ft_bzero(map, sizeof(t_map));
	if (argc != 2)
	{
		ft_printf("Usage: ./so_long <map>\n");
		exit(0);
	}
	load_map_in_buffer(&map_buf, argv[1]);
	if (!check_element(map_buf))
		exit(0);
	ft_printf("Check element : ✅\n");
	if (!is_lines_equals(map_buf))
		exit(0);
	ft_printf("Is lines equals : ✅\n");
	if (!is_map_closed(map_buf))
		exit(0);
	ft_printf("Is map closed : ✅\n");
	map_parse(map, map_buf);
	free(map_buf);
}

static void	start(t_map *map)
{
	t_loop_data		data;
	mlx_texture_t	*texture;

	data.map = map;
	data.mlx = mlx_init(map->width * I_SIZE, map->height * I_SIZE, TITLE, 0);
	if (!data.mlx)
		exit(1);
	texture = mlx_load_png("assets/p00.png");
	if (!texture)
		exit(1);
	data.player.img = mlx_texture_to_image(data.mlx, texture);
	if (!data.player.img)
		exit(1);
	data.floor_texture = mlx_load_png("assets/t023.png");
	if (!data.floor_texture)
		exit(1);
	data.floor_img = mlx_texture_to_image(data.mlx, data.floor_texture);
	if (!data.floor_img)
		exit(1);
	data.fence_texture = mlx_load_png("assets/t012.png");
	if (!data.fence_texture)
		exit(1);
	data.fence_img = mlx_texture_to_image(data.mlx, data.fence_texture);
	if (!data.fence_img)
		exit(1);
	data.egg_texture = mlx_load_png("assets/egg.png");
	if (!data.egg_texture)
		exit(1);
	data.egg_img = mlx_texture_to_image(data.mlx, data.egg_texture);
	if (!data.egg_img)
		exit(1);

	get_player_pos(&(data.player.x), &(data.player.y), map);
	mlx_key_hook(data.mlx, ft_key_hook, &data);
	mlx_loop_hook(data.mlx, ft_hook, &data);
	map_render(map, &data);
	mlx_image_to_window(data.mlx, data.player.img,
		data.player.x - I_SIZE, data.player.y - I_SIZE);
	mlx_loop(data.mlx);

	mlx_delete_image(data.mlx, data.egg_img);
	mlx_delete_texture(data.egg_texture);
	mlx_delete_image(data.mlx, data.fence_img);
	mlx_delete_texture(data.fence_texture);
	mlx_delete_image(data.mlx, data.floor_img);
	mlx_delete_texture(data.floor_texture);
	mlx_delete_image(data.mlx, data.player.img);
	mlx_delete_texture(texture);
	mlx_terminate(data.mlx);
}

int	main(int argc, char *argv[])
{
	t_map	map;

	map_init(&map, argc, argv);
	start(&map);
	map_free(&map);
}
