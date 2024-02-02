/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 00:00:00 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/02 22:18:10 by akuburas         ###   ########.fr       */
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
				(*player_amount)++;
			if (data->map[i][j] == 'E')
				(*exit_amount)++;
			if (data->map[i][j] == 'C')
				data->collectable_amount += 1;
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

static void	line_check(t_data *data)
{
	int	player_amount;
	int	exit_amount;

	player_amount = 0;
	exit_amount = 0;
	compare_length(data);
	ft_printf("After compare_length\n");
	val_first_last(data->map[0], data->map[data->line_amount - 1], data);
	ft_printf("After val_first_last\n");
	check_characters(data, &player_amount, &exit_amount);
	ft_printf("After check_characters\n");
	ft_printf("This is player_amount %d\n", player_amount);
	ft_printf("This is exit_amount %d\n", exit_amount);
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
		error_handler(data, 4);
	ft_printf("After opening map in map_validity_check\n");
	i = 0;
	while (i < data->line_amount)
	{
		data->map[i] = get_next_line(data->map_fd);
		if (!data->map[i])
			error_handler(data, 3);
		i++;
	}
	close(data->map_fd);
	line_check(data);
	ft_printf("After line_check\n");
}

void	map_path_check(t_data *data, char *map_path)
{
	char	*temp;

	argument_check(data, map_path);
	temp = get_next_line(data->map_fd);
	while (temp != NULL)
	{
		free(temp);
		data->line_amount++;
		temp = get_next_line(data->map_fd);
	}
	ft_printf("This is line amount %d\n", data->line_amount);
	if (data->line_amount < 3)
		error_handler(data, 2);
	ft_printf("After checking line_amount\n");
	data->map = ft_calloc(data->line_amount + 1, sizeof(char *));
	if (data->map == NULL)
		error_handler(data, 3);
	ft_printf("After mallocing data->map\n");
	data->map[data->line_amount] = NULL;
	ft_printf("After setting data->map to NULL\n");
}
