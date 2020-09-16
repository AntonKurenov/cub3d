/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 16:02:14 by elovegoo          #+#    #+#             */
/*   Updated: 2020/09/16 20:03:48 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	next_frame(int key, t_data *data)
{
	int i;
	int j;
	printf("inside next_frame\n");

	i = 0;
	j = 0;
	if (key == BUTTON_ESC)
		close_win(data);
	if (key == BUTTON_W)
		move_up(data);
	if (key == ARR_LEFT)
		turn_left(data);
	if (key == BUTTON_S)
		move_down(data);
	if (key == ARR_RIGHT)
		turn_right(data);
	/*if (key == 1)*/
		/*move_down(img);*/
	/*if (key == 2)*/
		/*move_right(img);*/
	printf("datadat\n");
	receiver(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	mlx_loop(data->mlx);
	printf("after receiver\n");
	return (0);
}

void init_engine(t_player *player, t_set *set, t_map *map_specs, char **map)
{
	t_data img;
	int res_h;
	int res_w;
	int i;
	int j;

	img.map = map;
	img = init_img(img, player, map_specs, set);
	img.mlx = mlx_init();
	printf("inside init_engine\n");
	/*mlx_get_screen_size(img.mlx, &res_w, &res_h);*/
	/*img.res_h = (res_h < set->res_h) ? res_h : set->res_h;*/
	/*img.res_w = (res_w < set->res_w) ? res_w : set->res_w;*/
	printf("part_angle = %f\n", img.part_angle);

	img.mlx_win = mlx_new_window(img.mlx, img.res_w, img.res_h, "cub3D");
	/*mlx_hook(img.mlx_win, 2, 1L<<2, next_frame, &img);*/
	img.img = mlx_new_image(img.mlx, img.res_w, img.res_h);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	receiver(&img);
	mlx_hook(img.mlx_win, 2, 1L<<2, next_frame, &img);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_loop(img.mlx);
}
