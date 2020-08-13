/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 14:58:15 by elovegoo          #+#    #+#             */
/*   Updated: 2020/05/30 14:48:08 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	comparator_one(char const *str, char const *set, size_t st, \
		size_t finish)
{
	size_t	a;
	size_t	count;
	size_t	n;

	n = 0;
	while (st < finish)
	{
		a = 0;
		count = 0;
		while (set[a])
		{
			if (str[st] == set[a])
			{
				count++;
				break ;
			}
			a++;
		}
		if (count == 0)
			break ;
		n++;
		st++;
	}
	return (n);
}

static size_t	comparator_two(char const *str, char const *set, size_t st, \
		size_t finish)
{
	size_t		a;
	size_t		count;
	size_t		n;

	n = 0;
	while (st > finish)
	{
		a = 0;
		count = 0;
		while (set[a])
		{
			if (str[st] == set[a])
			{
				count++;
				break ;
			}
			a++;
		}
		if (count == 0)
			break ;
		n++;
		st--;
	}
	return (n);
}

static char		*writer(char const *s1, size_t start, size_t finish)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!(str = malloc(finish - start + 1)))
		return (NULL);
	while (start < finish)
	{
		str[i] = s1[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	start;
	size_t	finish;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	start = comparator_one(s1, set, 0, len);
	finish = len - comparator_two(s1, set, len - 1, start);
	return (writer(s1, start, finish));
}
