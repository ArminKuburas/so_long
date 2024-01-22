/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:08:52 by akuburas          #+#    #+#             */
/*   Updated: 2024/01/22 15:04:59 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../MLX42/MLX42.h"

void	my_keyhook(mlx_key_data_t keydata, mlx_image_t *img)
{
	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
	{
		puts("Hello ");
		img->width += 10;
	}
	if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
		puts("World");
	if (keydata.key == MLX_KEY_L && keydata.action == MLX_REPEAT)
		puts("!");
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


int	main(void)
{
	mlx_t			*window;
	mlx_texture_t	*texture;
	double			initial_time;
	mlx_image_t		*img;

	initial_time = mlx_get_time();
	window = mlx_init(512, 512, "Hello World", 1);
	mlx_scroll_hook(window, my_scrollhook, NULL);
	texture = mlx_load_png("./warrior.png");
	img = mlx_texture_to_image(window, texture);
	mlx_key_hook(window, my_keyhook, img);
	mlx_image_to_window(window, img, 0, 0);
	mlx_loop_hook(window);
	mlx_loop(window);
	mlx_terminate(window);
	return (0);
}
