/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 17:13:24 by elovegoo          #+#    #+#             */
/*   Updated: 2020/10/12 16:31:21 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			check_set(t_set set)
{
	int flag;

	flag = 0;
	if (set.colour.f_red != -1 && set.colour.f_green != -1 && \
		set.colour.f_blue != -1 && set.colour.ce_red != -1 && \
		set.colour.ce_green != -1 && set.colour.ce_blue != -1)
		flag = flag + 1;
	if (set.res_w != 0 && set.res_h != 0 && set.no_texture != NULL && \
		set.s_texture != NULL && set.we_texture != NULL && \
		set.ea_texture != NULL && set.so_texture != NULL)
		flag = flag + 1;
	if (flag == 2)
		return (1);
	return (0);
}

int			arr_len(char **str_arr)
{
	int i;

	i = 0;
	while (str_arr[i])
		i++;
	return (i);
}

static int	open_file(char *name, t_set *set, int flag)
{
	int		fd;
	char	*line;
	char	*tmp;

	fd = check_name(name);
	while (get_next_line(fd, &line))
	{
		tmp = line;
		if ((check_set(*set) != 1) && line[0] != '\0')
			setting_parser(line, set);
		else if ((check_set(*set) == 1) && line[0] == '\0' && flag != 0)
			file_exit(1);
		else if ((check_set(*set) == 1) && line[0] != '\0')
		{
			flag++;
			init_map_parser(line, set, 0);
		}
		free(tmp);
	}
	if (flag > 0)
		init_map_parser(line, set, 1);
	else
		file_exit(1);
	return (0);
}

int			main(int args, char **argv)
{
	int		flag;
	char	*save;
	t_set	set;

	save = "--save";
	flag = 0;
	init_set(&set);
	if (args < 2)
		return (error_manager(1));
	else if (args == 2 || args == 3)
	{
		if (args == 3)
		{
			if (ft_strncmp(argv[2], "--save", 6) == 0)
				set.is_save = 1;
			else
				file_exit(5);
		}
		open_file(argv[1], &set, flag);
		return (0);
	}
	else
		file_exit(9);
}
