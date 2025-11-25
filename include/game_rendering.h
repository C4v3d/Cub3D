/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rendering.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:25:40 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/25 15:13:57 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_RENDERING_H
# define GAME_RENDERING_H

void	draw_scene(t_main *cub, t_graphic *gfx, t_rays *r, t_player *p);
void	draw_background(int floor_c, int ceiling_c, t_image *img);
int		check_wall_side(int side, double *p_pos, int *w_pos, double aov);
int		get_main_ray(t_rays *r, t_player *p, t_map *m);
int		create_image(t_main *cub, t_image *img);
void	draw(t_image *img, size_t dim[AXIS], size_t pos[AXIS], int color);
void	put_p(t_image *img, int x, int y, int color);
void	init_dda(t_rays *r, t_player *p, int x);
void	dda(t_rays *r, char **grid);
void 	rotate(double dir[2], double plane[2], double rot_speed);

#endif
