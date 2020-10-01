/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 14:26:00 by elovegoo          #+#    #+#             */
/*   Updated: 2020/09/30 16:33:07 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	*dup_with_new_line(const char *s)
{
	char	*dup_s;
	int	i;
	int len;

	len = 0;
	i = 0;
	while (s[len])
	{
		if (s[len] == '1' || s[len] == '0')
			i++;
		len++;
	}
	if (i == 0)
		file_exit(1);
	if (!(dup_s = malloc((len + 2))))
		return (NULL);
	i = 0;
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
 * map_checker with helps two other functions 
 */

static void map_checker(char **map, t_set *set)
{
	int i;
	int j;
	int len;
	t_player player;
	t_map map_specs;

	player = init_player(player);
	map_specs = init_map_specs(map_specs);
	i = 0;
	len = arr_len(map);
	printf("len = %d\n", len);
	map = map_preparation(map, len, &map_specs);
	while (map[i])
	{
		printf("map = %s|\n", map[i]);
		i++;
	}
	next_level_map_check(map, len, &map_specs, &player);
	init_engine(&player, set, &map_specs, map);
}

static int map_parser(char **line, t_set *set)
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

void init_map_parser(char *line, t_set *set, int flag)
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
	str = str_join(str, new_line);
	printf("after str_join str = %s\n", str);
}
