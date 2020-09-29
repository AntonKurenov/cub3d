/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 12:11:05 by elovegoo          #+#    #+#             */
/*   Updated: 2020/09/29 18:48:54 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_sprt_angle(t_data *data, t_spr *spr, double angle, double len)
{
	double new;

	new = angle + data->part_angle * len;
	if (data->flag == 1)
		spr->strt_angle = new;
	if (data->flag == 2)
		spr->strt_angle = 180 - new;
	if (data->flag == 3)
		spr->strt_angle = 180 + new;
	if (data->flag == 4)
		spr->strt_angle = 360 - new;
	spr->start_i = (data->start_ang - spr->strt_angle) / data->step_ang - 1;
	spr->end_i = spr->start_i + spr->height;
}

void	check_sprites(t_data *data, int x, int y)
{
	int i;
	double angle;
	double dist;
	int diff_x;
	int diff_y;

	i = -1;
	angle = data->cur_angle;
	while (++i < data->num_spr)
	{
		if (data->spr[i].x == x && data->spr[i].y == y)
		{
			if (data->spr[i].flag == 1)
				return ;
			data->spr[i].flag = 1;
			break ;
		}
	}
	diff_x = abs((int)data->pos_x - data->spr[i].new_x);
	diff_y = abs((int)data->pos_y - data->spr[i].new_y);
	data->spr[i].dist = sqrt(diff_x * diff_x + diff_y * diff_y);
	data->spr[i].height = (data->plane_dist / data->spr[i].dist);
	data->spr[i].angle = atan(diff_y / diff_x);
	data->spr[i].half_height = data->spr[i].height / 2;
	get_sprt_angle(data, &data->spr[i], data->spr[i].angle, data->spr[i]. \
			half_height);
}

void	init_sprites(t_data *data, char **map)
{
	int i;
	int j;
	int num;

	j = -1;
	num = data->num_spr;
	if ((data->spr = (t_spr*)(malloc(sizeof(t_spr) * num))) == NULL)
		file_exit(2);
	data->spr_name = data->set->s_texture;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (map[j][i] == '2')
			{
				data->spr[num].flag = 0;
				data->spr[num].new_y = j * 64 + 32;
				data->spr[num].y = j;
				data->spr[num].new_x = i * 64 + 32;
				data->spr[num].x = i;
				data->spr[num].init_angle = -1;
				data->spr[num].dist = 0;
				num++;
			}
		}
	}
	printf("inside init_sprites\n");
}
