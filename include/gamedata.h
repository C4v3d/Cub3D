/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamedata.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:13:03 by emonacho          #+#    #+#             */
/*   Updated: 2025/09/15 11:45:39 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEDATA_H
# define GAMEDATA_H

# define ESC 65307
# define Q 113
# define W 119
# define A 97
# define S 115
# define D 100

typedef struct		s_player_data
{
	int				x;
	int				y;
	t_game_data		*game;
}					t_player_data;

typedef struct		s_map_data
{
	int				**grid;		// MAP MATRIX
	int				*start_pos;	// PLAYER X&Y START POSITION + ORIENTATION (N,S,W or E)
	t_game_data		*game;
}					t_map_data;

typedef struct		s_graphic_data
{
	void			*no_texture;// NORTH
	void			*so_texture;// SOUTH
	void			*we_texture;// WEST
	void			*ea_texture;// EAST
	int				*f_color;	// FLOOR in RGB
	int				*c_color;	// CEILINIG in RGB
	t_game_data		*game;
}					t_graphic_data;

#endif
