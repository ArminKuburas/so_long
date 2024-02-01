/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:26:14 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/01 06:10:56 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void	argument_check(t_data *data, char *map_path)
{
	int		str_len;

	str_len = ft_strlen(map_path);
	if (str_len < 5)
		error_handler(data, 2);
	if (ft_strncmp(&map_path[str_len - 4], ".ber", 4) != 0)
		error_handler(data, 2);
	data->map_fd = open(map_path, O_RDONLY);
	if (data->map_fd == -1)
		error_handler(data, 4);
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
	data->map = (char **)malloc((data->line_amount + 1) * sizeof(char **));
	if (data->map == NULL)
		error_handler(data, 3);
	ft_printf("After mallocing data->map\n");
	data->map[data->line_amount] = NULL;
	ft_printf("After setting data->map to NULL\n");
}

void	init_data(t_data *data, char *map_path)
{
	int	check;

	map_path_check(data, map_path);
	ft_printf("After map_path_check\n");
	map_validity_check(data, map_path);
	ft_printf("After map_validity_check\n");
	check = is_map_beatable(data);
	if (check == 0)
		error_handler(data, 2);
	else if (check == 1)
		ft_printf("Map is beatable\n");
}
