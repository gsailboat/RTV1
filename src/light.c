/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 22:32:27 by gselbo            #+#    #+#             */
/*   Updated: 2016/06/29 19:52:54 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	l_ray(t_mlx *e, t_obj *hold, double ta)
{
	e->lightray.st = e->n_st;
	e->lightray.dir = vscale((1 / ta), &e->dist);
	e->t = ta;
	e->shadow = 0;
	inter_sh(e, hold, &e->lightray);
	if (e->curshape != -1)
		e->shadow = 1;
	else
		e->shadow = 0;
}

void	reflect(t_mlx *e, t_ray *r)
{
	double	ref;
	t_vect	tmp;

	e->coef *= e->shape.reflect;
	r->st = e->n_st;
	ref = 2.0f * vdot(&r->dir, &e->n);
	tmp = vscale(ref, &e->n);
	r->dir = vsub(&r->dir, &tmp);
	e->level++;
}

void	light_setup(t_mlx *e, t_obj *hold)
{
	int		j;
	double	ta;

	e->shape = e->all_sh[e->sh.mat];
	j = -1;
	while (j++ < e->l_num)
	{
		e->light = e->all_li[j];
		e->dist = vsub(&e->light.pos, &e->n_st);
		if (vdot(&e->n, &e->dist) <= 0.0f)
			continue;
		ta = sqrtf(vdot(&e->dist, &e->dist));
		if (ta <= 0.0f)
			continue;
		l_ray(e, hold, ta);
		if (e->shadow == 0)
			lambert(e);
	}
}
