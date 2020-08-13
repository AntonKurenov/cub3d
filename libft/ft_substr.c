/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 11:59:55 by elovegoo          #+#    #+#             */
/*   Updated: 2020/05/30 14:28:47 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		str_len;
	size_t		i;
	char		*str;

	if (!s)
		return (NULL);
	i = 0;
	str_len = ft_strlen(s);
	if (str_len < start)
	{
		if (!(str = malloc(sizeof(char) * 1)))
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
