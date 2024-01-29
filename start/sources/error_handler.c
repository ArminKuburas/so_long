/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:38:13 by akuburas          #+#    #+#             */
/*   Updated: 2024/01/29 14:55:25 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void	error_handler(t_data *data, int classification)
{
	if (classification == 1)
		ft_printf("Usage: ./so_long [file_name].ber\n");
	else if (classification == 2)
		ft_printf("Invalid file given. \n");
	exit(1);
}