/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 10:50:11 by elovegoo          #+#    #+#             */
/*   Updated: 2020/10/07 11:38:53 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int get_flag(double pl_x, double pl_y, double spr_x, double spr_y)
{
	if (pl_x <= spr_x && pl_y >= spr_y)
		return (1);
	if (pl_x > spr_x && pl_y > spr_y)
		return (2);
	if (pl_x > spr_x && pl_y < spr_y)
		return (3);
	if (pl_x < spr_x && pl_y < spr_y)
		return (4);
	return (0);
}

int	get_ang_flag(double angle)
{
	if (angle >= 0 && angle <= 90)
		return (1);
	if (angle > 90 && angle <= 180)
		return (2);
	if (angle > 180 && angle <= 270)
		return (3);
	if (angle > 270 && angle <= 360)
		return (4);
	return (0);
}
