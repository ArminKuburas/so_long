/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_strdup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:36:07 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/02 22:30:21 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void	ft_double_strdup(char **copy, char **original)
{
	int	i;

	i = 0;
	ft_printf("Before while loop inside ft double strdup\n");
	while (original[i] != NULL)
	{
		ft_printf("Inside while loop inside ft double strdup\n");
		ft_printf("This is original[i]: %s\n", original[i]);
		copy[i] = ft_strdup(original[i]);
		if (!copy[i])
		{
			ft_free_substrings(&copy);
			break ;
		}
		i++;
	}
}
