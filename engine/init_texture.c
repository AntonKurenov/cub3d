/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 15:52:37 by elovegoo          #+#    #+#             */
/*   Updated: 2020/10/12 11:57:27 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	open_textr(t_data *data)
{
	int i;

	i = -1;
	if ((data->spr_img = mlx_xpm_file_to_image(data->mlx, data->spr_name,\
		&data->spr_w, &data->spr_h)) == NULL)
	{
		ft_putstr("Error\nWrong sprite file\n");
		exit(0);
	}
	if ((data->spr_addr = (int*)mlx_get_data_addr(data->spr_img, &data->\
					spr_bpp, &data->spr_line, &data->endian)) == NULL)
	{
		ft_putstr("Error\nWrong sprite file\n");
		exit(0);
	}
	while (++i < 4)
	{
		if ((data->textr[i]->t_img = mlx_xpm_file_to_image(data->mlx, data->\
			textr[i]->name, &data->textr[i]->w, &data->textr[i]->h)) == NULL)
			file_exit(10);
		data->textr[i]->t_addr = (int*)mlx_get_data_addr(data->textr[i]->t_img,\
		&data->textr[i]->bpp, &data->textr[i]->s_line, &data->textr[i]->end);
	}
}
