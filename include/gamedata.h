/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamedata.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 19:13:03 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/25 15:20:54 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAMEDATA_H
# define GAMEDATA_H

/**
 * General definition to access
 * axis in an array
 */
typedef enum e_axis
{
	X,
	Y
}	t_axis;

typedef enum e_rgb_elements
{
	FLOOR,
	CEILING
}	t_rgbel;

typedef enum e_orientation
{
	NO,
	SO,
	WE,
	EA
}	t_ori;

#endif
