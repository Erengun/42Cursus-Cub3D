/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erengun <erengun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:31:38 by Lil_Dicks         #+#    #+#             */
/*   Updated: 2023/06/01 12:26:25 by erengun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_char(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	is_border_wall(t_data *data, int i, int j)
{
	if (i == 0 || i == (int)(array_len(data->map_data.map) - 1) || j == 0)
	{
		if (data->map_data.map[i][j] == '0')
			return (-1);
	}
	return (0);
}

int	is_valid_direction(t_data *data, int i, int j)
{
	if (data->map_data.map[i - 1][j] == ' '
		|| data->map_data.map[i + 1][j] == ' '
		|| data->map_data.map[i][j - 1] == ' '
		|| data->map_data.map[i][j + 1] == ' ')
		return (-1);
	return (0);
}

int	check_wall(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map_data.map[i])
	{
		j = 0;
		while (data->map_data.map[i][j])
		{
			if (is_border_wall(data, i, j) == -1)
				return (-1);

			if (is_valid_char(data->map_data.map[i][j]))
			{
				if (is_valid_direction(data, i, j) == -1)
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}



int	ft_multi_map(t_data *data, char **lines)
{
	int		flag;
	int		i;
	char	*tmp;

	i = 0;
	flag = 0;
	while (lines[i])
	{
		tmp = ft_strdup(ft_is_space(lines[i]));
		flag = control(tmp, flag, data, i);
		if (flag == 3)
			return (-1);
		free(tmp);
		i++;
	}
	if (flag == 1)
		data->map_data.map_end = i - 1;
	return (0);
}
