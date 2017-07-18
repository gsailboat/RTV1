/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 22:32:27 by gselbo            #+#    #+#             */
/*   Updated: 2016/06/29 19:52:54 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	scenefive(t_obj *hold, t_mlx *e)
{
	e->all_sh[0].diff.r = 1;
	e->all_sh[0].diff.g = 0;
	e->all_sh[0].diff.b = 0;
	e->all_sh[0].reflect = 0;
	e->all_li[0].pos.x = 400;
	e->all_li[0].pos.y = -300;
	e->all_li[0].pos.z = -300;
	e->all_li[0].intensity.r = 1;
	e->all_li[0].intensity.g = 1;
	e->all_li[0].intensity.b = 1;
	hold[0].shape = SPHERE;
	hold[0].pos.x = 400 * cos(e->theta);
	hold[0].pos.y = 300;
	hold[0].pos.z = -200 * sin(e->theta);
	hold[0].radius = 80;
	hold[0].mat = 0;
}

void	setescene(t_mlx *e)
{
	if (e->scene == 2)
	{
		e->sh_num = 5;
		e->l_num = 2;
	}
	else if (e->scene == 1 || e->scene == 6)
	{
		e->sh_num = 2;
		e->l_num = 2;
	}
	else
	{
		e->sh_num = 1;
		e->l_num = 1;
	}
	e->theta = 0;
}
