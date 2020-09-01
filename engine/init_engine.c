/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 16:02:14 by elovegoo          #+#    #+#             */
/*   Updated: 2020/09/01 15:12:01 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void first_frame(t_data *img)
{
	int i;
	int j;

	img->img = mlx_new_image(img->mlx, img->res_w, img->res_h);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
								 &img->endian);


}

int	next_frame(int key, t_data *img)
{
	img->img = mlx_new_image(img->mlx, img-res_w, img->res_h);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
								 &img->endian);

	if (key == 53)
		close(img);
	if (key == 13)
		move_up(img);
	if (key == 0)
		move_left(img);
	if (key == 1)
		move_down(img);
	if (key == 2)
		move_right(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}

void init_engine(t_player *player, t_set *set, t_map *map_specs, char **map)
{
	void *mlx;
	t_data img;
	int res_h;
	int res_w;

	img = init_img(img, player, map, set);
	img.mlx = mlx_init();
	mlx_get_screen_size(img.mlx, &res_w, &res_h);
	img.res_h = (res_h < set->res_h) ? res_h : set->res_h;
	img.res_w = (res_w < set->res_w) ? res_w : set->res_w;
	img.part_angle = (FOV / res_w);
	img.mlx_win = mlx_new_window(img.mlx, res_w, res_h, "cub3D");
	mlx_hook(img.mlx_win, 2, 1L<<2, next_frame, &img);


}
