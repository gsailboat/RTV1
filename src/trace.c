/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 22:32:27 by gselbo            #+#    #+#             */
/*   Updated: 2016/06/29 19:52:54 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int		ray_trace(int x, t_mlx *e, t_obj *hold, t_ray *r)
{
	t_vect		scale;

	while (x == 0 || (x >= 1 && e->coef > 0.0f && e->level < 15))
	{
		e->t = 20000.0f;
		inter_sh(e, hold, r);
		if (e->curshape == -1)
			return (0);
		scale = vscale(e->t, &r->dir);
		e->n_st = vadd(&r->st, &scale);
		norm_shapes(e);
		if (vdot(&e->n, &e->n) == 0)
			return (0);
		e->n = vscale(1.0f / sqrtf(vdot(&e->n, &e->n)), &e->n);
		light_setup(e, hold);
		reflect(e, r);
		if (x == 0 && e->coef == 0.0f)
			break ;
	}
	return (1);
}

void	set_structs(t_mlx *e, t_ray *r, int x, int y)
{
	e->level = 0;
	e->coef = 1.0;
	e->red = 0;
	e->green = 0;
	e->blue = 0;
	if (e->scene == 1 || e->scene == 2)
		r->st.x = x;
	else
		r->st.x = x - (WIN_W / 2);
	r->st.y = y;
	r->st.z = -2000;
	r->dir.x = 0;
	r->dir.y = 0;
	r->dir.z = 1;
}

void	trace(t_mlx *e, t_obj *hold)
{
	int		y;
	int		x;
	t_ray	*r;

	y = 0;
	r = (t_ray*)ft_memalloc(sizeof(t_ray));
	while (y < WIN_H)
	{
		x = -1;
		while (x++ < WIN_W)
		{
			set_structs(e, r, x, y);
			if (ray_trace(x, e, hold, r) == 0)
				mlx_pixel_put(e->mlx, e->win, x, y, 0x00);
			else
				color(x, y, e);
		}
		y++;
	}
	free(r);
}
