/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_vertical.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 15:10:50 by elovegoo          #+#    #+#             */
/*   Updated: 2020/10/03 11:26:38 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void get_vert_len(t_data *data, int flag)
{
	double len_x;
	double len_y;

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

static void vert_check(t_data *data)
{
	int ret;

	ret = 0;
	data->v_a_x = (data->flag == 1 || data->flag == 4) ? B_SIZE: -B_SIZE;
	data->v_a_y = (data->flag == 3 || data->flag == 4) ? B_SIZE * data->tang :\
				  -(B_SIZE * data->tang);
	while ((ret = check_map_for_inter(data, data->vert_x, data->vert_y)) == 0)
	{
		if (ret == 1)
			break ;
		if (ret == -1)
			break ;
		/*check_map_for_sprt(data, data->new_x, data->new_y);*/
		data->vert_x = ((data->vert_x + data->v_a_x) > 0) ?\
					   (data->vert_x += data->v_a_x) : 0;
		data->vert_y = ((data->vert_y + data->v_a_y) > 0) ?\
					   (data->vert_y += data->v_a_y) : 0;
	}
	get_vert_len(data, data->flag);
}

void get_vert_inter(t_data *data, int flag)
{
	double a_x;
	double a_y;
	int		x;
	int		y;
	int		ret;

	data->vert_flag = 1;
	a_x = (flag == 1 || flag == 4) ? (data->init_a_x + B_SIZE) :\
		  (data->init_a_x - 1);
	/*printf("data->tang = %f\n", data->tang);*/
	if (flag == 1)
		a_y = data->pos_y - (a_x - data->pos_x) * data->tang;
	if (flag == 2)
		a_y = data->pos_y - (data->pos_x - a_x) * data->tang;
	if (flag == 3)
		a_y = data->pos_y + (data->pos_x - a_x) * data->tang;
	if (flag == 4)
		a_y = data->pos_y + (a_x - data->pos_x ) * data->tang;
	/*printf("1 vert: a_x = %f || a_y = %f\n", a_x, a_y);*/
	data->vert_x = a_x;
	data->vert_y = a_y;
	ret = check_map(data, a_x, a_y);
	if (ret == 1 || ret == -1)
		get_vert_len(data, data->flag);
	vert_check(data);
}
