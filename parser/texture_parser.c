/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 15:01:41 by elovegoo          #+#    #+#             */
/*   Updated: 2020/10/17 17:24:15 by elovegoo         ###   ########.fr       */
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

static void	check_set_colors(t_set *set, int type)
{
	if (type == 1)
	{
		if (set->colour.f_red > 255 || set->colour.f_red < 0)
			file_exit(3);
		if (set->colour.f_green > 255 || set->colour.f_green < 0)
			file_exit(3);
		if (set->colour.f_blue > 255 || set->colour.f_blue < 0)
			file_exit(3);
	}
	if (type == 2)
	{
		if (set->colour.ce_red > 255 || set->colour.ce_red < 0)
			file_exit(3);
		if (set->colour.ce_green > 255 || set->colour.ce_green < 0)
			file_exit(3);
		if (set->colour.ce_blue > 255 || set->colour.ce_blue < 0)
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
		if (*str == ',')
			file_exit(3);
		word++;
	}
	return (word);
}

int			colour_parser(char **line, t_set *set, int type)
{
	char **arr;

	(*line) += 2;
	check_colors(*line);
	arr = ft_split(*line, ',');
	if (arr_len(arr) != 3)
		file_exit(3);
	if ((check_str_for_color(*line)) != 3)
		file_exit(3);
	if (type == 1)
	{
		set->colour.f_red = atoi_for_color(arr[0]);
		set->colour.f_green = atoi_for_color(arr[1]);
		set->colour.f_blue = atoi_for_color(arr[2]);
	}
	if (type == 2)
	{
		set->colour.ce_red = atoi_for_color(arr[0]);
		set->colour.ce_green = atoi_for_color(arr[1]);
		set->colour.ce_blue = atoi_for_color(arr[2]);
	}
	free_arr(arr);
	check_set_colors(set, type);
	return (0);
}

int			texture_parser(char *line, t_set *set, int type, int len)
{
	char	*name;

	if (len != 2)
		file_exit(1);
	if (ft_strncmp(line, "./", 2) == 0)
	{
		if (ft_strncmp(line, ".//", 3) == 0)
			file_exit(1);
		name = ft_substr(line, 0, ft_strlen(line));
		if (check_file_name(&name, set, type) == 1)
			file_exit(1);
	}
	else
		return (1);
	return (0);
}
