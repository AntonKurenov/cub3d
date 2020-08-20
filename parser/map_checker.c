/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:44:59 by elovegoo          #+#    #+#             */
/*   Updated: 2020/08/20 19:46:12 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static s_player init_player(s_player new)
{
	new.x = 0;
	new.y = 0;
	new.direct = 0;
	return (new);
}

static int check_up_and_down(char **map, int x, int y, int range)
{
	int i;
	int j;
	int flag;

	j = y;
	flag = 0;
	while (j >= 0)
	{
		j--;
		if (map[j][x] == ' ')
			return (1);
		if (map[j][x] == '1')
		{
			flag++;
			break ;
		}
		/*printf("%c", map[j][x]);*/
	}
	i = y;
	while (i < range)
	{
		i++;
		if (map[i][x] == ' ')
			return (1);
		if (map[i][x] == '1')
			break ;
		/*printf("%c", map[i][x]);*/
	}
	if (j == 0 || i == range)
		return (1);
	return (0);
}

static int check_left_and_right(char **map, int x, int y, int line_len)
{
	int i;
	int j;

	j = x;
	while (j > 0)
	{
		j--;
		if (map[y][j] == ' ')
			return (1);
		if (map[y][j] == '1')
			break ;
		/*printf("%c", map[y][j]);*/
	}
	i = x;
	while (i < line_len)
	{
		if (map[y][i] == ' ')
			return (1);
		if (map[y][i] == '1')
			break ;
		/*printf("%c", map[y][i]);*/
		i++;
	}
	if (j == 0 || i == line_len)
		return (1);
	return (0);
}

void check_map_elem(char **map, int x, int y, int type)
{
	int i;
	int j;
	int flag;

	i = x;
	j = y;
	flag = 0;
	/*printf("inside check_map_elem\n");*/
	if (type == 1 || type == 2)
	{
		if ((check_up_and_down(map, x, y, arr_len(map))) != 0 && \
			(check_left_and_right(map, x, y, ft_strlen(map[y])) != 0))
			file_exit(1);
	}
	if (type == 3)
	{
		if ((check_up_and_down(map, x, y, arr_len(map))) == 0 && \
			(check_left_and_right(map, x, y, ft_strlen(map[y])) == 0))
			file_exit(1);
	}
}

int next_level_map_check(char **map, int len)
{
	int i;
	int j;
	s_player player;
	/*s_map map_param;*/

	/*map_param = init_map(map_param);*/
	player = init_player(player);
	i = 1;
	while (i < len - 1)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				j++;
			if (map[i][j] == '0' || map[i][j] == '2')
				check_map_elem(map, j, i, 1);
			if (map[i][j] == 'W' || map[i][j] == 'N' || \
				map[i][j] == 'E' || map[i][j] == 'S')
			{
				player.y = i;
				player.x = j;
				player.direct = map[i][j];
				check_map_elem(map, j, i, 2);
			}
			if (map[i][j] == ' ')
				check_map_elem(map, j, i, 3);
			printf("map_elem = %c ", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("really end\n");
	return (0);
}
