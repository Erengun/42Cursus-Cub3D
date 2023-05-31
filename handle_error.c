/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erengun <erengun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:54:35 by erengun           #+#    #+#             */
/*   Updated: 2023/05/31 15:05:02 by erengun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_conditions(t_control control)
{
    return (control.read_file != 0 || control.check_wall != 0
        || control.get_map != 0 || control.set_map != 0
        || control.player_pos != 0);
}

void handle_error(t_data *data, t_control control)
{
    free_func(data, control.check_wall | control.get_map |
              control.player_pos | control.read_file | control.set_map);
    printf("Error\n");
}
