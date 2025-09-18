/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:13:57 by timmi             #+#    #+#             */
/*   Updated: 2025/09/18 11:22:14 by timmi            ###   ########.fr       */
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

typedef struct s_main_struct	t_main;
typedef struct s_parser	t_parser;
typedef struct s_scene	t_scene;
typedef struct s_program_data	t_prog;

# include "../lib/libft/libft.h"
# include "parser.h"
# include "error.h"
# include "checker.h"
# include "map.h"
# include "parser.h"
# include "gamedata.h"
# include "initfree.h"

typedef struct		s_graphic_data
{
	int				txtr_s;			// txtr array size
	void			**txtr;			// void*[txtr_s] for: wall textures
	int				rgb_s;			// rgb array size
	int				**rgb;			// int[rgb_arr_s][3] for: FLOOR and CEILING in RGB
	t_main			*cub;			// `ptr` to parent struct
}					t_graphic;

typedef struct		s_map_data
{
	int				height;
	int				width;
	int				**grid;			// int[w][h] for:MAP MATRIX
	int				*p_start_pos;	// int[2] for: PLAYER X&Y START POSITION
	int				p_start_ori;	// START ORIENTATION (N,S,W or E)
	t_main			*cub;			// `ptr` to parent struct
}					t_map;

typedef struct		s_player_data
{
	int				*pos;
	int				aov;			// angle of view in degree
	t_main			*cub;			// `ptr` to parent struct
}					t_player;

typedef struct		s_program_data
{
	t_parser	*parser;
	t_main		*cub;			// `ptr` to parent struct
}	t_prog;

typedef struct		s_main_struct
{
	t_player		pl;
	t_map			map;
	t_graphic		gfx;
	t_prog			pr;
}					t_main;

/**
 * Debugging functions (to remove)
 */
void	log_data_scene(t_prog *pr);
#endif
