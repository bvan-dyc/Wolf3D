/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:09:07 by bvan-dyc          #+#    #+#             */
/*   Updated: 2017/02/17 16:09:08 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

void			musicshadow(t_env *e, int color, char *s)
{
	mlx_string_put(e->mlx, e->win, WIN_W - 160, 14, BLACK, s);
	mlx_string_put(e->mlx, e->win, WIN_W - 160, 15, color, s);
}

void			shadow_print(t_env *e, int x, int y, char *s)
{
	mlx_string_put(e->mlx, e->win, x, y + 1, BLACK, s);
	mlx_string_put(e->mlx, e->win, x, y, WHITE, s);
}

void			wolf_line(t_env *e, int x, int ystart, int yend)
{
	double	deltay;
	double	slopey;
	double	err;
	int		sw;

	deltay = abs(yend - ystart);
	slopey = ystart < yend ? 1 : -1;
	err = (0 > deltay ? 0 : -deltay) / 2;
	sw = 0;
	while (sw == 0)
	{
		pixel_put(e, x, ystart, e->color);
		if (ystart == yend)
			sw = 1;
		if (sw == 0 && err < deltay)
			ystart += slopey;
	}
}

void			pixel_put(t_env *e, int x, int y, int color)
{
	int		pos;

	if (x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
	{
		pos = (x * e->bits_per_pixel / 8) + (y * e->size_line);
		e->img[pos] = color;
		e->img[pos + 1] = color >> 8;
		e->img[pos + 2] = color >> 16;
	}
}

void			fill_image(t_env *e, int skycolor, int floorcolor)
{
	int		x;
	int		y;

	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			pixel_put(e, x, y, skycolor);
			x++;
		}
		y++;
	}
	y = WIN_H / 2;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			pixel_put(e, x, y, floorcolor);
			x++;
		}
		y++;
	}
}
