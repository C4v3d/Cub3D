/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rendering.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:25:40 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/26 19:15:52 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_RENDERING_H
# define GAME_RENDERING_H

int		draw_scene(t_main *cub);
int 	game_rendering(t_main *cub);
int		create_image(t_main *cub, t_image *img);
int		paint(t_image *img, size_t *dim, size_t *pos, int color);
void	my_mlx_pixel_put(t_image *img, int x, int y, int color);



#endif
