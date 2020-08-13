/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 14:07:28 by elovegoo          #+#    #+#             */
/*   Updated: 2020/05/11 16:09:13 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*pos;

	pos = NULL;
	while (*str != '\0')
	{
		if (*str == (char)c)
			pos = (char *)str;
		str++;
	}
	if (*str == (char)c)
		return ((char*)str);
	return (pos);
}
