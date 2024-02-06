/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 01:20:30 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/06 04:58:46 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void	check_exit(t_data *data)
{
	if (data->collected == data->collectable_amount)
	{
		ft_printf("You have collected all collectibles\n");
		ft_printf("You have won the game\n");
		close_everything(data);
	}
	else
		ft_printf("You can't exit yet\n");
}

void	check_collectible(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->collectable_amount)
	{
		if (data->collectable_x[i] == data->player_x
			&& data->collectable_y[i] == data->player_y)
		{
			data->collected++;
			data->collectable_x[i] = -1;
			data->collectable_y[i] = -1;
			data->img_collectible->instances[i].enabled = false;
			break ;
		}
		i++;
	}
}

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
	else
		ft_printf("You can't move there\n");
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
	else
		ft_printf("You can't move there\n");
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
	else
		ft_printf("You can't move there\n");
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
	else
		ft_printf("You can't move there\n");
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
