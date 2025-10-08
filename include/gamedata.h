/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamedata.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:13:03 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/08 09:34:50 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEDATA_H
# define GAMEDATA_H

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
