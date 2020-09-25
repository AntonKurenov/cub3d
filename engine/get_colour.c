/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colour.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:26:36 by elovegoo          #+#    #+#             */
/*   Updated: 2020/09/25 17:33:36 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int create_colour(int red, int green, int blue)
{
	int rgb;

	rgb = red;
	rgb = (rgb << 8) + green;
	rgb = (rgb << 8) + blue;
	return (rgb);
}

void	get_colour(t_data *data)
{
	data->ceil = create_colour(data->set->colour.ce_red, data->set-> \
	colour.ce_green, data->set->colour.ce_blue);
	data->floor = create_colour(data->set->colour.f_red, data->set-> \
	colour.f_green, data->set->colour.f_blue);
}
