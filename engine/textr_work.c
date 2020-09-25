/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textr_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 15:23:00 by elovegoo          #+#    #+#             */
/*   Updated: 2020/09/25 17:32:26 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	get_percent(t_data *data, double len)
{
	double x;
	double y;
	int	part_len;
	int	x_inter;
	int y_inter;
	double percent;

	x = (data->is_vert == 1) ? data->vert_x : data->hor_x;
	y = (data->is_vert == 1) ? data->vert_y : data->hor_y;
	if (data->is_vert == 0)
		percent = (x - (floor(x / 64) * 64)) / B_SIZE;
	if (data->is_vert == 1)
		percent = (y - (floor(y / 64) * 64)) / B_SIZE;
	return (percent);
}

void	put_texture(int *t_addr, int t, t_data *data, double len)
{
	double wall_len;
	int half_res;
	int y;
	double step_x;
	double step_y;
	double percent;
	double tmp;

	wall_len = (data->plane_dist / len);
	draw_ceil_and_floor(data, wall_len);
	percent = get_percent(data, len);
	step_x =  data->textr[t]->w * percent;
	step_y = data->textr[t]->h / wall_len;
	tmp = step_y;
	/*printf("step_y = %f\nstep_x = %f\n", step_y, step_x);*/
	if (wall_len >= data->res_h)
	{
		step_y = ((wall_len - data->res_h) / 2) * tmp;
		y = 0;
		wall_len = data->res_h;
	}
	else
	{
		y = (data->res_h - wall_len) / 2;	
		wall_len += y;
	}
	while (++y < wall_len)
	{
		data->addr[(int)data->i + (int)(y * data->res_w)] = t_addr[(int)step_x \
					+ (int)(step_y) * data->textr[t]->w];
		step_y = step_y + tmp;
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
