/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:13:28 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/01 17:45:19 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# define MINI_RES 12

typedef struct	s_image_data t_image;

void	draw_minimap(t_main *cub, t_image *img);
void	mark_minimap(t_image *img, t_player *p);

#endif
