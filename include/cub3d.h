/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:13:57 by timmi             #+#    #+#             */
/*   Updated: 2025/11/23 16:43:48 by timmi            ###   ########.fr       */
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

#ifdef __APPLE__
# include "../lib/mlx_macos/mlx.h"
#else
# include "../lib/mlx_linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
#endif

// struct MLX pour stocker les images
typedef struct	s_img	t_img;

typedef struct	s_main_struct		t_main;
typedef	struct	s_program_data		t_prog;
typedef	struct	s_player_data		t_player;
typedef struct	s_scene				t_scene;
typedef struct	s_graphic_data		t_graphic;
typedef struct	s_rays_calculation	t_rays;
typedef struct	s_map_data			t_map;
typedef union	u_color				t_color;

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720

/**
 * Define the number of
 * textures and colors
 * used by cub3d.
 */
# define N_TEXTURE 4
# define N_COLOR 2

/**
 * Map Data
 */
# define AXIS 2
# define AOV_MAX M_PI * 2

// Define decr/incrementation value from keyboard inputs
# define POS_MOVE_UNIT 0.1
# define VIS_MOVE_UNIT 0.05

# include "../lib/libft/libft.h"
//# include "../lib/mlx/mlx.h"
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

/**
 * Debugging functions (to remove)
 */
void	log_colors(t_main *cub);
void	log_map(t_main *cub);
void	log_data(t_main *cub);
void	log_player_data(t_player *p);

typedef struct	s_draw_data
{
	int		start;			// texture line starting point
	int		end;			// texture line ending point
	int		x;
	int		y;
	int		num;
	double	pos;
	double	wall_x;			// where the wall as exactly been hit
	double	step;
}	t_draw;

typedef struct	s_rays_calculation
{
	double	delta[AXIS];
	double	dir[AXIS];
	double	dist[AXIS];		// distance to next tile
	double	plane[AXIS];
	int		steps[AXIS];
	int		map[AXIS];		// wall seen
	double	cam_x;
	int		wall_side;		// wall side
	double	wall_dist;		// perpendicular wall distance instead of euclidean dist
	int		wall_height;
	t_main	*cub;
}	t_rays;

typedef struct	s_image_data
{
	void	*img;
	char	*addr;
	int		bpp;	//bits per pixel
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

typedef struct	s_graphic_data
{
	t_image	txtr[N_TEXTURE];
	void	*txtr_ptr[N_TEXTURE];
	int		txtr_res;
	t_color	*floor;
	t_color	*ceiling;
	int		el_counter;
	t_image	map;
	t_image	scene;	// USELESS???
	t_main	*cub;
}	t_graphic;

typedef struct	s_map_data
{
	char	**grid;						// int[w][h] for: MAP MATRIX
	size_t	dim[AXIS];				// int[2] for: map dimensions
	size_t	plyr_start_pos[AXIS];	// int[2] for: PLAYER X&Y START POSITION
	t_rays	r_mini;
	t_main	*cub;						// `ptr` to parent struct
}	t_map;

typedef struct	s_player_data
{
	double			pos[AXIS];
	double			dir[AXIS];
	double			aov;
	double			fov;
	t_main			*cub;
}					t_player;

typedef struct	s_program_data
{
	bool			show_minimap;
	bool			close_program;
	int				input_file_fd;
	t_main			*cub;				// `ptr` to parent struct
}	t_prog;

typedef struct	s_main_struct
{
	void			*mlx;
	void			*win;
	t_player		plyr;
	t_map			map;
	t_graphic		gfx;
	t_prog			pr;
	t_rays			r;
}	t_main;

#endif
