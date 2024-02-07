/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:19:32 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/07 07:41:51 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../Libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>

enum e_errors
{
	MALLOC_FAILED = 3,
	INVALID_FILE = 2,
	OPEN_FAILED = 4,
	IMAGE_FAILED = 5,
	INIT_FAILED = 6,
	LOAD_FAILURE = 7,
	RESIZE_FAILED = 8
};

typedef struct s_pointer
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	z;
}	t_pointer;

typedef struct s_data
{
	mlx_t			*mlx;
	int				map_fd;
	int				line_amount;
	int				collectable_amount;
	int				collected;
	int				enemy_amount;
	int				*enemy_x;
	int				*enemy_y;
	int				*collectable_x;
	int				*collectable_y;
	int				move_count;
	mlx_image_t		*move_str;
	int				player_x;
	int				player_y;
	mlx_texture_t	*hero[6];
	mlx_image_t		**img_hero;
	mlx_texture_t	*floor;
	mlx_image_t		*img_floor;
	mlx_texture_t	*wall;
	mlx_image_t		*img_wall;
	mlx_texture_t	collectible[][14][];
	mlx_image_t		img_collectible[][14][];
	mlx_texture_t	*exit;
	mlx_image_t		*img_exit;
	mlx_texture_t	enemy[][8][];
	mlx_image_t		img_enemy[][8][];
	char			**map;
}	t_data;

void	init_data(t_data *data, char *map);
void	error_handler(t_data *data, int classification);
char	*get_next_line(int fd, int *malloc_fail);
int		check_walls(char *str);
void	ft_double_strdup(char **copy, char **original);
void	ft_free_substrings(char ***arr_str);
int		is_map_beatable(t_data *data);
void	map_validity_check(t_data *data, char *map_path);
void	compare_length(t_data *data);
void	map_path_check(t_data *data, char *map_path);
void	argument_check(t_data *data, char *map_path);
void	player_movement(mlx_key_data_t keydata, void *param);
void	create_map(t_data *data);
void	texture_image_loader(t_data *data);
void	resizer(t_data *data);
void	close_everything(t_data *data);
void	mlx_error(t_data *data, int classification);
void	check_exit(t_data *data);
void	check_collectible(t_data *data);
char	*number_str(char *name, int number, t_data *data);
void	enemy_cordinates(t_data *data);



#endif