/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 10:49:21 by elovegoo          #+#    #+#             */
/*   Updated: 2020/05/27 14:16:59 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char *tmp;
	char *s;

	if (dest == src || n == 0)
		return (dest);
	tmp = (char *)dest;
	s = (char *)src;
	if (dest <= src)
	{
		while (n--)
			*tmp++ = *s++;
	}
	else
	{
		s += n;
		tmp += n;
		while (n--)
			*--tmp = *--s;
	}
	return (dest);
}
