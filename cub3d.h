/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 17:31:30 by elovegoo          #+#    #+#             */
/*   Updated: 2020/08/13 16:36:20 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "parser/get_next_line.h"
# include <stdio.h>

typedef struct t_files
{
	char *no;
	char *so;
	char *we;
	char *ea;
	char *s;
}		s_files;

typedef struct t_set
{
	int res_w;
	int res_h;
	char *no_texture;
	char *so_texture;
	char *we_texture;
	char *ea_texture;
	char *s_texture;
	char *fl_texture;
	char *c_texture;
} 				s_set;

int texture_parser(char **line, s_set *set, int type);
int error_manager(int num);
int check_name(char *name);

#endif
