/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:26:14 by akuburas          #+#    #+#             */
/*   Updated: 2024/01/30 15:55:22 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/so_long.h"

void	map_path_check(t_data *data, char *map_path)
{
	int		str_len;
	char	*temp;

	str_len = ft_strlen(map_path);
	if (str_len < 5)
		error_handler(data, 2);
	if (ft_strncmp(&map_path[str_len - 4], ".ber", 4) != 0)
		error_handler(data, 2);
	data->map_fd = open(map_path, O_RDONLY);
	if (data->map_fd == -1)
		error_handler(data, 2);
	temp = get_next_line(data->map_fd);
	data->line_amount = 0;
	while (temp != NULL)
	{
		free(temp);
		data->line_amount += 1;
		temp = get_next_line(data->map_fd);
	}
	if (data->line_amount < 3)
		error_handler(data, 2);
	data->map_data = (char **)malloc(data->line_amount * sizeof(char **));
	if (data->map_data == NULL)
		error_handler(data, 3);
}

void	validate_first_line(char *line, t_data *data)
{
	int	i;

	i = 0;
	if (ft_strlen(line) < 3)
		error_handler(data, 2);
	while (line[i] != '\0')
	{
		if (line[i] == '\n' && line[i + 1] == '\0')
			break ;
		if (line[i] != '1')
			error_handler(data, 2);
		i++;
	}
}

void	validate_last_line(char *line, t_data *data)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
			error_handler(data, 2);
		i++;
	}
}

void	compare_length(t_data *data)
{
	int	i;

	i = 0;
	ft_printf("Inside of compare_length \n");
	while (i < data->line_amount)
	{
		if (i == (data->line_amount - 1))
		{
			if (ft_strlen(data->map_data[i])
				!= (ft_strlen(data->map_data[0]) - 1))
				error_handler(data, 2);
		}
		else if (ft_strlen(data->map_data[i]) != ft_strlen(data->map_data[0]))
			error_handler(data, 2);
		i++;
	}
}

int	check_walls(char *str)
{
	int	str_len;

	str_len = (ft_strlen(str) - 2);
	if (str[0] == '1' && str[str_len] == '1')
		return (0);
	return (1);
}

void	check_characters(t_data *data)
{
	int	i;
	int	j;

	i = 1;
	while (i < data->line_amount - 1)
	{
		j = 0;
		while (data->map_data[i][j] != '\0')
		{
			ft_printf("This is in check_characters. This is the character now: %c\n", data->map_data[i][j]);
			if (check_walls(data->map_data[i]) == 1)
				error_handler(data, 2);
			if (ft_strchr("01CEP\n", data->map_data[i][j]) == NULL)
				error_handler(data, 2);
			if (data->map_data[i][j] == 'P')
				data->player_amount += 1;
			if (data->map_data[i][j] == 'E')
				data->exit_amount += 1;
			if (data->map_data[i][j] == 'C')
				data->collectable_amount += 1;
			j++;
		}
		i++;
	}
}

void dfs_collect(t_data *data, int x, int y, int *collected)
{

	if (x < 0 || y < 0 || x >= data->line_amount || y >= (int)ft_strlen(data->map_data[0]) || data->map_data[x][y] == '1')
		return ;
	if (data->map_data[x][y] == 'C')
	{
		(*collected)++;
		data->map_data[x][y] = '0';
	}
	data->map_data[x][y] = '1';
	dfs_collect(data, x + 1, y, collected);
	dfs_collect(data, x - 1, y, collected);
	dfs_collect(data, x, y + 1, collected);
	dfs_collect(data, x, y - 1, collected);
}

int	dfs_exit_reachable(char **map_data, int line_amount, int x, int y)
{
	if (x < 0 || y < 0 || x >= line_amount || y >= (int)ft_strlen(map_data[0]) || map_data[x][y] == '1')
		return (0);
	ft_printf("Inside of dfs exit: This is x %d and y %d and this is map_data %c\n", x, y, map_data[x][y]);
	if (map_data[x][y] == 'E')
		return (1);
	map_data[x][y] = '1';
	if (dfs_exit_reachable(map_data, line_amount, x + 1, y) == 1)
		return (1);
	if (dfs_exit_reachable(map_data, line_amount, x - 1, y) == 1)
		return (1);
	if (dfs_exit_reachable(map_data, line_amount, x, y + 1) == 1)
		return (1);
	if (dfs_exit_reachable(map_data, line_amount, x, y - 1) == 1)
		return (1);

	return (0);
}

int	is_map_beatable(t_data *data)
{
	int		collected;
	int		i;
	int		j;
	int		player_x;
	int		player_y;
	char	**map_copy;

	collected = 0;
	i = 0;
	player_x = -1;
	player_y = -1;
	while (i < data->line_amount && player_x == -1)
	{
		j = 0;
		while (j < (int)ft_strlen(data->map_data[i]))
		{
			if (data->map_data[i][j] == 'P')
			{
				player_x = i;
				player_y = j;
				break ;
			}
			j++;
		}
		i++;
	}
	map_copy = malloc(data->line_amount * sizeof(char **));
	if (!map_copy)
		return (0);
	i = 0;
	while (i < data->line_amount)
	{
		map_copy[i] = ft_strdup(data->map_data[i]);
		if (!map_copy[i])
			return (0);
		i++;
	}
	dfs_collect(data, player_x, player_y, &collected);
	int result = dfs_exit_reachable(map_copy, data->line_amount, player_x, player_y);
		// freeing **char function.
	ft_printf("Inside of is map beatable. lets see what collected is: %d and lets see what the result is: %d\n", collected, result);
	return (collected == data->collectable_amount && result);
}

void	line_check(t_data *data)
{
	validate_first_line(data->map_data[0], data);
	ft_printf("inside line check. after validating the first line\n");
	validate_last_line(data->map_data[data->line_amount - 1], data);
	ft_printf("inside line check. after validating the last line\n");
	compare_length(data);
	ft_printf("inside line check. after compare length\n");
	check_characters(data);
	ft_printf("Inside line check. After check_characters.\n");
	if (data->player_amount != 1 || data->exit_amount != 1
		|| data->collectable_amount < 1)
		error_handler(data, 2);
	ft_printf("Inside line check. right at the end\n");
}

void	map_validity_check(t_data *data, char *map_path)
{
	char	*temp;
	int		i;

	close(data->map_fd);
	data->map_fd = open(map_path, O_RDONLY);
	if (data->map_fd == -1)
		error_handler(data, 2);
	ft_printf("Inside of map validity check. After open\n");
	i = 0;
	while (i < data->line_amount)
	{
		temp = get_next_line(data->map_fd);
		data->map_data[i] = ft_strdup(temp);
		free(temp);
		i++;
	}
	ft_printf("Inside of map validity check. Before line_check\n");
	line_check(data);
	ft_printf("Inside of map validity check. After line_check\n");
}


void	init_data(t_data *data, char *map_path)
{
	int	j;

	ft_printf("Inside of init data. before bzero\n");
	ft_bzero(data, sizeof(t_data));
	ft_printf("After bzero  before map_path_check\n");
	map_path_check(data, map_path);
	ft_printf("After map_path_check\n");
	map_validity_check(data, map_path);
	ft_printf("After map validity check\n");
	j = is_map_beatable(data);
	ft_printf("Lets see what is_map_beatable is returning: %d\n", j);
	ft_printf("Inside of init data. After is_map_beatable\n");
}
