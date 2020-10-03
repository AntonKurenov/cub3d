/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_sprt_funct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 14:52:33 by elovegoo          #+#    #+#             */
/*   Updated: 2020/10/03 14:19:00 by elovegoo         ###   ########.fr       */
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

void get_strt_and_end_angle(t_data *data, t_spr *spr, double start, double end)
{
	spr->diff_ang_start = data->start_ang - start;
	spr->diff_ang_end = end - data->end_ang;
	printf("diff_ang_start = %f  diff_ang_end = %f\n", spr->diff_ang_start, \
			spr->diff_ang_end);
	spr->start_i = spr->diff_ang_start / data->part_angle;
	spr->end_i = data->res_w - spr->diff_ang_end / data->part_angle;
	printf("spr_start i = %d\n end i = %d\n", spr->start_i, spr->end_i);
	if (spr->diff_ang_start < 0)
	{
		spr->diff_start = -spr->diff_ang_start;
		spr->start_i = 0;
	}
	if (spr->diff_ang_end < 0)
	{
		spr->diff_end = -spr->diff_ang_end;
		spr->end_i = data->res_w;
	}
	printf("spr_start i = %d\n end i = %d\n", spr->start_i, spr->end_i);
}

void	get_sprt_angle(t_data *data, t_spr *spr, double angle, double len)
{
	double new;

	new = angle;
	if (spr->flag == 1)
		spr->strt_angle = new + len * data->part_angle;
	if (spr->flag == 2)
		spr->strt_angle = 180 - new + len * data->part_angle;
	if (spr->flag == 3)
		spr->strt_angle = 180 + new + len * data->part_angle;
	if (spr->flag == 4)
		spr->strt_angle = 360 - new + len * data->part_angle;
	spr->end_angle = spr->strt_angle - (len * data->part_angle);
	printf("spr_strt_angle = %f\n", spr->strt_angle);
	printf("spr_end_angle = %f\n", spr->end_angle);
	get_strt_and_end_angle(data, spr, spr->strt_angle, spr->end_angle);
}
