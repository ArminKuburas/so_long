/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 00:00:00 by akuburas          #+#    #+#             */
/*   Updated: 2024/01/31 13:33:41 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

static void	check_characters(t_data *data, int *player_amount, int *exit_amount)
{
	int	i;
	int	j;

	i = 1;
	while (i < data->line_amount - 1)
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (check_walls(data->map[i]) == 1)
				error_handler(data, 2);
			if (ft_strchr("01CEP\n", data->map[i][j]) == NULL)
				error_handler(data, 2);
			if (data->map[i][j] == 'P')
				player_amount += 1;
			if (data->map[i][j] == 'E')
				exit_amount += 1;
			if (data->map[i][j] == 'C')
				data->collectable_amount += 1;
			j++;
		}
		i++;
	}
}

void	val_first_last(char *first, char *last, t_data *data)
{
	int	i;

	i = 0;
	while (first[i] != '\0')
	{
		if (first[i] == '\n' && first[i + 1] == '\0')
			break ;
		if (first[i] != '1')
			error_handler(data, 2);
		i++;
	}
	i = 0;
	while (last[i] != '\0')
	{
		if (last[i] != '1')
			error_handler(data, 2);
		i++;
	}
}


void	compare_length(t_data *data)
{
	int	i;

	i = 0;
	if (ft_strlen(data->map[i]) < 3)
		error_handler(data, 2);
	while (i < data->line_amount)
	{
		if (i == (data->line_amount - 1))
		{
			if (ft_strlen(data->map[i]) != (ft_strlen(data->map[0]) - 1))
				error_handler(data, 2);
		}
		else if (ft_strlen(data->map[i]) != ft_strlen(data->map[0]))
			error_handler(data, 2);
		i++;
	}
}

static void	line_check(t_data *data)
{
	int	player_amount;
	int	exit_amount;

	player_amount = 0;
	exit_amount = 0;
	val_first_last(data->map[0], data->map[data->line_amount - 1], data);
	compare_length(data);
	check_characters(data, &player_amount, &exit_amount);
	if (player_amount != 1 || exit_amount != 1 || data->collectable_amount < 1)
		error_handler(data, 2);
}

void	map_validity_check(t_data *data, char *map_path)
{
	char	*temp;
	int		i;

	close(data->map_fd);
	data->map_fd = open(map_path, O_RDONLY);
	if (data->map_fd == -1)
		error_handler(data, 2);
	i = 0;
	while (i < data->line_amount)
	{
		temp = get_next_line(data->map_fd);
		data->map[i] = ft_strdup(temp);
		free(temp);
		i++;
	}
	line_check(data);
}
