/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 15:19:04 by elovegoo          #+#    #+#             */
/*   Updated: 2020/09/22 17:30:39 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_walls_2(t_data *data, double len)
{
	int wall_len;
	int half_wall_len;
	int half_len;
	int half_res;
	int start_pixel;
	int y;
	double step_x;
	double step_y;
	int i;
	double tmp;
	int h;
	int w;

	h = data->textr[i]->h;
	w = data->textr[i]->w;
	i = 0;
	get_percent(data, len);
	wall_len = (int)(floor(data->plane_dist / len));
	half_wall_len = wall_len >> 1;
	start_pixel = half_res - half_wall_len;
	step_y = data->textr[i]->h / wall_len;
	step_x = data->textr[i]->w * data->percent;
	tmp = step_y;
	if (start_pixel <= 0)
	{
		step_y = ((wall_len - data->res_h) / 2) * step_y;
		y = 0;
		wall_len = data->res_h;
	}
	else if (start_pixel > 0)
	{
		y = (data->res_h - wall_len) / 2;	
		wall_len += y;
	}
	while (++y < wall_len)
	{
		data->addr[(int)data->i + (int)(y * data->res_h)] = data->textr[i]-> \
			t_addr[(int)step_x + (int)(step_y * data->textr[i]->w)];
		step_y = step_y + tmp;
	}
}

void	draw_walls(t_data *data, double len)
{
	int wall_len;
	int half_wall_len;
	int half_len;
	int half_res;
	int start_pixel;
	int i;
	int j;

	/*printf("inside draw_walls\n");*/
	/*printf("plane_dist = %f\n", data->plane_dist);*/
	wall_len = (int)(floor(data->plane_dist / len));
	i = 0;
	get_textr_addr(data, wall_len, i);
	/*printf("wall_len = %d\n", wall_len);*/
	half_wall_len = wall_len >> 1;
	half_len = wall_len >> 1;
	j = 0;
	/*printf("len = %f\n", len);*/
	half_res = data->res_h >> 1;
	start_pixel = half_res - half_wall_len;

	if (start_pixel < 0)
	{
		i = 0;
		while (i < data->res_h - 1)
		{
			put_inside_addr(data, data->i, i);
			/*my_mlx_pixel_put(data, data->i, i, 0x000000FF);*/
			i++;
		}
		return ;
	}
	while (i < data->res_h)
	{
		if (i < half_res - half_wall_len)
			my_mlx_pixel_put(data, data->i, i, 0x0000FF00);
		if (i > half_res - half_wall_len && i < half_res + half_wall_len)
			my_mlx_pixel_put(data, data->i, i, 0x000000FF);
		if (i > half_res + half_wall_len)
			my_mlx_pixel_put(data, data->i, i, 0x00FF0000);
		i++;
	}
}
