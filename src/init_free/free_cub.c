/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:59:05 by timmi             #+#    #+#             */
/*   Updated: 2025/11/27 15:36:12 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	safe_destroy_image(void *mlx, void *img)
{
	if (img)
		mlx_destroy_image(mlx, img);
}

// /** Seg fault */
static void	destroy_images(t_main *cub)
{
	int	i;

	i = -1;
	while (++i < N_TEXTURE)
		safe_destroy_image(cub->mlx, cub->gfx.txtr[i].img);
	safe_destroy_image(cub->mlx, cub->gfx.scene.img);
}

static void	destroy_display(t_main *cub)
{
	if (cub->win)
		mlx_destroy_window(cub->mlx, cub->win);
	if (cub->mlx)
		mlx_destroy_display(cub->mlx);
}

static void	free_prog_map_gfx(t_prog *pr, t_map *map, t_graphic *gfx)
{
	size_t	i;

	(void)gfx;
	if (w_close(pr->input_file_fd) == -1)
		ft_perror(pr->cub, errno, WARNING);
	i = -1;
	while (++i < map->dim[Y])
		w_free((void **)&map->grid[i]);
	w_free((void **)&map->grid);
	w_free((void **)&gfx->ceiling);
	w_free((void **)&gfx->floor);
}

int	free_cub(t_main *cub)
{
	destroy_images(cub);
	destroy_display(cub);
	free_prog_map_gfx(&cub->pr, &cub->map, &cub->gfx);
	w_free((void **)&cub->mlx);
	return (0);
}
