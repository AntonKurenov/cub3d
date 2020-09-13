/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vertical.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 15:10:50 by elovegoo          #+#    #+#             */
/*   Updated: 2020/09/13 20:56:12 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void get_vert_len(t_data *data, int flag)
{
	double len_x;
	double len_y;

	printf("a_x inside get_vert_len = %f\n", data->vert_x);
	printf("a_x inside get_vert_len = %f\n", data->vert_y);
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

static int check_grid(t_data *data, double v_x, double v_y)
{
	int x;
	int y;
	double new_x;
	double new_y;

	new_x = data->vert_x + v_x;
	new_y = data->vert_y + v_y;
	if (new_x > 0 && new_y > 0)
	{
		x = (int)(round(new_x) / 64);
		y = (int)(round(new_y) / 64);
		if (x < data->map_w && y < data->map_h)
		{
			if (data->map[y][x] == '0')
			{
				data->vert_x += v_x;
				data->vert_y += v_y;
				return (0);
			}
			else
				return (1);
		}
		return (-1);
	}
	return (-1);
}

static void check_vert_map(t_data *data)
{
	int x;
	int y;
	int ret;

	data->v_a_x = (data->flag == 1 || data->flag == 4) ? B_SIZE: -B_SIZE;
	data->v_a_y = (data->flag == 3 || data->flag == 4) ? B_SIZE * data->tang : -(B_SIZE * data->tang);
	/*ret = check_grid(data, data->h_a_x, data->h_a_y);*/
	/*if (ret == 1 || ret == -1)*/
		/*get_vert_len(data, data->flag);*/
	printf("Check vert map before while\ndata->vert_x = %f\ndata->vert_y = %f\n", data->vert_x, data->vert_y);
	printf("|_________|\n");
	while ((ret = check_grid(data, data->v_a_x, data->v_a_y)) != -1)
	{
		if (ret == 1)
			break ;
		printf("check_vert_map\nx = %d  y = %d\n", x, y);
	}
	printf("|_________|\n");
	printf("data->vert_x = %f\ndata->vert_y = %f\n", data->vert_x, data->vert_y);
	get_vert_len(data, data->flag);
}

void get_vert_inter(t_data *data, int flag)
{
	double a_x;
	double a_y;
	int		x;
	int		y;
	int		ret;

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
	printf("1 vert: a_x = %f || a_y = %f\n", a_x, a_y);
	data->vert_x = a_x;
	data->vert_y = a_y;
	ret = check_grid(data, 0, 0);
	if (ret == 1 || ret == -1)
		get_vert_len(data, data->flag);
	check_vert_map(data);
}
