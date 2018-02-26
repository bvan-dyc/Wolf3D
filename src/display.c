/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:09:07 by bvan-dyc          #+#    #+#             */
/*   Updated: 2017/02/17 16:09:08 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

static void	display_color(t_env *e)
{
	shadow_print(e, WIN_W - 230, 35, "COLORS:");
	if (e->palette == MCOLOR || e->palette == MCOLOR + 1)
	{
		mlx_string_put(e->mlx, e->win, WIN_W - 160, 35 + 1, BLACK, \
" MULTICOLOR");
		mlx_string_put(e->mlx, e->win, WIN_W - 160, 35, YELLOW, " MULTICOLOR");
	}
	if (e->palette == FOREST || e->palette == FOREST + 1)
	{
		mlx_string_put(e->mlx, e->win, WIN_W - 160, 35 + 1, BLACK, " FOREST");
		mlx_string_put(e->mlx, e->win, WIN_W - 160, 35, GREEN, " FOREST");
	}
	if (e->palette == BICOLOR || e->palette == BICOLOR + 1)
	{
		mlx_string_put(e->mlx, e->win, WIN_W - 160, 35 + 1, BLACK, " UNICOLOR");
		mlx_string_put(e->mlx, e->win, WIN_W - 160, 35, BLUE, " UNICOLOR");
	}
}

static void	display_parameters(t_env *e)
{
	char	*mspd;
	char	*rspd;
	double	nm;
	double	nr;

	nm = e->movespd;
	nr = e->rspd;
	mspd = ft_itoa(nm * 1000);
	rspd = ft_itoa(nr * 1000);
	shadow_print(e, WIN_W - 230, 65,
		"MOVESPEED:     %");
	shadow_print(e, WIN_W - 120, 65, mspd);
	shadow_print(e, WIN_W - 230, 80,
		"ROTSPEED:      %");
	shadow_print(e, WIN_W - 120, 80, rspd);
	shadow_print(e, WIN_W - 230, 15, "TRACK:");
	tracklist(e);
	free(mspd);
	free(rspd);
}

void		display_data(t_env *e)
{
	display_parameters(e);
	display_color(e);
}

void		display_menu(t_env *e)
{
	shadow_print(e, 20, 20, "Use the direction pad to move around");
	shadow_print(e, 20, 35, "Use 'M' and 'N' to increase/decrease the \
movement speed");
	shadow_print(e, 20, 50, "Use 'R' and 'E' to increase/decrease the \
rotation speed");
	shadow_print(e, 20, 65, "Use 'P' to switch between palettes");
	shadow_print(e, 20, 95, "Use 'A' and 'D' to switch between tracks");
	shadow_print(e, 20, 110, "Play track 'Y' - Stop track 'S'");
	shadow_print(e, 20, 140, "(Use 'H' to hide menu and again to hide data)");
}
