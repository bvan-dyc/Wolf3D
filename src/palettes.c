/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palettes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:09:07 by bvan-dyc          #+#    #+#             */
/*   Updated: 2017/02/17 16:09:08 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

static void	mcolor(t_env *e, int z)
{
	if (z == 1)
		e->color = RED;
	else if (z == 2)
		e->color = GREEN;
	else if (z == 3)
		e->color = BLUE;
	else if (z == 4)
		e->color = PINK;
	else if (z == 5)
		e->color = YELLOW;
	else if (z == 6)
		e->color = BLACK;
	else
		e->color = WHITE;
	e->skycolor = DGRAY;
	e->floorcolor = LGRAY;
}

static void	forestpalet(t_env *e, int z)
{
	if (z == 1)
		e->color = FOREST1;
	else if (z == 2)
		e->color = FOREST2;
	else if (z == 3)
		e->color = FOREST3;
	else if (z == 4)
		e->color = FOREST4;
	else if (z == 5)
		e->color = FOREST5;
	else if (z == 6)
		e->color = BLACK;
	else
		e->color = WHITE;
	e->skycolor = FSKY;
	e->floorcolor = FGROUND;
}

void		raycolor(t_env *e, int z)
{
	while (z > 6)
		z %= 6;
	if (e->palette == MCOLOR || e->palette == MCOLOR + 1)
		mcolor(e, z);
	if (e->palette == FOREST || e->palette == FOREST + 1)
		forestpalet(e, z);
	if (e->palette == BICOLOR || e->palette == BICOLOR + 1)
	{
		e->color = MONOCOLOR;
		if (z == 6)
			e->color = BLACK;
		e->skycolor = DGRAY;
		e->floorcolor = LGRAY;
	}
}
