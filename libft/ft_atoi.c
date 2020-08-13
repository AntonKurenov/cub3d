/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 10:17:07 by elovegoo          #+#    #+#             */
/*   Updated: 2020/05/26 22:40:06 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(const char *str, size_t i)
{
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
			(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	return (i);
}

static int	checker(long min_int, long res, int p)
{
	if (p == -1)
	{
		if ((res * p) < min_int)
			return (1);
	}
	if (p == 1)
	{
		if (res > (min_int - (min_int * 2 + 1)))
			return (1);
	}
	return (0);
}

int			ft_atoi(const char *str)
{
	long		min_int;
	size_t		i;
	long		res;
	int			p;

	i = 0;
	p = 1;
	res = 0;
	min_int = -2147483648;
	i = i + is_space(str, i);
	p = (str[i] == '-') ? -1 : 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		res = 10 * res + (str[i] - '0');
		if (checker(min_int, res, p))
			return (-1);
		i++;
	}
	return ((int)p * res);
}
