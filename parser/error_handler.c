/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 17:29:07 by elovegoo          #+#    #+#             */
/*   Updated: 2020/08/16 17:35:55 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int error_manager(int num)
{
	if (num == 1)
		ft_putstr("Error\nNo argument provided\n");
	return (1);
}

int extension_comp(char *name, int len)
{
	char *extension;
	char *ptr;
	int i;

	i = 0;
	ptr = (name + len - 4);
	/*printf("ptr = %s\n", ptr);*/
	extension = ".cub";
	while (extension[i] == ptr[i] && ptr[i])
		i++;
	/*printf("i = %d\n", i);*/
	if (i == 4)
		return (1);
	return (0);
}

int check_name(char *name)
{
	int len;

	if ((len = ft_strlen(name)) < 4)
	{
		ft_putstr("Error\nWrong file name");
		return (0);
	}
	if (extension_comp(name, len) == 1)
		return (1);
	else
		ft_putstr("Error\nWrong file extension");
	return (0);
}
