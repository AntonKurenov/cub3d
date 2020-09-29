/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprt_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:35:43 by elovegoo          #+#    #+#             */
/*   Updated: 2020/09/29 18:28:04 by elovegoo         ###   ########.fr       */
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

static int	sort_sprites(t_data *data)
{
	int i;
	int j;
	int num;

	i = -1;
	num = 0;
	while (++i < data->num_spr - 1)
	{
		j = -1;
		if (data->spr[i].flag == 1)
		{
			while (++j < data->num_spr - i - 1)
			{
				if (data->spr[j].dist < data->spr[j + 1].dist)
					swap_el(&data->spr[j], &data->spr[j + 1]);
			}
			num++;
		}
	}
	return (num);
}

void	draw_sprt(t_data *data, double height, int *addr, t_spr *spr)
{
	int y;
	double tmp;
	double step_x;
	double step_y;
	double i;

	step_y = data->spr_h / height;
	step_x = data->spr_w / height;
	tmp = step_y;
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
	while (++spr->start_i < spr->end_i)
	{
		y = -1;
		while (++y < height)
		{
			data->addr[(int)spr->start_i + (int)(y * data->res_w)] = data->\
				spr_addr[(int)(step_x) + (int)(step_y) * data->spr_h];
			step_y = step_y + tmp;
		}
	}
}



void	sprt_work(t_data *data)
{
	int i;
	int num;

	num = sort_sprites(data) + 1;
	i = 0;
	while (--num)
	{
		draw_sprt(data, data->spr[i].height, data->spr_addr, &data->spr[i]);
	}
}
