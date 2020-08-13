/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 19:23:27 by elovegoo          #+#    #+#             */
/*   Updated: 2020/05/28 10:22:18 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char *tmp;

	tmp = (unsigned char *)src;
	if (n != 0)
	{
		while (n != 0)
		{
			if (*tmp++ == (unsigned char)c)
				return ((void *)(tmp - 1));
			n--;
		}
	}
	return (NULL);
}
