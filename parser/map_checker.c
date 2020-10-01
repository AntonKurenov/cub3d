/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:44:59 by elovegoo          #+#    #+#             */
/*   Updated: 2020/09/30 16:33:07 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void check_map_elem(char **map, int x, int y, t_player *player)
{
	char *str;
	char *pl;

	str = "021NEWS";
	pl = "NEWS";
	printf("map[%d][%d] = %c\n", y, x, map[y][x]);
	if ((ft_strchr(pl, map[y][x]) != NULL) && player->x != 0)
		file_exit(1);
	if ((ft_strchr(pl, map[y][x]) != NULL) && player->x == 0)
	{
		player->direct = map[y][x];
		player->x = x;
		player->y = y;
	}
	if ((ft_strchr(str, map[y][x - 1])) == NULL)
		file_exit(1);
	if ((ft_strchr(str, map[y][x + 1])) == NULL)
		file_exit(1);
	if ((ft_strchr(str, map[y - 1][x])) == NULL)
		file_exit(1);
	if ((ft_strchr(str, map[y + 1][x])) == NULL)
		file_exit(1);
}

int next_level_map_check(char **map, int len, t_map *map_sp, t_player *player)
{
	int i;
	int j;

	len -= 1;
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '1')
				j++;
			if (map[i][j] == ' ')
				j++;
			if (map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'E' || \
					map[i][j] == 'S')
				check_map_elem(map, j, i, player);
			if (map[i][j] == '0' || map[i][j] == '2')
				check_map_elem(map, j, i, player);
			if (map[i][j] == '2')
				map_sp->spr_num++;
		}
	}
	printf("map_sp.spr_num = %d\n", map_sp->spr_num);
	printf("really end!!!!!\n");
	return (0);
}
