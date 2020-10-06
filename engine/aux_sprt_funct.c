/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_sprt_funct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 14:52:33 by elovegoo          #+#    #+#             */
/*   Updated: 2020/10/06 21:27:06 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void reset_sprite(t_data *data, t_spr *spr)
{
	data->spr_in_view = 0;
	spr->diff_ang_end = 0;
	spr->diff_ang_start = 0;
	spr->flag = 0;
	spr->angle = 0;
	spr->dist = -1;
	spr->init_angle = -1;
	spr->diff_end = 0;
	spr->diff_start = 0;
	spr->start_i = 0;
	spr->end_i = 0;
	spr->height = 0;
	spr->strt_angle = 0;
	spr->end_angle = 0;
}

int get_diff(double num1, int num2)
{
	int diff;
	int new_num1;

	new_num1 = (int)num1;
	if (num1 > num2)
		return (num1 - num2);
	else if (num2 > num1)
		return (num2 - num1);
	return (0);
}

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

/*void get_diff_angle(t_data *data, t_spr *spr, double start, double end)*/
/*{*/
	/*spr->diff_ang_start = data->start_ang - start;*/
	/*spr->diff_ang_end = end - data->end_ang;*/
	/*if ((data->end_ang > 270 && data->end_ang < 360) && (end > 0 && end < 90))*/

void get_strt_and_end_angle(t_data *data, t_spr *spr, double start, double end)
{
	spr->diff_ang_start = data->start_ang - start;
	spr->diff_ang_end = end - data->end_ang;
	if (start - data->start_ang > 100)
		spr->diff_ang_start = data->start_ang + 360 - start;
	if (end - data->end_ang > 100)
		spr->diff_ang_end = data->end_ang + 360 - end;
	if (data->start_ang - start > 100)
		spr->diff_ang_start = start + 360 - data->start_ang;
	if (data->end_ang - end > 100)
		spr->diff_ang_end = end + 360 - data->end_ang;
	/*if ((data->end_ang > 270 && data->end_ang < 360) && (end > 0 && end < 90))*/
		/*spr->diff_ang_end = (360 + end) - data->end_ang;*/
	/*if (data->start_ang < start)*/
		/*spr->diff_ang_start = start + 360 - */
	printf("diff_ang_start = %f  diff_ang_end = %f\n", spr->diff_ang_start, \
			spr->diff_ang_end);
	spr->start_i = spr->diff_ang_start / data->part_angle;
	spr->end_i = data->res_w - spr->diff_ang_end / data->part_angle;
	printf("spr_start i = %d\n end i = %d\n", spr->start_i, spr->end_i);
	if (spr->diff_ang_start < 0)
	{
		spr->diff_start = -spr->diff_ang_start;
		spr->diff_start = -spr->start_i;
		spr->start_i = 0;
	}
	if (spr->diff_ang_end < 0)
	{
		spr->diff_end = -spr->diff_ang_end;
		spr->end_i = data->res_w;
	}
	printf("spr_start i = %d\n end i = %d\n", spr->start_i, spr->end_i);
	printf("diff_start = %f  diff_end = %f\n", spr->diff_start, spr->diff_end);
}

void	get_sprt_angle(t_data *data, t_spr *spr, double angle, double len)
{
	if (spr->flag == 1)
		spr->mid_angle = angle;
	if (spr->flag == 2)
		spr->mid_angle = 180 - angle;
	if (spr->flag == 3)
		spr->mid_angle = 180 + angle;
	if (spr->flag == 4)
		spr->mid_angle = 360 - angle;
	spr->end_angle = spr->mid_angle - (len * data->part_angle);
	spr->strt_angle =spr->mid_angle + (len * data->part_angle);
	if (spr->strt_angle > 360)
		spr->strt_angle = spr->strt_angle - 360;
	if (spr->end_angle < 0)
		spr->end_angle = 360 + spr->end_angle;
	printf("data: start_ang = %f end_ang = %f\n", data->start_ang, data->end_ang);
	printf("pl_mid_angle = %d\n", data->angle);
	printf("pos_x = %f pos_y = %f\n", data->pos_x, data->pos_y);
	printf("spr: x = %f y = %f\n", spr->new_x, spr->new_y);
	printf("spr_strt_angle = %f\n", spr->strt_angle);
	printf("spr_end_angle = %f\n", spr->end_angle);
	get_strt_and_end_angle(data, spr, spr->strt_angle, spr->end_angle);
}
