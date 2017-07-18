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

void	set_hold_six(t_obj *hold, t_mlx *e)
{
	hold[0].shape = SPHERE;
	hold[0].pos.x = 500 * cos(e->theta);
	hold[0].pos.y = 100;
	hold[0].pos.z = 10 * sin(e->theta);
	hold[0].radius = 100;
	hold[0].mat = 0;
	hold[1].shape = SPHERE;
	hold[1].pos.x = 200 * cos(e->theta);
	hold[1].pos.y = 400;
	hold[1].pos.z = 10 * sin(e->theta);
	hold[1].radius = 80;
	hold[1].mat = 1;
}

void	scenesix(t_obj *hold, t_mlx *e)
{
	e->all_sh[0].diff.r = 0.5;
	e->all_sh[0].diff.g = 0;
	e->all_sh[0].diff.b = 0.5;
	e->all_sh[0].reflect = 0;
	e->all_sh[1].diff.r = 0;
	e->all_sh[1].diff.g = 0.8;
	e->all_sh[1].diff.b = 0.2;
	e->all_sh[1].reflect = 0;
	e->all_li[0].pos.x = 400;
	e->all_li[0].pos.y = -50;
	e->all_li[0].pos.z = -500;
	e->all_li[0].intensity.r = 1;
	e->all_li[0].intensity.g = 1;
	e->all_li[0].intensity.b = 1;
	e->all_li[1].pos.x = 0;
	e->all_li[1].pos.y = -50;
	e->all_li[1].pos.z = -500;
	e->all_li[1].intensity.r = 1;
	e->all_li[1].intensity.g = 1;
	e->all_li[1].intensity.b = 1;
	set_hold_six(hold, e);
}
