/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:26:14 by akuburas          #+#    #+#             */
/*   Updated: 2024/01/29 14:56:06 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void	init_data(t_data *data, char *map_path)
{
	int	str_len;
	int	map_fd;

	str_len = ft_strlen(map_path);
	if (str_len < 5)
		error_handler(data, 2);
	if (ft_strncmp(map_path[str_len - 4], ".ber", 4) != 0)
		error_handler(data, 2);
	map_fd = open(map_path, O_RDONLY);
	if (map_fd == -1)
		error_handler(data, 2);
	else
		close(map_fd);
}
