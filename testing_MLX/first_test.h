/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:12:47 by akuburas          #+#    #+#             */
/*   Updated: 2024/01/26 16:46:54 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIRST_TEST_H
# define FIRST_TEST_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../MLX42/MLX42.h"

typedef struct s_gdata
{
	mlx_t			*window;
	mlx_texture_t	*hero_textures[6];
	mlx_texture_t	*hero_m_textures[6];
	mlx_image_t		*hero_images[6];
	mlx_image_t		*hero_m_images[6];
	double			time;
	int				hero_frames;
	int				x;
}			t_gdata;

#endif