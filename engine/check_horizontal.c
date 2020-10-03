/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_horizontal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 15:05:58 by elovegoo          #+#    #+#             */
/*   Updated: 2020/10/03 11:26:38 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void get_hor_len(t_data *data, int flag)
{
	double len_x;
	double len_y;

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

static void horiz_check(t_data *data)
{
	int ret;

	ret = 0;
	data->h_a_y = (data->flag == 1 || data->flag == 2) ? -B_SIZE : B_SIZE;
	data->h_a_x = (data->flag == 1 || data->flag == 4) ? B_SIZE / data->tang :\
				  -(B_SIZE / data->tang);
	while ((ret = check_map_for_inter(data, data->hor_x, data->hor_y)) == 0)
	{
		/*printf("ret = %d\n", ret);*/
		if (ret == 1)
			break ;
		if (ret == -1)
			break ;
		/*check_map_for_sprt(data, data->new_x, data->new_y);*/
		data->hor_x = ((data->hor_x + data->h_a_x) > 0) ?\
					  (data->hor_x += data->h_a_x) : 0;
		data->hor_y = ((data->hor_y + data->h_a_y) > 0) ?\
					  (data->hor_y += data->h_a_y) : 0;
	}
	get_hor_len(data, data->flag);
}

void get_horiz_inter(t_data *data, int flag)
{
	double a_x;
	double a_y;
	int		x;
	int		y;
	int		ret;

	data->vert_flag = 0;
	a_y = (flag == 3 || flag == 4) ? (data->init_a_y + B_SIZE) :\
		  (data->init_a_y - 1);
	if (flag == 1)
		a_x = data->pos_x + (data->pos_y - a_y) / data->tang;
	if (flag == 2)
		a_x = data->pos_x - (data->pos_y - a_y) / data->tang;
	if (flag == 3)
		a_x = data->pos_x - (a_y - data->pos_y) / data->tang;
	if (flag == 4)
		a_x = data->pos_x + (a_y - data->pos_y) / data->tang;
	data->hor_x = a_x;
	data->hor_y = a_y;
	ret = check_map(data, a_x, a_y);
	if (ret == 1 || ret == -1)
		get_hor_len(data, data->flag);
	horiz_check(data);
}
