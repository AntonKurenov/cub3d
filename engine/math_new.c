/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 17:26:11 by elovegoo          #+#    #+#             */
/*   Updated: 2020/09/16 20:11:33 by elovegoo         ###   ########.fr       */
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
	/*printf("len_vert = %f\nlen_horiz = %f\n", len_vert, len_horiz);*/
	printf("||||||||||||||||||||||||||||||||||||\n");
	printf("hor_len = %f\nlen_vert = %f\n||||||||||||||||||||||||\n", data->hor_len, data->vert_len);
	if (data->hor_len >= data->vert_len)
	{
		len = data->vert_len * cos(corr_angle * RAD_CONV);
		draw_walls(data, len);
	}
	else
	{
		len = data->hor_len * cos(corr_angle * RAD_CONV);
		draw_walls(data, len);
	}
}

void receiver(t_data *data)
{
	int i;
	double angle;
	double init_angle;
	double start_angle;

	printf("pos_x = %f\npos_y = %f\n", data->pos_x, data->pos_y);
	i = 0;
	/*i = 30;*/
	start_angle = (double)((data->angle + H_FOV));
	data->init_a_x = (floor(data->pos_x / B_SIZE)) * B_SIZE;
	data->init_a_y = (floor(data->pos_y / B_SIZE)) * B_SIZE;
	printf("pos_x = %f\npos_y = %f\n", data->pos_x, data->pos_y);
	printf("data->init_a_x = %f\ndata->init_a_y = %f\n", data->init_a_x, data->init_a_y);
	/*while (i < 10)*/
	while (i < data->res_w)
	{
		printf("_____________________________________\n\n");
		/*reset_data(data);*/
		data->i = i;
		data->step_ang = ((double)i) * data->part_angle;
		init_angle = start_angle - data->step_ang;
		printf("i = %d\n", i);
		printf("init_angle = %f\n", init_angle);
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
	/*mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);*/
	/*mlx_loop(data->mlx);*/
}
