/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 17:26:11 by elovegoo          #+#    #+#             */
/*   Updated: 2020/09/01 19:31:44 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

typedef struct s_range
{

}	t_range;

double get_vert_inter(int x, int y)
{

	return (0);
}

double get_horiz_inter(int x, int y)
{

	return (0);
}


double get_len(double angle, t_data *data, int i, int flag)
{
	int a_x;
	int a_y;
	int a_y_grid;
	double x_a;
	double y_a;
	double len;

	/*Finding horizontal intersection*/
	if (flag == 1 || flag == 2)
	{
		a_y = (data->x >> 6) * 64 - 1;
		a_y_grid = a_y >> 6;
	}

}

double receiver(t_data *data)
{
	int i;
	int x;
	int y;
	int near_x;
	int near_y;
	double angle;
	double curr_angle;
	double init_angle;
	int flag;

	data->player->x = data->player->x * 64 + 32;
	data->player->y = data->player->y * 64 + 32;
	x = data->player->x;
	y = data->player->y;
	near_y = (x >> 6) * 64;
	i = 0;
	init_angle = data->angle - H_FOV;
	while (i < data->set->res_w)
	{
		init_angle = (data->angle - H_FOV) + i * data->part_angle;
		if (init_angle >= 0 && init_angle < 90)
		{
			angle = init_angle;
			get_len(angle, data, i, 1);
		}
		if (init_angle >= 90 && init_angle < 180)
		{
			angle = 180 - init_angle;
			get_len(angle, data, i, 2);
		}
		if (init_angle >= 180 && init_angle < 270)
		{
			angle = init_angle - 180;
			get_len(angle, data, i, 3);
		}
		if (init_angle >= 270 && init_angle <= 360)
		{
			angle = 360 - init_angle;
			get_len(angle, data, i, 4);
		}
		i++;
	}
	return (0);

}
