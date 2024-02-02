/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:26:14 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/02 23:45:38 by akuburas         ###   ########.fr       */
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

void	init_data(t_data *data, char *map_path)
{
	int	check;

	map_path_check(data, map_path);
	ft_printf("After map_path_check\n");
	map_validity_check(data, map_path);
	ft_printf("After map_validity_check\n");
	check = is_map_beatable(data);
	if (check == 0)
		error_handler(data, 2);
	else if (check == 1)
		ft_printf("Map is beatable\n");
	ft_printf("This is data->player_x: %d\n", data->player_x);
	ft_printf("This is data->player_y: %d\n", data->player_y);
	ft_printf("This is data->line_amount: %d\n", data->line_amount);
	ft_printf("This is data->collectable_amount: %d\n", data->collectable_amount);
	ft_printf("This is data->move_count: %d\n", data->move_count);
	data->map_fd = open(map_path, O_RDONLY);
	if (data->map_fd == -1)
		error_handler(data, 4);
	initialize_map(data);
	ft_printf("After initialize_map\n");
	ft_printf("This is where the player is: %c\n", data->map[data->player_y][data->player_x]);
	mlx_get_monitor_size(0, &data->width, &data->height);
	ft_printf("This is data->width: %d\n", data->width);
	ft_printf("This is data->height: %d\n", data->height);
	data->mlx = mlx_init(500, 500, "so_long", 0);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}
