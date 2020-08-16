/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 17:13:24 by elovegoo          #+#    #+#             */
/*   Updated: 2020/08/16 12:01:58 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

s_col init_colours()
{
	s_col colour;

	colour.ce_red = 0;
	colour.ce_blue = 0;
	colour.ce_green = 0;
	colour.f_red = 0;
	colour.f_green = 0;
	colour.f_blue = 0;
	return (colour);
}

s_set	init_set(s_set set)
{
	set.colour = init_colours();		
	set.res_w = 0;
	set.res_h = 0;
	set.no_texture = NULL;
	set.s_texture = NULL;
	set.we_texture = NULL;
	set.ea_texture = NULL;
	set.s_texture = NULL;
	set.fl_texture = NULL;
	set.c_texture = NULL;
	return (set);
}

int check_rest(char **line)
{
	while (**line == ' ')
		(*line)++;
	if (**line != '\0')
		return (1);
	return (0);
}

int	parse_resolution(char **line, s_set *set)
{
	while (**line == ' ')
		(*line)++;
	while (**line >= '0' && **line <= '9')
	{
		set->res_h = set->res_h * 10 + (**line - '0');
		(*line)++;
	}
	while (**line == ' ')
		(*line)++;
	while (**line >= '0' && **line <= '9')
	{
		set->res_w = set->res_w * 10 + (**line - '0');
		(*line)++;
	}
	printf("res_h = %d\n", set->res_h);
	printf("res_w = %d\n", set->res_w);
	return (check_rest(line));
}

int	setting_parser(char **line, s_set *set)
{
	char *str;
	int ret;

	while (**line == ' ')
		(*line)++;
	if (**line == 'R' && set->res_h == 0)
	{
		(*line)++;
		if ((parse_resolution(line, set) == 1))
			return (1);
	}
	if (**line == 'N' && set->no_texture == 0)
	{
		(*line)++;
		if (**line == 'O')
		{
			(*line)++;
			if ((texture_parser(line, set, 1)) == 0)
				return (1);
		}
	}
	if (**line == 'W' && set->we_texture == 0)
	{
		(*line)++;
		if (**line == 'E')
		{
			(*line)++;
			if ((texture_parser(line, set, 3)) == 0)
				return (1);
		}
	}
	if (**line == 'S')
	{
		(*line)++;
		if (**line == 'O' && set->so_texture == 0)
		{
			(*line)++;
			if ((texture_parser(line, set, 2)) == 0)
				return (1);
		}
		if (**line == ' ' && set->s_texture == 0)
		{
			if ((texture_parser(line, set, 0)) == 0)
				return (1);
		}
	}
	if (**line == 'E' && set->ea_texture == 0)
	{
		(*line)++;
		if (**line == 'A')
		{
			(*line)++;
			if ((texture_parser(line, set, 4)) == 0)
				return (1);
		}
	}
	if (**line == 'F' || **line == 'C')
		ret = colour_parser(line, set);
	return (0);
}

int open_file(char *name, s_set *set)
{
	char *ptr;
	int fd;
	char *line;
	char *tmp;
	int ret;
	int count;

	if ((check_name(name)) == 0)
		return (0);
	if ((fd = open(name, O_RDONLY)) == -1)
	{
		ft_putstr("Error\nBad file descriptor");
		return (0);
	}
	printf("name2 = %s\n", name);
	printf("fd = %d\n", fd);
	while ((ret = get_next_line(fd, &line)))
	{
		tmp = line;
		if ((setting_parser(&tmp, set)) == 1)
		{
			ft_putstr("Error\nInvalid map\n");
			exit (0);
		}
		free(line);
	}
	return (0);
}

int main(int args, char **argv)
{
	int i;
	int n;
	s_set set;

	set = init_set(set);
	if (args != 2)
		return (error_manager(1));
	else if (args == 2)
	{
		open_file(argv[1], &set);
		return (0);
	}
	
}
