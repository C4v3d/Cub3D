/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:13:57 by timmi             #+#    #+#             */
/*   Updated: 2025/11/13 09:10:00 by emonacho         ###   ########.fr       */
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
typedef struct	s_display_window	t_display;
typedef	struct	s_player_data		t_player;
typedef struct	s_scene				t_scene;
typedef struct	s_graphic_data		t_graphic;
typedef struct	s_rays_calculation	t_rays;
typedef struct	s_map_data			t_map;
typedef struct	s_user_control_input	t_usr_ctrl_in;
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
# include "maths_utils.h"
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

typedef struct	s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct	s_rays_calculation
{
	double	cam_x;
	double	delta[AXIS];
	double	dir[AXIS];
	double	dist[AXIS];		// distance to next tile
	double	plane[AXIS];
	double	wall_x;
	int		map[AXIS];	// wall seen
	int		w_side;			// wall side
	double	p_w_dist;		// perpendicular wall distance instead of euclidean dist
	int		line_h;			// line height
	int		steps[AXIS];
}	t_rays;

typedef struct	s_image_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef union u_color
{
	int		color;
	struct
	{
		char	r;
		char	g;
		char	b;
		char	a;
	};
}	t_color;

typedef struct	s_user_control_input // USELESS?
{
	int		*kc;			//  int[n] for: users keyboard inputs | `kc` = keycode
	t_main	*cub;			// `ptr` to parent struct
}	t_usr_ctrl_in;

typedef struct		s_display_window
{
	void	*win;
	size_t	win_dim[AXIS];
	t_main	*cub;			// `ptr` to parent struct
}	t_display;

typedef struct	s_graphic_data
{
	void	*txtr[N_TEXTURE];	/* Working with fixed data on the Stack*/
	int		*txtr_w;
	int		*txtr_h;
	int		txtr_res;
	t_color	*colors[N_COLOR];	/* Working with fixed data on the Stack*/
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
	double	plyr_start_ori;				// START ORIENTATION (N,S,W or E)
	t_rays	r_mini;
	t_main	*cub;						// `ptr` to parent struct
}	t_map;

typedef struct	s_player_data
{
	double			pos[AXIS];
	double			tile_pos[AXIS];	// float of pos
	double			dir[AXIS];
	double			ray_len;
	double			aov;
	double			fov;
	t_main			*cub;
}					t_player;

typedef struct	s_program_data
{
	bool			show_minimap;
	double			last_time;
	double			move_speed;
	double			rot_speed;
	bool			close_program;
	int				input_file_fd;
	t_main			*cub;				// `ptr` to parent struct
}	t_prog;

typedef struct	s_main_struct
{
	void			*mlx;
	t_player		plyr;
	t_map			map;
	t_graphic		gfx;
	t_display		dspl;
	t_prog			pr;
	t_usr_ctrl_in	ctrl;
	t_rays			r;
}	t_main;

#endif
