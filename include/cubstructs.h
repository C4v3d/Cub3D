/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubstructs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 22:25:45 by emonacho          #+#    #+#             */
/*   Updated: 2025/09/16 23:20:02 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBSTRUCT_H
# define CUBSTRUCT_H

typedef struct s_main_struct	t_main;
typedef struct s_game_data		t_game;

typedef struct		s_graphic_data
{
	void			*no_txtr;	// NORTH TEXTURE
	void			*so_txtr;	// SOUTH TEXTURE
	void			*we_txtr;	// WEST TEXTURE
	void			*ea_txtr;	// EAST TEXTURE
	int				*f_color;	// int[3] for: FLOOR in RGB
	int				*c_color;	// int[3] for: CEILINIG in RGB
	t_game			*gd;		// `ptr` to parent struct
}					t_graphic;

typedef struct		s_map_data
{
	int				**grid;		// int[w][h] for:MAP MATRIX
	int				*start_pos;	// int[3] for: PLAYER X&Y START POSITION + ORIENTATION (N,S,W or E)
	t_game			*gd;		// `ptr` to parent struct
}					t_map;

typedef struct		s_player_data
{
	int				x;
	int				y;
	t_game			*gd;		// `ptr` to parent struct
}					t_player;

typedef struct		s_program_data
{
	int				input_file_fd;
	t_main			*cub;		// `ptr` to parent struct
}					t_prog;

typedef struct		s_game_data
{
	t_player		p;
	t_map			map;
	t_graphic		gfx;
	t_main			*cub;		// `ptr` to parent struct
}					t_game;

typedef struct		s_main_struct
{
	t_game			gd;
	t_prog			pd;
}					t_main;

#endif