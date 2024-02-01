/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_success_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:37:37 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/01 06:11:29 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

static void	dfs_collect(t_data *data, int x, int y, int *collected)
{
	if (x < 0 || y < 0 || x >= data->line_amount
		|| y >= (int)ft_strlen(data->map[0]) || data->map[x][y] == '1')
		return ;
	if (data->map[x][y] == 'C')
	{
		(*collected)++;
		data->map[x][y] = '0';
	}
	data->map[x][y] = '1';
	dfs_collect(data, x + 1, y, collected);
	dfs_collect(data, x - 1, y, collected);
	dfs_collect(data, x, y + 1, collected);
	dfs_collect(data, x, y - 1, collected);
}

static int	dfs_exit(char **map_data, int line_amount, int x, int y)
{
	if (x < 0 || y < 0 || x >= line_amount
		|| y >= (int)ft_strlen(map_data[0]) || map_data[x][y] == '1')
		return (0);
	if (map_data[x][y] == 'E')
		return (1);
	map_data[x][y] = '1';
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
	while (i < data->line_amount && *player_x == -1)
	{
		j = 0;
		while (j < (int)ft_strlen(data->map[i]))
		{
			if (data->map[i][j] == 'P')
			{
				*player_x = i;
				*player_y = j;
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
	ft_printf("After ft_double_strdup\n");
	dfs_collect(data, player_x, player_y, &collected);
	ft_printf("After dfs_collect\n");
	result = dfs_exit(map_copy, data->line_amount, player_x, player_y);
	ft_printf("After dfs_exit\n");
	ft_free_substrings(map_copy);
	ft_free_substrings(data->map);
	return (collected == data->collectable_amount && result);
}
