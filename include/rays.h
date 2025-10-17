/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:15:38 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/17 18:00:37 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYS_H
# define RAYS_H

int		rays_calculation(t_player *p, t_map *m);
void	init_steps_dist_next_tile(t_player *p, int map_x, int map_y);
void	dda(t_player *p, char **grid, int *x, int *y);
int		calculate_ray_len(t_player *p, int x, int y);

#endif
