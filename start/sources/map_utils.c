/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 00:00:00 by akuburas          #+#    #+#             */
/*   Updated: 2024/01/30 09:45:23 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	dfs(t_data *data, int x, int y, int *collected)
{
	if (x < 0 || y < 0 || x >= data->line_amount
		|| y >= strlen(data->map_data[0]) || data->map_data[x][y] == '1')
		return ;
	if (data->map_data[x][y] == 'C')
	{
		(*collected)++;
		data->map_data[x][y] = '0';
	}
	data->map_data[x][y] = '1';
	dfs(data, x - 1, y, collected);
	dfs(data, x + 1, y, collected);
	dfs(data, x, y - 1, collected);
	dfs(data, x, y + 1, collected);
}

int	is_map_beatable(t_data *data)
{
	int	collected;
	int	i;
	int	j;

	collected = 0;
	i = 0;
	while (i < data->line_amount)
	{
		j = 0;
		while (j < strlen(data->map_data[i]))
		{
			if (data->map_data[i][j] == 'P')
			{
				data->player_x = i;
				data->player_y = j;
				break ;
			}
			j++;
		}
		i++;
	}
	dfs(data, player_x, player_y, &collected);
	return (collected == data->collectable_amount
		&& data->map_data[player_x][player_y] == 'E');
}
