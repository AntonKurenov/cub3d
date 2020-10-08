/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprt_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:35:43 by elovegoo          #+#    #+#             */
/*   Updated: 2020/10/08 11:00:12 by elovegoo         ###   ########.fr       */
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
			if (spr[j].dist < spr[j + 1].dist)
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
