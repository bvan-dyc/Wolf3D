/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <bvan-dyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 16:15:22 by bvan-dyc          #+#    #+#             */
/*   Updated: 2017/02/20 19:42:04 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <time.h>
# include "../Includes/libft.h"

# define WIN_W			1080
# define WIN_H			720
# define MAP_W			26
# define MAP_H			28

# define POSX			23.5
# define POSY			1.5
# define ENDX			4.0
# define ENDY			24
# define DIRX			-1
# define DIRY			0
# define CAMX			0
# define CAMY			0.65

# define NUMDISKS		11
# define NVICDISKS		6

# define KEY_ESC		53
# define KEY_UP			126
# define KEY_DOWN		125
# define KEY_LEFT		123
# define KEY_RIGHT		124
# define KEY_A			0
# define KEY_B			11
# define KEY_D			2
# define KEY_E			14
# define KEY_F			3
# define KEY_G			5
# define KEY_H			4
# define KEY_I			34
# define KEY_J			38
# define KEY_M			46
# define KEY_N			45
# define KEY_P			35
# define KEY_R			15
# define KEY_S			1
# define KEY_T			17
# define KEY_U			32
# define KEY_W			13
# define KEY_Y			16
# define KEY_PLUS		69
# define KEY_MINUS		78

# define MCOLOR			1
# define FOREST			3
# define BICOLOR		5

# define WHITE			0xFFFFFF
# define BLACK			0x000000
# define RED			0xFF5733
# define GREEN			0x28B463
# define BLUE			0x2E86C1
# define YELLOW			0xF1C40F
# define PINK			0x8D7787
# define ORANGE			0xF39C12
# define PURPLE			0x7D3C98
# define BROWN			0xCC8000
# define LGRAY			0x777777
# define DGRAY			0x333333

# define OOTGREEN		0x0E5135
# define Z2GREEN		0x4ABA91
# define EBRED		 	0xFF5733
# define SKPURPLE		0x7D3C98
# define MM3BLUE		0x2E86C1
# define DDGREY			0xA9A9A9
# define AEBROWN		0xCC8000
# define GSYELLOW		0xF1C40F
# define MPORANGE		0xF39C12
# define W3DRED			0x7F0000
# define CTRED			0xFF5733
# define CTYELLOW		0xFFE39F
# define FFBLUE			0x43E8D8
# define RHBLUE			0x00B159
# define FFTBROWN		0xA47C48
# define PYELLOW		0xEAD61C

# define FOREST1			0x19270D
# define FOREST2			0x25591F
# define FOREST3			0x818C3C
# define FOREST4			0x72601B
# define FOREST5			0x593A0E
# define FSKY				0x14351A
# define FGROUND			0x77AB59

# define MONOCOLOR			0x012345

# define KEY_PRESS_MASK (1L<<0)
# define KEY_PRESS 2
# define CROSS_PRESS 17

typedef struct		s_coord
{
	double				x;
	double				y;
}					t_coord;

typedef struct		s_icord
{
	int				x;
	int				y;
}					t_icord;

typedef struct		s_ray
{
	t_coord			pos;
	t_coord			dir;
	t_coord			sidedist;
	t_coord			deltad;
	t_icord			map;
	t_coord			step;
	double			camx;
	double			raylength;
	int				side;
	int				hit;
	int				drawend;
	int				drawstart;
	int				lineheight;
}					t_ray;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img_ptr;
	char			*img;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				**mat;
	int				skycolor;
	int				floorcolor;
	int				color;
	int				escaped;
	int				victory;
	int				palette;
	int				music;
	t_coord			pos;
	t_coord			pdir;
	t_coord			pcam;
	int				mapw;
	int				maph;
	double			rspd;
	double			movespd;
	int				hidemenu;
}					t_env;

int					key_hook(int keycode, t_env *e);
void				display_menu(t_env *e);
void				display_data(t_env *e);
int					raycaster(t_env *e);
void				raycolor(t_env *e, int z);
void				wolf_line(t_env *e, int x, int ystart, int yend);
void				shadow_print(t_env *e, int x, int y, char *s);
void				pixel_put(t_env *e, int x, int y, int color);
void				fill_image(t_env *e, int skycolor, int floorcolor);
int					expose_hook(t_env *e);
void				env_init(t_env *e);
int					mat_create(char *file, t_env *e);
int					open_file(char *file);
int					fill_mat(int fd, t_env *e);
void				makemap(t_env *e);
int					**ft_strintsplit(char *s, char c);
void				printtab(int **map);
void				victoryjukebox(t_env *e);
void				victorytracks(t_env *e);
void				display_answer();
void				tracklist(t_env *e);
void				jukebox(t_env *e);
void				musicshadow(t_env *e, int color, char *s);
void				music_keys(int keycode, t_env *e);
#endif
