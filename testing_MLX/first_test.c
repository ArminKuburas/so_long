/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:08:52 by akuburas          #+#    #+#             */
/*   Updated: 2024/01/26 17:05:08 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "first_test.h"
#include "libft.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_gdata	*data;
	int		i;

	data->x = 1;
	i = 0;
	data = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->window);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		while (i < 6)
			data->hero_images[i++]->instances[0].y += 15;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		while (i < 6)
			data->hero_images[i++]->instances[0].y -= 15;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		while (i < 6)
			data->hero_images[i++]->instances[0].x += 15;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		while (i < 6)
			data->hero_images[i++]->instances[0].x -= 15;
	if (keydata.key == MLX_KEY_T && keydata.action == MLX_PRESS)
	{
		data->time = mlx_get_time();
		printf("Value at address stored in time: %lf\n", data->time);
	}
	if (keydata.key == MLX_KEY_N && keydata.action == MLX_PRESS)
		mlx_image_to_window(data->window, data->hero_images[0], 0, 0);
	data->x = 0;
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

void	exit_data(t_gdata *data, int classification)
{
	mlx_close_window(data->window);
	if (classification)
	{
		printf("Error strjoin failed");
		exit(1);
	}
}

char	*png_path(char *name, int number, t_gdata *data)
{
	char	*str;
	char	trans_number[2];

	trans_number[0] = 48 + number;
	trans_number[1] = '\0';
	str = ft_strjoin(name, trans_number);
	str = ft_strjoin(str, ".png");
	if (!str)
		exit_data(data, 1);
	return (str);
}

int	check_button(t_gdata *data)
{
	if (mlx_is_key_down(data->window, MLX_KEY_W))
		return (1);
	if (mlx_is_key_down(data->window, MLX_KEY_S))
		return (1);
	if (mlx_is_key_down(data->window, MLX_KEY_D))
		return (1);
	if (mlx_is_key_down(data->window, MLX_KEY_A))
		return (1);
	return (0);
}

void	my_hook(void *param)
{
	t_gdata	*data;
	double	time_since;
	int		num_frames;

	// if (data->x == 1)
	// 	return ;
	num_frames = 6;
	data = param;
	time_since = mlx_get_time();
	if (time_since - data->time >= 0.05)
	{
		data->hero_images[data->hero_frames]->instances->enabled = false;
		data->hero_frames = (data->hero_frames + 1) % num_frames;
		data->hero_images[data->hero_frames]->instances->enabled = true;
		data->time = mlx_get_time();
	}
	data->x = 1;
}

// void	my_hook2(void *param)
// {
// 	t_gdata		*data;
// 	static int	amount;
// 	double		time_since;

// 	data = param;
// 	amount++;
// 	time_since = mlx_get_time();
// 	if (time_since - data->time >= 1)
// 	{
// 		data->x = 1;
// 		printf("This is the amount of frames per second: %d\n", amount);
// 		data->time = mlx_get_time();
// 		amount = 0;
// 	}
// }

int	main(void)
{
	t_gdata		data;
	int			i;
	char		*png;

	data.hero_frames = 0;
	data.x = 0;
	data.time = mlx_get_time();
	data.window = mlx_init(512, 512, "Hello World", 1);
	mlx_scroll_hook(data.window, my_scrollhook, NULL);
	i = 0;
	while (i < 6)
	{
		png = (png_path("./warrior_idle_frames/warrior_", i, &data));
		printf("this is the png path: %s\n", png);
		data.hero_textures[i] = mlx_load_png(png);
		data.hero_images[i] = mlx_texture_to_image(data.window, data.hero_textures[i]);
		if (mlx_image_to_window(data.window, data.hero_images[i], 50, 50) < 0)
			;
		data.hero_images[i]->instances->enabled = false;
		free(png);
		// png = (png_path("./warrior_move_frames/warrior_m_", i, &data));
		// data.hero_m_textures[i] = mlx_load_png(png);
		// data.hero_m_images[i] = mlx_texture_to_image(data.window, data.hero_m_textures[i]);
		// if (mlx_image_to_window(data.window, data.hero_m_images[i], 50, 50) < 0)
		// 	;
		// data.hero_m_images[i]->instances->enabled = false;
		// free(png);
		i++;
	}
	data.hero_images[0]->instances->enabled = true;
	mlx_key_hook(data.window, my_keyhook, &data);
	mlx_loop_hook(data.window, my_hook, &data);
	// mlx_loop_hook(data.window, my_hook2, &data);
	mlx_loop(data.window);
	mlx_terminate(data.window);
	return (0);
}
