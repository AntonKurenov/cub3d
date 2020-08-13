/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 15:01:41 by elovegoo          #+#    #+#             */
/*   Updated: 2020/08/13 15:29:43 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int check_file_name(char **name, s_set *set, int type)
{
	if ((open(*name, O_RDONLY)) == -1)
		return (1);
	if (type == 1)
		set->no_texture = *name;
	if (type == 2)
		set->so_texture = *name;
	if (type == 3)
		set->we_texture = *name;
	if (type == 0)
		set->s_texture = *name;
	if (type == 4)
		set->ea_texture = *name;
	return (0);
}

int texture_parser(char **line, s_set *set, int type)
{
	int i;
	char *str;
	int n;

	i = 0;
	n = -1;
	while (**line == ' ')
		(*line)++;
	if (**line == '.')
	{
		(*line)++;
		if (**line == '/')
		{
			while (*line[i] != ' ' && *line[i] != '\0')
				i++;
			if (!(str = malloc(sizeof(char) * (i + 1))))
				return (0);
			while (i > 0)
			{
				str[++n] = **line;
				(*line)++;
			}
			str[++n] = '\0';
			if (check_file_name(&str, set, type) == 1)
				return (0);
		}
	}
	else 
		return (0);
	return (1);
}
