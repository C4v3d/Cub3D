/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/10/05 15:15:06 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/cub3d.h"

static void	destroy_display(t_display *dspl)
{
	mlx_destroy_window(dspl->cub->mlx, dspl->win);
	mlx_destroy_display(dspl->cub->mlx);
}

static void	free_program_data(t_prog *pr)
{
	if (w_close(pr->input_file_fd) == -1)
		ft_perror(pr->cub, errno, WARNING);
}

static void	free_map_data(t_map *map)
{
	size_t	i;

	i = -1;
	while (++i < map->dim[Y])
		w_free((void**)&map->grid[i]);
	w_free((void**)&map->grid);
}

int	free_cub(t_main *cub)
{
	destroy_display(&cub->dspl);
	free_program_data(&cub->pr);
	free_map_data(&cub->map);
	return (0);
}
