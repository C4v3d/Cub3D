/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:46:24 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/12 22:30:42 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_UTILS_H
# define MATHS_UTILS_H

#define M_PI 3.14159265358979323846
double	degrees_to_radians(double degrees);
void	get_cos_sin(t_player *p);
double	get_angle(double x, double y);
double	get_hypotenus(double x, double y);
double	extract_double(double n_float);

#endif
