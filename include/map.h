/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:06:35 by timmi             #+#    #+#             */
/*   Updated: 2025/11/25 15:37:59 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# define MAP_PATH "map/"

/**
 * Ids list to parse file.
 */
# define ID_LEN 2	/** < Id len*/
# define NO_ID "NO"
# define SO_ID "SO"
# define WE_ID "WE"
# define EA_ID "EA"
# define C_ID "C"
# define F_ID "F"

# define NO_RAD	M_PI / 2 // CANT DO THAT
# define SO_RAD	M_PI + (M_PI / 2) // CANT DO THAT
# define WE_RAD	M_PI
# define EA_RAD	M_PI * 2 // CANT DO THAT

#endif
