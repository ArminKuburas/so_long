/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:01:10 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/07 07:50:34 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long_bonus.h"

static void	image_loader_helper(t_data *data)
{
	data->wall = mlx_load_png("./map_textures/wall_tile.png");
	if (data->wall == NULL)
		mlx_error(data, LOAD_FAILURE);
	data->img_wall = mlx_texture_to_image(data->mlx, data->wall);
	if (data->img_wall == NULL)
		mlx_error(data, IMAGE_FAILED);
	data->floor = mlx_load_png("./map_textures/ground_tile.png");
	if (data->floor == NULL)
		mlx_error(data, LOAD_FAILURE);
	data->img_floor = mlx_texture_to_image(data->mlx, data->floor);
	if (data->img_floor == NULL)
		mlx_error(data, IMAGE_FAILED);
}

void	texture_image_loader(t_data *data)
{
	int		i;
	char	*path;

	i = 0;
	image_loader_helper(data);
	while (i < 6)
	{
		path = png_path("./warrior_idle_textures/warrior_", i, data);
		if (path == NULL)
			mlx_error(data, MALLOC_FAILED);
		data->hero = mlx_load_png(path);
		if (data->hero == NULL)
			mlx_error(data, LOAD_FAILURE);
		free (path);
		i++;
	}
	i = 0;
	while (i < 6)
	{
		data->img_hero = mlx_texture_to_image(data->mlx, data->hero[i]);
		if (data->img_hero == NULL)
			mlx_error(data, IMAGE_FAILED);
		i++;
	}
	i = 0;
	while (i < 14)
	{
		path = png_path("./sheep_textures/sheep_", i, data);
		if (path == NULL)
			mlx_error(data, MALLOC_FAILED);
		data->collectible[i] = mlx_load_png(path);
		if (data->collectible == NULL)
			mlx_error(data, LOAD_FAILURE);
		free (path);
		i++;
	}
	data->collectible = mlx_load_png("./sheep_textures/sheep_0.png");
	if (data->collectible == NULL)
		mlx_error(data, LOAD_FAILURE);
	data->img_collectible = mlx_texture_to_image(data->mlx, data->collectible);
	if (data->img_collectible == NULL)
		mlx_error(data, IMAGE_FAILED);
	data->exit = mlx_load_png("./map_textures/exit_castle.png");
	if (data->exit == NULL)
		mlx_error(data, LOAD_FAILURE);
	data->img_exit = mlx_texture_to_image(data->mlx, data->exit);
	if (data->img_exit == NULL)
		mlx_error(data, IMAGE_FAILED);
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
		mlx_error(data, RESIZE_FAILED);
	if (mlx_resize_image(data->img_floor, width, height) == false)
		mlx_error(data, RESIZE_FAILED);
	if (mlx_resize_image(data->img_hero, width, height) == false)
		mlx_error(data, RESIZE_FAILED);
	if (mlx_resize_image(data->img_collectible, width, height) == false)
		mlx_error(data, RESIZE_FAILED);
	if (mlx_resize_image(data->img_exit, width, height) == false)
		mlx_error(data, RESIZE_FAILED);
	mlx_set_window_size(data->mlx, width * (ft_strlen(data->map[0]) - 1),
		height * data->line_amount);
}

void	check_exit(t_data *data)
{
	if (data->collected == data->collectable_amount)
		close_everything(data);
}

void	check_collectible(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->collectable_amount)
	{
		if (data->collectable_x[i] == data->player_x
			&& data->collectable_y[i] == data->player_y)
		{
			data->collected++;
			data->collectable_x[i] = -1;
			data->collectable_y[i] = -1;
			data->img_collectible->instances[i].enabled = false;
			break ;
		}
		i++;
	}
}
