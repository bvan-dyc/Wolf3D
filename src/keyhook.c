/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:09:07 by bvan-dyc          #+#    #+#             */
/*   Updated: 2017/02/17 16:09:08 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

static void	special_keys(int keycode, t_env *e)
{
	if (keycode == KEY_ESC)
	{
		system("killall afplay &> /dev/null");
		mlx_destroy_window(e->mlx, e->win);
		(void)e;
		exit(1);
	}
}

static void	letter_keys(int keycode, t_env *e)
{
	if (keycode == KEY_R && e->rspd < 0.5)
		e->rspd += 0.0125;
	if (keycode == KEY_E && e->rspd > 0.025)
		e->rspd -= 0.0125;
	if (keycode == KEY_M && e->movespd < 0.5)
		e->movespd += 0.0125;
	if (keycode == KEY_N && e->movespd > 0.025)
		e->movespd -= 0.0125;
	if (keycode == KEY_H)
		e->hidemenu = (e->hidemenu == 6 ? 0 : e->hidemenu + 1);
	if (keycode == KEY_P)
		e->palette = (e->palette == 6 ? 1 : e->palette + 1);
	if (keycode == KEY_S)
		system("killall afplay &> /dev/null");
	if (keycode == KEY_Y)
	{
		system("killall afplay &> /dev/null");
		if (e->escaped == 2)
			victoryjukebox(e);
		else
			jukebox(e);
	}
}

static void	leftandright_keys(int keycode, t_env *e)
{
	double	oldpdx;
	double	oldpcx;

	oldpdx = e->pdir.x;
	oldpcx = e->pcam.x;
	if (keycode == KEY_LEFT)
	{
		e->pdir.x = e->pdir.x * cos(e->rspd) - e->pdir.y * sin(e->rspd);
		e->pdir.y = oldpdx * sin(e->rspd) + e->pdir.y * cos(e->rspd);
		e->pcam.x = e->pcam.x * cos(e->rspd) - e->pcam.y * sin(e->rspd);
		e->pcam.y = oldpcx * sin(e->rspd) + e->pcam.y * cos(e->rspd);
	}
	if (keycode == KEY_RIGHT)
	{
		e->pdir.x = e->pdir.x * cos(-e->rspd) - e->pdir.y * sin(-e->rspd);
		e->pdir.y = oldpdx * sin(-e->rspd) + e->pdir.y * cos(-e->rspd);
		e->pcam.x = e->pcam.x * cos(-e->rspd) - e->pcam.y * sin(-e->rspd);
		e->pcam.y = oldpcx * sin(-e->rspd) + e->pcam.y * cos(-e->rspd);
	}
}

static void	upanddown_keys(int keycode, t_env *e)
{
	if (keycode == KEY_UP)
	{
		if (e->mat[(int)(e->pos.x + e->pdir.x * e->movespd)]\
[(int)(e->pos.y)] == 0)
			e->pos.x += e->pdir.x * e->movespd;
		if (e->mat[(int)(e->pos.x)]\
[(int)(e->pos.y + e->pdir.y * e->movespd)] == 0)
			e->pos.y += e->pdir.y * e->movespd;
	}
	if (keycode == KEY_DOWN)
	{
		if (e->mat[(int)(e->pos.x - e->pdir.x * e->movespd)]\
[(int)(e->pos.y)] == 0)
			e->pos.x -= e->pdir.x * e->movespd;
		if (e->mat[(int)(e->pos.x)]\
[(int)(e->pos.y - e->pdir.y * e->movespd)] == 0)
			e->pos.y -= e->pdir.y * e->movespd;
	}
}

int			key_hook(int keycode, t_env *e)
{
	if (e->escaped != 2)
	{
		leftandright_keys(keycode, e);
		upanddown_keys(keycode, e);
		letter_keys(keycode, e);
	}
	music_keys(keycode, e);
	special_keys(keycode, e);
	expose_hook(e);
	return (0);
}
