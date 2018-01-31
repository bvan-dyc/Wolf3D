/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 16:09:07 by bvan-dyc          #+#    #+#             */
/*   Updated: 2017/02/17 16:09:08 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/wolf3d.h"

static void	raydatainit(t_env *e, t_ray *ray, int x)
{
	ray->camx = 2 * x / (double)e->mapw - 1;
	ray->pos.x = e->pos.x;
	ray->pos.y = e->pos.y;
	if (e->pos.x >= ENDX && e->pos.x <= ENDX + 2 && e->pos.y >= ENDY && \
e->pos.x <= ENDY + 4)
		e->escaped = 2;
	ray->dir.x = e->pdir.x + e->pcam.x * ray->camx;
	ray->dir.y = e->pdir.y + e->pcam.y * ray->camx;
	ray->step.x = (ray->dir.x >= 0 ? 1 : -1);
	ray->step.y = (ray->dir.y >= 0 ? 1 : -1);
	ray->map.x = (int)ray->pos.x;
	ray->map.y = (int)ray->pos.y;
	ray->deltad.x = sqrt(1 + (ray->dir.y * ray->dir.y) /\
(ray->dir.x * ray->dir.x));
	ray->deltad.y = sqrt(1 + (ray->dir.x * ray->dir.x) /\
(ray->dir.y * ray->dir.y));
	ray->hit = 0;
	ray->sidedist.x = (ray->dir.x >= 0 ? ((ray->map.x + 1.0 - ray->pos.x) * \
ray->deltad.x) : ((ray->pos.x - ray->map.x) * ray->deltad.x));
	ray->sidedist.y = (ray->dir.y >= 0 ? ((ray->map.y + 1.0 - ray->pos.y) * \
ray->deltad.y) : ((ray->pos.y - ray->map.y) * ray->deltad.y));
}

static void	ddalinegen(t_env *e, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->sidedist.x >= ray->sidedist.y)
		{
			ray->sidedist.y += ray->deltad.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
		}
		else
		{
			ray->sidedist.x += ray->deltad.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
		}
		if (e->mat[ray->map.x][ray->map.y] > 0)
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->raylength = (ray->map.x - ray->pos.x + (1 - ray->step.x) / 2) / \
		ray->dir.x;
	else
		ray->raylength = (ray->map.y - ray->pos.y + (1 - ray->step.y) / 2) / \
		ray->dir.y;
}

static void	raydraw(t_env *e, t_ray *ray, int x)
{
	int z;

	ray->lineheight = (int)(e->maph / ray->raylength);
	ray->drawstart = -ray->lineheight / 2 + e->maph / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = ray->lineheight / 2 + e->maph / 2;
	if (ray->drawend >= e->maph)
		ray->drawend = e->maph - 1;
	z = e->mat[ray->map.x][ray->map.y];
	raycolor(e, z);
	if (ray->side == 0 && ray->step.x < 0)
		e->color = 2 * e->color / 3;
	if (ray->side == 1)
		e->color = e->color / 2;
	if (ray->side == 1 && ray->step.y < 0)
		e->color = e->color / 3;
	wolf_line(e, x, ray->drawstart, ray->drawend);
}

int			raycaster(t_env *e)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < e->mapw)
	{
		raydatainit(e, &ray, x);
		ddalinegen(e, &ray);
		raydraw(e, &ray, x);
		x++;
	}
	return (0);
}
