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

void	set_hold_one(t_obj *hold)
{
	hold[0].shape = PLANE;
	hold[0].pos.x = 400;
	hold[0].pos.y = 800;
	hold[0].pos.z = -700;
	hold[0].norm.x = 0;
	hold[0].norm.y = 0.5;
	hold[0].norm.z = 0.5;
	hold[0].mat = 0;
	hold[1].shape = SPHERE;
	hold[1].pos.x = 400;
	hold[1].pos.y = 300;
	hold[1].pos.z = -800;
	hold[1].radius = 50;
	hold[1].mat = 1;
}

void	sceneone(t_obj *hold, t_mlx *e)
{
	e->all_sh[0].diff.r = 0.3;
	e->all_sh[0].diff.g = 0.2;
	e->all_sh[0].diff.b = 0.5;
	e->all_sh[0].reflect = 0;
	e->all_sh[1].diff.r = 0.4;
	e->all_sh[1].diff.g = 0.2;
	e->all_sh[1].diff.b = 0.4;
	e->all_sh[1].reflect = 0;
	e->all_li[0].pos.x = -800;
	e->all_li[0].pos.y = 300;
	e->all_li[0].pos.z = -2550;
	e->all_li[0].intensity.r = 1;
	e->all_li[0].intensity.g = 1;
	e->all_li[0].intensity.b = 1;
	e->all_li[1].pos.x = 1600;
	e->all_li[1].pos.y = 300;
	e->all_li[1].pos.z = -2550;
	e->all_li[1].intensity.r = 1;
	e->all_li[1].intensity.g = 1;
	e->all_li[1].intensity.b = 1;
	set_hold_one(hold);
}

void	scenethree(t_obj *hold, t_mlx *e)
{
	e->all_sh[0].diff.r = 0.1;
	e->all_sh[0].diff.g = 0.9;
	e->all_sh[0].diff.b = 0;
	e->all_sh[0].reflect = 0;
	e->all_li[0].pos.x = 100;
	e->all_li[0].pos.y = -100;
	e->all_li[0].pos.z = -600;
	e->all_li[0].intensity.r = 1;
	e->all_li[0].intensity.g = 1;
	e->all_li[0].intensity.b = 1;
	hold[0].shape = CYL;
	hold[0].pos.x = 400 * cos(e->theta);
	hold[0].pos.y = 300;
	hold[0].pos.z = 10 * sin(e->theta);
	hold[0].norm.x = 0;
	hold[0].norm.y = 1;
	hold[0].norm.z = 0;
	hold[0].radius = 50;
	hold[0].mat = 0;
}

void	scenefour(t_obj *hold, t_mlx *e)
{
	e->all_sh[0].diff.r = 0.7;
	e->all_sh[0].diff.g = 0.3;
	e->all_sh[0].diff.b = 0;
	e->all_sh[0].reflect = 0;
	e->all_li[0].pos.x = -100;
	e->all_li[0].pos.y = 100;
	e->all_li[0].pos.z = -300;
	e->all_li[0].intensity.r = 2;
	e->all_li[0].intensity.g = 2;
	e->all_li[0].intensity.b = 2;
	hold[0].shape = CONE;
	hold[0].pos.x = 400 * cos(e->theta);
	hold[0].pos.y = 300;
	hold[0].pos.z = 0 * sin(e->theta);
	hold[0].norm.x = 0;
	hold[0].norm.y = 1;
	hold[0].norm.z = 0;
	hold[0].radius = 50;
	hold[0].mat = 0;
}
