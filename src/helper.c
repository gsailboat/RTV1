/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 22:32:27 by gselbo            #+#    #+#             */
/*   Updated: 2016/06/29 19:52:54 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_vect		vsub(t_vect *va, t_vect *vb)
{
	t_vect	res;

	res.x = va->x - vb->x;
	res.y = va->y - vb->y;
	res.z = va->z - vb->z;
	return (res);
}

double		vdot(t_vect *vone, t_vect *vtwo)
{
	double	dot;

	dot = vone->x * vtwo->x + vone->y * vtwo->y + vone->z * vtwo->z;
	return (dot);
}

t_vect		vscale(double c, t_vect *v)
{
	t_vect	ret;

	ret.x = v->x * c;
	ret.y = v->y * c;
	ret.z = v->z * c;
	return (ret);
}

t_vect		vadd(t_vect *a, t_vect *b)
{
	t_vect	ret;

	ret.x = a->x + b->x;
	ret.y = a->y + b->y;
	ret.z = a->z + b->z;
	return (ret);
}

double		mini(double a, double b)
{
	return ((a < b) ? a : b);
}
