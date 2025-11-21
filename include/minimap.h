/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:13:28 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/21 11:38:48 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# define MINI_RES 8 /* SWEET SPOT*/

typedef struct	s_image_data t_image;

void	draw_minimap(t_main *cub, t_image *img);
void	mark_minimap(t_image *img, t_player *p);

#endif
