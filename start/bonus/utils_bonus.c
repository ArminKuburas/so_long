/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:37:26 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/06 14:13:21 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long_bonus.h"

char	*png_path(char *name, int number, t_data *data)
{
	char	*str;
	char	*trans_number;

	trans_number = ft_itoa(number);
	str = ft_strjoin(name, trans_number);
	if (!str)
		error_handler(data, MALLOC_FAILED);
	str = ft_strjoin(str, ".png");
	if (!str)
		error_handler(data, MALLOC_FAILED);
	return (str);
}

char	*number_str(char *name, int number, t_data *data)
{
	char	*str;
	char	*trans_number;

	trans_number = ft_itoa(number);
	str = ft_strjoin(name, trans_number);
	if (!str)
		mlx_error(data, MALLOC_FAILED);
	return (str);
}
