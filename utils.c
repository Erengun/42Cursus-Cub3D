/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erengun <erengun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:58:30 by Lil_Dicks         #+#    #+#             */
/*   Updated: 2023/06/01 12:59:04 by erengun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	deg2rad(int deg)
{
	return (deg * (M_PI / 180));
}

void	render_window(t_data *data)
{
	double		angle;
	t_ray_data	*ray;
	int			i;

	i = GAMEWIDTH;
	angle = data->player.fov;
	ray = (t_ray_data *)malloc(sizeof(t_ray_data) * GAMEWIDTH);
	mlx_clear_window(data->mlx, data->win4);
	while (i--)
	{
		ray[i] = calculate_ray(data, angle);
		angle -= data->player.fov / GAMEWIDTH;
	}
	draw_screen4(data, ray);
	data->dist_l = ft_sqrt(ft_pow(ray[0].ray_location.x, 2)
			+ ft_pow(ray[0].ray_location.y, 2));
	data->dist_r = ft_sqrt(ft_pow(ray[GAMEWIDTH - 1].ray_location.x, 2)
			+ ft_pow(ray[GAMEWIDTH - 1].ray_location.y, 2));
	free(ray);
}


int	extension_check(char *path)
{
	int len;

	len = ft_strlen(path);
	if (len > 4 && ft_strncmp(path + len - 4, ".cub", 4) == 0)
		return (0);
	return (-1);
}

void	ft_xpm_cleaner(t_data *data)
{
	if (data->map_data.xpm_dir[0])
		free(data->map_data.xpm_dir[0]);
	if (data->map_data.xpm_dir[1])
		free(data->map_data.xpm_dir[1]);
	if (data->map_data.xpm_dir[2])
		free(data->map_data.xpm_dir[2]);
	if (data->map_data.xpm_dir[3])
		free(data->map_data.xpm_dir[3]);
}

void	update_direction(t_data *data, int i, int j, int angle)
{
	data->player.direction = angle;
	data->player.pos.x = (double)j + .5;
	data->player.pos.y = (double)i + .5;
	data->map_data.map[i][j] = '0';
}
