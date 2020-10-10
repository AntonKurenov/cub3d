/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 15:10:53 by elovegoo          #+#    #+#             */
/*   Updated: 2020/10/10 16:31:31 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void check_position(t_data *data, double new_x, double new_y)
{
	double x;
	double x_s;
	double y_s;
	double y;
	int ret;

	x = new_x * 3;
	y = new_y * 3;
	ret = check_map(data, data->pos_x + x, data->pos_y + y);
	if (ret == 0)
	{
		data->pos_x += new_x;
		data->pos_y += new_y;
		return ;
	}
}

void move_s_and_w(t_data *data, t_angle *ang)
{
	double new_x;
	double new_y;

	convert_angle(ang);
	/*printf("data->angle = %d\nangle = %d\n", data->angle, ang->new_angle);*/
	if (ang->key == BUTTON_W)
	{
		new_x = ((data->angle >= 0 && data->angle < 90) || \
		(data->angle >= 270 && data->angle <= 360)) ? ang->new_x : -ang->new_x;
		new_y = (data->angle >= 0 && data->angle <= 180) ? -ang->new_y :\
				ang->new_y;
		check_position(data, new_x, new_y);	
		return ;
	}
	if (ang->key == BUTTON_S)
	{
		new_x = ((data->angle >= 0 && data->angle <= 90) || \
		(data->angle >= 270 && data->angle <= 360)) ? -ang->new_x : ang->new_x;
		new_y = (data->angle >= 0 && data->angle <= 180) ? ang->new_y :\
				-ang->new_y;
		check_position(data, new_x, new_y);
		return ;
	}
}

void move_d_and_a(t_data *data, t_angle *ang)
{
	double new_x;
	double new_y;

	convert_angle(ang);
	/*printf("init_angle = %d\n", ang->init_angle);*/
	/*printf("angle d_and_a = %d\n", ang->new_angle);*/
	if (ang->key == BUTTON_D)
	{
		new_x = (ang->init_angle >= 0 && ang->init_angle < 180) \
				? ang->new_x : -ang->new_x;
		new_y = ((ang->init_angle >= 0 && ang->init_angle <= 90) ||\
		(ang->init_angle >= 270 && ang->init_angle <= 360)) ?\
				ang->new_y : -ang->new_y;
		check_position(data, new_x, new_y);	
		return ;
	}
	if (ang->key == BUTTON_A)
	{
		new_x = (ang->init_angle > 180 && ang->init_angle <= 360) ?\
				ang->new_x : -ang->new_x;
		new_y = (ang->init_angle >= 90 && ang->init_angle <= 270) ? ang->new_y\
				: -ang->new_y;
		check_position(data, new_x, new_y);
		return ;
	}
}

void turn_left(t_data *data)
{
	if ((data->angle + TURN_ANG) < 360)
	{
		data->angle += TURN_ANG;
		return ;
	}
	else if ((data->angle + TURN_ANG) > 360)
		data->angle = 0;
	data->angle += TURN_ANG;
}

void turn_right(t_data *data)
{
	if ((data->angle - TURN_ANG) > 0)
	{
		data->angle -= TURN_ANG;
		return ;
	}
	else if ((data->angle - TURN_ANG) < 0)
	{
		data->angle = 359;
	}
	data->angle -= TURN_ANG;
}
