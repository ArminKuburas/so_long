/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:12:10 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/03 20:02:45 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

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
		while (i < (int)ft_strlen(data->map[j]))
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
