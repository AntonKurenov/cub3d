/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_each_cell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 12:55:17 by elovegoo          #+#    #+#             */
/*   Updated: 2020/08/24 14:41:18 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void check_around(char **map, int x, int y)
{
	int i;
	int j;
	char *str;

	str = "021NEWS";
	if ((ft_strchr(str, map[y][x-1])) == NULL)
		file_exit(1);
	if ((ft_strchr(str, map[y][x+1])) == NULL)
		file_exit(1);
	if ((ft_strchr(str, map[y-1][x])) == NULL)
		file_exit(1);
	if ((ft_strchr(str, map[y+1][x])) == NULL)
		file_exit(1);
}

int check_left(char *line, int j)
{
	int i;
	char *str;

	str = "021NEWS";
	i = 0;
	while (i < j)
	{
		if (ft_strchr(str, line[i]) != NULL)
			break ;
		i++;
	}
	if (j == i)
		return (1);
	return (0);
}

int check_right(char *line, int j, int len)
{
	int i;
	char *str;

	str = "021NEWS";
	while (j < len)
	{
		if (ft_strchr(str, line[j]) != NULL)
			break ;
		j--;
	}
	if (j == len)
		return (1);
	return (0);
}

int check_up(char **map, int y, int x)
{
	char *str;
	int i;

	str = "021NEWS";
	i = y;
	while (i > 0)
	{
		if (ft_strchr(str, map[i][x]) != NULL)
			break ;
		i--;
	}
	if (i == 0)
		return (1);
	return (0);
}

int check_down(char **map, int y, int x, int len)
{
	char *str;
	int i;

	str = "021NEWS";
	i = y;
	while (i < len)
	{
		if (ft_strchr(str, map[i][x]) != NULL)
			break ;
		i--;
	}
	if (i == 0)
		return (1);
	return (0);
}
