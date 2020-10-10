/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_preparation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 17:26:36 by elovegoo          #+#    #+#             */
/*   Updated: 2020/10/10 17:29:01 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void check_last_line(char *str)
{
	int i;
	int flag;
	char ptr;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '1')
			file_exit(1);
		i++;
	}
}

static void check_right_side(char *str, int len)
{
	int i;
	int flag;

	printf("inside check_right_side\n");
	i = len - 1;
	flag = 0;
	printf("check rs len = %d\n", len);
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
	printf("inside check_right_side\n");
}

/*
 * Returns the length and check the line for forbidden symbols and also check
 * left side of the map.
 */

static int get_len_and_check(char *str)
{
	char *line;
	int i;
	int flag;
	char *ptr;
	char *line_2;

	i = 0;
	flag = 0;
	line = "201 NEWS";
	line_2 = "201NEWS";
	printf("inside get_len_and_check\n");
	while (str[i])
	{
		if ((ft_strchr(line, str[i])) == NULL)
		{
			printf("str[%d] = %c\n", i, str[i]);
			file_exit(1);
		}
		if (str[i] == '1')
		{
			flag++;
		}
		if ((ptr = ft_strchr(line_2, str[i])) != NULL && flag == 0)
			file_exit(1);
		i++;
	}
	check_right_side(str, i);
	return (i);
}

static void line_filler(char **line, int len)
{
	int i;
	char *new_line;
	char *tmp;

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

char **map_preparation(char **map, int arr_len, t_map *map_specs)
{
	int len;
	int i;
	int max_len;

	i = 0;
	max_len = 0;
	while (i < arr_len)
	{
		if ((len = get_len_and_check(map[i])) > max_len)
			max_len = len;
		i++;
	}
	check_last_line(map[i - 1]);
	map_specs->width = max_len;
	map_specs->height = arr_len;
	i = 0;
	printf("end of the map_preparation\n");
	while (i < arr_len)
	{
		if ((len = ft_strlen(map[i])) != max_len)
			line_filler(&map[i], max_len);
		printf("%s\n", map[i]);
		i++;
	}
	printf("end of the map_preparation\n");
	return (map);
}
