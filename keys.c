/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egun <egun@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:57:35 by egun              #+#    #+#             */
/*   Updated: 2023/06/01 18:10:02 by egun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press_func(int keycode, t_data *data)
{
	if (keycode == Key_W || keycode == Key_A || keycode == Key_S
		|| keycode == Key_D)
		ft_move(keycode, data);
	if (keycode == key_rt)
		data->player.direction += 3;
	if (keycode == key_lt)
		data->player.direction -= 3;
	if (data->player.direction >= 360)
		data->player.direction = ft_abs((int)data->player.direction % 360);
	if (data->player.direction < 0)
		data->player.direction = 359;
	if (keycode == Key_ESC)
		ft_exit(data);
	render_window(data);
	return (0);
}
