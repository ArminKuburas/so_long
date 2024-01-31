/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:26:14 by akuburas          #+#    #+#             */
/*   Updated: 2024/01/31 15:19:23 by akuburas         ###   ########.fr       */
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

void	init_data(t_data *data, char *map_path)
{
	int	j;

	ft_printf("Inside of init data. before bzero\n");
	ft_bzero(data, sizeof(t_data));
	ft_printf("After bzero  before map_path_check\n");
	map_path_check(data, map_path);
	ft_printf("After map_path_check\n");
	map_validity_check(data, map_path);
	ft_printf("After map validity check\n");
	j = is_map_beatable(data);
	ft_printf("Lets see what is_map_beatable is returning: %d\n", j);
	ft_printf("Inside of init data. After is_map_beatable\n");
}
