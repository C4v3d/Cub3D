/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rendering.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:25:40 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/30 17:10:22 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_RENDERING_H
# define GAME_RENDERING_H

int		draw_scene(t_main *cub);
int		draw_background(t_main *cub, t_image *img);
int		render_game(t_main *cub);
int		create_image(t_main *cub, t_image *img);
int		paint(t_image *img, size_t dim[AXIS], size_t pos[AXIS], int color);
void	my_mlx_pixel_put(t_image *img, int x, int y, int color);
int		rays_calculation(t_player *p, t_map *m);
void	init_main_ray_calculation(t_player *p);
void	dda(t_player *p, char **grid);
double	calculate_ray_len(t_player *p, double x, double y);
bool	wall_is_on_axis(t_player *p, char **grid);

#endif
