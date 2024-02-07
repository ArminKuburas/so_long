/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:12:10 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/07 07:00:27 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long_bonus.h"

static void	place_wall_floor(t_data *data)
{
	t_pointer	cordinates;
	int32_t		check;

	cordinates = (t_pointer){};
	while (cordinates.j < data->line_amount)
	{
		cordinates.i = 0;
		cordinates.x = 0;
		while (cordinates.i < (int)ft_strlen(data->map[cordinates.j]))
		{
			if (data->map[cordinates.j][cordinates.i] == '1')
				check = mlx_image_to_window(data->mlx, data->img_wall,
						cordinates.x, cordinates.y);
			else
				check = mlx_image_to_window(data->mlx, data->img_floor,
						cordinates.x, cordinates.y);
			if (check == -1)
				mlx_error(data, IMAGE_FAILED);
			cordinates.x += data->img_wall->width;
			cordinates.i++;
		}
		cordinates.j++;
		cordinates.y += data->img_wall->height;
	}
}

static void	place_player(t_data *data)
{
	int	x;
	int	y;

	x = data->player_x * data->img_wall->width;
	y = data->player_y * data->img_wall->height;
	if (mlx_image_to_window(data->mlx, data->img_hero, x, y) == -1)
		mlx_error(data, IMAGE_FAILED);
}

static void	place_collectibles(t_data *data)
{
	t_pointer	cordinates;

	cordinates = (t_pointer){};
	while (cordinates.j < data->line_amount)
	{
		cordinates.i = 0;
		cordinates.x = 0;
		while (cordinates.i < (int)ft_strlen(data->map[0]) - 1)
		{
			if (data->map[cordinates.j][cordinates.i] == 'C')
			{
				if (mlx_image_to_window(data->mlx, data->img_collectible,
						cordinates.x, cordinates.y) == -1)
					mlx_error(data, IMAGE_FAILED);
				data->collectable_x[cordinates.z] = cordinates.i;
				data->collectable_y[cordinates.z] = cordinates.j;
				cordinates.z++;
			}
			cordinates.x += data->img_wall->width;
			cordinates.i++;
		}
		cordinates.j++;
		cordinates.y += data->img_wall->height;
	}
}

static void	place_exit(t_data *data)
{
	t_pointer	cordinates;

	cordinates = (t_pointer){};
	while (cordinates.j < data->line_amount)
	{
		cordinates.i = 0;
		cordinates.x = 0;
		while (cordinates.i < (int)ft_strlen(data->map[0]) - 1)
		{
			if (data->map[cordinates.j][cordinates.i] == 'E')
				if (mlx_image_to_window(data->mlx, data->img_exit,
						cordinates.x, cordinates.y) == -1)
					mlx_error(data, IMAGE_FAILED);
			cordinates.x += data->img_wall->width;
			cordinates.i++;
		}
		cordinates.j++;
		cordinates.y += data->img_wall->height;
	}
}

void	create_map(t_data *data)
{
	place_wall_floor(data);
	place_collectibles(data);
	place_exit(data);
	place_player(data);
	place_enemy(data);
}
