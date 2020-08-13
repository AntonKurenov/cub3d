/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 13:13:47 by elovegoo          #+#    #+#             */
/*   Updated: 2020/05/27 14:13:31 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	if (len == 0 || dest == src)
		return (dest);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (len--)
		*d++ = *s++;
	return (dest);
}
