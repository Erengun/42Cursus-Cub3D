/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egun <egun@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 00:22:27 by egun              #+#    #+#             */
/*   Updated: 2023/06/01 18:10:35 by egun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_xpm(char *s, char **find, t_data *data)
{
	char	*tmp;
	int		i;

	i = 0;
	s = ft_is_space(s);
	while (i < 4)
	{
		if (!ft_strncmp(s, find[i], 2))
		{
			s = s + 2;
			s = ft_is_space(s);
			if (data->map_data.xpm_dir[i])
				return (-1);
			tmp = ft_substr(s, 0, ft_strlen(s) - 1);
			data->map_data.xpm_dir[i] = ft_strdup(tmp);
			data->map_data.xpm_dir[i] = last_trim(data->map_data.xpm_dir[i]);
			free(tmp);
			break ;
		}
		i++;
	}
	return (0);
}

char	**get_lines(char *path, int total_line)
{
	char	*line;
	int		fd;
	char	**ret;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	ret = ft_calloc(total_line + 1, sizeof(char *));
	line = get_next_line(fd);
	while (line)
	{
		ret[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	return (ret);
}

int	control(char *tmp, int flags, t_data *data, int i)
{
	if (flags == 0)
	{
		if (*tmp != '0' && *tmp != '1')
		{
			data->map_data.map_start = i + 1;
			return (flags);
		}
	}
	if (flags == 1)
	{
		if (*tmp == '0' || *tmp == '1')
		{
			data->map_data.map_end = i;
			return (flags);
		}
	}
	if (flags == 2)
	{
		if (*tmp != '0' && *tmp != '1')
			return (flags);
	}
	return (flags + 1);
}

int	ft_get_map(t_data *data, char *path)
{
	int		total_line;
	char	**lines;

	total_line = read_lines(path, &lines);
	if (total_line == -1)
		return (-1);
	data->map_data.map = ft_calloc(total_line, sizeof(char *));
	if (ft_multi_map(data, lines) == -1)
	{
		array_cleaner((void **)lines);
		return (-1);
	}
	if (put_map(data, lines) == -1)
		return (-1);
	return (0);
}

int	ft_read_file(t_data *data, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
	{
		printf("Error\n");
		exit(1);
	}
	while (line)
	{
		if (ft_check_xpm(line, (char *[]){"NO", "EA", "WE", "SO"}, data) == -1
			|| ft_check_rgb(line, (char *[]){"F", "C"}, 2, data) == -1)
		{
			free(line);
			return (xpm);
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	if (check_null(data) == -1)
		return (xpm);
	return (0);
}
