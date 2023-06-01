/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erengun <erengun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:54:35 by erengun           #+#    #+#             */
/*   Updated: 2023/06/01 12:47:34 by erengun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_conditions(t_control control)
{
	return (control.read_file != 0 || control.check_wall != 0
		|| control.get_map != 0 || control.set_map != 0
		|| control.player_pos != 0);
}

void	handle_error(t_data *data, t_control control)
{
	free_func(data, control.read_file | control.get_map | control.set_map);
}

//TODO printf serbest mi?
int	error_check(t_data *data, char *path)
{
	int			fd;
	t_control	control;

	fd = open(path, O_RDONLY);
	if (fd < 0 || extension_check(path) == -1)
	{
		printf("Error\n");
		return (-1);
	}
	control = (t_control){ft_read_file(data, fd), ft_check_xpm_fd(data),
		ft_get_map(data, path), ft_set_map(data),
		.player_pos = (data->player.pos.x == 0 && data->player.pos.y == 0)
		* (xpm | map | int_map)};
	if (check_conditions(control))
	{
		handle_error(data, control);
		return (-1);
	}
	return (0);
}
