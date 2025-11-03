/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rendering.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:25:40 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/03 10:42:36 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_RENDERING_H
# define GAME_RENDERING_H

double	get_time(void);
int		draw_fps(t_main *cub, t_image *img);
int		draw_scene(t_main *cub, t_rays *r, t_player *p, t_image *img);
void	draw_background(t_main *cub, t_image *img);
int		check_w_side(int side, double *p_pos, int *w_pos, double aov);
int		get_main_ray(t_rays *r, t_player *p, t_map *m);
int		create_image(t_main *cub, t_image *img);
void	paint_line(t_image *img, int x, int start, int end, int col);
void	paint(t_image *img, size_t dim[AXIS], size_t pos[AXIS], int color);
void	my_mlx_pixel_put(t_image *img, int x, int y, int color);
void	init_ray_calculation(t_rays *r, t_player *p);
void	init_dda(t_rays *r, t_player *p, int x);
void	dda(t_rays *r, char **grid);
bool	wall_is_on_axis(t_rays *r, t_player *p, char **grid);
void 	rotate(double dir[2], double plane[2], double rot_speed);

#endif
