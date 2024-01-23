/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:12:47 by akuburas          #+#    #+#             */
/*   Updated: 2024/01/23 15:33:16 by akuburas         ###   ########.fr       */
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
	mlx_texture_t	*hero_texture;
	mlx_image_t		*hero_image;
	double			time;
}				t_gdata;

#endif