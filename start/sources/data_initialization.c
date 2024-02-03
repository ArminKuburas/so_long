/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:26:14 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/03 20:37:10 by akuburas         ###   ########.fr       */
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

void	resize_function(int32_t width, int32_t height, void *param)
{
	t_data	*data;

	data = param;
	ft_printf("This is width: %d\n", width);
	ft_printf("This is height: %d\n", height);
	ft_printf("This is data->mlx->width: %d\n", data->mlx->width);
	ft_printf("This is data->mlx->height: %d\n", data->mlx->height);
	data->width = data->mlx->width;
	data->height = data->mlx->height;
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

void	key_handler(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_terminate(data->mlx);
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		data->img_hero->instances[0].y -= data->img_wall->height;
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		data->img_hero->instances[0].x -= data->img_wall->width;
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		data->img_hero->instances[0].y += data->img_wall->height;
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		data->img_hero->instances[0].x += data->img_wall->width;
}

void	init_data(t_data *data, char *map_path)
{
	int			check;
	uint32_t	width;
	uint32_t	height;

	map_path_check(data, map_path);
	ft_printf("After map_path_check\n");
	map_validity_check(data, map_path);
	ft_printf("After map_validity_check\n");
	check = is_map_beatable(data);
	if (check == 0)
		error_handler(data, 2);
	else if (check == 1)
		ft_printf("Map is beatable\n");
	ft_printf("This is data->player_x: %d\n", data->player_x);
	ft_printf("This is data->player_y: %d\n", data->player_y);
	ft_printf("This is data->line_amount: %d\n", data->line_amount);
	ft_printf("This is data->collectable_amount: %d\n", data->collectable_amount);
	ft_printf("This is data->move_count: %d\n", data->move_count);
	data->map_fd = open(map_path, O_RDONLY);
	if (data->map_fd == -1)
		error_handler(data, 4);
	initialize_map(data);
	ft_printf("After initialize_map\n");
	ft_printf("This is where the player is: %c\n", data->map[data->player_y][data->player_x]);
	ft_printf("This is data->width: %d\n", data->width);
	ft_printf("This is data->height: %d\n", data->height);
	data->mlx = mlx_init(1800, 900, "so_long", 0);
	mlx_resize_hook(data->mlx, resize_function, data);
	data->wall = mlx_load_png("../map_textures/wall_tile.png");
	data->img_wall = mlx_texture_to_image(data->mlx, data->wall);
	data->floor = mlx_load_png("../map_textures/ground_tile.png");
	data->img_floor = mlx_texture_to_image(data->mlx, data->floor);
	data->hero = mlx_load_png("../warrior_idle_textures/warrior_0.png");
	data->img_hero = mlx_texture_to_image(data->mlx, data->hero);
	width = 1800 / ft_strlen(data->map[0]);
	height = 900 / data->line_amount;
	if (width > height)
		width = height;
	else
		height = width;
	mlx_resize_image(data->img_wall, width, height);
	mlx_resize_image(data->img_floor, width, height);
	mlx_resize_image(data->img_hero, width, height);
	create_map(data);
	ft_printf("This is the height and witdh of the image: %d, %d\n", data->img_wall->height, data->img_wall->width);
	ft_printf("This is the height and witdh of the image floor: %d, %d\n", data->img_floor->height, data->img_floor->width);
	ft_printf("This is the height and witdh of the image hero: %d, %d\n", data->img_hero->height, data->img_hero->width);
	place_player(data);
	mlx_key_hook(data->mlx, key_handler, data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}
