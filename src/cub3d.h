/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 16:48:39 by iidzim            #+#    #+#             */
/*   Updated: 2021/01/19 09:33:02 by iidzim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WALL 0xFFCFC4
# define MAX_WIDTH  2560
# define MAX_HEIGHT 1440
# define MAX_INT 2147483647
# define MOVESPD 0.4
# define ROTSPD 0.6
# define KEY_ESC 53
# define KEY_X 17
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 124
# define KEY_RIGHT 123
# define KEY_UP 126
# define KEY_DOWN 125

# include "get_next_line.h"
# include <mlx.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <string.h>
# include <stdint.h>

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_point
{
	double			x;
	double			y;
}					t_point;

typedef struct		s_txt
{
	char			*texture[5];
	double			step;
	double			pos;
	int				*color;
	int				tex_x;
	int				tex_y;
	int				w;
	int				h;
}					t_txt;

typedef struct		s_player
{
	int				nbr;
	char			pos;
}					t_player;

typedef struct		s_sprite
{
	int				nbr;
	int				w;
	int				h;
	double			**sprite;
	t_point			spr;
	double			inverse_deter;
	t_point			transform;
	int				screen_x;
	int				drawstart_x;
	int				drawstart_y;
	int				drawend_x;
	int				drawend_y;
	int				stripe;
	int				tex_x;
	int				tex_y;
	int				*color;
}					t_sprite;

typedef struct		s_data
{
	unsigned int	file_size;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	void			*mlx_img_txt[5];
	int				img_win;
	int				*data_addr;
	int				count;
	int				endian;
	int				bpp;
	int				size_line;
	int				width;
	int				height;
	int				limit;
	char			*info;
	char			*m;
	char			**data;
	char			**old_map;
	char			**map;
	int				*w;
	int				element_cpt;
	int				nbr_line;
	int				nbr_column;
	t_color			c;
	t_color			f;
	t_txt			txt;
	t_player		ply;
	t_point			pos;
	t_point			dir;
	t_point			raydir;
	t_point			plane;
	t_point			camera;
	t_point			sidedist;
	t_point			deltadist;
	t_point			step;
	unsigned int	mp_x;
	unsigned int	mp_y;
	double			oldirx;
	double			oldplanex;
	int				hit;
	int				side;
	int				drawstart;
	int				drawend;
	int				lineheight;
	double			perpwalldis;
	t_sprite		s;
	double			*buff;
}					t_data;

void				ft_init(t_data *d);
void				ft_init2(t_data *d);
void				ft_init3(t_data *d);
void				ft_init_txt_ply(t_txt *txt, t_player *ply);
void				ft_init_pt(t_point *p);
int					ft_args(int argc, char **argv, t_data *d);
void				ft_read_file(t_data *d, int fd);
void				ft_read_file2(t_data *d, char *line, int *start_map);
void				ft_read_file3(t_data *d, char *line);
int					resize_map(t_data *d);
int					fill_new_map(t_data *d);
int					get_max_l(t_data *d);
int					ft_get_data(t_data *d);
int					ft_get_data2(t_data *d, int i, int off);
int					ft_txt(t_data *d);
void				ft_check_resolution(t_data *d, char *s);
void				ft_check_map(t_data *d);
void				ft_check_color(t_data *d, char *s, char l);
void				ft_get_color(t_data *d, t_color *t, char **c, char *l);
int					ft_check_color_form(char *c);
char				*ft_switch_comma_to_space(t_data *d, char *s);
void				ft_check_ntxt(t_data *d, char *s);
void				ft_check_stxt(t_data *d, char *s);
void				ft_check_wtxt(t_data *d, char *s);
void				ft_check_etxt(t_data *d, char *s);
void				ft_check_sprite_txt(t_data *d, char *s);
int					ft_empty_line(t_data *d);
int					ft_check_intrus(t_data *d);
int					ft_check_colmn(t_data *d);
int					ft_check_line(t_data *d);
int					ft_check_space(t_data *d);
int					ft_check_ply_spr(t_data *d, int i, int j, int c);
void				ft_init_player(t_data *d);
void				ft_init_player2(t_data *d);
void				ft_sprite(t_data *d);
void				sort_sprite(t_data *d);
int					calcul_pos_dir(t_data *d, int x);
int					calcul_step_sidedist(t_data *d);
int					perform_dda(t_data *d);
int					calcul_deltadist(t_data *d);
int					project_line(t_data *d);
void				cast(t_data *d);
void				ft_color(t_data *d);
void				ft_texture(t_data *d);
int					verline(t_data *d, int x);
int					rgb_to_int(t_color c);
int					ft_key(int keycode, t_data *d);
int					key_ws(int keycode, t_data *d);
int					key_ad(int keycode, t_data *d);
int					key_rl(int keycode, t_data *d);
void				ft_sprite_position(t_data *d, int i);
void				ft_draw_start_end(t_data *d);
void				ft_draw_sprite(t_data *d, int i);
void				sprite(t_data *d);
void				ft_bmp(t_data *d);
void				ft_header(t_data *d, char *header, int height);
void				*ft_memset(void *str, int x, size_t l);
int					ft_strlen(char *line);
int					ft_strcmp(char *str, int c);
int					ft_strncmp(char *s1, char *s2, size_t n);
long long			ft_atoi(t_data *d, char *str);
int					ft_rtsrts(char *s, char *to_find);
int					ft_isdigit(int c);
int					ft_isspace(char s);
int					ft_count_args(char **a);
int					ft_start_map(char *line, int *part2, t_data *d);
char				*remove_space(char *str);
void				ft_print_msg(char *msg, t_data *d);
void				ft_clear(char **p);
int					ft_exit(t_data *d, int i);
int					fttexit(t_data *d);
char				**ft_split(char *str, char c);

#endif
