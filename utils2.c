/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erengun <erengun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:08:05 by Lil_Dicks         #+#    #+#             */
/*   Updated: 2023/05/31 15:05:08 by erengun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_func(t_data *data, int control_data)
{
	if (control_data & xpm)
		ft_xpm_cleaner(data);
	if (control_data & int_map)
		array_cleaner((void **)data->map_data.int_map);
	if (control_data & map)
		array_cleaner((void **)data->map_data.map);
}

int	array_len(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		i++;
	}
	return (i);
}

int	check_wall_xpm(t_data *data)
{
	int	i;
	int	fd;

	i = 0;
	fd = 0;
	while (i < 4)
	{
		fd = open(data->map_data.xpm_dir[i], O_RDONLY);
		if (fd == -1)
		{
			return (xpm);
		}
		close(fd);
		i++;
	}
	return (0);
}

