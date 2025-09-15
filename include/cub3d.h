/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:13:57 by timmi             #+#    #+#             */
/*   Updated: 2025/09/15 11:45:13 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <math.h>
# include <stdbool.h>
# include <errno.h>

# include "error.h"
# include "gamedata.h"
# include "../lib/libft/libft.h"

typedef struct		s_map_data;
typedef struct		s_player_data;
typedef struct		s_graphic_data;

typedef struct		s_game_data
{
	t_player_data	*p;
	t_map_data		*map;
	t_graphic_data	*gfx;
	//🚧ptr to main struct
}					t_game_data;

#endif
