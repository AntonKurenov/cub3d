/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 14:26:00 by elovegoo          #+#    #+#             */
/*   Updated: 2020/10/14 11:16:35 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	*dup_with_new_line(const char *s)
{
	char	*dup_s;
	int		i;
	int		len;

	len = -1;
	i = 0;
	while (s[++len])
	{
		if (s[len] == '1' || s[len] == '0' || s[len] == ' ')
			i++;
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

static int	blank_line(const char *line)
{
	int			i;
	static int	flag;

	i = -1;
	if (flag == 1)
		check_last_line((char *)line);
	while (line[++i])
	{
		if (line[i] != ' ')
			break ;
	}
	if (line[i] != '\0')
	{
		flag = 0;
		return (1);
	}
	else
		flag = 1;
	return (0);
}

static void	map_checker(char **map, t_set *set)
{
	int			i;
	int			len;
	t_player	player;
	t_map		map_specs;

	init_player(&player);
	init_map_specs(&map_specs);
	i = 0;
	len = arr_len(map);
	map = map_preparation(map, len, &map_specs);
	while (map[i])
		i++;
	next_level_map_check(map, len, &map_specs, &player);
	init_engine(&player, set, &map_specs, map);
}

static int	map_parser(char **line, t_set *set)
{
	int		len;
	char	**map;

	map = ft_split(*line, '\n');
	del_str(line);
	len = arr_len(map);
	map_checker(map, set);
	return (0);
}

void		init_map_parser(char *line, t_set *set, int flag)
{
	static char		*str;
	char			*new_line;

	if (flag == 1)
	{
		map_parser(&str, set);
		return ;
	}
	if (blank_line(line) == 1)
	{
		new_line = dup_with_new_line(line);
		str = str_join(str, new_line);
		free(new_line);
	}
}
