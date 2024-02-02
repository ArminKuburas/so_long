/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:38:13 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/02 21:06:43 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void	error_handler(t_data *data, int classification)
{
	ft_printf("Error\n");
	if (classification == 1)
		ft_printf("Usage: ./so_long [file_name].ber\n");
	else if (classification == 2)
		ft_printf("Invalid file given. \n");
	else if (classification == 3)
		ft_printf("Malloc failed. \n");
	else if (classification == 4)
		ft_printf("Open failed \n");
	if (data->map != NULL)
		ft_free_substrings(&(data->map));
	ft_printf("Exiting program\n");
	exit(1);
}
