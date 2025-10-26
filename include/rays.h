/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:15:38 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/25 10:58:58 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYS_H
# define RAYS_H

int		rays_calculation(t_player *p, t_map *m);
void	init_main_ray_calculation(t_player *p);
void	dda(t_player *p, char **grid);
double	calculate_ray_len(t_player *p, double x, double y);
bool	wall_is_on_axis(t_player *p, char **grid);

#endif
