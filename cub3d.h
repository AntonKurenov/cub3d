/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 17:31:30 by elovegoo          #+#    #+#             */
/*   Updated: 2020/09/01 15:43:59 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include "parser/get_next_line.h"
# include <stdio.h>

# define RAD_CONV 0.0174533
# define FOV 60
# define H_FOV 30
# define BUTTON_W 13
# define BUTTON_A 0
# define BUTTON_S 1
# define BUTTON_D 2
# define ARR_LEFT 123
# define ARR_RIGHT 124
# define PI 3.1415

typedef struct s_colours
{
	int f_red;
	int f_green;
	int f_blue;
	int ce_red;
	int ce_green;
	int ce_blue;
}		t_col;

typedef struct s_player
{
	int x;
	int y;
	char direct;
}		t_player;

typedef struct s_map
{
	int width;
	int height;
	//int x;
	//int y;
}		t_map;

typedef struct s_set
{
	t_col colour;
	int res_w;
	int res_h;
	char *no_texture;
	char *so_texture;
	char *we_texture;
	char *ea_texture;
	char *s_texture;
} 				t_set;

typedef struct	s_data 
{
	t_set	*set;
	t_player *player;
	int		x;
	int		y;
	int		angle;
	char	**map;
	void	*img;
	char	*addr;
	int 	bits_per_pixel;
	int 	line_length;
	int 	endian;
	void 	*mlx;
	void	*mlx_win;
	int		res_h;
	int		res_w;
	double	part_angle;
}			t_data;

int texture_parser(char *line, t_set *set, int type);
int error_manager(int num);
int check_name(char *name);
int	atoi_str(char **str);
int colour_parser(char *line, t_set *set, int type);
void init_map_parser(char *line, t_set *set, int flag);
int arr_len(char **str_arr);
int file_exit(int flag);
int next_level_map_check(char **map, int len, t_map map_sp, t_player *player);
char **map_preparation(char **map, int arr_len, t_map *map_specs);
t_player init_player(t_player new);
t_col init_colours();
t_set	init_set(t_set set);
t_map init_map_specs(t_map map);
void init_engine(t_player *player, t_set *set, t_map *map_specs, char **map);
t_data	init_img(t_data new, t_player *player, char **map, t_set *set);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
