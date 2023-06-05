/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egun <egun@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 00:31:58 by egun              #+#    #+#             */
/*   Updated: 2023/06/01 18:10:29 by egun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_map_height(char *path)
{
	char	*line;
	char	*tmp;
	int		fd;
	int		ret;

	fd = open(path, O_RDONLY);
	ret = 0;
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_is_space(line);
		if (*tmp == '0' || *tmp == '1')
			ret++;
	}
	return (ret);
}

int	put_map(t_data *data, char **lines)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	start = data->map_data.map_start;
	end = data->map_data.map_end;
	while (start + i <= end)
	{
		data->map_data.map[i] = ft_strdup(lines[start + i]);
		i++;
	}
	array_cleaner((void **)lines);
	if (check_wall(data) == -1)
		return (-1);
	return (0);
}

int	check_all_way(t_data *data, int i, int j)
{
	if (data->map_data.map[i - 1][j] == 32 || (data->map_data.map[i - 1][j] >= 9
			&& data->map_data.map[i - 1][j] <= 13))
		return (-1);
	if (data->map_data.map[i + 1][j] == 32 || (data->map_data.map[i + 1][j] >= 9
			&& data->map_data.map[i + 1][j] <= 13))
		return (-1);
	if (data->map_data.map[i][j - 1] == 32 || (data->map_data.map[i][j - 1] >= 9
			&& data->map_data.map[i][j - 1] <= 13))
		return (-1);
	if (data->map_data.map[i][j + 1] == 32 || (data->map_data.map[i][j + 1] >= 9
			&& data->map_data.map[i][j + 1] <= 13))
		return (-1);
	if (data->map_data.map[i + 1][j + 1] == 32 || (data->map_data.map[i + 1][j
			+ 1] >= 9 && data->map_data.map[i + 1][j + 1] <= 13))
		return (-1);
	if (data->map_data.map[i - 1][j - 1] == 32 || (data->map_data.map[i - 1][j
			- 1] >= 9 && data->map_data.map[i - 1][j - 1] <= 13))
		return (-1);
	if (data->map_data.map[i - 1][j + 1] == 32 || (data->map_data.map[i - 1][j
			+ 1] >= 9 && data->map_data.map[i - 1][j + 1] <= 13))
		return (-1);
	if (data->map_data.map[i + 1][j - 1] == 32 || (data->map_data.map[i + 1][j
			- 1] >= 9 && data->map_data.map[i + 1][j - 1] <= 13))
		return (-1);
	return (0);
}

int	read_lines(char *path, char ***lines)
{
	int		fd;
	int		line_count;
	int		i;
	char	*line;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	line_count = count_lines(fd);
	close(fd);
	if (!line_count)
		return (-1);
	*lines = ft_calloc(line_count + 1, sizeof(char *));
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		(*lines)[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (line_count);
}
