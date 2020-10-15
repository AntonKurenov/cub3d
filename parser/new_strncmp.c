/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_strncmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 20:31:10 by elovegoo          #+#    #+#             */
/*   Updated: 2020/10/13 20:37:34 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		new_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	size_t			i;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (1);
	while ((s2[i] != '\0' || s1[i] != '\0') && i < n)
	{
		if (tmp1[i] != tmp2[i])
			return ((int)(tmp1[i] - tmp2[i]));
		i++;
	}
	return (0);
}
