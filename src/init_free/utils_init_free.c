/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:06:48 by emonacho          #+#    #+#             */
/*   Updated: 2025/09/21 14:47:46 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*
* mode == '+' ---> increment pos
* mode == '-' ---> decrement pos
*/
bool	update_tile_pos(size_t *pos, size_t tile_size, char mode)
{
	if (mode == '+')
	{
		if (*pos + 1 > tile_size)
		{
			*pos = 1;
			return (true);
		}
		else if (*pos + 1 <= tile_size)
			(*pos)++;
	}
	else if (mode == '-')
	{
		if (*pos - 1 == 0)
		{
			*pos = tile_size;
			return (true);
		}
		else if (*pos - 1 > 0)
			(*pos)--;
	}
	return (false);
}

int	to_close_program(t_main *cub)
{
	if (cub->pr.close_program == true)
	{
		free_cub(cub);
		return (true);
	}
	return (false);
}

int	**init_2d_array(int height, int width)
{
	int	**array;
	int	i;

	array = malloc(sizeof(int *) * height);
	if (!array)
		return (NULL);
	i = -1;
	while (++i < height)
	{
		array[i] = ft_calloc(width, sizeof(int));
		if (!array[i])
		{
			while (--i >= 0)
				free(array[i]);
			free(array);
			return (NULL);
		}
	}
	return (array);
}
