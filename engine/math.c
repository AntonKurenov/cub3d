/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 17:26:11 by elovegoo          #+#    #+#             */
/*   Updated: 2020/09/25 17:45:34 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void len_compare(double angle, t_data *data, int i, int flag)
{
	int j;
	double corr_angle;
	double len;

	corr_angle = -30 + data->step_ang;
	data->flag = flag;
	get_horiz_inter(data, flag);
	get_vert_inter(data, flag);
	if (data->hor_len >= data->vert_len)
	{
		data->is_vert = 1;
		len = data->vert_len * cos(corr_angle * RAD_CONV);
		which_texture(data, len, flag);
	}
	else
	{
		data->is_vert = 0;
		len = data->hor_len * cos(corr_angle * RAD_CONV);
		which_texture(data, len, flag);
	}
}

double get_init_angle(t_data *data, double start_angle)
{
	double init_angle;

	init_angle = start_angle - data->step_ang;
	if (init_angle > 359)
	{
		init_angle = init_angle - 359;
		return (init_angle);
	}
	if (init_angle < 0)
	{
		init_angle = 360 + init_angle;
		return (init_angle);
	}
	return (init_angle);
}

void receiver(t_data *data)
{
	int i;
	double angle;
	double init_angle;
	double start_angle;

	i = 0;
	printf("data->angle = %d\n", data->angle);
	start_angle = (double)((data->angle + H_FOV));
	data->init_a_x = (floor(data->pos_x / B_SIZE)) * B_SIZE;
	data->init_a_y = (floor(data->pos_y / B_SIZE)) * B_SIZE;
	while (i < data->res_w)
	{
		data->i = i;
		data->step_ang = ((double)i) * data->part_angle;
		init_angle = get_init_angle(data, start_angle);
		data->cur_angle = init_angle;
		if (init_angle >= 0 && init_angle < 90)
		{
			angle = init_angle;
			data->tang = tan(angle * RAD_CONV);
			len_compare(angle, data, i, 1);	
		}
		if (init_angle >= 90 && init_angle < 180)
		{
			angle = 180 - init_angle;
			data->tang = tan(angle * RAD_CONV);
			len_compare(angle, data, i, 2);	
		}
		if (init_angle >= 180 && init_angle < 270)
		{
			angle = init_angle - 180;
			data->tang = tan(angle * RAD_CONV);
			len_compare(angle, data, i, 3);	
		}
		if (init_angle >= 270 && init_angle < 360)
		{
			angle = 360 - init_angle;
			data->tang = tan(angle * RAD_CONV);
			len_compare(angle, data, i, 4);	
		}
		i++;
	}
}
