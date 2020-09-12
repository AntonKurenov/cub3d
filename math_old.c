/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 17:26:11 by elovegoo          #+#    #+#             */
/*   Updated: 2020/09/11 15:13:08 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double get_len(t_data *data, int flag)
{
	double len_x;
	double len_y;
	double len;

	printf("a_x inside get_len = %f\n", data->inter.);
	printf("a_y = %f\n", a_y);
	if (flag == 1)
	{
		len_x = a_x - data->pos_x;
		len_y = data->pos_y - a_y;
	}
	if (flag == 2)
	{
		len_x = data->pos_x - a_x;
		len_y = data->pos_y - a_y;
	}
	if (flag == 3)
	{
		len_x = data->pos_x - a_x;
		len_y = a_y - data->pos_y;
	}
	if (flag == 4)
	{
		len_x = a_x - data->pos_x;
		len_y = a_y - data->pos_y;
	}
	len = sqrt(len_x * len_x + len_y * len_y);	
	return (len);
}

int check_map(t_data *data, int y, int x)
{
	if (x > data->map_w || y > data->map_h || x < 0 || y < 0)
		return (-1);
	if (data->map[y][x] == '1')
		return (1);
	if (data->map[y][x] == '0')
		return (0);
}

int check_grid(t_data *data, int flag)
{
	int grid_x;
	int grid_y;
	int fl_grid_x;
	int fl_grid_y;
	int ret;

	if (flag == 1)
	{
		grid_x = data->inter.hor_grid_x;
		grid_y = data->inter.hor_grid_y;
		data->map_chk_ret = check_map(data, grid_x, grid_y);
	}
	if (flag == 2)
	{
		grid_x = data->inter.vert_grid_x;
		grid_y = data->inter.vert_grid_y;
		data->map_chk_ret = check_map(data, grid_x, grid_y);
	}
	if (flag == 3)
	{
		grid_x = (((int)(ceil(data->inter.cur_hor_x)) >> 6));
		grid_y = (((int)(ceil(data->inter.cur_hor_y)) >> 6));
		if ((ret = check_map(data, grid_x, grid_y)) == 1)
			return (ret);
		if (ret == 0)	
			return (0);
		if (ret == -1)
			return (-1);
		grid_x = (((int)(floor(data->inter.cur_hor_x)) >> 6));
		grid_y = (((int)(floor(data->inter.cur_hor_y)) >> 6));
		if ((ret = check_map(data, grid_x, grid_y)) == 1)
			return (ret);
		if (ret == 0)	
			return (0);
		if (ret == -1)
			return (-1);
	}
	if (flag == 4)
	{
		grid_x = (((int)(ceil(data->inter.cur_hor_x)) >> 6));
		grid_y = (((int)(ceil(data->inter.cur_hor_y)) >> 6));
		if ((ret = check_map(data, grid_x, grid_y)) == 1)
			return (ret);
		if (ret == 0)	
			return (0);
		if (ret == -1)
			return (-1);
		grid_x = (((int)(floor(data->inter.cur_hor_x)) >> 6));
		grid_y = (((int)(floor(data->inter.cur_hor_y)) >> 6));
		if ((ret = check_map(data, grid_x, grid_y)) == 1)
			return (ret);
		if (ret == 0)	
			return (0);
		if (ret == -1)
			return (-1);
	}
	return (data->map_chk_ret);
}

/*
 * Flag = 1 is for horizontal, 2 for vertical intersections.
 * flag 3 is for continue horizontal 
 * flag 4 is fot continue vertical
*/
int convert_coordinates(t_data *data, int flag)
{
	if (flag == 1)
	{
		data->inter.hor_grid_x = ((int)(ceil(data->inter.cur_hor_x)) >> 6);
		data->inter.hor_grid_y = ((int)(ceil(data->inter.cur_hor_y)) >> 6);
		if (check_grid(data, flag) == 1)
			return (1);
		data->inter.hor_grid_x = ((int)(floor(data->inter.cur_hor_x)) >> 6);
		data->inter.hor_grid_y = ((int)(floor(data->inter.cur_hor_y)) >> 6);
		if (check_grid(data, flag) == 1)
			return (1);
		return (0);
	}
	if (flag == 2)
	{
		data->inter.vert_grid_x = (((int)(ceil(data->inter.cur_vert_x))) >> 6);
		data->inter.vert_grid_y = (((int)(ceil(data->inter.cur_vert_y))) >> 6);
		if (check_grid(data, flag) == 1)
			return (1);
		data->inter.vert_grid_x = (((int)(floor(data->inter.cur_vert_x))) >> 6);
		data->inter.vert_grid_y = (((int)(floor(data->inter.cur_vert_y))) >> 6);
		if (check_grid(data, flag) == 1)
			return (1);
		return (0);
	}

	if (flag == 3)
	{
		while (check_grid(data, flag) != -1)
		{
			data->inter.cur_hor_x += data->inter.h_a_x;
			data->inter.cur_hor_y += data->inter.h_a_y;
			if (check_grid(data, flag) == 1)
				return (1);
		}
	}
	if (flag == 4)
	{
		while (check_grid(data, flag) != -1)
		{
			data->inter.cur_vert_x += data->inter.v_a_x;
			data->inter.cur_vert_y += data->inter.v_a_y;
			if (check_grid(data, flag) == 1)
				return (1);
		}
	}
	if (check_grid(data, flag) == 1)
		return (1);
	return (-1);
}

