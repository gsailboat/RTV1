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

void	scene_init(t_mlx *e)
{
	t_obj	hold[e->sh_num];
	t_shape	sh[e->sh_num];
	t_li	li[e->l_num];

	if (e->theta == 0)
	{
		e->mlx = mlx_init();
		e->win = mlx_new_window(e->mlx, WIN_W, WIN_H, "RTv1");
	}
	e->all_sh = sh;
	e->all_li = li;
	if (e->scene == 1)
		sceneone(hold, e);
	else if (e->scene == 2)
		scenetwo(hold, e);
	else if (e->scene == 3)
		scenethree(hold, e);
	else if (e->scene == 4)
		scenefour(hold, e);
	else if (e->scene == 5)
		scenefive(hold, e);
	else
		scenesix(hold, e);
	trace(e, hold);
}

int		main(int ac, char **av)
{
	t_mlx	*e;

	e = (t_mlx *)ft_memalloc(sizeof(t_mlx));
	if (ac == 2)
	{
		e->scene = ft_atoi(av[1]);
		if (e->scene >= 1 && e->scene <= 6)
		{
			setescene(e);
			scene_init(e);
			mlx_hook(e->win, 2, 3, my_key, e);
			mlx_hook(e->win, 17, 0, exit_hook, e);
			mlx_loop(e->mlx);
		}
		else
		{
			ft_putstr("Follow key for executable:\n1 = Sphere\n");
			ft_putstr("2 = Sphere/plane\n3 = Cylinder\n");
			ft_putstr("4 = Cone\n5 = Default\n6 = Sphere-o\n");
		}
	}
	else
		ft_putstr("Need two parameters: ./fractol [number between 1 and 6]\n");
	free(e);
	return (0);
}
