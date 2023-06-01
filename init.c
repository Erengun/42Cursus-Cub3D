/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erengun <erengun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 00:16:40 by erengun           #+#    #+#             */
/*   Updated: 2023/06/01 15:21:07 by erengun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_direction	*init_directions(t_direction *directions)
{
	directions[0] = (t_direction){'N', 270};
	directions[1] = (t_direction){'W', 180};
	directions[2] = (t_direction){'E', 0};
	directions[3] = (t_direction){'S', 90};
	return (directions);
}

int	init_direction(t_data *data, int i, int j)
{
	static int			flags;
	static t_direction	directions[4];
	int					k;

	init_directions(directions);
	k = 0;
	while (k < 4)
	{
		if (data->map_data.map[i][j] == directions[k].c)
		{
			update_direction(data, i, j, directions[k].angle);
			flags += 1;
			break ;
		}
		k++;
	}
	if (k == 4 && (data->map_data.map[i][j] != '0'
		&& data->map_data.map[i][j] != '1'
		&& data->map_data.map[i][j] != 0)
		&& ft_isascii(data->map_data.map[i][j]))
		return ((-1));
	if (flags > 1)
		return ((-1));
	return ((0));
}

void	init_xpm(t_data *data)
{
	data->xpm[north].img = mlx_xpm_file_to_image(data->mlx,
			data->map_data.xpm_dir[north], &data->xpm[north].width,
			&data->xpm[north].height);
	data->xpm[north].img_ptr = mlx_get_data_addr(data->xpm[north].img,
			&data->xpm[north].bpp, &data->xpm[north].line_len,
			&data->xpm[north].endian);
	data->xpm[east].img = mlx_xpm_file_to_image(data->mlx,
			data->map_data.xpm_dir[east], &data->xpm[east].width,
			&data->xpm[east].height);
	data->xpm[east].img_ptr = mlx_get_data_addr(data->xpm[east].img,
			&data->xpm[east].bpp, &data->xpm[east].line_len,
			&data->xpm[east].endian);
	data->xpm[west].img = mlx_xpm_file_to_image(data->mlx,
			data->map_data.xpm_dir[west], &data->xpm[west].width,
			&data->xpm[west].height);
	data->xpm[west].img_ptr = mlx_get_data_addr(data->xpm[west].img,
			&data->xpm[west].bpp, &data->xpm[west].line_len,
			&data->xpm[west].endian);
	data->xpm[south].img = mlx_xpm_file_to_image(data->mlx,
			data->map_data.xpm_dir[south], &data->xpm[south].width,
			&data->xpm[south].height);
	data->xpm[south].img_ptr = mlx_get_data_addr(data->xpm[south].img,
			&data->xpm[south].bpp, &data->xpm[south].line_len,
			&data->xpm[south].endian);
}

void	init_var(t_data *data)
{
	data->player.pos.x = 0;
	data->player.pos.y = 0;
	data->player.fov = 60;
	data->player.direction = 60;
	data->mlx = mlx_init();
	data->width = MAPWIDTH * 64;
	data->height = MAPHEIGHT * 64;
	data->win4 = mlx_new_window(data->mlx, GAMEWIDTH, GAMEHEIGHT,
			"CZN BURAK");
	data->img4.img = mlx_new_image(data->mlx, GAMEWIDTH, GAMEHEIGHT);
	data->img4.addr = mlx_get_data_addr(data->img4.img, &data->img4.bpp,
			&data->img4.line_len, &data->img4.endian);
	ft_bzero(data->xpm, sizeof(t_xpm) * 4);
	ft_bzero(&data->map_data, sizeof(t_mapdata));
	data->ceiling_color = data->map_data.colors[flooor][0] * 0x010000
		+ data->map_data.colors[flooor][1] * 0x0100
		+ data->map_data.colors[flooor][2] * 0x01;
	data->floor_color = data->map_data.colors[ceiling][0] * 0x010000
		+ data->map_data.colors[ceiling][1] * 0x0100
		+ data->map_data.colors[ceiling][2] * 0x01;
}

void	init_color(t_data *data)
{
	data->floor_color = data->map_data.colors[flooor][0] * 0x010000
		+ data->map_data.colors[flooor][1] * 0x0100
		+ data->map_data.colors[flooor][2] * 0x01;
	data->ceiling_color = data->map_data.colors[ceiling][0] * 0x010000
		+ data->map_data.colors[ceiling][1] * 0x0100
		+ data->map_data.colors[ceiling][2] * 0x01;
}
