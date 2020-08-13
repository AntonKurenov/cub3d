/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 20:03:28 by elovegoo          #+#    #+#             */
/*   Updated: 2020/05/28 14:44:41 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		len_measurer(long n)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void		write_num(char *res, long num, int len, int neg)
{
	res[len] = '\0';
	res[--len] = num % 10 + '0';
	num /= 10;
	while (num > 0)
	{
		res[--len] = num % 10 + '0';
		num /= 10;
	}
	res[0] = (neg == 1) ? '-' : res[0];
}

char			*ft_itoa(int n)
{
	int		neg;
	char	*res;
	long	num;
	int		len;

	num = (n < 0) ? ((long)n * -1) : ((long)n);
	neg = (n < 0) ? 1 : 0;
	len = len_measurer(num) + neg;
	if (!(res = malloc(len + 1)))
		return (NULL);
	write_num(res, num, len, neg);
	return (res);
}
