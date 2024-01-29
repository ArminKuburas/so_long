/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:56:08 by akuburas          #+#    #+#             */
/*   Updated: 2024/01/29 14:48:44 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"


int32_t	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		error_handler(&data, 1);
	init_data(&data, argv[1]);
	return (0);
}
