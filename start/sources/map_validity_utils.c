/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:35:35 by akuburas          #+#    #+#             */
/*   Updated: 2024/01/31 13:35:53 by akuburas         ###   ########.fr       */
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