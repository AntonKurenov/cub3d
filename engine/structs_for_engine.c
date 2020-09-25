/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_for_engine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 14:08:53 by elovegoo          #+#    #+#             */
/*   Updated: 2020/09/25 16:37:47 by elovegoo         ###   ########.fr       */
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

	i = 0;
	data->map_size_y = data->map_h * B_SIZE;
	data->map_size_x = data->map_w * B_SIZE;
	get_colour(data);
	data->half_res = data->res_h >> 1;
	while (i < 4)
	{
		data->textr[i] = (t_tex *)malloc(sizeof(t_tex));
		if (i == 0)
			data->textr[i]->name = data->set->no_texture;
		else if (i == 1)
			data->textr[i]->name = data->set->so_texture;
		else if (i == 2)
			data->textr[i]->name = data->set->we_texture;
		else if (i == 3)
			data->textr[i]->name = data->set->ea_texture;
		printf("i = %d\n", i);
		data->textr[i]->t_addr = NULL;
		data->textr[i]->t_img = NULL;
		i++;
	}
}

t_data	init_img(t_data new, t_player *player, t_map *map_specs, t_set *set)
{
	set_angle(&new, player);
	new.mlx = NULL;
	new.addr = NULL;
	new.mlx_win = NULL;
	new.res_h = set->res_h;
	new.res_w = set->res_w;
	new.map_h = map_specs->height - 1;
	new.map_w = map_specs->width - 1;
	new.plane_dist = B_SIZE * (((double)(new.res_w >> 1)) / tan((double)H_FOV * RAD_CONV));
	/*printf("plane_len = %f\n", new.plane_dist);*/
	/*printf("tan = %f\n", tan(H_FOV * RAD_CONV));*/
	new.i = 0;
	new.pos_x = (player->x) * B_SIZE + 32;
	new.pos_y = (player->y) * B_SIZE + 32;
	/*printf("player pos_x = %d  pos_y = %d\n", player->x, player->y);*/
	/*printf("pos_x = %f || pos_y = %f\n", new.pos_x, new.pos_y);*/
	new.cur_angle = 0;
	new.part_angle = (double)(FOV) / (double)(new.res_w);
	new.set = set;
	new.player = player;
	new.line_length = 0;
	next_step_init(&new);
	return (new);
}
