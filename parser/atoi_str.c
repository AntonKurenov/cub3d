/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 15:00:42 by elovegoo          #+#    #+#             */
/*   Updated: 2020/10/20 17:23:08 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	skipping_spaces(char **str)
{
	while (**str == ' ')
		(*str)++;
}

int			atoi_str_res(char **str)
{
	unsigned int	ret;

	ret = 0;
	skipping_spaces(str);
	if (**str == '-' || **str == '+' || **str < '0' || **str > '9')
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
	if (**str != '\0')
		file_exit(4);
	return (ret);
}

void		check_numbers(char *str)
{
	int num_count;

	num_count = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			num_count++;
			while (*str >= '0' && *str <= '9')
				str++;
		}
		str++;
	}
	if (num_count != 3)
		file_exit(3);
}

void		check_colors(char *str)
{
	int count;

	count = 0;
	while (*str)
	{
		if (*str == ',')
			count++;
		if (count > 2)
			file_exit(3);
		if (*str != ' ' && *str != ',' && (*str < '0' || *str > '9'))
			file_exit(3);
		str++;
	}
}

int			atoi_for_color(char *str)
{
	unsigned int	ret;
	int				flag;

	flag = 0;
	ret = 0;
	skipping_spaces(&str);
	while (*str >= '0' && *str <= '9' && *str)
	{
		if (*str == '0' && flag == 0)
		{
			if (*(++str) >= '0' && *str <= '9')
				file_exit(3);
			break ;
		}
		if (*str != '0')
			flag = 1;
		ret = ret * 10 + (*str - '0');
		if (ret >= 300)
			file_exit(3);
		(str)++;
	}
	skipping_spaces(&str);
	if (*str != '\0')
		file_exit(3);
	return (ret);
}
