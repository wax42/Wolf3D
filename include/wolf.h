/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:37:17 by wsabates          #+#    #+#             */
/*   Updated: 2018/03/20 16:21:43 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WOLF_H
# define __WOLF_H

# include <stdio.h>

# include "../libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/time.h>

# define ZOOM_MAP  6
# define WIN_X  800
# define WIN_Y  800
# define UDIV 1.1
# define VDIV 1.1
# define VMOVE 64.0
# define K_ENTER	36
# define K_R	15
# define K_Y	16
# define K_T	17
# define K_ESC	53
# define K_M	46
# define K_N	45
# define K_0	82
# define K_1	83
# define K_2	84
# define K_3	85
# define K_W_MOVE_UP	13
# define K_S_MOVE_DOWN	1
# define K_A_MOVE_LEFT 0
# define K_D_MOVE_RIGHT 2
# define K_Q_LOOK_LEFT 12
# define K_E_LOOK_RIGHT 14
# define K_ARROW_UP	126
# define K_ARROW_DOWM 125
# define K_ARROW_LEFT 123
# define K_ARROW_RIGHT 124

typedef struct	s_scaling
{
	int vmovescreen;
}				t_scaling;

typedef struct	s_coord
{
	int	x;
	int	y;
}				t_coord;

typedef struct	s_mlx
{
	void	*img;
	char	*map;
	int		bpp;
	int		size_line;
	int		endian;
	void	*init;
	void	*wdow;
	void	*mlx;
	void	*win;
}				t_mlx;

typedef struct	s_parsing
{
	t_coord		max;
	int			**tab;
}				t_parsing;

typedef struct	s_floor
{
	double	floor_sky_wallx;
	double	floor_sky_wally;
	double	current_floor_sky_x;
	double	current_floor_sky_y;
	int		floor_sky_tex_x;
	int		floor_sky_tex_y;
	double	weight;
	double	distplayer;

}				t_floor;

typedef struct	s_fps
{
	double	oldtime;
	double	time;
	double	frametime;
}				t_fps;

typedef struct	s_raycasting
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	camerax;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	double	movespeed;
	double	rotate;
	double	speed;
	double	olddirx;
	double	oldplanex;
	double	wallx;
	double	distwall;
	double	currentdist;
	int		del_wall;
	int		del;
	char	*pistol;
	char	*menu;
	char	*start_menu;
	int		mouse;
	int		menu_select;
	int		denom;
	int		shoot;
	double	linex;
	double	liney;
}				t_raycasting;

typedef struct	s_obj
{
	t_coord coord;
	int		bol;
	int		spritescreenx;
	int		drawstarty;
	int		drawstartx;
	int		drawendy;
	int		drawendx;
	double	spriteheight;
	double	spritewidth;
	double	transformx;
	double	transformy;
}				t_obj;

typedef struct	s_ligne
{
	int	dx;
	int	dy;
	int	xplus;
	int	yplus;
	int	cumul;
	int	x;
	int	y;
}				t_ligne;

typedef struct	s_lst_obj
{
	t_coord				coord;
	struct s_lst_obj	*next;
}				t_lst_obj;

typedef struct	s_tab
{
	t_lst_obj	*obj;
	double		dist;
}				t_tab;

typedef struct	s_texture
{
	int		texture_y;
	int		texture_x;
	char	*t_pistol;
	int		w_pistol;
	int		h_pistol;
	char	*tex_mur_nord;
	int		w_tex_mur_nord;
	int		h_tex_mur_nord;
	char	*tex_mur_sud;
	int		w_tex_mur_sud;
	int		h_tex_mur_sud;
	char	*tex_mur_west;
	int		w_tex_mur_west;
	int		h_tex_mur_west;
	char	*tex_mur_est;
	int		w_tex_mur_est;
	int		h_tex_mur_est;
	char	*texture_floor;
	int		w_texture_floor;
	int		h_texture_floor;
	char	*tex_sky;
	int		w_tex_sky;
	int		h_tex_sky;
	char	*texture_obj;
	int		w_texture_obj;
	int		h_texture_obj;
	char	*tex_menu;
	int		w_tex_menu;
	int		h_tex_menu;
	char	*texture;
	int		w_texture;
	int		h_texture;
}				t_texture;

typedef struct	s_var
{
	int					val;
	t_fps				fps;
	t_floor				f;
	t_mlx				mlx;
	t_scaling			s;
	t_obj				o;
	t_lst_obj			*lst;
	int					nbr_elem;
	t_raycasting		r;
	t_texture			t;
	t_parsing			parsing;
}				t_var;

void			ft_pos_spawn(t_var *var);
void			ft_shooting(t_var *var);
void			ft_width_wall(t_var *var);
void			ft_lancer_de_rayon(t_var *var);
void			ft_init_raycasting(t_var *var, int x);
void			ft_raycasting(t_var *var);
void			ft_ligne(t_mlx mlx, t_coord p, t_coord p2, int color);
int				ft_exit_click(void);
void			ft_condtion_ray(t_var *var);
void			objet(t_var *var, int x, int y);
void			ft_put_map(t_var *var);
void			ft_floor(t_var *var, int x, int y);
void			sky(t_var *var, int x, int y);
void			mur(t_var *var, int x, int y);
int				**parsing(t_parsing *p, char *str);
void			mlx_pixel_put_to_image(t_mlx mlx, int x, int y, int color);
void			ft_init_struct(t_var *var);
void			ft_init_texture(t_var *var);
void			ft_init_obj(t_var *var, int x, int y);
void			ft_fps_counter(t_var *var);
int				my_key_funct(int keycode, t_var *var);
void			ft_move_up_hook(int keycode, t_var *var);
int				rgb_to_hexa(int r, int g, int b);
void			ft_aff_obj(t_var *var);
int				mouse_hook(int x, int y, t_var *var);
void			ft_menu(t_var *var);
void			ft_exit(int code);

#endif
