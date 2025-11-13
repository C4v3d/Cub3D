/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/11/13 11:28:16 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/cub3d.h"

void	safe_destroy_image(t_main *cub, void *ptr)
{
	#ifdef __APPLE__
	(void)cub;
	(void)ptr;
	// rien à faire
	#else
	if (ptr)
		mlx_destroy_image(&cub->mlx, ptr);
	#endif
}

static void	destroy_display(t_main *cub)
{
	#ifdef __APPLE__
	if (cub->dspl.win)
		mlx_destroy_window(cub->mlx, cub->dspl.win);
	// Sur macOS, mlx_destroy_display n'existe pas
	#else
	if (cub->dspl.win)
		mlx_destroy_window(cub->mlx, cub->dspl.win);
	if (cub->mlx)
		mlx_destroy_display(cub->mlx);
	#endif
	//mlx_destroy_window(dspl->cub->mlx, dspl->win);
	//mlx_destroy_display(dspl->cub->mlx);
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
	destroy_display(cub);
	free_program_data(&cub->pr);
	free_map_data(&cub->map);
	exit(0);
	return (0);
}
