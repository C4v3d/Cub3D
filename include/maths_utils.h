/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:46:24 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/16 14:45:48 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_UTILS_H
# define MATHS_UTILS_H

#define M_PI 3.14159265358979323846
double	get_delta(double val);
double	degrees_to_radians(double degrees);
void	get_cos_sin(t_player *p);
float	get_quadrant(double aov);
double	get_hypotenus(double x, double y);
double	extract_double(double n_float);

#endif
