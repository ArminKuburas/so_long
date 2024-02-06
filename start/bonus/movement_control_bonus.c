/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_control_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 01:20:30 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/06 14:23:00 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long_bonus.h"

static void	move_player_up(t_data *data)
{
	char	*temp;
	int		i;

	i = 0;
	if (data->map[data->player_y - 1][data->player_x] != '1')
	{
		while (i < 6)
			data->img_hero[i++]->instances[0].y -= data->img_wall->height;
		data->player_y--;
		data->move_count++;
		number_str(temp, data->move_count, data);
		if (data->move_str != NULL)
			mlx_delete_image(data->mlx, data->move_str);
		data->move_str = mlx_put_string(data->mlx, temp, 0, 0);
		if (data->move_str == NULL)
			mlx_error(data, IMAGE_FAILED);
		if (data->map[data->player_y][data->player_x] == 'E')
			check_exit(data);
		if (data->map[data->player_y][data->player_x] == 'C')
			check_collectible(data);
		if (data->map[data->player_y][data->player_x] == 'B')
			close_everything(data);
	}
}

static void	move_player_left(t_data *data)
{
	char	*temp;
	int		i;

	i = 0;
	if (data->map[data->player_y][data->player_x - 1] != '1')
	{
		while (i < 6)
			data->img_hero[i++]->instances[0].x -= data->img_wall->width;
		data->player_x--;
		data->move_count++;
		number_str(temp, data->move_count, data);
		if (data->move_str != NULL)
			mlx_delete_image(data->mlx, data->move_str);
		data->move_str = mlx_put_string(data->mlx, temp, 0, 0);
		if (data->move_str == NULL)
			mlx_error(data, IMAGE_FAILED);
		if (data->map[data->player_y][data->player_x] == 'E')
			check_exit(data);
		if (data->map[data->player_y][data->player_x] == 'C')
			check_collectible(data);
		if (data->map[data->player_y][data->player_x] == 'B')
			close_everything(data);
	}
}

static void	move_player_down(t_data *data)
{
	char	*temp;
	int		i;

	i = 0;
	if (data->map[data->player_y + 1][data->player_x] != '1')
	{
		while (i < 6)
			data->img_hero[i++]->instances[0].y += data->img_wall->height;
		data->player_y++;
		data->move_count++;
		number_str(temp, data->move_count, data);
		if (data->move_str != NULL)
			mlx_delete_image(data->mlx, data->move_str);
		data->move_str = mlx_put_string(data->mlx, temp, 0, 0);
		if (data->move_str == NULL)
			mlx_error(data, IMAGE_FAILED);
		if (data->map[data->player_y][data->player_x] == 'E')
			check_exit(data);
		if (data->map[data->player_y][data->player_x] == 'C')
			check_collectible(data);
		if (data->map[data->player_y][data->player_x] == 'B')
			close_everything(data);
	}
}

static void	move_player_right(t_data *data)
{
	char	*temp;
	int		i;

	i = 0;
	if (data->map[data->player_y][data->player_x + 1] != '1')
	{
		while (i < 6)
			data->img_hero[i++]->instances[0].x += data->img_wall->width;
		data->player_x++;
		data->move_count++;
		number_str(temp, data->move_count, data);
		if (data->move_str != NULL)
			mlx_delete_image(data->mlx, data->move_str);
		data->move_str = mlx_put_string(data->mlx, temp, 0, 0);
		if (data->move_str == NULL)
			mlx_error(data, IMAGE_FAILED);
		if (data->map[data->player_y][data->player_x] == 'E')
			check_exit(data);
		if (data->map[data->player_y][data->player_x] == 'C')
			check_collectible(data);
		if (data->map[data->player_y][data->player_x] == 'B')
			close_everything(data);
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
