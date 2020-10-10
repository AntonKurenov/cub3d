/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screenshot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 10:49:31 by elovegoo          #+#    #+#             */
/*   Updated: 2020/10/10 11:22:38 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    write_pixel(int num, unsigned char *arr)
{
	arr[0] = (unsigned char)(num & 255);
	arr[1] = (unsigned char)((num >> 8) & 255);
	arr[2] = (unsigned char)((num >> 16) & 255);
	arr[3] = (unsigned char)((num >> 24) & 255);
}

void    write_header(t_data *data, unsigned char *bytes, int bmpsize)
{
	int	pixels_per_meter;

	bytes[0] = 'B';
	bytes[1] = 'M';
	write_pixel(bmpsize, bytes + 2);
	bytes[10] = (unsigned char)54;
	bytes[14] = (unsigned char)40;
	write_pixel(data->res_w, bytes + 18);
	write_pixel(data->res_h, bytes + 22);
	bytes[26] = (unsigned char)1;
	bytes[28] = (unsigned char)32;
	bytes[34] = (unsigned char)32;
	pixels_per_meter = (int)((double)70 * 39.37);
	write_pixel(pixels_per_meter, bytes + 38);
	write_pixel(pixels_per_meter, bytes + 42);
}

void    write_image(t_data *data, unsigned char *bytes, int bmpsize)
{
	int	i;
	int	x;
	int	y;

	i = 54;
	y = data->res_h;
	while (y-- > 0)
	{
	    x = -1;
	    while (++x < data->res_w && i < bmpsize)
	    {
	        write_pixel(data->addr[y * data->res_w + x], bytes + i);
	        i += 4;
	    }
	}
	mlx_destroy_image(data->mlx, data->img);
	data->img = NULL;
}

void    get_screenshot(t_data *data)
{
	int             file;
	int             size;
	unsigned char   *bytes;

	file = open("./screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, \
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (file < 0)
		file_exit(6);
	size = data->res_w * data->res_h * 4 + 54;
	if (!(bytes = (unsigned char*)malloc(sizeof(unsigned char) * size)))
		file_exit(2);
	write_header(data, bytes, size);
	write_image(data, bytes, size);
	if (write(file, bytes, size) < size)
	{
		free(bytes);
		close(file);
		file_exit(6);
	}
	free(bytes);
	close(file);
	file_exit(8);
}
