/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:13:28 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/26 14:48:51 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# define MINI_RES 16

typedef struct	s_image_data t_image;

void	draw_minimap(int kc, t_main *cub);
void	my_mlx_pixel_put(t_image *img, int x, int y, int color);
void	draw_front_wall(t_image *map, t_player *p);

#endif
