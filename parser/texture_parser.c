/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 15:01:41 by elovegoo          #+#    #+#             */
/*   Updated: 2020/10/12 14:50:48 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	check_file_name(char **name, t_set *set, int type)
{
	int f;

	if ((f = open(*name, O_RDONLY)) == -1)
		file_exit(10);
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
	return (0);
}

static void	check_colors(t_set *set, int type)
{
	if (type == 1)
	{
		if (set->colour.f_red > 255 && set->colour.f_red < 0)
			file_exit(3);
		if (set->colour.f_green > 255 && set->colour.f_green < 0)
			file_exit(3);
		if (set->colour.f_blue > 255 && set->colour.f_blue < 0)
			file_exit(3);
	}
	if (type == 2)
	{
		if (set->colour.ce_red > 255 && set->colour.ce_red < 0)
			file_exit(3);
		if (set->colour.ce_green > 255 && set->colour.ce_green < 0)
			file_exit(3);
		if (set->colour.ce_blue > 255 && set->colour.ce_blue < 0)
			file_exit(3);
	}
}

int			check_str_for_color(char *str)
{
	int count;
	int word;

	word = 0;
	str++;
	while (word < 3 && *str)
	{
		count = 0;
		while (*str == ' ')
			str++;
		while (*str >= '0' && *str <= '9')
		{
			count++;
			if (count > 3)
				file_exit(3);
			str++;
		}
		if (*str == ',')
			str++;
		word++;
	}
	return (word);
}

int			colour_parser(char **line, t_set *set, int type)
{
	if ((check_str_for_color(*line)) != 3)
		file_exit(3);
	if (type == 1)
	{
		set->colour.f_red = atoi_str_color(line);
		(*line)++;
		set->colour.f_green = atoi_str_color(line);
		(*line)++;
		set->colour.f_blue = atoi_str_color(line);
		if (**line != '\0')
			file_exit(3);
	}
	if (type == 2)
	{
		set->colour.ce_red = atoi_str_color(line);
		(*line)++;
		set->colour.ce_green = atoi_str_color(line);
		(*line)++;
		set->colour.ce_blue = atoi_str_color(line);
		if (**line != '\0')
			file_exit(3);
	}
	check_colors(set, type);
	return (0);
}

int			texture_parser(char *line, t_set *set, int type, int len)
{
	char	*name;

	if (len != 2)
		file_exit(1);
	if (ft_strncmp(line, "./", 2) == 0)
	{
		name = ft_substr(line, 0, ft_strlen(line));
		if (check_file_name(&name, set, type) == 1)
			file_exit(1);
	}
	else
		return (1);
	return (0);
}
