/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:14:04 by elovegoo          #+#    #+#             */
/*   Updated: 2020/08/22 12:24:49 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

s_player init_player(s_player new)
{
	new.x = 0;
	new.y = 0;
	new.direct = 0;
	return (new);
}

s_col init_colours()
{
	s_col colour;

	colour.ce_red = -1;
	colour.ce_blue = -1;
	colour.ce_green = -1;
	colour.f_red = -1;
	colour.f_green = -1;
	colour.f_blue = -1;
	return (colour);
}

s_set	init_set(s_set set)
{
	set.colour = init_colours();		
	set.res_w = 0;
	set.res_h = 0;
	set.no_texture = NULL;
	set.s_texture = NULL;
	set.we_texture = NULL;
	set.ea_texture = NULL;
	set.so_texture = NULL;
	return (set);
}

s_map init_map_specs(s_map map)
{
	map.height = 0;
	map.width = 0;
	return (map);
}
