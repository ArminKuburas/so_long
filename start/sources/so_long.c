/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:56:08 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/05 10:08:14 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void	game_handler(t_data *data)
{
	data->mlx = mlx_init(1800, 900, "Save The Sheep!", 0);
	if (data->mlx == NULL)
		error_handler(data, 5);
	texture_image_loader(data);
	resizer(data);
	create_map(data);
	mlx_key_hook(data->mlx, player_movement, data);
	mlx_close_hook(data->mlx, close_everything, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	if (argc != 2)
	{
		ft_printf("Error\nUsage: ./so_long [file_name].ber\n");
		return (1);
	}
	init_data(&data, argv[1]);
	game_handler(&data);
	return (0);
}
