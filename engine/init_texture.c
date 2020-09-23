/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 15:52:37 by elovegoo          #+#    #+#             */
/*   Updated: 2020/09/23 20:46:55 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	open_textr(t_data *data)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if ((data->textr[i]->t_img = mlx_xpm_file_to_image(data->mlx, data-> \
			textr[i]->name, &data->textr[i]->w, &data->textr[i]->h)) == NULL)
		{
			write(1, "Error\nWrong texture\n", 20); 
			exit (0);
		}
		data->textr[i]->t_addr = (int*)mlx_get_data_addr(data->textr[i]->t_img, \
		&data->textr[i]->bpp, &data->textr[i]->s_line, &data->textr[i]->end);
		i++;
	}
}

