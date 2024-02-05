/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:26:14 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/05 04:05:19 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

static void	initialize_map(t_data *data)
{
	int		i;

	i = 0;
	data->map = ft_calloc(data->line_amount + 1, sizeof(char *));
	if (!data->map)
		error_handler(data, 3);
	data->map[data->line_amount] = NULL;
	while (i < data->line_amount)
	{
		data->map[i] = get_next_line(data->map_fd);
		if (!data->map[i])
			error_handler(data, 3);
		i++;
	}
}

void	create_map(t_data *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	j = 0;
	y = 0;
	while (j < data->line_amount)
	{
		i = 0;
		x = 0;
		while (i < (int)ft_strlen(data->map[0]) - 1)
		{
			if (data->map[j][i] == '1')
				mlx_image_to_window(data->mlx, data->img_wall, x, y);
			else
				mlx_image_to_window(data->mlx, data->img_floor, x, y);
			x += data->img_wall->width;
			i++;
		}
		j++;
		y += data->img_wall->height;
	}
}

void	place_player(t_data *data)
{
	int	x;
	int	y;

	x = data->player_x * data->img_wall->width;
	y = data->player_y * data->img_wall->height;
	mlx_image_to_window(data->mlx, data->img_hero, x, y);
}

void	place_collectibles(t_data *data)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	z;

	j = 0;
	y = 0;
	z = 0;
	while (j < data->line_amount)
	{
		i = 0;
		x = 0;
		while (i < (int)ft_strlen(data->map[0]) - 1)
		{
			if (data->map[j][i] == 'C')
			{
				if (mlx_image_to_window(data->mlx, data->img_collectible, x, y)
					== -1)
					mlx_error(data, 1);
				data->collectable_x[z] = i;
				data->collectable_y[z] = j;
				z++;
			}
			x += data->img_wall->width;
			i++;
		}
		j++;
		y += data->img_wall->height;
	}
}

void	place_exit(t_data *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	j = 0;
	y = 0;
	while (j < data->line_amount)
	{
		i = 0;
		x = 0;
		while (i < (int)ft_strlen(data->map[0]) - 1)
		{
			if (data->map[j][i] == 'E')
				mlx_image_to_window(data->mlx, data->img_exit, x, y);
			x += data->img_wall->width;
			i++;
		}
		j++;
		y += data->img_wall->height;
	}
}

void	init_data(t_data *data, char *map_path)
{
	int			check;
	uint32_t	width;
	uint32_t	height;

	map_path_check(data, map_path);
	map_validity_check(data, map_path);
	check = is_map_beatable(data);
	if (check == 0)
		error_handler(data, 2);
	else if (check == 1)
		ft_printf("Map is beatable\n");
	data->map_fd = open(map_path, O_RDONLY);
	if (data->map_fd == -1)
		error_handler(data, 4);
	initialize_map(data);
	data->mlx = mlx_init(1800, 900, "so_long", 0);
	mlx_resize_hook(data->mlx, resize_function, data);
	data->wall = mlx_load_png("../map_textures/wall_tile.png");
	data->img_wall = mlx_texture_to_image(data->mlx, data->wall);
	data->floor = mlx_load_png("../map_textures/ground_tile.png");
	data->img_floor = mlx_texture_to_image(data->mlx, data->floor);
	data->hero = mlx_load_png("../warrior_idle_textures/warrior_0.png");
	data->img_hero = mlx_texture_to_image(data->mlx, data->hero);
	data->collectible = mlx_load_png("../sheep_textures/sheep_0.png");
	data->img_collectible = mlx_texture_to_image(data->mlx, data->collectible);
	data->exit = mlx_load_png("../map_textures/exit_castle.png");
	data->img_exit = mlx_texture_to_image(data->mlx, data->exit);
	width = 1800 / ft_strlen(data->map[0]);
	height = 900 / data->line_amount;
	if (width > height)
		width = height;
	else
		height = width;
	mlx_resize_image(data->img_wall, width, height);
	mlx_resize_image(data->img_floor, width, height);
	mlx_resize_image(data->img_hero, width, height);
	mlx_resize_image(data->img_collectible, width, height);
	mlx_resize_image(data->img_exit, width, height);
	create_map(data);
	ft_printf("after create_map\n");
	mlx_set_window_size(data->mlx, data->img_wall->width * (ft_strlen(data->map[0]) - 1), data->img_wall->height * data->line_amount);
	data->collectable_x = ft_calloc(data->collectable_amount + 1, sizeof(int));
	if (!data->collectable_x)
		error_handler(data, 3);
	data->collectable_y = ft_calloc(data->collectable_amount + 1, sizeof(int));
	if (!data->collectable_y)
		error_handler(data, 3);
	data->collectable_x[data->collectable_amount] = -1;
	data->collectable_y[data->collectable_amount] = -1;
	place_collectibles(data);
	place_exit(data);
	place_player(data);
	mlx_key_hook(data->mlx, player_movement, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}
