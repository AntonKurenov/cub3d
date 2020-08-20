/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 17:31:30 by elovegoo          #+#    #+#             */
/*   Updated: 2020/08/19 16:58:54 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "parser/get_next_line.h"
# include <stdio.h>

typedef struct t_colours
{
	int f_red;
	int f_green;
	int f_blue;
	int ce_red;
	int ce_green;
	int ce_blue;
}		s_col;

typedef struct t_player
{
	int x;
	int y;
	char direct;
}		s_player;

typedef struct t_map
{
	int width;
	int height;
	int x;
	int y;
}		s_map;

typedef struct t_set
{
	s_col colour;
	int res_w;
	int res_h;
	char *no_texture;
	char *so_texture;
	char *we_texture;
	char *ea_texture;
	char *s_texture;
} 				s_set;

int texture_parser(char *line, s_set *set, int type);
int error_manager(int num);
int check_name(char *name);
int	atoi_str(char **str);
int colour_parser(char *line, s_set *set, int type);
void init_map_parser(char *line, s_set *set, int flag);
int arr_len(char **str_arr);
int file_exit(int flag);
int next_level_map_check(char **map, int len);

#endif
