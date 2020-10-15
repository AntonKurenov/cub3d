/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:19:00 by elovegoo          #+#    #+#             */
/*   Updated: 2020/10/13 20:38:35 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		parse_resolution(char *str1, char *str2, t_set *set, int len)
{
	if (len != 3)
		file_exit(4);
	if (((set->res_w = atoi_str_res(&str1)) == -1))
		file_exit(4);
	if (((set->res_h = atoi_str_res(&str2)) == -1))
		file_exit(4);
	return (0);
}

void	free_arr(char **arr)
{
	int i;

	i = -1;
	if (arr == NULL)
		return ;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	setting_parser(char *line, t_set *set)
{
	char	**arr;
	int		len;

	arr = ft_split(line, ' ');
	len = arr_len(arr);
	if ((new_strncmp(arr[0], "R", 1) == 0) && set->res_h == 0)
		parse_resolution(arr[1], arr[2], set, len);
	else if ((new_strncmp(arr[0], "NO", 2) == 0) && set->no_texture == NULL)
		texture_parser(arr[1], set, 1, len);
	else if ((new_strncmp(arr[0], "SO", 2) == 0) && set->so_texture == NULL)
		texture_parser(arr[1], set, 2, len);
	else if ((new_strncmp(arr[0], "WE", 2) == 0) && set->we_texture == NULL)
		texture_parser(arr[1], set, 3, len);
	else if ((new_strncmp(arr[0], "EA", 2) == 0) && set->ea_texture == NULL)
		texture_parser(arr[1], set, 4, len);
	else if ((new_strncmp(arr[0], "S", 1) == 0) && set->s_texture == NULL)
		texture_parser(arr[1], set, 5, len);
	else if ((new_strncmp(arr[0], "F", 1) == 0))
		colour_parser(&line, set, 1);
	else if ((new_strncmp(arr[0], "C", 1) == 0))
		colour_parser(&line, set, 2);
	else
		file_exit(1);
	free_arr(arr);
}
