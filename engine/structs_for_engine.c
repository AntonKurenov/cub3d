/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_for_engine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 14:08:53 by elovegoo          #+#    #+#             */
/*   Updated: 2020/10/10 13:06:25 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_angle(t_data *new, t_player *player)
{
	if (player->direct == 'N')
		new->angle = 90;
	if (player->direct == 'S')
		new->angle = 270;
	if (player->direct == 'W')
		new->angle = 180;
	if (player->direct == 'E')
		new->angle = 0;
}

void	next_step_init(t_data *data)
{
	int i;

	i = -1;
	if (!(data->dist_arr = (double *)malloc(sizeof(double) * data->res_w)))
		file_exit (2);
	data->map_size_y = data->map_h * B_SIZE;
	data->map_size_x = data->map_w * B_SIZE;
	get_colour(data);
	data->act_map_h = data->map_h + 1;
	data->act_map_w = data->map_w + 1;
	data->half_res = data->res_h >> 1;
	while (++i < 4)
	{
		if ((data->textr[i] = (t_tex *)malloc(sizeof(t_tex))) == NULL)
			file_exit(2);
		if (i == 0)
			data->textr[i]->name = data->set->no_texture;
		else if (i == 1)
			data->textr[i]->name = data->set->so_texture;
		else if (i == 2)
			data->textr[i]->name = data->set->we_texture;
		else if (i == 3)
			data->textr[i]->name = data->set->ea_texture;
		data->textr[i]->t_addr = NULL;
		data->textr[i]->t_img = NULL;
	}
}

void get_resolution(t_data *data)
{
	int res_h;
	int res_w;

	res_h = 0;
	res_w = 0;
	mlx_get_screen_size(data->mlx, &res_w, &res_h);
	if (data->res_w > res_w || data->res_w == -2)
		data->res_w = res_w;
	if (data->res_h > res_h || data->res_h == -2)
		data->res_h = res_h;
	printf("res_h = %d res_w = %d\n", data->res_h, data->res_w);
}

void	init_img(t_data *new, t_player *player, t_map *map_specs, t_set *set)
{
	set_angle(new, player);
	new->num_spr = map_specs->spr_num;
	new->spr_name = set->s_texture;
	printf("res_h = %d res_w = %d\n", set->res_h, set->res_w);
	new->res_h = set->res_h;
	new->res_w = set->res_w;
	if ((new->mlx = mlx_init()) == NULL)
		file_exit(7);
	get_resolution(new);
	new->matr_size = map_specs->height * map_specs->width;
	new->map_h = map_specs->height - 1;
	new->map_w = map_specs->width - 1;
	new->plane_dist = B_SIZE * (((double)(new->res_w >> 1)) / \
			tan((double)H_FOV * RAD_CONV));
	/*p->intf("plane_len = %f\n", new.plane_dist);*/
	new->spr = NULL;
	new->i = 0;
	new->pos_x = (player->x) * B_SIZE + 32;
	new->pos_y = (player->y) * B_SIZE + 32;
	printf("player pos_x = %d  pos_y = %d\n", player->x, player->y);
	printf("pos_x = %f || pos_y = %f\n", new->pos_x, new->pos_y);
	new->cur_angle = 0;
	new->part_angle = (double)(FOV) / (double)(new->res_w);
	new->set = set;
	new->player = player;
	new->line_length = 0;
	next_step_init(new);
}
