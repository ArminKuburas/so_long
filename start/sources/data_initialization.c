/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:26:14 by akuburas          #+#    #+#             */
/*   Updated: 2024/01/29 17:16:59 by akuburas         ###   ########.fr       */
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
}

void	map_validity_check(t_data *data, char *map_path)
{
	char	*temp;
	int		i;

	close(data->map_fd);
	data->map_fd = open(map_path, O_RDONLY);
	if (data->map_fd == -1)
		error_handler(data, 2);
	temp = get_next_line(data->map_fd);
	validate_first_line(temp);
}


void	init_data(t_data *data, char *map_path)
{
	map_path_check(data, map_path);
	map_validity_check(data, map_path);
	
}
