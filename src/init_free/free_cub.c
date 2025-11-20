/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2025/11/20 18:09:07 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/cub3d.h"

void	safe_destroy_image(t_main *cub, void *ptr)
{
	#ifdef __APPLE__
	(void)cub;
	(void)ptr;
	#else
	if (ptr)
		mlx_destroy_image(&cub->mlx, ptr);
	#endif
}

static void	destroy_images(t_main *cub)
{
	#ifdef __APPLE__
	(void)cub;
	#else
	int	i;

	i = -1;
	while (++i < N_TEXTURE)
			mlx_destroy_image(&cub->mlx, &cub->gfx.txtr[i].img);
	mlx_destroy_image(&cub->mlx, &cub->gfx.scene.img);
	#endif
}

static void	destroy_display(t_main *cub)
{
	#ifdef __APPLE__
	if (cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	#else
	if (cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	if (cub->mlx)
		mlx_destroy_display(cub->mlx);
	#endif
}

static void	free_prog_map(t_prog *pr, t_map *map)
{
	size_t	i;

	if (w_close(pr->input_file_fd) == -1)
		ft_perror(pr->cub, errno, WARNING);
	i = -1;
	while (++i < map->dim[Y])
		w_free((void**)&map->grid[i]);
	w_free((void**)&map->grid);
}

int	free_cub(t_main *cub)
{
	destroy_images(cub);
	destroy_display(cub);
	free_prog_map(&cub->pr, &cub->map);
	free(cub->mlx);
	exit(0);
	return (0);
}
