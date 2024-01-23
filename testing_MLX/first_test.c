/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:08:52 by akuburas          #+#    #+#             */
/*   Updated: 2024/01/23 16:17:48 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "first_test.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_gdata	*data;

	data = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->window);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		data->hero_image->instances[0].y += 15;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		data->hero_image->instances[0].y -= 15;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		data->hero_image->instances[0].x += 15;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		data->hero_image->instances[0].x -= 15;
	if (keydata.key == MLX_KEY_T && keydata.action == MLX_PRESS)
	{
		data->time = mlx_get_time();
		printf("Value at address stored in x: %lf\n", data->time);
	}
	if (keydata.key == MLX_KEY_N && keydata.action == MLX_PRESS)
		mlx_image_to_window(data->window, data->hero_image, 0, 0);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		data->hero_image->instances[1].y += 15;
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		data->hero_image->instances[1].y -= 15;
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		data->hero_image->instances[1].x += 15;
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		data->hero_image->instances[1].x -= 15;
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	if (ydelta > 0)
		puts("Up!");
	else if (ydelta < 0)
		puts("Down!");

	if (xdelta < 0)
		puts("Sliiiide to the left!");
	else if (xdelta > 0)
		puts("Sliiiide to the right!");
}

void	my_hook(void *param)
{
	t_gdata		*data;
	double		time_since;
	int32_t		x;
	int32_t		y;

	data = param;
	time_since = mlx_get_time();
	if (time_since - data->time >= 10)
	{
		x = data->hero_image->instances[0].x;
		y = data->hero_image->instances[0].y;
		mlx_delete_image(data->window, data->hero_image);
		mlx_delete_texture(data->hero_texture);
		data->hero_texture = mlx_load_png("./warrior_2.png");
		data->hero_image = mlx_texture_to_image(data->window, data->hero_texture);
		mlx_image_to_window(data->window, data->hero_image, x, y);
		printf("It has been 10 seconds\n");
		data->time = mlx_get_time();
	}
}

int	main(void)
{
	t_gdata	*data;

	data->time = mlx_get_time();
	printf("Value at address stored in x: %lf\n", data->time);
	data->window = mlx_init(512, 512, "Hello World", 1);
	mlx_scroll_hook(data->window, my_scrollhook, NULL);
	data->hero_texture = mlx_load_png("./warrior.png");
	data->hero_image = mlx_texture_to_image(data->window, data->hero_texture);
	mlx_key_hook(data->window, my_keyhook, data);
	//mlx_loop_hook(data->window, my_hook, data);
	mlx_image_to_window(data->window, data->hero_image, 0, 0);
	mlx_loop(data->window);
	mlx_terminate(data->window);
	return (0);
}
