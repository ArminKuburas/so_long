/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:45:15 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/02 17:15:27 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX42/MLX42.h"
#include <stdio.h>
#include "libft.h"

void	loopey(mlx_t *mlx)
{
	mlx_loop(mlx);
}

int	main(void)
{
	mlx_t		*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(500, 500, "Second test", 1);
	loopey(mlx);
	printf("mlx_init returned: %p\n", mlx);
	mlx_terminate(mlx);
	return (0);
}