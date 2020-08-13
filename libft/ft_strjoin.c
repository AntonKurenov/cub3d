/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 14:27:42 by elovegoo          #+#    #+#             */
/*   Updated: 2020/05/28 14:32:51 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	char	*str;

	i = 0;
	len1 = 0;
	len2 = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(str = malloc(len1 + len2 + 1)))
		return (NULL);
	while (i <= len1)
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i <= len2)
	{
		str[i + len1] = s2[i];
		i++;
	}
	str[len1 + len2 + 1] = '\0';
	return (str);
}