double get_vert_inter(t_data *data, int flag)
{
	double len;
	double a_x;
	double a_y;
	int a_x_grid;
	int a_y_grid;
	double x_a;
	double y_a;
	double init_a_x;

	init_a_x = (floor(data->pos_x / B_SIZE)) * B_SIZE;
	a_x = (flag == 1 || flag == 4) ? (init_a_x + B_SIZE) : (init_a_x - 1);
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
	if (convert_coordinates(data, 2) == 1)
		return (get_len(data, flag));
	printf("1 vert: a_x = %f || a_y = %f\n", a_x, a_y);
	printf("1 vert: a_x_grid = %d || a_y_grid = %d\n", a_x_grid, a_y_grid);

	x_a = (flag == 1 || flag == 4) ? B_SIZE: -B_SIZE;
	y_a = (flag == 3 || flag == 4) ? B_SIZE * data->tang : -(B_SIZE * data->tang);
	while (check_grid(data, a_x_grid, a_y_grid) != -1)
	{
		a_x += x_a;
		a_y += y_a;
		a_x_grid = round(a_x / B_SIZE);
		a_y_grid = round(a_y / B_SIZE);
		printf("2 vert: a_x = %f || a_y = %f\n", a_x, a_y);
		printf("2 vert: a_x_grid = %d || a_y_grid = %d\n", a_x_grid, a_y_grid);
		if (check_grid(data, a_x_grid, a_y_grid) == 1)
			return (get_len(data, a_x, a_y, flag));
	}
	return (get_len(data, a_x, a_y, flag));
}

double get_horiz_inter(t_data *data, int flag)
{
	double len;
	double a_x;
	double a_y;
	int a_x_grid;
	int a_y_grid;
	double x_a;
	double y_a;
	double init_a_y;

	init_a_y = (floor(data->pos_y / B_SIZE));
	a_y = (flag == 3 || flag == 4) ? (init_a_y + B_SIZE) : (init_a_y - 1);
	printf("flag = %d\n", flag);
	if (flag == 1)
		a_x = data->pos_x + (data->pos_y - a_y) / data->tang;
	if (flag == 2)
		a_x = data->pos_x - (data->pos_y - a_y) / data->tang;
	if (flag == 3)
		a_x = data->pos_x - (data->pos_y + a_y) / data->tang;
	if (flag == 4)
		a_x = data->pos_x + (data->pos_y + a_y) / data->tang;
	data->inter.hor_x = a_x;
	data->inter.hor_y = a_y;
	printf("1 horiz: a_x = %f || a_y = %f\n", a_x, a_y);
	printf("1 horiz: a_x_grid = %d || a_y_grid = %d\n", a_x_grid, a_y_grid);
	if (convert_coordinates(data, 2) == 1)
		return (get_len(data, flag));

	data->inter.h_a_x = (flag == 1 || flag == 4) ? B_SIZE / data->tang : -(B_SIZE / data->tang);
	data->inter.h_a_y = (flag == 1 || flag == 2) ? -B_SIZE : B_SIZE;
	while (check_grid(data, a_x_grid, a_y_grid) != -1)
	{
		a_x += x_a;
		a_y += y_a;
		a_x_grid = floor(a_x / B_SIZE);
		a_y_grid = floor(a_y / B_SIZE);
		printf("2 horiz: a_x = %f || a_y = %f\n", a_x, a_y);
		printf("2 horiz: a_x_grid = %d || a_y_grid = %d\n", a_x_grid, a_y_grid);
		if (check_grid(data, a_x_grid, a_y_grid) == 1)
			return (get_len(data, a_x, a_y, flag));
	}
	return (get_len(data, a_x, a_y, flag));
}

void len_compare(double angle, t_data *data, int i, int flag)
{
	int j;
	double len_horiz;
	double len_vert;

	len_horiz = get_horiz_inter(data, flag);
	len_vert = get_vert_inter(data, flag);
	printf("len_vert = %f\nlen_horiz = %f\n", len_vert, len_horiz);
	if (len_horiz >= len_vert)
		draw_walls(data, len_vert);
	else
		draw_walls(data, len_horiz);
}

void receiver(t_data *data)
{
	int i;
	double angle;
	double init_angle;
	double start_angle;

	/*i = 0;*/
	i = 40;
	start_angle = (double)((data->angle + H_FOV));
	while (i < 70)
	/*while (i < data->res_w)*/
	{
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
