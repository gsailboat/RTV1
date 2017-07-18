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

int		exit_hook(t_mlx *e)
{
	mlx_destroy_window(e->mlx, e->win);
	free(e);
	exit(0);
}

int		my_key(int keycode, t_mlx *e)
{
	if (keycode == 49)
	{
		e->theta += M_PI / 8;
		mlx_clear_window(e->mlx, e->win);
		scene_init(e);
	}
	if (keycode == 53)
	{
		mlx_destroy_window(e->mlx, e->win);
		free(e);
		exit(0);
	}
	return (0);
}
