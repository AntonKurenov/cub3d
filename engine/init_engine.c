/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 16:02:14 by elovegoo          #+#    #+#             */
/*   Updated: 2020/10/10 12:49:24 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = (char*)data->addr + (y * data->line_length + x *\
			(data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	next_frame(int key, t_data *data)
{
	t_angle ang;
	
	ang = reset_angle(ang, data, key);
	if (key == BUTTON_ESC)
		close_win(data);
	if (key == BUTTON_W || key == BUTTON_S)
		move_s_and_w(data, &ang);
	if (key == BUTTON_D || key == BUTTON_A)
		move_d_and_a(data, &ang);
	if (key == ARR_LEFT)
		turn_left(data);
	if (key == ARR_RIGHT)
		turn_right(data);

	receiver(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	/*mlx_destroy_image(data->mlx, data->img);*/
	mlx_loop(data->mlx);
	return (0);
}

void run_engine(t_data *data)
{

}

void init_engine(t_player *player, t_set *set, t_map *map_specs, char **map)
{
	t_data img;

	printf("spr_num in map_specs = %d\n", map_specs->spr_num);
	img.map = map;
	init_img(&img, player, map_specs, set);
	/*if (img.res_h == -2 || img.res_w == -2)*/
		/*mlx_get_screen_size(img.mlx, &img.res_w, &img.res_h);*/
	img.mlx_win = mlx_new_window(img.mlx, img.res_w, img.res_h, "cub3D");
	img.img = mlx_new_image(img.mlx, img.res_w, img.res_h);
	img.addr = (int*)mlx_get_data_addr(img.img, &img.bits_per_pixel, \
			&img.line_length, &img.endian);
	open_textr(&img);
	init_sprites(&img, map);
	receiver(&img);
	if (img.set->is_save == 1)
		get_screenshot(&img);
	mlx_hook(img.mlx_win, 2, 1L<<2, next_frame, &img);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	/*mlx_destroy_image(img.mlx, img.img);*/
	mlx_loop(img.mlx);
}
