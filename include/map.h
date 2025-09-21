/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:06:35 by timmi             #+#    #+#             */
/*   Updated: 2025/09/21 11:29:51 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# define MAP_PATH "map/"

/**
 * Ids list to parse file.
 */
# define ID_LEN 2	/** < Id len*/
# define NO "NO"	/** < Path to north texture */
# define SO "SO"	/** < Path to south texture */
# define WE "WE" 	/** < Path to west texture */
# define EA "EA"	/** < Path to est texture */
# define C "C"		/** < Ceiling color data*/
# define F "F"		/** < Floor color data*/

typedef enum e_ids
{
	ID_NO,
	ID_SO,
	ID_WE,
	ID_EA,
}	t_id;

typedef struct s_textures
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_textures;

typedef struct s_color
{
	size_t	r;
	size_t	g;
	size_t	b;
}	t_color;

typedef struct s_scene
{
	t_textures	textures;
	t_color		ceiling;
	t_color		floor;
}	t_scene;

#endif
