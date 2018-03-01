/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:37:17 by wsabates          #+#    #+#             */
/*   Updated: 2018/03/01 17:23:57 by wsabates         ###   ########.fr       */
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

typedef struct s_coord
{
	int x;
	int y;
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
}			t_draw;

typedef struct s_texture
{
	int texture_x;
	char		*texture1;
	int			w_texture1;
	int			h_texture1;
	char		*texture2;
	int			w_texture2;
	int			h_texture2;
	char		*texture3;
	int			w_texture3;
	int			h_texture3;
	char		*texture4;
	int			w_texture4;
	int			h_texture4;

	char		*texture_floor;
	int			w_texture_floor;
	int			h_texture_floor;

	char		*texture;
	int			w_texture;
	int			h_texture;

}				t_texture;


typedef struct s_var
{
	t_draw 		d;
	t_texture 	t;
	t_parsing	parsing;
}				t_var;

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


#endif
