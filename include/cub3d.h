/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:13:57 by timmi             #+#    #+#             */
/*   Updated: 2025/09/19 13:58:59 by emonacho         ###   ########.fr       */
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

typedef struct s_main_struct		t_main;
typedef	struct s_program_data		t_prog;
typedef struct s_display_window		t_display;
typedef	struct s_player_data		t_player;
typedef struct s_user_control_input	t_usr_ctrl_in;
typedef struct s_parser				t_parser;
typedef struct s_scene				t_scene;

# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"
# include "parser.h"
# include "error.h"
# include "checker.h"
# include "map.h"
# include "parser.h"
# include "gamedata.h"
# include "initfree.h"
# include "user_input.h"
# include "limits.h"

typedef struct		s_user_control_input
{
	int				*kc;			//  int[n] for: users keyboard inputs | `kc` = keycode
	t_main			*cub;			// `ptr` to parent struct
}					t_usr_ctrl_in;

typedef struct		s_display_window
{
	int				win_h;			// window height
	int				win_w;			// window width
	void			*win;
	t_main			*cub;			// `ptr` to parent struct
}					t_display;

typedef struct		s_graphic_data
{
	int				txtr_s;			// texture array size
	void			**txtr;			// void*[txtr_s] for: wall textures
	int				txtr_h;			// texture height
	int				txtr_w;			// texture width
	int				rgb_s;			// rgb array size
	int				**rgb;			// int[rgb_s][3] for: FLOOR and CEILING in RGB
	t_main			*cub;			// `ptr` to parent struct
}					t_graphic;

typedef struct		s_map_data
{
	int				height;
	int				width;
	int				**grid;			// int[w][h] for: MAP MATRIX
	int				*plyr_start_pos;// int[2] for: PLAYER X&Y START POSITION
	int				plyr_start_ori;	// START ORIENTATION (N,S,W or E)
	t_main			*cub;			// `ptr` to parent struct
}					t_map;

typedef struct		s_player_data
{
	int				*pos;			// int[2] for: PLAYER X&Y POSITION
	int				aov;			// angle of view in degree
	t_main			*cub;			// `ptr` to parent struct
}					t_player;

typedef struct		s_program_data
{
	bool			close_program;
	int				input_file_fd;
	t_parser		*parser;
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
void	log_data_scene(t_prog *pr);
#endif
