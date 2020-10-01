/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 12:02:22 by elovegoo          #+#    #+#             */
/*   Updated: 2020/10/01 10:57:41 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void check_map_for_sprt(t_data *data, int x, int y)
{
	if (x < 0 || y < 0)
		return ;
	if (data->map[y][x] == '2')
		check_sprites(data, x, y);
}

int check_map_for_inter(t_data *data, double x, double y)
{
	int flag;
	/*int new_x;*/
	/*int new_y;*/

	if (x < 0 || y < 0)
		return (-1);
	flag = data->vert_flag;
	if ((!flag || data->cur_angle > 180) && !(data->cur_angle > 90 && \
		data->cur_angle < 270 && !flag))
	{
		data->new_x = ((int)floor(x) >> 6);
		data->new_y = ((int)floor(y) >> 6);
	}
	else
	{
		data->new_x = ((int)ceil(x) >> 6);
		data->new_y = ((int)ceil(y) >> 6);
	}
	if (data->new_x > data->map_w || data->new_y > data->map_h ||\
			data->new_x < 0 || data->new_y < 0)
		return (-1);
	if (data->map[data->new_y][data->new_x] == 49)
		return (1);
	if (data->new_x == 0 || data->new_y == 0)
		return (1);
	return (0);
}

int check_map(t_data *data, double x, double y)
{
	int new_x;
	int new_y;

	if (x < 0 || y < 0)
		return (-1);
	new_x = (int)(floor(x / 64));
	new_y = (int)(floor(y / 64));
	if (new_x > data->map_w || new_y > data->map_h || new_x < 0 || new_y < 0)
		return (-1);
	if (data->map[new_y][new_x] == 49)
	{
		return (1);
	}
	return (0);
}
