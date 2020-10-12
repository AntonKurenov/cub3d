/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_sprt_funct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 14:52:33 by elovegoo          #+#    #+#             */
/*   Updated: 2020/10/12 15:01:19 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	reset_sprite(t_data *data, t_spr *spr)
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

int		get_diff(double num1, int num2)
{
	int new_num1;

	new_num1 = (int)num1;
	if (num1 > num2)
		return (num1 - num2);
	else if (num2 > num1)
		return (num2 - num1);
	return (0);
}

void	get_strt_and_end_angle(t_data *data, t_spr *spr, int fl_st, int fl_end)
{
	spr->diff_ang_start = data->start_ang - spr->strt_angle;
	spr->diff_ang_end = spr->end_angle - data->end_ang;
	if (data->flag_start == 1 && fl_st == 4)
		spr->diff_ang_start = data->start_ang + 360 - spr->strt_angle;
	if (data->flag_start == 4 && fl_st == 1)
		spr->diff_ang_start = -(spr->strt_angle + 360 - data->start_ang);
	if (data->flag_end == 1 && fl_end == 4)
		spr->diff_ang_end = -(data->end_ang + 360 - spr->end_angle);
	if (data->flag_end == 4 && fl_end == 1)
		spr->diff_ang_end = spr->end_angle + 360 - data->end_ang;
	spr->start_i = spr->diff_ang_start / data->part_angle;
	spr->end_i = data->res_w - spr->diff_ang_end / data->part_angle;
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
	spr->strt_angle = spr->mid_angle + (len * data->part_angle);
	if (spr->strt_angle > 360)
		spr->strt_angle = spr->strt_angle - 360;
	if (spr->end_angle < 0)
		spr->end_angle = 360 + spr->end_angle;
	spr->st_flag = get_ang_flag(spr->strt_angle);
	spr->end_flag = get_ang_flag(spr->end_angle);
	get_strt_and_end_angle(data, spr, spr->st_flag, spr->end_flag);
}
