/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_each_cell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 12:55:17 by elovegoo          #+#    #+#             */
/*   Updated: 2020/09/26 14:56:07 by elovegoo         ###   ########.fr       */
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
