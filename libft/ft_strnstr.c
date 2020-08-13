/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 21:38:13 by elovegoo          #+#    #+#             */
/*   Updated: 2020/05/28 14:19:33 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		k;
	size_t		i;
	size_t		a;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (i < len && big[i])
	{
		k = 0;
		a = i;
		if (little[k] == big[a])
		{
			while (little[k] == big[a] && a < len && big[a])
			{
				k++;
				a++;
			}
			if (k == ft_strlen(little))
				return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}
