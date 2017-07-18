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

int		find_least(double a, double b, double c, t_mlx *e)
{
	double	disc;
	double	t0;
	double	t1;

	disc = b * b - 4 * a * c;
	t0 = (-b + sqrt(disc)) / (2);
	t1 = (-b - sqrt(disc)) / (2);
	if (t0 > t1)
		t0 = t1;
	if (t0 > 0.001f && t0 < e->t)
	{
		e->t = t0;
		return (1);
	}
	else
		return (0);
}

int		find_pldisc(t_ray *r, t_obj *p, t_mlx *e)
{
	double	t;

	if (vdot(&r->dir, &p->pos) != 0)
		t = -(vdot(&p->norm, &p->pos)) - vdot(&p->norm, &r->st) /
			vdot(&p->norm, &r->dir);
	else
		return (0);
	if (t > 0.001f && t < e->t)
	{
		e->t = t;
		return (1);
	}
	else
		return (0);
}

int		find_spdisc(t_ray *r, t_obj *s, t_mlx *e)
{
	double	a;
	double	b;
	double	c;
	t_vect	dist;

	dist = vsub(&r->st, &s->pos);
	a = vdot(&r->dir, &r->dir);
	b = 2 * vdot(&r->dir, &dist);
	c = vdot(&dist, &dist) - (s->radius * s->radius);
	if ((b * b) - (4 * a * c) < 0)
		return (0);
	else
	{
		if (find_least(a, b, c, e) == 1)
			return (1);
		else
			return (0);
	}
}

int		find_codisc(t_ray *r, t_obj *co, t_mlx *e)
{
	double	a;
	double	b;
	double	c;
	t_vect	dist;

	dist = vsub(&r->st, &co->pos);
	a = vdot(&r->dir, &r->dir) - (1 + pow(tan(co->radius), 2)) *
		pow(vdot(&r->dir, &co->norm), 2);
	b = 2 * vdot(&r->dir, &dist) - (1 + pow(tan(co->radius), 2)) *
		vdot(&r->dir, &co->norm) * vdot(&dist, &co->norm);
	c = vdot(&dist, &dist) - (1 + pow(tan(co->radius), 2)) *
		pow(vdot(&dist, &co->norm), 2);
	if (b * b - 4 * a * c < 0)
		return (0);
	else
	{
		if (find_least(a, b, c, e) == 1)
			return (1);
		else
			return (0);
	}
}

int		find_cydisc(t_ray *r, t_obj *cyl, t_mlx *e)
{
	double	a;
	double	b;
	double	c;
	t_vect	dist;

	dist = vsub(&r->st, &cyl->pos);
	a = vdot(&r->dir, &r->dir) - (vdot(&r->dir, &cyl->norm) *
		vdot(&r->dir, &cyl->norm));
	b = 2 * (vdot(&r->dir, &dist) - vdot(&r->dir, &cyl->norm) *
		vdot(&dist, &cyl->norm));
	c = vdot(&dist, &dist) - vdot(&dist, &cyl->norm) * vdot(&dist, &cyl->norm) -
		(cyl->radius * cyl->radius);
	if (b * b - 4 * a * c < 0)
		return (0);
	else
	{
		if (find_least(a, b, c, e) == 1)
			return (1);
		else
			return (0);
	}
}
