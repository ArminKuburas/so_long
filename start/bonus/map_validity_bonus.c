/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 00:00:00 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/07 07:00:29 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long_bonus.h"

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
				error_handler(data, INVALID_FILE);
			if (ft_strchr("01CEPB\n", data->map[i][j]) == NULL)
				error_handler(data, INVALID_FILE);
			if (data->map[i][j] == 'P')
				(*player_amount)++;
			if (data->map[i][j] == 'E')
				(*exit_amount)++;
			if (data->map[i][j] == 'C')
				data->collectable_amount += 1;
			if (data->map[i][j] == 'B')
				data->enemy_amount += 1;
			j++;
		}
		i++;
	}
}

static void	val_first_last(char *first, char *last, t_data *data)
{
	int	i;

	i = 0;
	while (first[i] != '\0')
	{
		if (first[i] == '\n' && first[i + 1] == '\0')
			break ;
		if (first[i] != '1')
			error_handler(data, INVALID_FILE);
		i++;
	}
	i = 0;
	while (last[i] != '\0')
	{
		if (last[i] != '1')
			error_handler(data, INVALID_FILE);
		i++;
	}
}

static void	line_check(t_data *data)
{
	int	player_amount;
	int	exit_amount;

	player_amount = 0;
	exit_amount = 0;
	compare_length(data);
	val_first_last(data->map[0], data->map[data->line_amount - 1], data);
	check_characters(data, &player_amount, &exit_amount);
	if (player_amount != 1 || exit_amount != 1 || data->collectable_amount < 1)
		error_handler(data, INVALID_FILE);
}

void	map_validity_check(t_data *data, char *map_path)
{
	int		i;
	int		malloc_check;

	close(data->map_fd);
	malloc_check = 0;
	data->map_fd = open(map_path, O_RDONLY);
	if (data->map_fd == -1)
		error_handler(data, OPEN_FAILED);
	i = 0;
	while (i < data->line_amount)
	{
		data->map[i] = get_next_line(data->map_fd, &malloc_check);
		if (malloc_check != 0)
			error_handler(data, MALLOC_FAILED);
		i++;
	}
	close(data->map_fd);
	line_check(data);
}

void	map_path_check(t_data *data, char *map_path)
{
	char	*temp;
	int		malloc_check;

	malloc_check = 0;
	argument_check(data, map_path);
	temp = get_next_line(data->map_fd, &malloc_check);
	if (malloc_check != 0)
		error_handler(data, MALLOC_FAILED);
	while (temp != NULL)
	{
		free(temp);
		data->line_amount++;
		temp = get_next_line(data->map_fd, &malloc_check);
		if (malloc_check != 0)
			error_handler(data, MALLOC_FAILED);
	}
	if (data->line_amount < 3)
		error_handler(data, INVALID_FILE);
	data->map = ft_calloc(data->line_amount + 1, sizeof(char *));
	if (data->map == NULL)
		error_handler(data, MALLOC_FAILED);
	data->map[data->line_amount] = NULL;
}
