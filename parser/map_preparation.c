/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_preparation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 17:26:36 by elovegoo          #+#    #+#             */
/*   Updated: 2020/10/14 11:22:20 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		check_last_line(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '1')
			file_exit(1);
		i++;
	}
}

static void	check_right_side(char *str, int len)
{
	int i;
	int flag;

	i = len - 1;
	flag = 0;
	while (i > 0)
	{
		while (str[i] == ' ' && i > 0)
			i--;
		if (str[i] == '1')
			break ;
		if (str[i] != '1')
			file_exit(1);
		i--;
	}
}

static int	get_len_and_check(char *str)
{
	char	*line;
	int		i;
	int		flag;
	char	*ptr;
	char	*line_2;

	i = 0;
	flag = 0;
	line = "201 NEWS";
	line_2 = "201NEWS";
	while (str[i])
	{
		if ((ft_strchr(line, str[i])) == NULL)
			file_exit(1);
		if (str[i] == '1')
			flag++;
		if ((ptr = ft_strchr(line_2, str[i])) != NULL && flag == 0)
			file_exit(1);
		i++;
	}
	check_right_side(str, i);
	return (i);
}

static void	line_filler(char **line, int len)
{
	int		i;
	char	*new_line;
	char	*tmp;

	i = 0;
	tmp = *line;
	if (!(new_line = ft_calloc(sizeof(char), (len + 1))))
		file_exit(2);
	while (tmp[i])
	{
		new_line[i] = tmp[i];
		i++;
	}
	while (i < len)
	{
		new_line[i] = ' ';
		i++;
	}
	new_line[i] = '\0';
	*line = new_line;
	free(tmp);
}

char		**map_preparation(char **map, int arr_len, t_map *map_specs)
{
	int len;
	int i;
	int max_len;

	i = -1;
	max_len = 0;
	while (++i < arr_len)
	{
		if (i == 0)
			check_last_line(map[i]);
		if ((len = get_len_and_check(map[i])) > max_len)
			max_len = len;
	}
	check_last_line(map[i - 1]);
	map_specs->width = max_len;
	map_specs->height = arr_len;
	i = -1;
	while (++i < arr_len)
	{
		if ((len = ft_strlen(map[i])) != max_len)
			line_filler(&map[i], max_len);
	}
	return (map);
}
