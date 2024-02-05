/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:01:10 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/05 10:09:50 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void	texture_image_loader(t_data *data)
{
	data->wall = mlx_load_png("../map_textures/wall_tile.png");
	if (data->wall == NULL)
		mlx_error(data, 1);
	data->img_wall = mlx_texture_to_image(data->mlx, data->wall);
	data->floor = mlx_load_png("../map_textures/ground_tile.png");
	if (data ->wall == NULL)
		mlx_error(data, 1);
	data->img_floor = mlx_texture_to_image(data->mlx, data->floor);
	data->hero = mlx_load_png("../warrior_idle_textures/warrior_0.png");
	if (data ->wall == NULL)
		mlx_error(data, 1);
	data->img_hero = mlx_texture_to_image(data->mlx, data->hero);
	data->collectible = mlx_load_png("../sheep_textures/sheep_0.png");
	if (data->collectible == NULL)
		mlx_error(data, 1);
	data->img_collectible = mlx_texture_to_image(data->mlx, data->collectible);
	data->exit = mlx_load_png("../map_textures/exit_castle.png");
	if (data->exit == NULL)
		mlx_error(data, 1);
	data->img_exit = mlx_texture_to_image(data->mlx, data->exit);
}

void	resizer(t_data *data)
{
	uint32_t	width;
	uint32_t	height;

	width = 1800 / ft_strlen(data->map[0]);
	height = 900 / data->line_amount;
	if (width > height)
		width = height;
	else
		height = width;
	if (mlx_resize_image(data->img_wall, width, height) == false)
		mlx_error(data, 4);
	if (mlx_resize_image(data->img_floor, width, height) == false)
		mlx_error(data, 4);
	if (mlx_resize_image(data->img_hero, width, height) == false)
		mlx_error(data, 4);
	if (mlx_resize_image(data->img_collectible, width, height) == false)
		mlx_error(data, 4);
	if (mlx_resize_image(data->img_exit, width, height) == false)
		mlx_error(data, 4);
	mlx_set_window_size(data->mlx, width * (ft_strlen(data->map[0]) - 1),
		height * data->line_amount);
}

void	close_everything(void *param)
{
	t_data	*data;

	data = param;
	mlx_delete_image(data->mlx, data->img_collectible);
	mlx_terminate(data->mlx);
}