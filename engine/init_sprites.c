/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 12:11:05 by elovegoo          #+#    #+#             */
/*   Updated: 2020/10/12 14:15:36 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_sprites(t_data *data, t_spr *spr)
{
	int diff_x;
	int diff_y;

	if (spr->dist == -1)
	{
		data->spr_in_view++;
		spr->flag = get_flag(data->pos_x, data->pos_y, spr->new_x, spr->new_y);
		diff_x = get_diff(data->pos_x, spr->new_x);
		diff_y = get_diff(data->pos_y, spr->new_y);
		spr->dist = sqrt(diff_x * diff_x + diff_y * diff_y) * 0.95;
		spr->height = (data->plane_dist / spr->dist);
		spr->angle = (atan((double)diff_y / (double)diff_x)) * INV_RAD;
		spr->half_height = spr->height * 0.5;
		get_sprt_angle(data, spr, spr->angle, spr->half_height);
	}
}

void	init_sprites(t_data *data, char **map)
{
	int i;
	int j;

	j = -1;
	if (!(data->spr = (t_spr**)(malloc(sizeof(t_spr*) * data->matr_size))))
		file_exit(2);
	while (map[++j] && (i = -1))
	{
		if (!(data->spr[j] = (t_spr*)(malloc(sizeof(t_spr) * data->act_map_w))))
			file_exit(2);
		while (map[j][++i])
		{
			reset_sprite(data, &data->spr[j][i]);
			if (map[j][i] == '2')
			{
				data->spr[j][i].new_y = j * B_SIZE + 32;
				data->spr[j][i].y = j;
				data->spr[j][i].new_x = i * B_SIZE + 32;
				data->spr[j][i].x = i;
			}
		}
	}
}
