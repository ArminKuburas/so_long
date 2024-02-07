/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:35:35 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/05 12:29:34 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

int	check_walls(char *str)
{
	int	str_len;

	str_len = (ft_strlen(str) - 2);
	if (str[0] == '1' && str[str_len] == '1')
		return (0);
	return (1);
}

void	compare_length(t_data *data)
{
	int	i;

	i = 0;
	if (ft_strlen(data->map[i]) < 3)
		error_handler(data, INVALID_FILE);
	while (i < data->line_amount)
	{
		if (i == (data->line_amount - 1))
		{
			if (ft_strlen(data->map[i]) != (ft_strlen(data->map[0]) - 1))
				error_handler(data, INVALID_FILE);
		}
		else if (ft_strlen(data->map[i]) != ft_strlen(data->map[0]))
			error_handler(data, INVALID_FILE);
		i++;
	}
}

void	argument_check(t_data *data, char *map_path)
{
	int		str_len;

	str_len = ft_strlen(map_path);
	if (str_len < 5)
		error_handler(data, INVALID_FILE);
	if (ft_strncmp(&map_path[str_len - 4], ".ber", 4) != 0)
		error_handler(data, INVALID_FILE);
	data->map_fd = open(map_path, O_RDONLY);
	if (data->map_fd == -1)
		error_handler(data, OPEN_FAILED);
}
