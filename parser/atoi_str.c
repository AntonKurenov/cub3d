/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 15:00:42 by elovegoo          #+#    #+#             */
/*   Updated: 2020/10/10 20:33:53 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		atoi_str_res(char **str)
{
	unsigned int	ret;

	ret = 0;
	while (**str == ' ')
		(*str)++;
	if (**str == '-' || **str == '+' || (**str < '0' && **str > '9'))
		file_exit(4);
	while (**str >= '0' && **str <= '9' && **str)
	{
		ret = ret * 10 + (**str - '0');
		if (ret >= 1000000)
		{
			while (**str >= '0' && **str <= '9')
				(*str)++;
			if (**str != ' ' && **str != '\0')
				file_exit(4);
			return (-2);
		}
		(*str)++;
	}
	return (ret);
}

int		atoi_str_color(char **str)
{
	unsigned int	ret;
	int				flag;

	flag = 0;
	ret = 0;
	(*str)++;
	while (**str == ' ')
		(*str)++;
	if (**str == '-' || **str == '+' || (**str < '0' && **str > '9'))
		file_exit(3);
	while (**str >= '0' && **str <= '9' && **str)
	{
		if (**str == '0' && flag == 0)
			flag = 1;
		if (**str != '0' && flag == 1)
			flag = 0;
		ret = ret * 10 + (**str - '0');
		if (ret >= 1000)
			file_exit(3);
		(*str)++;
		if (**str == '0' && flag == 1)
			file_exit(3);
	}
	return (ret);
}
