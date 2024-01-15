/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:08:52 by akuburas          #+#    #+#             */
/*   Updated: 2024/01/15 16:51:18 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../MLX42/MLX42.h"

int	main(void)
{
	mlx_t	*window;

	window = mlx_init(512, 512, "Hello World", 1);
	mlx_loop(window);
	return (0);
}
