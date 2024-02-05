/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:26:14 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/05 10:04:42 by akuburas         ###   ########.fr       */
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

static void	initialize_collectable_cordinates(t_data *data)
{
	data->collectable_x = ft_calloc(data->collectable_amount + 1, sizeof(int));
	if (!data->collectable_x)
		error_handler(data, 3);
	data->collectable_y = ft_calloc(data->collectable_amount + 1, sizeof(int));
	if (!data->collectable_y)
		error_handler(data, 3);
	data->collectable_x[data->collectable_amount] = -1;
	data->collectable_y[data->collectable_amount] = -1;
}

void	init_data(t_data *data, char *map_path)
{
	map_path_check(data, map_path);
	map_validity_check(data, map_path);
	if (is_map_beatable(data) == 0)
		error_handler(data, 2);
	data->map_fd = open(map_path, O_RDONLY);
	if (data->map_fd == -1)
		error_handler(data, 4);
	initialize_map(data);
	initialize_collectable_cordinates(data);
}
