/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wsabates <wsabates@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 13:37:17 by wsabates          #+#    #+#             */
/*   Updated: 2018/02/27 02:21:43 by vguerand         ###   ########.fr       */
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

typedef struct s_draw
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	double time;
	double oldtime;
	double cameraX;
	double raydirX;
	double raydirY;
	int		mapX;
	int		mapY;
	double sideDistX;
	double sideDistY;
	double deltaDistX;
	double deltaDistY;
	double perpWallDist;
	int 	stepX;
	int		stepY;
	int		hit;
	int		side;
	int 	lineHeight;
	int		 drawStart;
	int 	drawEnd;
	void			*img;
	char			*map;
	int				bpp;
	int				size_line;
	int				endian;
	void			*init;
	void			*wdow;
	void			*mlx;
	void			*win;
	double			movespeed;
	double			frametime;
	double rotspeed;
	double speed;
	double oldDirX;
	double oldPlaneX;

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
	char		*texture;
	int			w_texture;
	int			h_texture;
}				t_texture;


typedef struct s_var
{
	t_draw d;
	t_texture t;
	int 	**tab;
}				t_var;

void	sol(t_var *var, int x, int y);
int 	**parsing(char *str);
void	ciel(t_var *var, int x, int y);
void	mlx_pixel_put_to_image(t_draw draw, int x, int y, int color);
void	ft_init_struct(t_var *var);
void	mur(t_var *var, int x, int y);
void	fps_counter(t_var *var);
void	raycaster(t_var *var);
int my_key_funct(int keycode, t_var *var);



#endif
