/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:52:35 by akuburas          #+#    #+#             */
/*   Updated: 2024/01/29 16:39:29 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>

typedef struct s_data
{
	mlx_t			mlx;
	int				map_fd;
	int				line_amount;
	int32_t			width;
	int32_t			height;
	mlx_texture_t	hero;
	mlx_image_t		img_hero;
	mlx_texture_t	empty_space;
	mlx_image_t		img_empty_space;
	mlx_texture_t	wall;
	mlx_image_t		img_wall;
	mlx_texture_t	collectible;
	mlx_image_t		img_collectible;
	mlx_texture_t	exit;
	mlx_image_t		img_exit;
	char			**map_data;
}	t_data;

void	init_data(t_data *data, char *map);
void	error_handler(t_data *data, int classification);
char	*get_next_line(int fd);


#endif