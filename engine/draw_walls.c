/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 15:19:04 by elovegoo          #+#    #+#             */
/*   Updated: 2020/09/07 13:19:10 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_walls(t_data *data, double len)
{
	int wall_len;
	int half_wall_len;
	int half_len;
	int half_res;
	int start_pixel;
	int i;
	int j;

	printf("inside draw_walls\n");
	printf("plane_dist = %f\n", data->plane_dist);
	wall_len = (int)(floor(data->plane_dist / len));
	printf("wall_len = %d\n", wall_len);
	half_wall_len = wall_len >> 1;
	half_len = wall_len >> 1;
	i = 0;
	j = 0;
	printf("len = %f\n", len);
	half_res = data->res_h / 2;
	start_pixel = half_res - half_wall_len;

	if (start_pixel < 0)
	{
		i = 0;
		while (i < data->res_h - 1)
		{
			my_mlx_pixel_put(data, data->i, i, 0x000000FF);
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
			my_mlx_pixel_put(data, data->i, i, 0x000F0000);
		i++;
	}
}

