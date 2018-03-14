/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:37:17 by wsabates          #+#    #+#             */
/*   Updated: 2018/03/14 05:31:48 by vguerand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WOLF_H
# define __WOLF_H

# include <stdio.h>

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/time.h>

# define WIN_X  800
# define WIN_Y  800
# define uDiv 1.1
# define vDiv 1.1
# define vMove 64.0
# define K_Y	16
# define K_T	17
# define K_ESC	53
# define K_MOVE_UP	13
# define K_MOVE_DOWN	1
# define K_MOVE_LEFT 0
# define K_MOVE_RIGHT 2
# define K_LOOK_RIGHT 14
# define K_LOOK_LEFT 12

typedef struct s_scaling
{
	int vMoveScreen;
}				t_scaling;

typedef struct s_coord
{
	int 	x;
	int	 	y;
}				t_coord;

typedef struct s_parsing
{
	t_coord		max;
	int 		**tab;
}				t_parsing;

typedef struct s_draw
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	time;
	double	oldtime;
	double	cameraX;
	double	raydirX;
	double	raydirY;
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int 	stepX;
	int		stepY;
	int		hit;
	int		side;
	int 	lineHeight;
	int		 drawStart;
	int 	drawEnd;
	void	*img;
	char	*map;
	int		bpp;
	int		size_line;
	int		endian;
	void	*init;
	void	*wdow;
	void	*mlx;
	void	*win;
	double	movespeed;
	double	frametime;
	double	rotate;
	double	speed;
	double	oldDirX;
	double	oldPlaneX;
	double	floorXwall;
	double	floorYwall;
	double	wallX;
	double	distWall;
	double	distPlayer;
	double	currentDist;
	double	weight;
	double currentFloorX;
	double currentFloorY;
	int floorTexX;
	int floorTexY;
	int del_wall;
	int del;
}			t_draw;

typedef struct s_obj
{
	t_coord coord;
	int 	bol;
	int		spriteScreenX;
	int 	drawStartY;
	int 	drawStartX;
	int 	drawEndY;
	int 	drawEndX;
	double 	spriteHeight;
	double 	spriteWidth;
	double transformX;
	double transformY;
}				t_obj;

typedef struct s_lst_obj
{
	t_coord 			coord;
	struct s_lst_obj	*next;
}				t_lst_obj;

typedef struct s_tab
{
	t_lst_obj 	*obj;
	int			dist;
}				t_tab;

typedef struct s_texture
{
	int texture_x;
	char		*tex_mur_nord;
	int			w_tex_mur_nord;
	int			h_tex_mur_nord;
	char		*tex_mur_sud;
	int			w_tex_mur_sud;
	int			h_tex_mur_sud;
	char		*tex_mur_west;
	int			w_tex_mur_west;
	int			h_tex_mur_west;
	char		*tex_mur_est;
	int			w_tex_mur_est;
	int			h_tex_mur_est;

	char		*texture_floor;
	int			w_texture_floor;
	int			h_texture_floor;

	char		*tex_sky;
	int			w_tex_sky;
	int			h_tex_sky;

	char		*texture_obj;
	int			w_texture_obj;
	int			h_texture_obj;

	char		*texture;
	int			w_texture;
	int			h_texture;

	void *pt_texture;

}				t_texture;

typedef struct s_map
{
	int 		x;
	int 		y;
	int 		z;
}				t_map;

typedef struct s_var
{

	int alpha;
	int beta;
	int teta;

	t_scaling	s;
	t_obj		o;
	t_lst_obj	*lst;
	int 		nbr_elem;
	t_draw 		d;
	t_texture 	t;
	t_map 		map;
	t_parsing	parsing;
}				t_var;

void	ft_change_tex(t_var *var);
int		ft_exit_click(int i);
void	ft_condtion_ray(t_var *var);
void 	objet(t_var *var, int x, int y);
void	ft_put_map(t_var *var);
void	sol(t_var *var, int x, int y);
int 	**parsing(t_parsing *p, char *str);
void	ciel(t_var *var, int x, int y);
void	mlx_pixel_put_to_image(t_draw draw, int x, int y, int color);
void	ft_init_struct(t_var *var);
void	mur(t_var *var, int x, int y);
void	fps_counter(t_var *var);
void	ft_raycasting(t_var *var);
int my_key_funct(int keycode, t_var *var);
int		rgb_to_hexa(int r, int g, int b);
void ft_aff_obj(t_var *var);


#endif
