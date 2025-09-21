/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamedata.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:13:03 by emonacho          #+#    #+#             */
/*   Updated: 2025/09/18 13:46:54 by timmi            ###   ########.fr       */
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
//# define LA // LEFT ARROW
//# define RA // RIGHT ARROW
//# define UA // UP ARROW
//# define DA // DOWN ARROW

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
