/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:13:57 by timmi             #+#    #+#             */
/*   Updated: 2025/09/18 09:42:04 by timmi            ###   ########.fr       */
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

typedef struct s_cub t_cub;

# include "../lib/libft/libft.h"
# include "error.h"
# include "checker.h"
# include "map.h"
# include "parser.h"
# include "init.h"

typedef struct s_cub
{
	int		input_file_fd;
	t_scene	data_scene;
}	t_cub;

/**
 * Debugging functions (to remove)
 */
void	log_data_scene(t_cub *cub);
#endif