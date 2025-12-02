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
	t_prog *pr;

	pr = (t_prog *)param;
	printf("key_release | kc: %d\n", kc);
	if (kc == W_KC)
		pr->key_on[W] = false;
	else if (kc == S_KC)
		pr->key_on[S] = false;
	else if (kc == A_KC)
		pr->key_on[A] = false;
	else if (kc == D_KC)
		pr->key_on[D] = false;
	else if (kc == UA_KC)
		pr->key_on[UA] = false;
	else if (kc == DA_KC)
		pr->key_on[DA] = false;
	else if (kc == LA_KC)
		pr->key_on[LA] = false;
	else if (kc == RA_KC)
		pr->key_on[RA] = false;
	return (0);
}

int	key_press(int kc, void *param)
{
	t_prog *pr;

	pr = (t_prog *)param;
	printf("key_press | kc: %d\n", kc);
	if (kc == ESC_KC)
	{
		pr->close_program = true;
		return (0);
	}
	else if (kc == M)
		switch_bool(&pr->show_minimap);

	if (kc == W_KC && pr->key_on[S] == false
		&& pr->key_on[UA] == false && pr->key_on[DA] == false)
		pr->key_on[W] = true;
	else if (kc == S_KC && pr->key_on[W] == false
		&& pr->key_on[UA] == false && pr->key_on[DA] == false)
		pr->key_on[S] = true;
	else if (kc == A_KC && pr->key_on[D] == false)
		pr->key_on[A] = true;
	else if (kc == D_KC && pr->key_on[A] == false)
		pr->key_on[D] = true;
	else if (kc == UA_KC && pr->key_on[DA] == false
		&& pr->key_on[W] == false && pr->key_on[S] == false)
		pr->key_on[UA] = true;
	else if (kc == DA_KC && pr->key_on[UA] == false
		&& pr->key_on[W] == false && pr->key_on[S] == false)
		pr->key_on[DA] = true;
	else if (kc == LA_KC && pr->key_on[RA] == false)
		pr->key_on[LA] = true;
	else if (kc == RA_KC && pr->key_on[LA] == false)
		pr->key_on[RA] = true;

	//else if (kc == W_KC || kc == A_KC || kc == S_KC || kc == D_KC
	//		|| kc == UA_KC || kc == DA_KC)
	//	update_plyr_position(&cub->plyr, kc);
	//else if (kc == LA_KC || kc == RA_KC || kc == I_KC || kc == O_KC)
	//	update_plyr_vision(&cub->plyr, kc);
	return (0);
}

//v1
//int	key_press(int kc, void *param)
//{
//	t_main *cub;

//	cub = (t_main *)param;
//	printf("key_press | kc: %d\n", kc);
//	if (kc == ESC_KC)
//	{
//		cub->pr.close_program = true;
//		return (0);
//	}
//	else if (kc == M)
//		switch_bool(&cub->pr.show_minimap);
//	else if (kc == W_KC || kc == A_KC || kc == S_KC || kc == D_KC
//			|| kc == UA_KC || kc == DA_KC)
//		update_plyr_position(&cub->plyr, kc);
//	else if (kc == LA_KC || kc == RA_KC || kc == I_KC || kc == O_KC)
//		update_plyr_vision(&cub->plyr, kc);
//	return (0);
//}

int	loop(t_main *cub)
{
	if (cub->pr.close_program == true)
		free_cub(cub);
	if (cub->gfx.scene.img != NULL)
		safe_destroy_image(cub->mlx, cub->gfx.scene.img);
	if (create_image(cub, &cub->gfx.scene) != 0)
		return (ft_perror(cub, MLX_FAIL, CRITICAL));
	draw_background(&cub->gfx.scene, &cub->gfx);
	draw_scene(cub, &cub->gfx, &cub->r, &cub->plyr);
	draw_minimap(cub, &cub->gfx.scene);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->gfx.scene.img, 0, 0);
	return (0);
}
