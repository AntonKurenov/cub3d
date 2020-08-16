/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 15:01:41 by elovegoo          #+#    #+#             */
/*   Updated: 2020/08/16 19:27:31 by elovegoo         ###   ########.fr       */
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
	if (type == 4)
		set->ea_texture = *name;
	if (type == 5)
		set->s_texture = *name;
	printf("so_texture = %s\n", set->so_texture);
	printf("no_texture = %s\n", set->no_texture);
	return (0);
}

int colour_parser(char *line, s_set *set, int type)
{
	if (type == 1)
	{
		set->colour.f_red = atoi_str(&line);
		line++;
		set->colour.f_green = atoi_str(&line);
		line++;
		set->colour.f_blue = atoi_str(&line);
	}
	if (type == 2)
	{
		set->colour.ce_red = atoi_str(&line);
		line++;
		set->colour.ce_green = atoi_str(&line);
		line++;
		set->colour.ce_blue = atoi_str(&line);
	}
	printf("ce_blue = %d\n", set->colour.ce_blue);
	return(0);
}

int texture_parser(char *line, s_set *set, int type)
{
	int i;
	char *name;
	int n;
	char *tmp;

	i = 0;
	n = -1;
	printf("type = %d\n", type);
	printf("line inside tex_par = %s\n", line);
	if (ft_strncmp(line, "./", 2) == 0)
	{
		name = ft_substr(line, 2, ft_strlen(line));
		printf("line inside tex_par = %s\n", line);
		printf("name of texture = |%s|\n", name);
		if (check_file_name(&name, set, type) == 1)
		{
			ft_putstr("Error\nInvalid map\n");
			exit (0);
		}
	}
	else 
		return (1);
	return (0);
}
