/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elovegoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 17:31:30 by elovegoo          #+#    #+#             */
/*   Updated: 2020/10/08 14:07:47 by elovegoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include "parser/get_next_line.h"
# include <stdio.h>
# include <math.h>

# define RAD_CONV 0.0174533
# define INV_RAD 57.2958
# define FOV 60
# define H_FOV 30
# define BUTTON_W 13
# define BUTTON_ESC 53
# define BUTTON_A 0
# define BUTTON_S 1
# define BUTTON_D 2
# define ARR_LEFT 123
# define ARR_RIGHT 124
# define PI 3.1415
# define B_SIZE 64.0
# define TURN_ANG 4
# define STEP 7

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
	int spr_num;
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

typedef struct s_tex
{
	int		flag;
	char	*name;
	int		*t_addr;
	void	*t_img;
	int		bpp;
	int		s_line;
	int		end;
	int		h;
	int		w;
	int		sq_vert;
	int		sq_hor;
}			t_tex;

typedef struct s_spr
{
	//char	*name;
	int		pos;
	int		x;
	double	new_x;
	int		y;
	double	new_y;
	int		flag;
	int		start_i;
	int		end_i;
	double	diff_ang_start;
	double	diff_ang_end;
	double	diff_start;
	double	diff_end;
	double	dist;
	double	height;
	double	half_height;
	double	angle;
	double	strt_angle;
	double	mid_angle;
	double	end_angle;
	int		st_flag;
	int		end_flag;
	double	step_x;
	double	tmp_step_x;
	double	tmp_step_y;
	double	tmp_y;
	double	step_y;
	double 	old_y;
	int		color;
}			t_spr;	

typedef struct	s_data 
{
	t_set	*set;
	t_player *player;
	t_tex		*textr[4];
	double	*dist_arr;
	t_spr	**spr;
	void	*spr_img;
	int		spr_h;
	int		spr_w;
	int		spr_in_view;		
	int 	matr_size;
	int		*spr_addr;
	int		spr_bpp;
	int		spr_line;
	int		num_spr;	
	char	*spr_name;
	double	pos_x;
	double	pos_y;
	int		angle;
	int		i;
	int		map_h;
	int		map_w;
	int		act_map_h;
	int		act_map_w;
	double	cur_angle;
	double	start_ang;
	int		flag_start;
	double	end_ang;
	int		flag_end;
	char	**map;
	void	*img;
	int		*addr;
	int 	bits_per_pixel;
	int 	line_length;
	int 	endian;
	void 	*mlx;
	void	*mlx_win;
	int		res_h;
	int		half_res;
	int		res_w;
	double	part_angle;
	double	plane_dist;
	double	tang;
	int		map_chk_ret;
	double	init_a_x;
	double	init_a_y;
	int		flag;
	double	step_ang;
	double	vert_len;
	double	hor_len;
	double	hor_x;
	double	hor_y;
	double	vert_x;
	double	vert_y;
	double	h_a_x;
	double	h_a_y;
	double	v_a_x;
	double	v_a_y;
	double	map_size_y;
	double	map_size_x;
	int		is_vert;
	double	percent;
	int		pph;
	int		place;
	int		vert_flag;
	int		floor;
	int		ceil;
	int		new_x;
	int		new_y;
}			t_data;

typedef struct s_angle
{
	int 	init_angle;
	int		new_angle;
	double	new_x;
	double	new_y;
	int		mid_angle;
	int		key;
}			t_angle;

int 	texture_parser(char *line, t_set *set, int type);
int 	error_manager(int num);
int 	check_name(char *name);
int		atoi_str_color(char **str);
int		atoi_str_res(char **str);
int 	colour_parser(char *line, t_set *set, int type);
void 	init_map_parser(char *line, t_set *set, int flag);
int 	arr_len(char **str_arr);
int 	file_exit(int flag);
int 	next_level_map_check(char **map, int len, t_map *map_sp, t_player *player);
char 	**map_preparation(char **map, int arr_len, t_map *map_specs);
t_player init_player(t_player new);
t_col 	init_colours();
t_set	init_set(t_set set);
t_map 	init_map_specs(t_map map);
void 	init_engine(t_player *player, t_set *set, t_map *map_specs, char **map);
t_data	init_img(t_data new, t_player *player, t_map *map_specs, t_set *set);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_walls(t_data *data, double len);
void 	receiver(t_data *data);
int 	convert_coordinates(t_data *data, int flag);
void 	reset_data(t_data *data);
void 	get_horiz_inter(t_data *data, int flag);
void 	get_vert_inter(t_data *data, int flag);
int 	check_map(t_data *data, double x, double y);
void 	close_win(t_data *data);
void 	turn_left(t_data *data);
void 	turn_right(t_data *data);
void 	move_s_and_w(t_data *data, t_angle *ang);
t_angle reset_angle(t_angle ang, t_data *data, int key);
void 	convert_angle(t_angle *ang);
void 	move_d_and_a(t_data *data, t_angle *ang);
void	open_textr(t_data *data);
double	get_percent(t_data *data, double len);
void	get_textr_addr(t_data *data, int wall_len, int i);
void	which_texture(t_data *data, double len, int flag);
int		check_map_for_inter(t_data *data, double x, double y);
void	get_colour(t_data *data);
void	draw_ceil_and_floor(t_data *data, double wall_len);
void	init_sprites(t_data *data, char **map);
void	fill_spr(t_data *data, char **map);
void	init_sprites(t_data *data, char **map);
void	sprt_work(t_data *data);
void	check_sprites(t_data *data, t_spr *spr);
//void 	check_map_for_sprt(t_data *data, int x, int y);
int 	get_flag(double pl_x, double pl_y, double spr_x, double spr_y);
int 	get_diff(double num1, int num2);
void	get_sprt_angle(t_data *data, t_spr *spr, double angle, double len);
void	reset_sprite(t_data *data, t_spr *spr);
int	get_ang_flag(double angle);
void	draw_sprt(t_data *data, t_spr spr, double height);

#endif
