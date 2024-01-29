/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:26:14 by akuburas          #+#    #+#             */
/*   Updated: 2024/01/29 23:53:17 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void	map_path_check(t_data *data, char *map_path)
{
	int		str_len;
	char	*temp;

	str_len = ft_strlen(map_path);
	if (str_len < 5)
		error_handler(data, 2);
	if (ft_strncmp(&map_path[str_len - 4], ".ber", 4) != 0)
		error_handler(data, 2);
	data->map_fd = open(map_path, O_RDONLY);
	if (data->map_fd == -1)
		error_handler(data, 2);
	temp = get_next_line(data->map_fd);
	data->line_amount = 0;
	while (temp != NULL)
	{
		free(temp);
		data->line_amount += 1;
		temp = get_next_line(data->map_fd);
	}
	if (data->line_amount < 3)
		error_handler(data, 2);
	data->map_data = (char **)malloc(data->line_amount * sizeof(char **));
	if (data->map_data == NULL)
		error_handler(data, 3);
}

void	validate_first_line(char *line, t_data *data)
{
	int	i;

	i = 0;
	if (ft_strlen(line) < 3)
		error_handler(data, 2);
	while (line[i] != '\0')
	{
		if (line[i] == '\n' && line[i + 1] == '\0')
			break ;
		if (line[i] != '1')
			error_handler(data, 2);
		i++;
	}
}

void	validate_last_line(char *line, t_data *data)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
			error_handler(data, 2);
		i++;
	}
}

void	compare_length(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->line_amount)
	{
		if 
		if (ft_strlen(data->map_data[i]) != ft_strlen(data->map_data[0]))
			error_handler(data, 2);
		i++;
	}
}

void	check_characters(t_data *data)
{
	int	i;
	int	j;

	i = 1;
	while (i < data->line_amount - 1)
	{
		j = 0;
		while (data->map_data[i][j] != '\n')
		{
			if (ft_strchr("01CEP", data->map_data[i][j]) != NULL)
				error_handler(data, 2);
			if (data->map_data[i][j] == 'P')
				data->player_amount += 1;
			if (data->map_data[i][j] == 'E')
				data->exit_amount += 1;
			if (data->map_data[i][j] == 'C')
				data->collectable_amount += 1;
			j++;
		}
		i++;
	}
}

// now we need a function that checks if you can reach the exit from the player's starting position and collect all the collectibles

void	play_check(t_data *data)


void	line_check(t_data *data)
{
	validate_first_line(data->map_data[0], data);
	validate_last_line(data->map_data[data->line_amount - 1], data);
	compare_length(data);
	check_characters(data);
	if (data->player_amount != 1 || data->exit_amount != 1
		|| data->collectable_amount < 1)
		error_handler(data, 2);
	play_check(data);
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
		data->map_data[i] = ft_strdup(temp);
		free(temp);
		i++;
	}
	line_check(data);
}


void	init_data(t_data *data, char *map_path)
{
	ft_bzero(data, sizeof(t_data));
	map_path_check(data, map_path);
	map_validity_check(data, map_path);
	
}
