/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erengun <erengun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 00:34:16 by erengun           #+#    #+#             */
/*   Updated: 2023/06/01 15:15:01 by erengun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathlib.h"

double	ft_pow(double var, int pow)
{
	int		i;
	double	ret;

	i = 0;
	ret = 1;
	while (i < pow)
	{
		ret *= var;
		i++;
	}
	return (ret);
}
