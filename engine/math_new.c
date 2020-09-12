/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 17:26:11 by elovegoo          #+#    #+#             */
/*   Updated: 2020/09/12 20:03:01 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void get_vert_len(t_data *data, int flag)
{
	double len_x;
	double len_y;

	printf("a_x inside get_len = %f\n", data->inter.hor_x);
	if (flag == 1)
	{
		len_x = data->vert_x - data->pos_x;
		len_y = data->pos_y - data->vert_y;
	}
	if (flag == 2)
	{
		len_x = data->pos_x - data->vert_x;
		len_y = data->pos_y - data->vert_y;
	}
	if (flag == 3)
	{
		len_x = data->pos_x - data->vert_x;
		len_y = data->vert_y - data->pos_y;
	}
	if (flag == 4)
	{
		len_x = data->vert_x - data->pos_x;
		len_y = data->vert_y - data->pos_y;
	}
	data->vert_len = sqrt(len_x * len_x + len_y * len_y);	
}

void get_hor_len(t_data *data, int flag)
{
	double len_x;
	double len_y;

	printf("a_x inside get_len = %f\n", data->hor_x);
	if (flag == 1)
	{
		len_x = data->hor_x - data->pos_x;
		len_y = data->pos_y - data->hor_y;
	}
	if (flag == 2)
	{
		len_x = data->pos_x - data->hor_x;
		len_y = data->pos_y - data->hor_y;
	}
	if (flag == 3)
	{
		len_x = data->pos_x - data->hor_x;
		len_y = data->hor_y - data->pos_y;
	}
	if (flag == 4)
	{
		len_x = data->hor_x - data->pos_x;
		len_y = data->hor_y - data->pos_y;
	}
	data->hor_len = sqrt(len_x * len_x + len_y * len_y);	
}

int check_map(t_data *data, int y, int x)
{
	if (x > data->map_w || y > data->map_h || x < 0 || y < 0)
		return (-1);
	printf("check map\ni = %d\ny = %d\nx = %d\n", data->i, y, x);
	if (data->map[y][x] == '1')
		return (1);
	if (data->map[y][x] == '0')
		return (0);
	return (0);
}

void check_vert_map(t_data *data, int flag)
{
	int x;
	int y;

	x = (((int)(round(data->vert_x)) >> 6));
	y = (((int)(round(data->vert_y)) >> 6));
	if (x < 0 || y < 0 || x > data->map_w || y > data->map_h || \
			data->map[y][x] == '1')
		get_vert_len(data, data->flag);
	data->v_a_x = (flag == 1 || flag == 4) ? B_SIZE: -B_SIZE;
	data->v_a_y = (flag == 3 || flag == 4) ? B_SIZE * data->tang : -(B_SIZE * data->tang);
	data->vert_x = (flag == 1) ? (data->vert_x + data->v_a_x) : (data->vert_x);
	data->vert_y = (flag == 1) ? (data->vert_y + data->v_a_y) : (data->vert_y);
	while (x > 0 && y > 0 && x < data->map_w && y < data->map_h && \
			data->map[y][x] != '1' && flag == 1)
	{
		data->vert_x += data->v_a_x;
		data->vert_y += data->v_a_y;
		x = (((int)(round(data->vert_x)) >> 6));
		y = (((int)(round(data->vert_y)) >> 6));
	}
	get_vert_len(data, data->flag);
}

void check_horiz_map(t_data *data, int flag)
{
	int x;
	int y;

	x = (((int)(round(data->hor_x)) >> 6));
	y = (((int)(round(data->hor_y)) >> 6));
	if (x < 0 || y < 0 || x > data->map_w || y > data->map_h || \
			data->map[y][x] == '1')
		get_hor_len(data, data->flag);
	data->h_a_x = (flag == 1 || flag == 4) ? B_SIZE / data->tang : -(B_SIZE / data->tang);
	data->h_a_y = (flag == 1 || flag == 2) ? -B_SIZE : B_SIZE;
	data->hor_x = (flag == 1) ? (data->hor_x + data->h_a_x) : (data->hor_x);
	data->hor_y = (flag == 1) ? (data->hor_y + data->h_a_y) : (data->hor_y);
	while (x > 0 && y > 0 && x < data->map_w && y < data->map_h && \
			data->map[y][x] != '1' && flag == 1)
	{
		data->hor_x += data->h_a_x;
		data->hor_y += data->h_a_y;
		x = (((int)(round(data->hor_x)) >> 6));
		y = (((int)(round(data->hor_y)) >> 6));
	}
	get_hor_len(data, data->flag);
}

void get_vert_inter(t_data *data, int flag)
{
	double a_x;
	double a_y;
	double init_a_x;
	int ret;

	a_x = (flag == 1 || flag == 4) ? (data->init_a_x + B_SIZE) : (data->init_a_x - 1);
	printf("data->tang = %f\n", data->tang);
	if (flag == 1)
		a_y = data->pos_y - (a_x - data->pos_x) * data->tang;
	if (flag == 2)
		a_y = data->pos_y - (data->pos_x - a_x) * data->tang;
	if (flag == 3)
		a_y = data->pos_y + (data->pos_x - a_x) * data->tang;
	if (flag == 4)
		a_y = data->pos_y + (a_x - data->pos_x ) * data->tang;
	data->inter.vert_x = a_x;
	data->inter.vert_y = a_y;
	printf("1 vert: a_x = %f || a_y = %f\n", a_x, a_y);
}

void get_horiz_inter(t_data *data, int flag)
{
	double a_x;
	double a_y;
	double init_a_y;
	int ret;

	a_y = (flag == 3 || flag == 4) ? (data->init_a_y + B_SIZE) : (data->init_a_y - 1);
	printf("flag = %d\n", flag);
	if (flag == 1)
		a_x = data->pos_x + (data->pos_y - a_y) / data->tang;
	if (flag == 2)
		a_x = data->pos_x - (data->pos_y - a_y) / data->tang;
	if (flag == 3)
		a_x = data->pos_x - (data->pos_y + a_y) / data->tang;
	if (flag == 4)
		a_x = data->pos_x + (data->pos_y + a_y) / data->tang;
	data->hor_x = a_x;
	data->hor_y = a_y;
	check_horiz_map(data, 0);
	printf("1 horiz: a_x = %f || a_y = %f\n", a_x, a_y);
}

void len_compare(double angle, t_data *data, int i, int flag)
{
	int j;
	double len_horiz;
	double len_vert;

	data->flag = flag;
	get_horiz_inter(data, flag);
	get_vert_inter(data, flag);
	printf("len_vert = %f\nlen_horiz = %f\n", len_vert, len_horiz);
	if (data->hor_len >= data->vert_len)
		draw_walls(data, data->vert_len);
	else
		draw_walls(data, data->hor_len);
}

void receiver(t_data *data)
{
	int i;
	double angle;
	double init_angle;
	double start_angle;

	printf("pos_x = %f\npos_y = %f\n", data->pos_x, data->pos_y);
	i = 0;
	i = 80;
	start_angle = (double)((data->angle + H_FOV));
	data->init_a_x = (floor(data->pos_x / B_SIZE)) * B_SIZE;
	data->init_a_y = (floor(data->pos_y / B_SIZE)) * B_SIZE;
	printf("pos_x = %f\npos_y = %f\n", data->pos_x, data->pos_y);
	printf("data->init_a_x = %f\ndata->init_a_y = %f\n", data->init_a_x, data->init_a_y);
	while (i < 90)
	/*while (i < data->res_w)*/
	{
		printf("_____________________________________\n");
		/*reset_data(data);*/
		data->i = i;
		init_angle = start_angle - ((double)i) * data->part_angle;
		printf("i = %d\n", i);
		printf("init_angle = %f\n", init_angle);
		if (init_angle >= 0 && init_angle < 90)
		{
			angle = init_angle;
			data->tang = tan(angle * RAD_CONV);
			len_compare(angle, data, i, 1);	
		}
		if (init_angle >= 90 && init_angle < 180)
		{
			angle = 180 - init_angle;
			data->tang = tan(angle * RAD_CONV);
			len_compare(angle, data, i, 2);	
		}
		if (init_angle >= 180 && init_angle < 270)
		{
			angle = init_angle - 180;
			data->tang = tan(angle * RAD_CONV);
			len_compare(angle, data, i, 3);	
		}
		if (init_angle >= 270 && init_angle <= 360)
		{
			angle = 360 - init_angle;
			data->tang = tan(angle * RAD_CONV);
			len_compare(angle, data, i, 4);	
		}
		i++;
	}
}
