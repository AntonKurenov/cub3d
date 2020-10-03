/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprt_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:35:43 by elovegoo          #+#    #+#             */
/*   Updated: 2020/10/03 14:25:49 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void swap_el(t_spr *one, t_spr *two)
{
	t_spr tmp;

	tmp = *one;
	*one = *two;
	*two = tmp;
}

static void	sort_sprites(t_data *data, t_spr *spr, int num)
{
	int i;
	int j;
	int num_flag;

	if (num == 1)
		return ;
	i = -1;
	while (++i < (data->spr_in_view - 1) && (j = -1))
	{
		while (++j < data->spr_in_view - i - 1)
		{
			if (spr[j].dist > spr[j + 1].dist)
				swap_el(&spr[j], &spr[j + 1]);
		}
	}
}

void	reset_after_draw(t_data *data, t_spr ***spr)
{
	int i;
	int j;

	j = -1;
	while (++j < data->act_map_h && (i = -1))
	{
		while (++i < data->act_map_w)
			reset_sprite(data, &data->spr[j][i]);
	}
}

void	draw_sprt(t_data *data, t_spr spr, double height)
{
	int y;
	double tmp;
	double step_x;
	double step_y;
	double i;
	int start;
	int end;

	step_y = data->spr_h / height;
	step_x = data->spr_w / height;
	tmp = step_y;
	printf("\ninside draw_sprt\n");
	i = -1;
	if (height >= data->res_h)
	{
		step_y = ((height - data->res_h) / 2) * tmp;
		y = 0;
		height = data->res_h;
	}
	else
	{
		y = (data->res_h - height) / 2;
		height += y;
	}
	printf("spr.start_i = %d spr_end_i = %d\n", spr.start_i, spr.end_i);
	printf("step_y = %f step_x = %f\n", step_x, step_y);
	while (spr.start_i < spr.end_i && (y = -1))
	{
		while (++y < height)
		{
			data->addr[(int)spr.start_i + (int)(y * data->res_w)] = data->\
				spr_addr[(int)(step_x) + (int)(spr.diff_start) + (int)(step_y)\
				* data->spr_h];
			step_y = step_y + tmp;
		}
		spr.start_i++;
	}
}

void	sprt_work(t_data *data)
{
	int j;
	int i;
	t_spr *view_spr;
	int num;

	if (data->spr_in_view == 0)
		return ;
	num = -1;
	j = -1;
	if (!(view_spr = (t_spr*)malloc(sizeof(t_spr) * data->spr_in_view)))
		file_exit(2);
	while (data->map[++j] && (i = -1))
	{
		while (data->map[j][++i])
		{
			if (data->spr[j][i].dist != -1)
				view_spr[++num] = data->spr[j][i];
		}
	}
	sort_sprites(data, view_spr, data->spr_in_view);
	i = -1;
	while (++i < data->spr_in_view)
		draw_sprt(data, view_spr[i], view_spr[i].height);
	free(view_spr);
	reset_after_draw(data, &data->spr);
}
