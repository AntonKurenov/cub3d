/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 17:29:07 by elovegoo          #+#    #+#             */
/*   Updated: 2020/10/12 16:16:58 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		error_manager(int num)
{
	if (num == 1)
		ft_putstr("Error\nNo argument provided\n");
	return (1);
}

int		extension_comp(char *name, int len)
{
	char	*extension;
	char	*ptr;
	int		i;

	i = 0;
	ptr = (name + len - 4);
	extension = ".cub";
	while (extension[i] == ptr[i] && ptr[i])
		i++;
	if (i == 4)
		return (1);
	return (0);
}

int		file_exit(int flag)
{
	if (flag == 0)
		ft_putstr("Error\nBad file descriptor\n");
	if (flag == 1)
		ft_putstr("Error\nInvalid map\n");
	if (flag == 2)
		ft_putstr("Error\nMemory allocation fail\n");
	if (flag == 3)
		ft_putstr("Error\nWrong color format\n");
	if (flag == 4)
		ft_putstr("Error\nInvalid resolution settings\n");
	if (flag == 5)
		ft_putstr("Error\nWrong third argument\n");
	if (flag == 6)
		ft_putstr("Error\nFailed to write screenshot\n");
	if (flag == 7)
		ft_putstr("Error\nMLX return NULL\n");
	if (flag == 8)
		ft_putstr("Screenshot saved to ./screenshot.bmp\n");
	if (flag == 9)
		ft_putstr("Error\nWrong number of arguments\n");
	if (flag == 10)
		ft_putstr("Error\nThe texture file doesn't open\n");
	exit(0);
}

int		check_name(char *name)
{
	int len;
	int fd;

	fd = 0;
	if ((len = ft_strlen(name)) < 4)
	{
		ft_putstr("Error\nWrong file name\n");
		exit(0);
	}
	if (extension_comp(name, len) == 1)
	{
		if ((fd = open(name, O_RDONLY)) == -1)
			file_exit(0);
		return (fd);
	}
	else
	{
		ft_putstr("Error\nWrong file extension\n");
		exit(0);
	}
	return (fd);
}
