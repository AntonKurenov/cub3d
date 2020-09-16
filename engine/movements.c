/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 15:10:53 by elovegoo          #+#    #+#             */
/*   Updated: 2020/09/16 20:11:55 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void close_win(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
}

void move_up(t_data *data)
{
	if (data->pos_y > 0)
		data->pos_y -= 5;
}

void turn_left(t_data *data)
{
	if ((data->angle + 5) < 360)
	{
		data->angle += 5;
		return ;
	}
	else if ((data->angle + 5) > 360)
	{
		data->angle = 0;
	}
	data->angle += 5;
}

void move_down(t_data *data)
{
	if (data->pos_y < data->map_h * 64)
		data->pos_y += 5;
}

void turn_right(t_data *data)
{
	if ((data->angle - 5) > 0)
	{
		data->angle -= 5;
		return ;
	}
	else if ((data->angle - 5) < 0)
	{
		data->angle = 359;
	}
	data->angle -= 5;
}
	
