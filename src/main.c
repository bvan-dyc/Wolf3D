/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:09:07 by bvan-dyc          #+#    #+#             */
/*   Updated: 2017/02/17 16:09:08 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

static int	cross_close(t_env *e)
{
	system("killall afplay &> /dev/null");
	mlx_destroy_window(e->mlx, e->win);
	(void)e;
	exit(0);
	return (0);
}

static void	put_overlay(t_env *e)
{
	if (e->escaped == 2)
		fill_image(e, BLACK, BLACK);
	mlx_put_image_to_window(e->mlx, e->win, e->img_ptr, 0, 0);
	if (e->escaped == -1)
	{
		shadow_print(e, WIN_W / 2, WIN_H / 2, "ESCAPE !");
		e->escaped = 0;
	}
	if (e->escaped == 2)
	{
		mlx_string_put(e->mlx, e->win, WIN_W / 2 - 100, WIN_H / 2 - 15, \
YELLOW, "CONGRATULATIONS:");
		mlx_string_put(e->mlx, e->win, WIN_W / 2 - 160, WIN_H / 2, YELLOW, \
" YOU ESCAPED THE LABYRINTH !");
		victorytracks(e);
		victoryjukebox(e);
	}
	else if (e->hidemenu <= 4)
	{
		if (e->hidemenu <= 2)
			display_menu(e);
		display_data(e);
	}
}

int			expose_hook(t_env *e)
{
	if (e->pos.x == POSX && e->pos.y == POSY)
		e->escaped = -1;
	mlx_clear_window(e->mlx, e->win);
	fill_image(e, e->skycolor, e->floorcolor);
	raycaster(e);
	put_overlay(e);
	return (0);
}

void		env_init(t_env *e)
{
	makemap(e);
	e->mapw = WIN_W;
	e->maph = WIN_H;
	e->pos.x = POSX;
	e->pos.y = POSY;
	e->pdir.x = DIRX;
	e->pdir.y = DIRY;
	e->pcam.x = CAMX;
	e->pcam.y = CAMY;
	e->palette = 3;
	e->victory = 1;
	e->escaped = 0;
	e->music = 1;
	e->hidemenu = 2;
	e->rspd = 0.1;
	e->floorcolor = FGROUND;
	e->skycolor = FSKY;
	e->movespd = 0.1;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_W, WIN_H, "Wolfenstein 3D");
	e->img_ptr = mlx_new_image(e->mlx, WIN_W, WIN_H);
	e->img = mlx_get_data_addr(e->img_ptr, &e->bits_per_pixel, \
	&e->size_line, &e->endian);
}

int			main(void)
{
	t_env e;

	system("afplay jukebox/zeldatemple.mp3&");
	env_init(&e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_hook(e.win, KEY_PRESS, KEY_PRESS_MASK, key_hook, &e);
	mlx_hook(e.win, CROSS_PRESS, KEY_PRESS_MASK, cross_close, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	system("killall afplay &> /dev/null");
	return (0);
}
