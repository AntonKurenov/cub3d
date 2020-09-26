/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sptites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 12:11:05 by elovegoo          #+#    #+#             */
/*   Updated: 2020/09/26 20:50:52 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_sprt_angle(t_data *data, int i, t_spr *spr)
{
	double angle;





void	check_sprites(t_data *data, int x, int y)
{
	int i;

	i = -1;
	while (++i < data->num_spr)
	{
		if (data->spr[i].x == x && data->spr[i].y == y)
		{
			data->spr[i].flag = 1;






}

void	init_sprites(t_data *data, char **map)
{
	int i;
	int j;
	int num;

	j = -1;
	num = 0;
	if ((data->spr = (t_spr*)(malloc(sizeof(t_spr) * num))) == NULL)
		file_exit(2);
	data->spr_name = data->set->s_texture;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (map[j][i] == '2')
			{
				data->spr[num].flag = 0;
				data->spr[num].new_y = j * 64 + 32;
				data->spr[num].y = j;
				data->spr[num].new_x = i * 64 + 32;
				data->spr[num].x = i;
				data->spr[num].pos = -1;
				num++;
			}
		}
	}
}
