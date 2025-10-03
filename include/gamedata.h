/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamedata.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:13:03 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/03 16:20:12 by emonacho         ###   ########.fr       */
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
# define I 105
# define O 111

/**
 * General definition to access
 * axis in an array
 */
typedef enum	e_axis
{
	X,
	Y
}				t_axis;

typedef enum	e_sides
{
	LFT,
	RGT
}				t_side;

typedef enum	e_rgb_elements
{
	FLOOR,
	CEILING
}				t_rgbel;

typedef enum	e_orientation
{
	NO,
	SO,
	WE,
	EA
}				t_ori;

#endif
