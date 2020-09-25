/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceil_and_floor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 16:30:13 by elovegoo          #+#    #+#             */
/*   Updated: 2020/09/25 17:15:16 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_ceil_and_floor(t_data *data, double wall_len)
{
	int i;
	int half_wall_len;
	int w_start;
	int w_end;

	half_wall_len = (int)(wall_len) >> 1;
	w_start = data->half_res - half_wall_len;
	w_end = w_start + wall_len;
	i = -1;
	while (++i < w_start)
		my_mlx_pixel_put(data, data->i, i, data->ceil);
	i = w_end - 1;
	while (++i < data->res_h)
		my_mlx_pixel_put(data, data->i, i, data->floor);
}
