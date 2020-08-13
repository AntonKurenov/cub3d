/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 10:47:58 by elovegoo          #+#    #+#             */
/*   Updated: 2020/05/28 10:49:26 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		filter(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
		ft_putchar_fd('0', fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	c[10];

	if (fd < 0)
		return ;
	if (n == 0 || n == -2147483648)
	{
		filter(n, fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	i = 0;
	while (n > 0)
	{
		c[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	i--;
	while (i >= 0)
		ft_putchar_fd(c[i--], fd);
}
