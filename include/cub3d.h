/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:13:57 by timmi             #+#    #+#             */
/*   Updated: 2025/10/11 14:31:26 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <math.h>
# include <stdbool.h>
# include <errno.h>
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_main_struct		t_main;
typedef	struct s_program_data		t_prog;
typedef struct s_display_window		t_display;
typedef	struct s_player_data		t_player;
typedef struct s_user_control_input	t_usr_ctrl_in;
typedef struct s_scene				t_scene;
typedef struct s_graphic_data		t_graphic;
typedef union u_color				t_color;
typedef struct s_map_data			t_map;


# define WINDOW_WIDTH 640
# define WINDOW_HEIGHT 480
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
# define DIMENSION 2
# define AOV_MAX M_PI * 2

// Define decr/incrementation value from keyboard inputs
# define MOVE_UNIT 0.1

# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"
# include "input_validation.h"
# include "map_validation.h"
# include "maths_utils.h"
# include "parser.h"
# include "preprocess.h"
# include "error.h"
# include "checker.h"
# include "map.h"
# include "gamedata.h"
# include "initfree.h"
# include "minimap.h"
# include "inputs_loop.h"
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

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_data;

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

typedef struct	s_user_control_input
{
	int		*kc;			//  int[n] for: users keyboard inputs | `kc` = keycode
	t_main	*cub;			// `ptr` to parent struct
}	t_usr_ctrl_in;

typedef struct		s_display_window
{
	void	*win;
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
	t_main	*cub;
}	t_graphic;

typedef struct	s_map_data
{
	char	**grid;						// int[w][h] for: MAP MATRIX
	size_t	dim[DIMENSION];				// int[2] for: map dimensions
	size_t	plyr_start_pos[DIMENSION];	// int[2] for: PLAYER X&Y START POSITION
	double	plyr_start_ori;				// START ORIENTATION (N,S,W or E)
	t_main	*cub;						// `ptr` to parent struct
}	t_map;

typedef struct	s_player_data
{
	double			pos[DIMENSION];
	double			dir[DIMENSION];
	double			aov;
	t_main			*cub;
}					t_player;

typedef struct	s_program_data
{
	bool	close_program;
	int		input_file_fd;
	t_main	*cub;				// `ptr` to parent struct
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
}	t_main;

#endif