/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 17:13:24 by elovegoo          #+#    #+#             */
/*   Updated: 2020/08/13 16:36:53 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

s_set	init_set(s_set set)
{
	set.res_w = 0;
	set.res_h = 0;
	set.no_texture = 0;
	set.s_texture = 0;
	set.we_texture = 0;
	set.ea_texture = 0;
	set.s_texture = 0;
	set.fl_texture = 0;
	set.c_texture = 0;
	return (set);
}

s_files init_names(s_files names)
{
	names.ea = 0;
	names.no = 0;
	names.we = 0;
	names.so = 0;
	names.s = 0;
	return (names);
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
	while (**line == ' ')
		(*line)++;
	if (**line != '\0')
		return (0);
	return (1);
}

int	setting_parser(char **line, int count, s_set *set)
{
	char *str;
	int ret;
	s_files names;

	names = init_names(names);
	while (**line == ' ')
		(*line)++;
	str = ft_strdup(*line);
	if (**line == 'R' && set->res_h == 0)
	{
		if ((parse_resolution(&str, set) == 0))
			return (0);
	}
	if (**line == 'N') 
	{
		(*line)++;
		if (**line == 'O')
		{
			if ((texture_parser(line, set, 1)) == 0)
				return (0);
		}
		exit(0);
	}
	if (**line == 'W')
	{
		(*line)++;
		if (**line == 'E')
		{
			if ((texture_parser(line, set, 3)) == 0)
				return (0);
		}
	}
	if (**line == 'S')
	{
		(*line)++;
		if (**line == 'O')
		{
			if ((texture_parser(line, set, 2)) == 0)
				return (0);
		}
		if (**line == ' ')
		{
			if ((texture_parser(line, set, 0)) == 0)
				return (0);
		}
	}
	if (**line == 'E')
	{
		(*line)++;
		if (**line == 'A')
		{
			if ((texture_parser(line, set, 4)) == 0)
				return (0);
		}
	}
	return (0);
}

int open_file(char *name, s_set *set)
{
	char *ptr;
	char fd;
	char *line;
	int ret;
	int count;

	if ((check_name(name)) == 0)
		return (0);
	if ((fd = open(name, O_RDONLY)) == -1)
	{
		ft_putstr("Error\n Bad file descriptor");
		return (0);
	}
	ret = 1;
	count = 0;
	while ((ret = get_next_line(fd, &line)))
	{
		if ((setting_parser(&line, count, set)) == 1)
			count++;
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
