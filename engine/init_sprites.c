/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 12:11:05 by elovegoo          #+#    #+#             */
/*   Updated: 2020/10/01 18:39:44 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_sprites(t_data *data, int x, int y)
{
	int i;
	double angle;
	int diff_x;
	int diff_y;

	i = -1;
	angle = data->cur_angle;
	printf("check_sprites x = %d  y = %d\n", x, y);
	while (++i < data->num_spr)
	{
		if (data->spr[i].x == x && data->spr[i].y == y)
		{
			printf("\ncheck sprites inside if\n");
			if (data->spr[i].flag == 0)
			{
				printf("data->spr[%d].flag = %d\n", i, data->spr[i].flag);
				data->spr[i].flag = get_flag(data->pos_x, data->pos_y,\
				data->spr[i].new_x, data->spr[i].new_y);
				diff_x = get_diff(data->pos_x, data->spr[i].new_x);
				diff_y = get_diff(data->pos_y, data->spr[i].new_y);
				data->spr[i].dist = sqrt(diff_x * diff_x + diff_y * diff_y);
				data->spr[i].height = (data->plane_dist / data->spr[i].dist);
				data->spr[i].angle = (atan((double)diff_y / (double)diff_x)) *\
									 INV_RAD;
				data->spr[i].half_height = data->spr[i].height * 0.5;
				printf("check_sprites i = %d\n", i);
				printf("spr_angle = %f\n", data->spr[i].angle);
				printf("spr_height = %f\n", data->spr[i].height);
				get_sprt_angle(data, &data->spr[i], data->spr[i].angle, data->spr[i]. \
					height);
				return ;
			}
			if (data->spr[i].flag == 1)
			{
				printf("data->spr[%d].flag = %d\n", i, data->spr[i].flag);
				return ;
			}
		}
	}
	printf("inside check_sprites\n");
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
	num = 0;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (map[j][i] == '2')
			{
				data->spr[num].diff_start = 0;
				data->spr[num].diff_end = 0;
				data->spr[num].flag = 0;
				data->spr[num].new_y = j * B_SIZE + 32;
				data->spr[num].y = j;
				data->spr[num].new_x = i * B_SIZE + 32;
				data->spr[num].x = i;
				data->spr[num].init_angle = -1;
				data->spr[num].dist = -1;
				printf("spr[%d] >> x = %d  y = %d\n", num, data->spr[num].x, \
						data->spr[num].y);
				num++;
			}
		}
	}
	printf("inside init_sprites    num = %d\n", num);
}
