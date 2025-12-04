/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rendering.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:25:40 by emonacho          #+#    #+#             */
/*   Updated: 2025/12/03 16:56:33 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_RENDERING_H
# define GAME_RENDERING_H

void	draw_scene(t_main *cub, t_graphic *gfx, t_rays *r, t_player *p);
void	draw_background(int floor_c, int ceiling_c, t_image *img);
int		check_wall_side(t_player *p, t_map *m, int side, int *w_pos);
int		get_main_ray(t_rays *r, t_player *p, t_map *m);
int		create_image(t_main *cub, t_image *img);
void	draw(t_image *img, size_t dim[AXIS], size_t pos[AXIS], int color);
void	put_p(t_image *img, int x, int y, int color);
void	init_dda(t_rays *r, t_player *p, int x);
void	dda(t_rays *r, char **grid);
void	rotate(double dir[2], double plane[2], double rot_speed);
int		fps(t_prog *pr);

#endif
