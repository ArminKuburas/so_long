/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_substrings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:34:00 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/02 21:04:15 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void	ft_free_substrings(char ***arr_str)
{
	int	i;

	i = 0;
	while ((*arr_str)[i] != NULL)
	{
		free((*arr_str)[i]);
		(*arr_str)[i] = NULL;
		i++;
	}
	if (*arr_str != NULL)
	{
		free(*arr_str);
		*arr_str = NULL;
	}
}
