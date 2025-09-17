/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamedata.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:13:03 by emonacho          #+#    #+#             */
/*   Updated: 2025/09/17 10:46:35 by emonacho         ###   ########.fr       */
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
	NO,
	SO,
	WE,
	EA
}				t_ori;

#endif
