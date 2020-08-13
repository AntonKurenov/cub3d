/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 22:09:51 by elovegoo          #+#    #+#             */
/*   Updated: 2020/06/11 11:34:43 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *ptr;
	unsigned char sym;

	ptr = (unsigned char *)b;
	sym = (unsigned char)c;
	while (len--)
		*ptr++ = sym;
	return (b);
}
