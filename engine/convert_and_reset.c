/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_and_reset.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 11:14:51 by elovegoo          #+#    #+#             */
/*   Updated: 2020/09/19 11:46:23 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_angle reset_angle(t_angle ang, t_data *data, int key)
{
	ang.init_angle = data->angle;
	ang.new_x = 0;
	ang.new_y = 0;
	ang.key = key;
	ang.mid_angle = 0;
	ang.new_angle = 0;
	printf("ang.init_angle = %d\n", ang.init_angle);
	return (ang);
}

void convert_angle(t_angle *ang)
{
	if (ang->key == BUTTON_W || ang->key == BUTTON_S)
		ang->mid_angle = ang->init_angle;
	else if (ang->key == BUTTON_D)
		ang->mid_angle = ang->init_angle - 90;
	else if (ang->key == BUTTON_A)
		ang->mid_angle = ang->init_angle + 90;
	if (ang->mid_angle >= 360)
		ang->mid_angle = ang->mid_angle - 360;
	if (ang->mid_angle < 0)
		ang->mid_angle = -1 * ang->mid_angle;
	ang->new_angle = ang->mid_angle;
	if (ang->mid_angle > 90 && ang->mid_angle <= 180) 
		ang->new_angle = 180 - ang->mid_angle;
	if (ang->mid_angle > 180 && ang->mid_angle <= 270)
		ang->new_angle = ang->mid_angle - 180;
	if (ang->mid_angle > 270 && ang->mid_angle <= 360)
		ang->new_angle = 360 - ang->mid_angle;
	printf("ang->new_angle = %d\n", ang->new_angle);
	ang->new_x = cos(ang->new_angle * RAD_CONV) * STEP;
	ang->new_y = sin(ang->new_angle * RAD_CONV) * STEP;
}

void close_win(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
}

