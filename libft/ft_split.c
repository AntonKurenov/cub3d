/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 16:01:43 by elovegoo          #+#    #+#             */
/*   Updated: 2020/05/30 13:51:38 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(char const *s, char c)
{
	size_t		w;
	size_t		i;
	int			flag;

	w = 0;
	flag = 1;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && flag == 0)
			flag = 1;
		if (s[i] != c && flag == 1)
		{
			w++;
			flag = 0;
		}
		i++;
	}
	return (w);
}

static size_t	word_len(char const *s, char c, size_t i)
{
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static size_t	thinker(char const *s, char **arr, char c)
{
	size_t	len_s;
	size_t	count_w;
	size_t	i;

	i = 0;
	count_w = 0;
	len_s = ft_strlen(s);
	while (i < len_s)
	{
		if (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			if (!(arr[count_w] = ft_substr(s, i, (word_len(s, c, i) - i))))
				return (0);
			count_w++;
			i = word_len(s, c, i);
		}
	}
	return (count_w);
}

char			**ft_split(char const *s, char c)
{
	size_t	word;
	char	**arr;

	if (!s)
		return (ft_split("", c));
	word = word_count(s, c);
	if (!(arr = (char**)malloc((word + 1) * sizeof(char*))) || !s)
		return (NULL);
	if (thinker(s, arr, c) != word)
	{
		while (word)
		{
			free(arr[word]);
			word--;
		}
		free(arr);
		return (NULL);
	}
	arr[word] = NULL;
	return (arr);
}
