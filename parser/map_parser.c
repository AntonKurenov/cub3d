/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 14:26:00 by elovegoo          #+#    #+#             */
/*   Updated: 2020/08/19 17:11:18 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	*dup_with_new_line(const char *s)
{
	char	*dup_s;
	size_t	i;

	i = 0;
	if (!(dup_s = malloc((ft_strlen(s) + 2))))
		return (NULL);
	while (s[i])
	{
		dup_s[i] = s[i];
		i++;
	}
	dup_s[i] = '\n';
	dup_s[i + 1] = '\0';
	return (dup_s);
}

/* 
 * First init_map_parser, next step is map_parser which generate
 * the two-dimensional array char **map, then that array processed in 
 * map_checker with helps two other functions is_only_one and 
 * next_level_map_check
 */

static void is_only_one(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			file_exit(1);
		i++;
	}
}

static void map_checker(char **map, s_set *set)
{
	int i;
	int j;
	int len;
	int start_wall;

	i = 0;
	len = arr_len(map) - 1;
	is_only_one(map[i]);
	is_only_one(map[len]);
	next_level_map_check(map, len);
}

static int map_parser(char **line, s_set *set)
{
	int i;
	int len;
	char **map;

	map = ft_split(*line, '\n');
	del_str(line);	
	len = arr_len(map);
	printf("end len = %d\n", len);
	map_checker(map, set);

	return (0);
}

void init_map_parser(char *line, s_set *set, int flag)
{
	static char *str;
	char *new_line;
	char *tmp;

	if (flag == 1)
	{
		map_parser(&str, set);
		return ;
	}
	new_line = dup_with_new_line(line);
	tmp = str;
	str = str_join(str, new_line);
	printf("after str_join str = %s\n", str);
	/*del_str(&tmp);*/
}
