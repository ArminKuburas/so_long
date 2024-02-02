/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_success_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:37:37 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/02 22:31:06 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

static void	dfs_collect(t_data *data, int x, int y, int *collected)
{
	if (x < 0 || y < 0 || y >= data->line_amount
		|| x >= (int)ft_strlen(data->map[0]) || data->map[y][x] == '1')
		return ;
	if (data->map[y][x] == 'C')
	{
		(*collected)++;
		data->map[y][x] = '0';
	}
	data->map[y][x] = '1';
	dfs_collect(data, x + 1, y, collected);
	dfs_collect(data, x - 1, y, collected);
	dfs_collect(data, x, y + 1, collected);
	dfs_collect(data, x, y - 1, collected);
}

static int	dfs_exit(char **map_data, int line_amount, int x, int y)
{
	if (x < 0 || y < 0 || y >= line_amount
		|| x >= (int)ft_strlen(map_data[0]) || map_data[y][x] == '1')
		return (0);
	if (map_data[y][x] == 'E')
		return (1);
	map_data[y][x] = '1';
	if (dfs_exit(map_data, line_amount, x + 1, y) == 1)
		return (1);
	if (dfs_exit(map_data, line_amount, x - 1, y) == 1)
		return (1);
	if (dfs_exit(map_data, line_amount, x, y + 1) == 1)
		return (1);
	if (dfs_exit(map_data, line_amount, x, y - 1) == 1)
		return (1);
	return (0);
}

static void	find_player(t_data *data, int *player_x, int *player_y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->line_amount && *player_y == -1)
	{
		j = 0;
		while (j < (int)ft_strlen(data->map[i]))
		{
			if (data->map[i][j] == 'P')
			{
				*player_x = j;
				*player_y = i;
				data->player_x = j;
				data->player_y = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

int	is_map_beatable(t_data *data)
{
	int		collected;
	int		player_x;
	int		player_y;
	char	**map_copy;
	int		result;

	collected = 0;
	player_x = -1;
	player_y = -1;
	find_player(data, &player_x, &player_y);
	map_copy = malloc((data->line_amount + 1) * sizeof(char **));
	if (!map_copy)
		error_handler(data, 3);
	map_copy[data->line_amount] = NULL;
	ft_printf("After mallocing map_copy\n");
	ft_double_strdup(map_copy, data->map);
	if (!map_copy)
		error_handler(data, 3);
	ft_printf("After ft_double_strdup\n");
	dfs_collect(data, player_x, player_y, &collected);
	ft_printf("After dfs_collect\n");
	ft_printf("This is collected: %d\n", collected);
	ft_printf("This is data->collectable_amount: %d\n", data->collectable_amount);
	result = dfs_exit(map_copy, data->line_amount, player_x, player_y);
	ft_printf("This is result: %d\n", result);
	ft_printf("After dfs_exit\n");
	ft_free_substrings(&map_copy);
	ft_printf("After ft_free_substrings map_copy\n");
	ft_free_substrings(&(data->map));
	ft_printf("After ft_free_substrings data->map\n");
	return (collected == data->collectable_amount && result);
}
