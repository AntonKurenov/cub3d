/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_horizontal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 15:05:58 by elovegoo          #+#    #+#             */
/*   Updated: 2020/09/13 20:56:12 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void get_hor_len(t_data *data, int flag)
{
	double len_x;
	double len_y;

	printf("a_x inside get_hor_len = %f\n", data->hor_x);
	printf("a_y inside get_hor_len = %f\n", data->hor_y);
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

static int check_grid(t_data *data, double h_x, double h_y)
{
	int x;
	int y;
	double new_x;
	double new_y;

	new_x = data->hor_x + h_x;
	new_y = data->hor_y + h_y;
	if (new_x > 0 && new_y > 0)
	{
		x = (int)(round(new_x) / 64);
		y = (int)(round(new_y) / 64);
		if (x < data->map_w && y < data->map_h)
		{
			if (data->map[y][x] == '0')
			{
				data->hor_x += h_x;
				data->hor_y += h_y;
				return (0);
			}
			else
				return (1);
		}
		return (-1);
	}
	return (-1);
}

static void check_horiz_map(t_data *data)
{
	int x;
	int y;
	int ret;

	x = 1;
	y = 1;
	data->h_a_y = (data->flag == 1 || data->flag == 2) ? -B_SIZE : B_SIZE;
	data->h_a_x = (data->flag == 1 || data->flag == 4) ? B_SIZE / data->tang : -(B_SIZE / data->tang);
	/*ret = check_grid(data, data->h_a_x, data->h_a_y);*/
	/*if (ret == 1 || ret == -1)*/
		/*get_hor_len(data, data->flag);*/
	printf("Check horiz map before while\ndata->hor_x = %f\ndata->hor_y = %f\n", data->hor_x, data->hor_y);
	printf("|_________|\n");
	while ((ret = check_grid(data, data->h_a_x, data->h_a_y)) != -1)
	{
		if (ret == 1)
			break ;
	}
	printf("|_________|\n");
	printf("data->hor_x = %f\ndata->hor_y = %f\n", data->hor_x, data->hor_y);
	get_hor_len(data, data->flag);
}

void get_horiz_inter(t_data *data, int flag)
{
	double a_x;
	double a_y;
	int		x;
	int		y;
	int		ret;

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
	printf("1 horiz: a_x = %f || a_y = %f\n", a_x, a_y);
	ret = check_grid(data, 0, 0);
	if (ret == 1 || ret == -1)
		get_hor_len(data, data->flag);
	check_horiz_map(data);
}
