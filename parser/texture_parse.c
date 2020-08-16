/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 15:01:41 by elovegoo          #+#    #+#             */
/*   Updated: 2020/08/16 11:35:52 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int check_file_name(char **name, s_set *set, int type)
{
	int f;

	printf("name = %s\n", *name);
	if ((f = open(*name, O_RDONLY)) == -1)
	{
		printf("f = %d\n", f);
		return (1);
	}
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
	printf("so_texture = %s\n", set->so_texture);
	return (0);
}

int colour_parser(char **line, s_set *set)
{
	if (**line == 'F' && set->colour.f_blue == 0)
	{
		(*line)++;
		if ((set->colour.f_red = atoi_str(line) > 255) || \
			(set->colour.f_red < 0))
			return (1);
		(*line)++;
		if ((set->colour.f_green = atoi_str(line) > 255) || \
			(set->colour.f_green < 0))
			return (1);
		(*line)++;
		if ((set->colour.f_blue = atoi_str(line) > 255) || \
			(set->colour.f_blue < 0))
			return (1);
	}
	if (**line == 'C' && set->colour.ce_blue == 0)
	{
		(*line)++;
		if ((set->colour.ce_red = atoi_str(line) > 255) || \
			(set->colour.ce_red < 0))
			return (1);
		(*line)++;
		if ((set->colour.ce_green = atoi_str(line) > 255) || \
			(set->colour.ce_green < 0))
			return (1);
		(*line)++;
		if ((set->colour.ce_blue = atoi_str(line) > 255) || \
			(set->colour.ce_blue < 0))
			return (1);
	}
	return(0);
}

int texture_parser(char **line, s_set *set, int type)
{
	int i;
	char *str;
	int n;
	char *tmp;

	i = 0;
	n = -1;
	printf("type = %d\n", type);
	printf("line inside tex_par = %s\n", *line);
	while (**line == ' ')
		(*line)++;
	if (**line == '.')
	{
		(*line)++;
		if (**line == '/')
		{
			(*line)++;
			printf("line inside tex_par = %s\n", *line);
			tmp = *line;
			while (tmp[i] != '\0' && tmp[i] != ' ')
				i++;
			printf("i = %d\n", i);
			if (!(str = malloc(sizeof(char) * (i + 1))))
				return (0);
			while (i > 0)
			{
				str[++n] = **line;
				i--;
				(*line)++;
			}
			str[++n] = '\0';
			printf("name of texture = |%s|\n", str);
			if (check_file_name(&str, set, type) == 1)
				return (0);
		}
		else
			return (0);
	}
	else 
		return (0);
	return (1);
}
