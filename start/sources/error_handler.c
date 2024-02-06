/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:38:13 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/06 04:51:54 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void	error_handler(t_data *data, int classification)
{
	ft_printf("Error\n");
	if (classification == INVALID_FILE)
		ft_printf("Invalid file given. \n");
	else if (classification == MALLOC_FAILED)
		ft_printf("Malloc failed. \n");
	else if (classification == OPEN_FAILED)
		ft_printf("Open failed \n");
	else if (classification == INIT_FAILED)
		ft_printf("MLX42 Initialization failed.\n");
	if (data->map != NULL)
		ft_free_substrings(&(data->map));
	exit(1);
}

void	mlx_error(t_data *data, int classification)
{
	if (classification == IMAGE_FAILED)
		ft_printf("Image failed to be placed.\n");
	else if (classification == LOAD_FAILURE)
		ft_printf("Image failed to load.\n");
	else if (classification == RESIZE_FAILED)
		ft_printf("Image failed to resize.\n");
	close_everything(data);
}

static void	delete_images(t_data *data)
{
	if (data->img_collectible != NULL)
		mlx_delete_image(data->mlx, data->img_collectible);
	if (data->img_exit != NULL)
		mlx_delete_image(data->mlx, data->img_exit);
	if (data->img_floor != NULL)
		mlx_delete_image(data->mlx, data->img_floor);
	if (data->img_hero != NULL)
		mlx_delete_image(data->mlx, data->img_hero);
	if (data->img_wall != NULL)
		mlx_delete_image(data->mlx, data->img_wall);
}

void	close_everything(t_data *data)
{
	mlx_close_window(data->mlx);
	delete_images(data);
	if (data->collectible != NULL)
		mlx_delete_texture(data->collectible);
	if (data->exit != NULL)
		mlx_delete_texture(data->exit);
	if (data->floor != NULL)
		mlx_delete_texture(data->floor);
	if (data->hero != NULL)
		mlx_delete_texture(data->hero);
	if (data->wall != NULL)
		mlx_delete_texture(data->wall);
	free(data->collectable_x);
	data->collectable_x = NULL;
	free(data->collectable_y);
	data->collectable_y = NULL;
	ft_free_substrings(&data->map);
	mlx_terminate(data->mlx);
	exit(0);
}
