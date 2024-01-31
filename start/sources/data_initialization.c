/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:26:14 by akuburas          #+#    #+#             */
/*   Updated: 2024/01/31 15:26:15 by akuburas         ###   ########.fr       */
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
	data->map = (char **)malloc((data->line_amount + 1) * sizeof(char **));
	if (data->map == NULL)
		error_handler(data, 3);
	data->map[data->line_amount + 1] = NULL;
}

void	init_data(t_data *data, char *map_path)
{
	int	j;

	ft_bzero(data, sizeof(t_data));
	map_path_check(data, map_path);
	map_validity_check(data, map_path);
	j = is_map_beatable(data);
}
