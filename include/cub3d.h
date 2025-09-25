/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:13:57 by timmi             #+#    #+#             */
/*   Updated: 2025/09/25 09:20:56 by timmi            ###   ########.fr       */
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

# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 400

# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"
# include "preprocess.h"
# include "error.h"
# include "checker.h"
# include "map.h"
# include "parser.h"
# include "gamedata.h"
# include "initfree.h"
# include "user_input.h"

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

typedef struct		s_user_control_input
{
	int				*kc;			//  int[n] for: users keyboard inputs | `kc` = keycode
	t_main			*cub;			// `ptr` to parent struct
}					t_usr_ctrl_in;

typedef struct		s_display_window
{
	void			*win;
	t_main			*cub;			// `ptr` to parent struct
}					t_display;

typedef struct		s_graphic_data
{
	int				txtr_s;			// texture array size
	void			**txtr;			// void*[txtr_s] for: wall textures
	int				*txtr_h;		// texture height
	int				*txtr_w;		// texture width
	int				txtr_res;
	t_color			*colors[2];		/** Array of pointer for color data */
	t_main			*cub;			// `ptr` to parent struct
}					t_graphic;

typedef struct		s_map_data
{
	int				**grid;			// int[w][h] for: MAP MATRIX
	size_t			*dim;			// int[2] for: map dimensions
	size_t			*plyr_start_pos;// int[2] for: PLAYER X&Y START POSITION
	size_t			plyr_start_ori;	// START ORIENTATION (N,S,W or E)
	t_main			*cub;			// `ptr` to parent struct
}					t_map;

typedef struct		s_player_data
{
	size_t			aov;			// angle of view based on (txtr_res * 4)
	size_t			fov_max;		// field of view
	size_t			fov_val;		// field of view
	size_t			*fov;			// field of view
	size_t			*pos_mp;		// int[2] for: PLAYER X&Y POSITION ON MAP GRID
	size_t			*pos_ti;		// int[2] for: PLAYER X&Y POSITION ON TILE
	t_main			*cub;			// `ptr` to parent struct
}					t_player;

typedef struct		s_program_data
{
	bool			close_program;
	int				input_file_fd;
	t_main			*cub;			// `ptr` to parent struct
}					t_prog;

typedef struct		s_main_struct
{
	void			*mlx;
	t_player		plyr;
	t_map			map;
	t_graphic		gfx;
	t_display		dspl;
	t_prog			pr;
	t_usr_ctrl_in	ctrl;
}					t_main;

/**
 * Debugging functions (to remove)
 */
void	log_colors(t_main *cub);
#endif
