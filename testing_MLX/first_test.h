/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:12:47 by akuburas          #+#    #+#             */
/*   Updated: 2024/01/25 17:32:00 by akuburas         ###   ########.fr       */
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
	mlx_texture_t	*hero_textures[3];
	mlx_image_t		*hero_images[3];
	double			time;
	int				hero_frames;
	int				x;
}			t_gdata;

#endif