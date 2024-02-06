/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 01:20:30 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/06 08:28:09 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

static void	move_player_up(t_data *data)
{
	if (data->map[data->player_y - 1][data->player_x] != '1')
	{
		data->img_hero->instances[0].y -= data->img_wall->height;
		data->player_y--;
		data->move_count++;
		ft_printf("Current move count: %d\n", data->move_count);
		if (data->map[data->player_y][data->player_x] == 'E')
			check_exit(data);
		if (data->map[data->player_y][data->player_x] == 'C')
			check_collectible(data);
	}
}

static void	move_player_left(t_data *data)
{
	if (data->map[data->player_y][data->player_x - 1] != '1')
	{
		data->img_hero->instances[0].x -= data->img_wall->width;
		data->player_x--;
		data->move_count++;
		ft_printf("Current move count: %d\n", data->move_count);
		if (data->map[data->player_y][data->player_x] == 'E')
			check_exit(data);
		if (data->map[data->player_y][data->player_x] == 'C')
			check_collectible(data);
	}
}

static void	move_player_down(t_data *data)
{
	if (data->map[data->player_y + 1][data->player_x] != '1')
	{
		data->img_hero->instances[0].y += data->img_wall->height;
		data->player_y++;
		data->move_count++;
		ft_printf("Current move count: %d\n", data->move_count);
		if (data->map[data->player_y][data->player_x] == 'E')
			check_exit(data);
		if (data->map[data->player_y][data->player_x] == 'C')
			check_collectible(data);
	}
}

static void	move_player_right(t_data *data)
{
	if (data->map[data->player_y][data->player_x + 1] != '1')
	{
		data->img_hero->instances[0].x += data->img_wall->width;
		data->player_x++;
		data->move_count++;
		ft_printf("Current move count: %d\n", data->move_count);
		if (data->map[data->player_y][data->player_x] == 'E')
			check_exit(data);
		if (data->map[data->player_y][data->player_x] == 'C')
			check_collectible(data);
	}
}

void	player_movement(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(data->mlx);
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_player_up(data);
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_player_left(data);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_player_down(data);
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_player_right(data);
}
