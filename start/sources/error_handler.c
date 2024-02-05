/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:38:13 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/05 12:28:13 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void	error_handler(t_data *data, int classification)
{
	ft_printf("Error\n");
	if (classification == INVALID_FILE)
		ft_printf("Invalid file given. \n");
	else if (classification == MALLOC_FAILED)
		ft_printf("Malloc failed. \n");
	else if (classification == OPEN_FAILED)
		ft_printf("Open failed \n");
	else if (classification == INIT_FAILED)
		ft_printf("MLX42 Initialization failed.\n");
	if (data->map != NULL)
		ft_free_substrings(&(data->map));
	exit(1);
}
