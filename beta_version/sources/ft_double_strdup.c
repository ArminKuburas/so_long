/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_strdup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:36:07 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/06 04:19:43 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void	ft_double_strdup(char **copy, char **original)
{
	int	i;

	i = 0;
	while (original[i] != NULL)
	{
		copy[i] = ft_strdup(original[i]);
		if (!copy[i])
		{
			ft_free_substrings(&copy);
			break ;
		}
		i++;
	}
}
