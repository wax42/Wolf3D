/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguerand <vguerand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:37:17 by vguerand          #+#    #+#             */
/*   Updated: 2018/05/27 01:47:25 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WOLF_H
# define __WOLF_H

# include "../libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <pthread.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/time.h>

# define COLOR_LINE 0xFFFF00
# define COLOR_FLOOR 0xAAB2AC
# define COLOR_WALL 0x000000
# define COLOR_OBJ 0xBC8F8F
# define COLOR_PERSO 0xFF0000

# define FACT 4
# define WIN_X  800
# define WIN_Y  800
# define ZOOM_MAP_X  WIN_X / FACT
# define ZOOM_MAP_Y  WIN_Y / FACT
# define SIZE_LINE 20

# define UDIV 1.1
# define VDIV 1.1
# define VMOVE 0.0
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

# define MAP_MAX 124
# define MAP_MIN 10
# define THREADS 8

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

typedef struct	s_key
{
	char		up;
	char		down;
	char		left;
	char		right;
	char		look_left;
	char		look_right;
	char		mouse;
	char		pistol;
}				t_key;

typedef struct	s_parsing
{
	t_coord		max;
	int			**tab;
}				t_parsing;

typedef struct	s_floor
{
	double	wallx;
	double	wally;
	double	current_x;
	double	current_y;
	int		tex_x;
	int		tex_y;
	double	weight;
	double	distplayer;

}				t_floor;

typedef struct	s_fps
{
	struct timeval	old;
	struct timeval	time1;
	int				compt;
	int				oldcompt;
}				t_fps;

typedef struct	s_map
{
	int				size_x;
	int				size_y;
	double			linex;
	double			liney;
}				t_map;

typedef struct	s_menu
{
	char			*imagestart;
	char			*pistol;
	char			*menu;
	int				menu_select;
	int				shoot;
}				t_menu;

typedef struct	s_raycasting
{
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
	double	wallx;
	double	distwall;
	double	currentdist;
	t_floor f;
	int		curent_thread;
	char	*texture;
	int		w_texture;
	int		h_texture;
	int		texture_x;
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

typedef struct	s_thread
{
	char		get_core;
	pthread_t	core[THREADS];
}				t_thread;

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
}				t_texture;

typedef struct	s_var
{
	int					val;
	t_fps				fps;
	t_mlx				mlx;
	t_obj				o;
	t_lst_obj			*lst;
	t_map				map;
	int					nbr_elem;
	t_key				key;
	t_texture			t;
	t_menu				m;
	t_parsing			parsing;
	t_thread			thread;
	int					vmovescreen;
	double				posx;
	double				posy;
	double				movespeed;
	double				rotate;
	double				speed;
	double				olddirx;
	double				oldplanex;
	double				dirx;
	double				diry;
	double				planex;
	double				planey;
	double				camerax;
}				t_var;

void			thread_start(t_var *var);
void			ft_pos_spawn(t_var *var);
void			ft_width_wall(t_var *var, t_raycasting *r);
void			ft_lancer_de_rayon(t_var *var, t_raycasting *r);
void			ft_init_raycasting(t_var *var, int x, t_raycasting *r);
void			ft_ligne(t_mlx mlx, t_coord p, t_coord p2, int color);
int				ft_exit_click(void);
void			ft_condtion_ray(t_var *var, t_raycasting *r);
void			objet(t_var *var, int x, int y);
void			ft_put_map(t_var *var);
void			ft_floor(t_var *var, int x, t_raycasting *r);
void			mur(t_var *var, int x, t_raycasting *r);
int				**parsing(t_parsing *p, char *str);
void			mlx_pixel_put_to_image(t_mlx mlx, int x, int y, int color);
void			ft_init_struct(t_var *var);
void			ft_init_texture(t_var *var);
void			ft_init_obj(t_var *var, int x, int y);
void			ft_fps_counter(t_var *var);
void			ft_move_up_hook(t_var *var);
int				rgb_to_hexa(int r, int g, int b);
void			ft_aff_obj(t_var *var);
int				mouse_hook(int x, int y, t_var *var);
void			ft_menu(t_var *var);
void			ft_key_event(t_var *var);

#endif
