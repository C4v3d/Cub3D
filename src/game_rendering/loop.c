/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 12:17:18 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/03 16:22:23 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	key_release(int kc, void *param)
{
	t_main	*cub;

	cub = (t_main *)param;
	if (kc == M_KC)
		cub->pr.show_minimap = !cub->pr.show_minimap;
	else if (kc == W_KC)
		cub->pr.key_on[W] = false;
	else if (kc == S_KC)
		cub->pr.key_on[S] = false;
	else if (kc == A_KC)
		cub->pr.key_on[A] = false;
	else if (kc == D_KC)
		cub->pr.key_on[D] = false;
	else if (kc == UA_KC)
		cub->pr.key_on[UA] = false;
	else if (kc == DA_KC)
		cub->pr.key_on[DA] = false;
	else if (kc == LA_KC)
		cub->pr.key_on[LA] = false;
	else if (kc == RA_KC)
		cub->pr.key_on[RA] = false;
	return (0);
}

static void	set_arrow_key(int kc, t_prog *p)
{
	if (kc == UA_KC && !p->key_on[DA]
		&& !p->key_on[W] && !p->key_on[S])
		p->key_on[UA] = true;
	else if (kc == DA_KC && !p->key_on[UA]
		&& !p->key_on[W] && !p->key_on[S])
		p->key_on[DA] = true;
	else if (kc == LA_KC && !p->key_on[RA])
		p->key_on[LA] = true;
	else if (kc == RA_KC && !p->key_on[LA])
		p->key_on[RA] = true;
}

int	key_press(int kc, void *param)
{
	t_main	*cub;

	cub = (t_main *)param;
	if (kc == ESC_KC)
		return (close_cub3d(cub));
	else if (kc == W_KC && !cub->pr.key_on[S]
		&& !cub->pr.key_on[UA] && !cub->pr.key_on[DA])
		cub->pr.key_on[W] = true;
	else if (kc == S_KC && !cub->pr.key_on[W]
		&& !cub->pr.key_on[UA] && !cub->pr.key_on[DA])
		cub->pr.key_on[S] = true;
	else if (kc == A_KC && !cub->pr.key_on[D])
		cub->pr.key_on[A] = true;
	else if (kc == D_KC && !cub->pr.key_on[A])
		cub->pr.key_on[D] = true;
	else if (kc == UA_KC || kc == DA_KC || kc == LA_KC || kc == RA_KC)
		set_arrow_key(kc, &cub->pr);
	return (0);
}

int	loop(t_main *cub)
{
	if (cub->pr.close_program == true)
	{
		free_cub(cub);
		exit(EXIT_SUCCESS);
	}
	if (cub->gfx.scene.img != NULL)
		safe_destroy_image(cub->mlx, cub->gfx.scene.img);
	if (create_image(cub, &cub->gfx.scene) != 0)
		return (ft_perror(cub, MLX_FAIL, CRITICAL));
	update_plyr_position(&cub->plyr, cub->pr.key_on);
	update_plyr_vision(&cub->plyr, cub->pr.key_on);
	draw_background(cub->gfx.floor->color, cub->gfx.ceiling->color,
		&cub->gfx.scene);
	draw_scene(cub, &cub->gfx, &cub->r, &cub->plyr);
	draw_minimap(cub, &cub->gfx.scene);
	fps(&cub->pr);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->gfx.scene.img, 0, 0);
	return (0);
}
