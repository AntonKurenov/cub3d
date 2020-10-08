/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 15:00:42 by elovegoo          #+#    #+#             */
/*   Updated: 2020/10/08 15:13:09 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	atoi_str_res(char **str)
{
	unsigned int ret;
	int m;

	ret = 0;
	m = 1;
	while (**str == ' ')
		(*str)++;
	if (**str == '-' || **str == '+' || (**str < '0' && **str > '9'))
	{
		m = -1;
		return (-1);
	}
	if (**str == '-' || **str == '+')
		(*str)++;
	while (**str >= '0' && **str <= '9' && **str)
	{
		ret = ret * 10 + (**str - '0');
		if (ret >= 10000)
			return (0);
		(*str)++;
	}
	return (ret * m);
}

int	atoi_str_color(char **str)
{
	unsigned int ret;
	int m;

	ret = 0;
	m = 1;
	while (**str == ' ')
		(*str)++;
	if (**str == '-' || **str == '+' || (**str < '0' && **str > '9'))
	{
		m = -1;
		return (-1);
	}
	if (**str == '-' || **str == '+')
		(*str)++;
	while (**str >= '0' && **str <= '9' && **str)
	{
		ret = ret * 10 + (**str - '0');
		if (ret >= 1000)
			return (-1);
		(*str)++;
	}
	return (ret * m);
}
