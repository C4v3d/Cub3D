/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:13:57 by timmi             #+#    #+#             */
/*   Updated: 2025/12/03 11:08:39 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <errno.h>
# include "../lib/libft/libft.h"
# include "../lib/mlx_linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include "fw.h"
# include "input_validation.h"
# include "map_validation.h"
# include "utils.h"
# include "parser.h"
# include "preprocess.h"
# include "error.h"
# include "checker.h"
# include "map.h"
# include "gamedata.h"
# include "initfree.h"
# include "minimap.h"
# include "loop.h"
# include "game_rendering.h"
# include "keys.h"
# include "moves.h"

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720

/**
 * Define the number of
 * textures and colors
 * used by cub3d.
 */
# define N_TEXTURE 4
# define N_COLOR 2
# define N_KEYS 8

// Define decr/incrementation value from keyboard inputs
# define POS_MOVE_UNIT 0.099999
# define VIS_MOVE_UNIT 0.05

typedef struct s_draw_data
{
	int		start;
	int		end;
	int		x;
	int		y;
	int		num;
	double	pos;
	double	wall_x;
	double	step;
}	t_draw;

typedef struct s_rays_calculation
{
	double	delta[AXIS];
	double	dir[AXIS];
	double	dist[AXIS];
	double	plane[AXIS];
	int		steps[AXIS];
	int		map[AXIS];
	double	cam_x;
	int		wall_side;
	double	wall_dist;
	int		wall_height;
	t_main	*cub;
}	t_rays;

typedef struct s_image_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		s_line;
	int		endian;
	int		width;
	int		height;
}	t_image;

typedef union u_color
{
	int		color;
	struct
	{
		unsigned char	b;
		unsigned char	g;
		unsigned char	r;
		unsigned char	a;
	};
}	t_color;

typedef struct s_graphic_data
{
	t_image	txtr[N_TEXTURE];
	void	*txtr_ptr[N_TEXTURE];
	t_color	*floor;
	t_color	*ceiling;
	int		el_counter;
	t_image	map;
	t_image	scene;
	t_main	*cub;
}	t_graphic;

typedef struct s_map_data
{
	char	**grid;
	size_t	dim[AXIS];
	bool	p_pos;
	size_t	plyr_start_pos[AXIS];
	double	no_rad;
	double	so_rad;
	double	we_rad;
	double	ea_rad;
	t_rays	r_mini;
	t_main	*cub;
}	t_map;

typedef struct s_player_data
{
	double	pos[AXIS];
	double	old_pos[AXIS];
	double	dir[AXIS];
	double	aov;
	double	fov;
	t_main	*cub;
}	t_player;

typedef struct s_program_data
{
	bool	show_minimap;
	bool	close_program;
	bool	fail;
	int		input_file_fd;
	bool	key_on[N_KEYS];
	t_main	*cub;
}	t_prog;

typedef struct s_main_struct
{
	void		*mlx;
	void		*win;
	t_player	plyr;
	t_map		map;
	t_graphic	gfx;
	t_prog		pr;
	t_rays		r;
}	t_main;

#endif
