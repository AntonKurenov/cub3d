/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 17:13:24 by elovegoo          #+#    #+#             */
/*   Updated: 2020/08/22 12:17:33 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int check_set(s_set set)
{
	int flag;

	/*printf("res_h = %d\n", set.res_h);*/
	/*printf("res_w = %d\n", set.res_w);*/
	flag = 0;
	if (set.colour.f_red != -1 && set.colour.f_green != -1 && \
		set.colour.f_blue != -1 && set.colour.ce_red != -1 && \
		set.colour.ce_green != -1 && set.colour.ce_blue != -1)
	{
		flag = flag + 1;
		printf("flag1 = %d\n", flag);
	}
	if (set.res_w != 0 && set.res_h != 0 && set.no_texture != NULL && \
		set.s_texture != NULL && set.we_texture != NULL && \
		set.ea_texture != NULL && set.so_texture != NULL)
	{
		flag = flag + 1;
		printf("flag2 = %d\n", flag);
	}
	if (flag == 2)
	{
		/*printf("Hey there! flag = 2!!!\n");*/
		return (1);
	}
	return (0);
}

int arr_len(char **str_arr)
{
	int i;

	i = 0;
	while (str_arr[i])
		i++;
	return (i);
}

int	parse_resolution(char *str1, char *str2, s_set *set, int len)
{
	if (len != 3)
	{
		ft_putstr("Error\nInvalid map\n");
		exit (0);
	}
	set->res_h = atoi_str(&str1);
	set->res_w = atoi_str(&str2);
	printf("res_h = %d\n", set->res_h);
	printf("res_w = %d\n", set->res_w);
	return (0);
}

int	setting_parser(char *line, s_set *set)
{
	char **str_arr;
	int len;
	int ret;

	str_arr = ft_split(line, ' ');
	len = arr_len(str_arr);
	/*printf("len = %d\n", len);*/
	/*printf("str0 = %s\nstr1 = %s\n", str_arr[0], str_arr[1]);*/
	ret = 1;
	if (len == 0)
		return (0);
	else if ((ft_strncmp(str_arr[0], "R", 1) == 0) && set->res_h == 0 && \
		len == 3)
		ret = parse_resolution(str_arr[1], str_arr[2], set, len);
	else if ((ft_strncmp(str_arr[0], "NO", 2) == 0) && set->no_texture == NULL && \
		len == 2)
		ret = texture_parser(str_arr[1], set, 1);
	else if ((ft_strncmp(str_arr[0], "SO", 2) == 0) && set->so_texture == NULL && \
		len == 2)
		ret = texture_parser(str_arr[1], set, 2);
	else if ((ft_strncmp(str_arr[0], "WE", 2) == 0) && set->we_texture == NULL && \
		len == 2)
		ret = texture_parser(str_arr[1], set, 3);
	else if ((ft_strncmp(str_arr[0], "EA", 2) == 0) && set->ea_texture == NULL && \
		len == 2)
		ret = texture_parser(str_arr[1], set, 4);
	else if ((ft_strncmp(str_arr[0], "S", 1) == 0) && set->s_texture == NULL && \
		len == 2)
		ret = texture_parser(str_arr[1], set, 5);
	else if ((ft_strncmp(str_arr[0], "F", 1) == 0))
		ret = colour_parser(str_arr[1], set, 1);
	else if ((ft_strncmp(str_arr[0], "C", 1) == 0))
		ret = colour_parser(str_arr[1], set, 2);
	else
		return (file_exit(1));
	return (ret);
}

int open_file(char *name, s_set *set)
{
	char *ptr;
	int fd;
	char *line;
	char *tmp;
	int ret;
	int count;
	int flag;

	if ((check_name(name)) == 0)
		return (0);
	if ((fd = open(name, O_RDONLY)) == -1)
	{
		ft_putstr("Error\nBad file descriptor");
		return (0);
	}
	/*printf("name2 = %s\n", name);*/
	/*printf("fd = %d\n", fd);*/
	flag = 0;
	while ((ret = get_next_line(fd, &line)))
	{
		if ((check_set(*set) != 1) && line[0] != '\0')
		{
			setting_parser(line, set);
			/*if ((setting_parser(line, set) == 1))*/
				/*return (file_exit(1));*/
		}
		else if ((check_set(*set) == 1) && line[0] != '\0')
		{
			/*printf("On the way line = %s\n", line);*/
			init_map_parser(line, set, 0);
		}
		free(line);
	}
	init_map_parser(line, set, 1);
	return (0);
}

int main(int args, char **argv)
{
	int i;
	int n;
	s_set set;

	i = 1;
	set = init_set(set);
	if (args != 2)
		return (error_manager(1));
	else if (args == 2)
	{
		open_file(argv[1], &set);
		i++;
		return (0);
	}
}
