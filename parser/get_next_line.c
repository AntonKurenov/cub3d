/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 12:18:14 by elovegoo          #+#    #+#             */
/*   Updated: 2020/08/11 17:29:04 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		new_line(char *rem, char **line)
{
	int		i;
	char	*str;

	if (!rem)
		return (0);
	i = 0;
	while (rem[i] && rem[i] != '\n')
		i++;
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (rem[i] && rem[i] != '\n')
	{
		str[i] = rem[i];
		i++;
	}
	str[i] = '\0';
	*line = str;
	return (1);
}

static char	*rem_check(char *rem, char **line)
{
	int		len;
	int		rem_len;

	if (!rem)
		return (0);
	len = ft_strlen(*line);
	rem_len = ft_strlen(rem);
	if (rem[len] == '\0')
	{
		free(rem);
		return (0);
	}
	ft_memmove(rem, (rem + len + 1), (rem_len - len));
	rem[rem_len - len] = '\0';
	return (rem);
}

static int		finder(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*rem;
	int			total;
	char		*buff;

	if (fd < 0 || BUFF_SIZE < 1 || !line)
		return (-1);
	if (!(buff = malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	total = 1;
	while (!(finder(rem)) && total != 0)
	{
		if ((total = read(fd, buff, BUFF_SIZE)) == -1)
			return (error_handler(buff, &rem));
		buff[total] = '\0';
		if (!(rem = str_join(rem, buff)))
			return (error_handler(buff, &rem));
	}
	free(buff);
	if ((new_line(rem, line) == -1))
		return (error_handler(rem, line));
	rem = rem_check(rem, line);
	if (total == 0)
		return (0);
	return (1);
}
