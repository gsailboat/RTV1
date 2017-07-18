/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gselbo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 22:32:27 by gselbo            #+#    #+#             */
/*   Updated: 2016/06/29 19:52:54 by gselbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	lambert(t_mlx *e)
{
	double lambert;

	lambert = vdot(&e->lightray.dir, &e->n) * e->coef;
	e->red += lambert * e->light.intensity.r * e->shape.diff.r;
	e->green += lambert * e->light.intensity.g * e->shape.diff.g;
	e->blue += lambert * e->light.intensity.b * e->shape.diff.b;
}

void	color(int x, int y, t_mlx *e)
{
	int ir;
	int ig;
	int ib;
	int color;

	ir = (unsigned char)mini(e->red * 255.0f, 255.0f);
	ig = (unsigned char)mini(e->green * 255.0f, 255.0f);
	ib = (unsigned char)mini(e->blue * 255.0f, 255.0f);
	color = ir << 16 | ig << 8 | ib;
	mlx_pixel_put(e->mlx, e->win, x, y, color);
}
