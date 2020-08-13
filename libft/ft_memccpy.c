/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 19:28:32 by elovegoo          #+#    #+#             */
/*   Updated: 2020/05/13 21:05:46 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t len)
{
	unsigned char sym;
	unsigned char *d;
	unsigned char *s;

	sym = (unsigned char)c;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (len--)
	{
		*d++ = *s++;
		if (*(d - 1) == sym)
			return (d);
	}
	return (NULL);
}
