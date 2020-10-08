/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 10:59:22 by elovegoo          #+#    #+#             */
/*   Updated: 2020/10/08 12:28:46 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static double get_draw_params(t_data *data, t_spr *spr, double height)
{
	spr->step_y = data->spr_h / height;
	spr->step_x = data->spr_w / height;
	spr->tmp_step_x = spr->step_x;
	spr->tmp_step_y = spr->step_y;
	spr->tmp_y = 0;
	height = ((int)height == data->res_h || ceil(height) == data->res_h || \
		floor(height) == data->res_h) ? (height + 2.0) : height;
	if (height >= data->res_h - 2.0)
	{
		spr->step_y = ((height - data->res_h) / 2) * spr->tmp_step_y;
		spr->tmp_y = spr->step_y;
		spr->old_y = -1;
		height = data->res_h;
	}
	else
	{
		spr->old_y = (data->res_h - height) / 2;
		height += spr->old_y;
	}
	return (height);
}

void	draw_sprt(t_data *data, t_spr spr, double height)
{
	int y;

	height = get_draw_params(data, &spr, height);
	while (spr.start_i < spr.end_i && (y = spr.old_y))
	{
		if (spr.dist < data->dist_arr[spr.start_i])
		{
			while (++y < height)
			{
				if (spr.step_y > data->spr_h)
					break ;
				spr.color = data->spr_addr[(int)(spr.step_x) + (int)(spr.\
				diff_start * spr.tmp_step_x) + (int)(spr.step_y) *\
							data->spr_w];
				if (spr.color >= 1000000 && spr.color <= 167772150)
					data->addr[(int)spr.start_i + (int)(y * data->res_w)] = \
									spr.color;
				spr.step_y = spr.step_y + spr.tmp_step_y;
			}
		}
		spr.start_i++;
		spr.step_y = spr.tmp_step_y + spr.tmp_y;
		spr.step_x = spr.step_x + spr.tmp_step_x;
	}
}
