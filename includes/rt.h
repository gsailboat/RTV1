/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <gselbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 15:33:51 by gselbo            #+#    #+#             */
/*   Updated: 2017/05/19 12:15:06 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# include <../libft/libft.h>
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>
# include <pthread.h>

# define WIN_H 600
# define WIN_W 800
# define PLANE 0x00
# define SPHERE 0x01
# define CYL 0x10
# define CONE 0x11

typedef struct		s_vect
{
	double			x;
	double			y;
	double			z;
}					t_vect;

typedef struct		s_color
{
	double			r;
	double			g;
	double			b;
}					t_color;

typedef struct		s_obj
{
	int				shape;
	t_vect			pos;
	t_vect			norm;
	double			radius;
	int				mat;
}					t_obj;

typedef struct		s_li
{
	t_vect			pos;
	t_color			intensity;
}					t_li;

typedef struct		s_ray
{
	t_vect			st;
	t_vect			dir;
}					t_ray;

typedef struct		s_shape
{
	t_color			diff;
	double			reflect;
}					t_shape;

typedef	struct		s_mlx
{
	void			*mlx;
	void			*win;
	t_shape			*all_sh;
	t_li			*all_li;
	t_shape			shape;
	t_li			light;
	t_ray			lightray;
	t_vect			n;
	t_vect			n_st;
	t_vect			dist;
	t_obj			sh;
	int				scene;
	int				sh_num;
	int				l_num;
	int				curshape;
	int				level;
	int				shadow;
	double			theta;
	double			t;
	double			coef;
	double			red;
	double			green;
	double			blue;
}					t_mlx;

void				inter_sh(t_mlx *e, t_obj *hold, t_ray *r);
t_vect				vsub(t_vect *va, t_vect *vb);
double				vdot(t_vect *vone, t_vect *vtwo);
t_vect				vscale(double c, t_vect *v);
t_vect				vadd(t_vect *a, t_vect *b);
double				mini(double a, double b);
void				trace(t_mlx *e, t_obj *hold);
void				color(int x, int y, t_mlx *e);
int					find_pldisc(t_ray *r, t_obj *pl, t_mlx *e);
int					find_spdisc(t_ray *r, t_obj *sp, t_mlx *e);
int					find_codisc(t_ray *r, t_obj *co, t_mlx *e);
int					find_cydisc(t_ray *r, t_obj *cyl, t_mlx *e);
void				light_setup(t_mlx *e, t_obj *hold);
void				lambert(t_mlx *e);
void				norm_shapes(t_mlx *e);
int					exit_hook(t_mlx *e);
int					my_key(int keycode, t_mlx *e);
void				sceneone(t_obj *hold, t_mlx *e);
void				scenetwo(t_obj *hold, t_mlx *e);
void				scenethree(t_obj *hold, t_mlx *e);
void				scenefour(t_obj *hold, t_mlx *e);
void				scenefive(t_obj *hold, t_mlx *e);
void				scenesix(t_obj *hold, t_mlx *e);
void				reflect(t_mlx *e, t_ray *r);
void				setescene(t_mlx *e);
void				scene_init(t_mlx *e);

#endif
