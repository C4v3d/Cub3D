/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:06:48 by emonacho          #+#    #+#             */
/*   Updated: 2025/09/19 13:26:08 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
