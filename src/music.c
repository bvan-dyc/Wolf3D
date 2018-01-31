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

#include "../Includes/wolf3D.h"

void	victorytracks(t_env *e)
{
	shadow_print(e, WIN_W - 230, 15, "THEME:");
	if (e->victory == 1 || e->victory == 2)
		mlx_string_put(e->mlx, e->win, WIN_W - 180, 15, RED, " CHRONOTRIGGER");
	if (e->victory == 3 || e->victory == 4)
		mlx_string_put(e->mlx, e->win, WIN_W - 180, 15, \
FFBLUE, " FINALFANTASY");
	if (e->victory == 5 || e->victory == 6)
		mlx_string_put(e->mlx, e->win, WIN_W - 180, 15, FFTBROWN, " FFTACTICS");
	if (e->victory == 7 || e->victory == 8)
		mlx_string_put(e->mlx, e->win, WIN_W - 180, 15, \
RHBLUE, " RADIANT HISTORIA");
	if (e->victory == 9 || e->victory == 10)
		mlx_string_put(e->mlx, e->win, WIN_W - 180, 15, PYELLOW, " POKEMONBW");
	if (e->victory == 11 || e->victory == 12)
		mlx_string_put(e->mlx, e->win, WIN_W - 180, 15, W3DRED, " WOLF3D");
}

void	tracklist(t_env *e)
{
	if (e->music == 1 || e->music == 2)
		musicshadow(e, Z2GREEN, " ZELDA2");
	if (e->music == 3 || e->music == 4)
		musicshadow(e, OOTGREEN, " ZELDAOOT");
	if (e->music == 5 || e->music == 6)
		musicshadow(e, EBRED, " EARTHBOUND");
	if (e->music == 7 || e->music == 8)
		musicshadow(e, SKPURPLE, " SHOVEL KNIGHT");
	if (e->music == 9 || e->music == 10)
		musicshadow(e, MM3BLUE, " MEGAMAN3");
	if (e->music == 11 || e->music == 12)
		musicshadow(e, DDGREY, " DOUBLE DRAGON");
	if (e->music == 13 || e->music == 14)
		musicshadow(e, AEBROWN, " APE ESCAPE");
	if (e->music == 15 || e->music == 16)
		musicshadow(e, GSYELLOW, " GOLDEN SUN");
	if (e->music == 17 || e->music == 18)
		musicshadow(e, MPORANGE, " METROID PRIME");
	if (e->music == 19 || e->music == 20)
		musicshadow(e, CTYELLOW, " CHRONOTRIGGER");
	if (e->music == 21 || e->music == 22)
		musicshadow(e, W3DRED, " WOLF3D");
}

void	jukebox(t_env *e)
{
	system("killall afplay &> /dev/null");
	if (e->music == 1 || e->music == 2)
		system("afplay jukebox/zeldatemple.mp3&");
	if (e->music == 3 || e->music == 4)
		system("afplay jukebox/lostwoods.mp3&");
	if (e->music == 5 || e->music == 6)
		system("afplay jukebox/earthbound.mp3&");
	if (e->music == 7 || e->music == 8)
		system("afplay jukebox/shovelknight.mp3&");
	if (e->music == 9 || e->music == 10)
		system("afplay jukebox/megaman3.mp3&");
	if (e->music == 11 || e->music == 12)
		system("afplay jukebox/doubledragon.mp3&");
	if (e->music == 13 || e->music == 14)
		system("afplay jukebox/kungfualley.mp3&");
	if (e->music == 15 || e->music == 16)
		system("afplay jukebox/goldensun.mp3&");
	if (e->music == 17 || e->music == 18)
		system("afplay jukebox/metroidprime.mp3&");
	if (e->music == 19 || e->music == 20)
		system("afplay jukebox/chronotrigger.mp3&");
	if (e->music == 21 || e->music == 22)
		system("afplay jukebox/nazianthem.mp3&");
}

void	victoryjukebox(t_env *e)
{
	system("killall afplay &> /dev/null");
	if (e->victory == 1 || e->victory == 2)
		system("afplay jukebox/victory/chronotrigger.mp3&");
	if (e->victory == 3 || e->victory == 4)
		system("afplay jukebox/victory/finalfantasy.mp3&");
	if (e->victory == 5 || e->victory == 6)
		system("afplay jukebox/victory/FFTactics.mp3&");
	if (e->victory == 7 || e->victory == 8)
		system("afplay jukebox/victory/radianthistoria.m4a&");
	if (e->victory == 9 || e->victory == 10)
		system("afplay jukebox/victory/pokemonbw.mp3&");
	if (e->victory == 11 || e->victory == 12)
		system("afplay jukebox/victory/wolf3D.mp3&");
}

void	music_keys(int keycode, t_env *e)
{
	if (keycode == 0)
	{
		if (e->music == 1)
			e->music = NUMDISKS * 2;
		if (e->victory == 1)
			e->victory = NVICDISKS * 2;
		e->music--;
		e->victory--;
	}
	if (keycode == KEY_D)
	{
		if (e->music == NUMDISKS * 2)
			e->music = 0;
		if (e->victory == NVICDISKS * 2)
			e->victory = 0;
		e->music++;
		e->victory++;
	}
	if (keycode == 0 || keycode == KEY_D)
	{
		if (e->escaped == 2)
			victoryjukebox(e);
		else
			jukebox(e);
	}
}
