/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamedata.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:13:03 by emonacho          #+#    #+#             */
/*   Updated: 2025/09/20 19:21:29 by emonacho         ###   ########.fr       */
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
# define UA 65362 // UP ARROW
# define LA 65361 // LEFT ARROW
# define DA 65364 // DOWN ARROW
# define RA 65363 // RIGHT ARROW

typedef enum	e_axis
{
	X,
	Y
}				t_axis;

typedef enum	e_rgb_elements
{
	FLOOR,
	CEILING
}				t_rgbel;

typedef enum	e_rgb
{
	R,
	G,
	B
}				t_rgbcol;

typedef enum	e_orientation
{
	O_NO,
	O_SO,
	O_WE,
	O_EA
}				t_ori;

#endif
