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

void	sflights(t_mlx *e)
{
	e->all_li[1].pos.x = 1200;
	e->all_li[1].pos.y = 0;
	e->all_li[1].pos.z = -8000;
	e->all_li[1].intensity.r = 1;
	e->all_li[1].intensity.g = 1;
	e->all_li[1].intensity.b = 1;
	e->all_li[0].pos.x = -600;
	e->all_li[0].pos.y = 0;
	e->all_li[0].pos.z = -8000;
	e->all_li[0].intensity.r = 1;
	e->all_li[0].intensity.g = 1;
	e->all_li[0].intensity.b = 1;
}

void	sfshapes2(t_obj *hold)
{
	hold[3].shape = CYL;
	hold[3].pos.x = 150;
	hold[3].pos.y = 300;
	hold[3].pos.z = -900;
	hold[3].norm.x = 0;
	hold[3].norm.y = 1;
	hold[3].norm.z = 0;
	hold[3].radius = 30;
	hold[3].mat = 3;
	hold[2].shape = CONE;
	hold[2].pos.x = 400;
	hold[2].pos.y = 300;
	hold[2].pos.z = -600;
	hold[2].norm.x = 0;
	hold[2].norm.y = 1;
	hold[2].norm.z = 0;
	hold[2].radius = 7;
	hold[2].mat = 4;
}

void	sfshapes3(t_obj *hold)
{
	hold[4].shape = CYL;
	hold[4].pos.x = 650;
	hold[4].pos.y = 300;
	hold[4].pos.z = -900;
	hold[4].norm.x = 0;
	hold[4].norm.y = 1;
	hold[4].norm.z = 0;
	hold[4].radius = 30;
	hold[4].mat = 3;
}

void	sfshapes(t_obj *hold)
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

void	scenetwo(t_obj *hold, t_mlx *e)
{
	e->all_sh[0].diff.r = 0.3;
	e->all_sh[0].diff.g = 0;
	e->all_sh[0].diff.b = 0.7;
	e->all_sh[0].reflect = 0;
	e->all_sh[1].diff.r = 0;
	e->all_sh[1].diff.g = 0.8;
	e->all_sh[1].diff.b = 0.2;
	e->all_sh[1].reflect = 0;
	e->all_sh[2].diff.r = 0;
	e->all_sh[2].diff.g = 0;
	e->all_sh[2].diff.b = 1;
	e->all_sh[2].reflect = 0;
	e->all_sh[3].diff.r = .5;
	e->all_sh[3].diff.g = 0;
	e->all_sh[3].diff.b = .5;
	e->all_sh[3].reflect = 0;
	e->all_sh[4].diff.r = 0;
	e->all_sh[4].diff.g = .8;
	e->all_sh[4].diff.b = .6;
	e->all_sh[4].reflect = 0;
	sflights(e);
	sfshapes(hold);
	sfshapes2(hold);
	sfshapes3(hold);
}
