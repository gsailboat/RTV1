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

void	norm_shapes(t_mlx *e)
{
	t_vect no;

	if (e->sh.shape == PLANE)
	{
		e->n.x = -(e->sh.norm.x);
		e->n.y = -(e->sh.norm.y);
		e->n.z = -(e->sh.norm.z);
	}
	else if (e->sh.shape == CYL)
	{
		no = vsub(&e->n_st, &e->sh.pos);
		e->n = vsub(&e->n_st, &e->sh.pos);
	}
	else
		e->n = vsub(&e->n_st, &e->sh.pos);
}
