/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textr_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 15:23:00 by elovegoo          #+#    #+#             */
/*   Updated: 2020/10/08 16:46:28 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	get_percent(t_data *data, double len)
{
	double x;
	double y;
	int	part_len;
	double percent;

	x = (data->is_vert == 1) ? data->vert_x : data->hor_x;
	y = (data->is_vert == 1) ? data->vert_y : data->hor_y;
	if (data->is_vert == 0)
		percent = (x - (floor(x / B_SIZE) * B_SIZE)) / B_SIZE;
	if (data->is_vert == 1)
		percent = (y - (floor(y / B_SIZE) * B_SIZE)) / B_SIZE;
	return (percent);
}

void	put_texture(int *t_addr, int t, t_data *data, double len)
{
	t_print tx;

	tx.wall_len = (data->plane_dist / len);
	draw_ceil_and_floor(data, tx.wall_len);
	tx.percent = get_percent(data, len);
	tx.step_x =  data->textr[t]->w * tx.percent;
	tx.step_y = data->textr[t]->h / tx.wall_len;
	tx.tmp = tx.step_y;
	tx.y = -1;
	if (tx.wall_len >= data->res_h)
	{
		tx.step_y = ((tx.wall_len - data->res_h) / 2) * tx.tmp;
		tx.wall_len = data->res_h;
	}
	else
	{
		tx.y = (data->res_h - tx.wall_len) / 2;	
		tx.wall_len += tx.y;
	}
	while (++tx.y < tx.wall_len)
	{
		data->addr[(int)data->i + (int)(tx.y * data->res_w)] = \
			t_addr[(int)tx.step_x + (int)(tx.step_y) * data->textr[t]->w];
		tx.step_y = tx.step_y + tx.tmp;
	}
}

void	which_texture(t_data *data, double len, int flag)
{
	int i;
	int is_vert;

	is_vert = data->is_vert;
	if (flag == 1 && is_vert == 1)
		put_texture(data->textr[3]->t_addr, 3, data, len);
	if (flag == 1 && is_vert == 0)
		/*no_texture*/
		put_texture(data->textr[0]->t_addr, 0, data, len);
	if (flag == 2 && is_vert == 1)
		/*we_texture*/
		put_texture(data->textr[2]->t_addr, 2, data, len);
	if (flag == 2 && is_vert == 0)
		/*no_texure*/
		put_texture(data->textr[0]->t_addr, 0, data, len);
	if (flag == 3 && is_vert == 1)
		/*we_text*/
		put_texture(data->textr[2]->t_addr, 2, data, len);
	if (flag == 3 && is_vert == 0)
		/*so_textr*/
		put_texture(data->textr[1]->t_addr, 1, data, len);
	if (flag == 4 && is_vert == 1)
		/*ea_texture*/
		put_texture(data->textr[3]->t_addr, 3, data, len);
	if (flag == 4 && is_vert == 0)
		/*so_textr*/
		put_texture(data->textr[1]->t_addr, 1, data, len);
}
