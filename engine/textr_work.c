/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textr_work.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 15:23:00 by elovegoo          #+#    #+#             */
/*   Updated: 2020/09/23 21:45:43 by elovegoo         ###   ########.fr       */
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
	{
		percent = (x - (floor(x / 64) * 64)) * 100 / B_SIZE;
		/*x_inter = floor(x / B_SIZE);*/
		/*part_len = x - (B_SIZE * x_inter);*/
		/*percent = part_len * B_SIZE / 100;*/
	}
	if (data->is_vert == 1)
	{
		percent = (y - (floor(y / 64) * 64)) * 100 / B_SIZE;
		/*y_inter = floor(y / B_SIZE);*/
		/*part_len = y - (B_SIZE * y_inter);*/
		/*percent = part_len / B_SIZE * 100;*/
	}
	return (percent);
}

void	put_texture(int *t_addr, int t, t_data *data, double len)
{
	int wall_len;
	int half_res;
	int y;
	int h;
	int w;
	double step_x;
	double step_y;
	double percent;
	int half_wall_len;
	double tmp;
	int i = -1;

	h = data->textr[t]->h;
	w = data->textr[t]->w;
	half_res = data->res_h >> 1;
	wall_len = (int)(floor(data->plane_dist / len));
	half_wall_len = wall_len >> 1;
	percent = get_percent(data, len);
	step_x = w * percent;
	printf("wall_len = %d\n", wall_len);
	step_y = (h / wall_len);
	tmp = step_y;
	while (++i < half_res)
			my_mlx_pixel_put(data, data->i, i, 0x0000FF00);
	while (++i < data->res_h)
			my_mlx_pixel_put(data, data->i, i, 0x000000FF);
	if (wall_len > data->res_h)
	{
		step_y = ((wall_len - data->res_h) / 2) * step_y;
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
		data->addr[(int)data->i + (int)(y * data->res_h)] = data->textr[t]-> \
			t_addr[(int)step_x + (int)(step_y * w)];
		step_y = step_y + tmp;
	}
}

void	which_texture(t_data *data, double len, int flag)
{
	int i;
	int is_vert;

	is_vert = data->is_vert;
	if (flag == 1 && is_vert == 1)
		/*ea_texture*/
		put_texture(data->textr[3]->t_addr, 3, data, len);
	if (flag == 1 && is_vert == 0)
	{
		/*no_texture*/
		put_texture(data->textr[0]->t_addr, 0, data, len);
	}
	if (flag == 2 && is_vert == 1)
	{
		/*we_texture*/
		put_texture(data->textr[2]->t_addr, 2, data, len);
	}
	if (flag == 2 && is_vert == 0)
	{
		/*no_texure*/
		put_texture(data->textr[0]->t_addr, 0, data, len);
	}
	if (flag == 3 && is_vert == 1)
	{
		/*we_text*/
		put_texture(data->textr[2]->t_addr, 2, data, len);
	}
	if (flag == 3 && is_vert == 0)
	{
		/*so_textr*/
		put_texture(data->textr[1]->t_addr, 1, data, len);
	}
	if (flag == 4 && is_vert == 1)
	{
		/*ea_texture*/
		put_texture(data->textr[3]->t_addr, 3, data, len);
	}
	if (flag == 4 && is_vert == 0)
	{
		/*so_textr*/
		put_texture(data->textr[1]->t_addr, 1, data, len);
	}
}
