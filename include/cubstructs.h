/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubstructs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 22:25:45 by emonacho          #+#    #+#             */
/*   Updated: 2025/09/17 17:36:33 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBSTRUCT_H
# define CUBSTRUCT_H

typedef struct s_main_struct	t_main;

typedef struct		s_graphic_data
{
	int				txtr_s;			// texture array size
	void			**txtr;			// void*[txtr_s] for: wall textures
	int				rgb_s;			// rgb array size
	int				**rgb;			// int[rgb_s][3] for: FLOOR and CEILING in RGB
	t_main			*cub;			// `ptr` to parent struct
}					t_graphic;

typedef struct		s_map_data
{
	int				height;
	int				width;
	int				**grid;			// int[w][h] for: MAP MATRIX
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
	int				input_file_fd;
	t_main			*cub;			// `ptr` to parent struct
}					t_prog;

typedef struct		s_main_struct
{
	t_player		pl;
	t_map			map;
	t_graphic		gfx;
	t_prog			pr;
}					t_main;

#endif