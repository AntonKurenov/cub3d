/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:14:04 by elovegoo          #+#    #+#             */
/*   Updated: 2020/10/12 11:32:31 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_player(t_player *new)
{
	new->x = 0;
	new->y = 0;
	new->direct = 0;
}

void	init_colours(t_col *colour)
{
	colour->ce_red = -1;
	colour->ce_blue = -1;
	colour->ce_green = -1;
	colour->f_red = -1;
	colour->f_green = -1;
	colour->f_blue = -1;
}

void	init_set(t_set *set)
{
	init_colours(&set->colour);
	set->res_w = 0;
	set->res_h = 0;
	set->is_save = 0;
	set->no_texture = NULL;
	set->s_texture = NULL;
	set->we_texture = NULL;
	set->ea_texture = NULL;
	set->so_texture = NULL;
}

void	init_map_specs(t_map *map)
{
	map->height = 0;
	map->width = 0;
}
