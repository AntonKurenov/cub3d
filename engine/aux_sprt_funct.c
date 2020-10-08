/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_sprt_funct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 14:52:33 by elovegoo          #+#    #+#             */
/*   Updated: 2020/10/08 11:09:06 by elovegoo         ###   ########.fr       */
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
	spr->diff_end = 0;
	spr->diff_start = 0;
	spr->start_i = 0;
	spr->end_i = 0;
	spr->height = 0;
	spr->strt_angle = 0;
	spr->end_angle = 0;
	spr->st_flag = 0;
	spr->end_flag = 0;
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

void get_strt_and_end_angle(t_data *data, t_spr *spr, int fl_st, int fl_end)
{
	spr->diff_ang_start = data->start_ang - spr->strt_angle;
	spr->diff_ang_end = spr->end_angle - data->end_ang;
	/*printf("data flag : st = %d end = %d\n", data->flag_start, data->flag_end);*/
	/*printf("spr flag: start = %d end = %d\n", fl_st, fl_end);*/
	if (data->flag_start == 1 && fl_st == 4)
		spr->diff_ang_start = data->start_ang + 360 - spr->strt_angle;
	if (data->flag_start == 4 && fl_st == 1)
		spr->diff_ang_start = -(spr->strt_angle + 360 - data->start_ang);
	if (data->flag_end == 1 && fl_end == 4)
		spr->diff_ang_end = -(data->end_ang + 360 - spr->end_angle);
	if (data->flag_end == 4 && fl_end == 1)
		spr->diff_ang_end = spr->end_angle + 360 - data->end_ang;
	/*printf("diff_ang_start = %f  diff_ang_end = %f\n", spr->diff_ang_start, \*/
			/*spr->diff_ang_end);*/
	spr->start_i = spr->diff_ang_start / data->part_angle;
	spr->end_i = data->res_w - spr->diff_ang_end / data->part_angle;
	/*printf("spr_start i = %d\n end i = %d\n", spr->start_i, spr->end_i);*/
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
	/*printf("spr->diff_start = %f\n", spr->diff_start);*/
	/*printf("spr_start i = %d\n end i = %d\n", spr->start_i, spr->end_i);*/
	/*printf("diff_start = %f  diff_end = %f\n", spr->diff_start, spr->diff_end);*/
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
	spr->st_flag = get_ang_flag(spr->strt_angle);
	spr->end_flag = get_ang_flag(spr->end_angle);
	/*printf("data: start_ang = %f end_ang = %f\n", data->start_ang, data->end_ang);*/
	/*printf("pl_mid_angle = %d\n", data->angle);*/
	/*printf("pos_x = %f pos_y = %f\n", data->pos_x, data->pos_y);*/
	/*printf("spr: x = %f y = %f\n", spr->new_x, spr->new_y);*/
	/*printf("spr_strt_angle = %f\n", spr->strt_angle);*/
	/*printf("spr_end_angle = %f\n", spr->end_angle);*/
	get_strt_and_end_angle(data, spr, spr->st_flag, spr->end_flag);
}
