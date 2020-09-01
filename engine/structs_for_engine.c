/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_for_engine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 14:08:53 by elovegoo          #+#    #+#             */
/*   Updated: 2020/09/01 16:38:13 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_data	init_img(t_data new, t_player *player, char **map, t_set *set)
{
	if (player->direct == 'N')
		new.angle = 60;
	if (player->direct == 'S')
		new.angle = -60;
	if (player->direct == 'W')
		new.angle = 120;
	if (player->direct == 'E')
		new.angle = 60;
	new.x = player->x * 64 + 32;
	new.y = player->y * 64 + 32;
	new.set = set;
	new.map = map;
	new.player = player;
	new.addr = NULL;
	new.bits_per_pixel = 0;
	new.endian = 0;
	new.line_length = 0;
	new.mlx = NULL;
	new.mlx_win = NULL;
	new.img = NULL;
	return (new);
}
