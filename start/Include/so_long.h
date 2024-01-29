/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:52:35 by akuburas          #+#    #+#             */
/*   Updated: 2024/01/29 14:53:59 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>

void	init_data(t_data *data, char *map);
void	error_handler(t_data *data, int classification);

typedef struct s_data
{
	mlx_t			mlx;
	int32_t			width;
	int32_t			height;
	mlx_texture_t	hero;
	mlx_image_t		hero;
	mlx_texture_t	empty_space;
	mlx_image_t		empty_space;
	mlx_texture_t	wall;
	mlx_image_t		wall;
	mlx_texture_t	collectible;
	mlx_image_t		collectible;
	mlx_texture_t	map_exit;
	mlx_image_t		map_exit;
}	t_data;

#endif