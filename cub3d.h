/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egun <egun@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 01:30:37 by egun              #+#    #+#             */
/*   Updated: 2023/06/01 18:09:18 by egun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "./libft/libft.h"
# include "get_next_line.h"
# include "mathlib/mathlib.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define PX 1.3
# define PY 1.3
# define MAPWIDTH 10
# define MAPHEIGHT 10
# define CELLSIZE 64
# define GAMEWIDTH 600
# define GAMEHEIGHT 600
# define T_SKY 0x123456
# define T_FLOOR 0x654321

typedef enum e_keys
{
	Key_W = 13,
	Key_A = 0,
	Key_S = 1,
	Key_D = 2,
	Key_ESC = 53,
	key_up = 126,
	key_dn = 125,
	key_lt = 123,
	key_rt = 124
}					t_keys;

typedef enum e_map_xpm
{
	map = 1,
	int_map = 2,
	xpm = 4
}					t_map_xpm;

typedef enum e_side
{
	north,
	east,
	west,
	south
}					t_side;

typedef enum e_color
{
	flooor,
	ceiling
}					t_color;

//https://www.youtube.com/watch?v=gYRrGTC7GtA
//https://eastmanreference.com/complete-list-of-applescript-key-codes
//https://github.com/Saxsori/ray-cast

typedef struct s_control
{
	int				read_file;
	int				check_wall;
	int				get_map;
	int				set_map;
	int				player_pos;
}					t_control;

typedef struct s_vector2
{
	double			x;
	double			y;
}					t_vector2;

typedef struct s_int_vector2
{
	int				x;
	int				y;
}					t_int_vector2;

typedef struct s_llocation
{
	int				x;
	int				y;
}					t_llocation;

typedef struct s_ray_data
{
	t_vector2		ray_location;
	t_llocation		last_location;
	t_llocation		wall_location;
	t_vector2		for_wall;

}					t_ray_data;

typedef struct s_xpm
{
	void			*img;
	char			*img_ptr;
	int				bpp;
	int				line_len;
	int				endian;
	int				width;
	int				height;
}					t_xpm;

typedef struct s_imgdata
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
}					t_imgdata;

typedef struct s_direction
{
	char			c;
	int				angle;
}				t_direction;
typedef struct s_player
{
	t_vector2		pos;
	double			direction;
	double			fov;
}					t_player;

typedef struct s_mapdata
{
	char			**map;
	char			**map_clone;
	char			p_dic;
	t_vector2		p_start;
	int				map_height;
	int				map_width;
	char			*xpm_dir[4];
	int				colors[2][3];
	int				map_start;
	int				map_end;
	int				**int_map;
}					t_mapdata;

typedef struct s_data
{
	void			*mlx;
	void			*win4;
	t_imgdata		img4;
	t_player		player;
	t_xpm			xpm[4];
	t_mapdata		map_data;
	int				width;
	int				height;
	int				dray;
	unsigned int	ceiling_color;
	unsigned int	floor_color;
	double			dist_l;
	double			dist_r;
}					t_data;

int					key_press_func(int keycode, t_data *data);
t_ray_data			calculate_ray(t_data *data, double angle);
void				ft_my_put_pixel(t_imgdata *img_data, int x, int y,
						int color);
unsigned int		ft_my_get_pixel(t_data *data, int x, int y, int i);
void				render_window(t_data *data);
double				deg2rad(int deg);
int					ft_read_file(t_data *data, int fd);
char				*last_trim(char *str);
int					ft_check_rgb(char *s, char **find, int size, t_data *data);
char				*ft_is_space(char *s);
void				array_cleaner(void **arr);
int					check_null(t_data *data);
int					ft_get_map(t_data *data, char *path);
int					array_len(char **str);
int					longest_line(t_data *data);
int					ft_exit(t_data *data);
int					draw_walls(t_data *data, t_ray_data *ray_data,
						double distance);
int					error_check(t_data *data, char *path);
int					extension_check(char *path);
void				ft_xpm_cleaner(t_data *data);
void				free_func(t_data *data, int control_data);
int					array_len(char **str);
void				render_window(t_data *data);
void				init_color(t_data *data);
void				init_var(t_data *data);
void				init_xpm(t_data *data);
int					init_direction(t_data *data, int i, int j);
int					get_map_height(char *path);
int					put_map(t_data *data, char **lines);
int					check_wall(t_data *data);
int					check_all_way(t_data *data, int i, int j);
int					ft_multi_map(t_data *data, char **lines);
int					draw_screen4(t_data *data, t_ray_data *ray_data);
int					ft_check_xpm_fd(t_data *data);
int					ft_set_map(t_data *data);
int					control(char *tmp, int flags, t_data *data, int i);
int					draw_wall_n_img(int angle, double distance, t_data *data,
						t_ray_data ray_data);
int					draw_wall_e_img(int angle, double distance, t_data *data,
						t_ray_data ray_data);
int					draw_wall_w_img(int angle, double distance, t_data *data,
						t_ray_data ray_data);
int					draw_wall_s_img(int angle, double distance, t_data *data,
						t_ray_data ray_data);
int					draw_floor(int angle, int i, t_data *data);
int					draw_ceiling(int angle, int i, int start, t_data *data);
void				ft_move(int keycode, t_data *data);
int					check_conditions(t_control control);
void				handle_error(t_data *data, t_control control);
int					count_lines(int fd);
int					read_lines(char *path, char ***lines);
void				update_direction(t_data *data, int i, int j, int angle);
#endif
