/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 12:36:18 by elovegoo          #+#    #+#             */
/*   Updated: 2020/07/20 14:41:48 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	del_str(char **str)
{
	if (str)
	{
		free(*str);
		*str = NULL;
	}
}

int		error_handler(char *str, char **line)
{
	if (line)
		del_str(line);
	if (str)
		del_str(&str);
	return (-1);
}

size_t	ft_strlen(const char *s)
{
	size_t n;

	n = 0;
	if (!s)
		return (0);
	while (s[n])
		n++;
	return (n);
}

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

char	*str_join(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	len_all;
	char	*str;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len_all = len1 + len2;
	if (!(str = malloc(sizeof(char) * (len_all + 1))))
		return (0);
	ft_memmove(str, s1, len1);
	ft_memmove((str + len1), s2, len2);
	str[len_all] = '\0';
	free((char*)s1);
	return (str);
}
