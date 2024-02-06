/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_functions_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:13:51 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/06 16:17:39 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long_bonus.h"

void	enemy_cordinates(t_data *data)
{
	t_pointer	cordinates;

	cordinates = (t_pointer){};
	while (cordinates.j < data->line_amount)
	{
		cordinates.i = 0;
		cordinates.x = 0;
		while (cordinates.i < (int)ft_strlen(data->map[cordinates.j]))
		{
			if (data->map[cordinates.j][cordinates.i] == 'B')
			{
				data->enemy_x[z] = cordinates.i;
				data->enemy_y[z] = cordinates.j;
				data->enemy_amount++;
			}
			cordinates.i++;
		}
		cordinates.j++;
	}
}

void	initialize_enemies(t_data *data)
{
	data->enemy_y = malloc(data->enemy_amount * sizeof(int));
	if (data->enemy_y == NULL)
		error_handler(data, MALLOC_FAILED);
	data->enemy_x = malloc(data->enemy_amount * sizeof(int));
	if (data->enemy_y == NULL)
		error_handler(data, MALLOC_FAILED);
	enemy_cordinates(data);
}

