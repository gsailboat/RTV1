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

void	set_sh(t_obj hold, t_mlx *e, int i)
{
	e->curshape = i;
	e->sh = hold;
}

void	check_other(t_mlx *e, t_obj hold, t_ray *r, int i)
{
	if (hold.shape == PLANE)
	{
		if (find_pldisc(r, &hold, e) == 1)
			set_sh(hold, e, i);
	}
	else if (hold.shape == CYL)
	{
		if (find_cydisc(r, &hold, e) == 1)
			set_sh(hold, e, i);
	}
}

void	inter_sh(t_mlx *e, t_obj *hold, t_ray *r)
{
	int	i;

	i = -1;
	e->curshape = -1;
	while (i++ < e->sh_num)
	{
		if (hold[i].shape == SPHERE)
		{
			if (find_spdisc(r, &hold[i], e) == 1)
				set_sh(hold[i], e, i);
		}
		else if (hold[i].shape == CONE)
		{
			if (find_codisc(r, &hold[i], e) == 1)
				set_sh(hold[i], e, i);
		}
		check_other(e, hold[i], r, i);
	}
}
