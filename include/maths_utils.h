/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:46:24 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/18 11:59:18 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_UTILS_H
# define MATHS_UTILS_H

# define Q1_1 (M_PI / 2) / 2				// quadrant 1.1 -> angles from 0 to 45 degrees
# define Q1_2 M_PI / 2						// quadrant 1.2 -> angles from 46 to 90 degrees
# define Q2_1 (M_PI / 2) + ((M_PI / 2) / 2)	// ...
# define Q2_2 M_PI
# define Q3_1 M_PI + ((M_PI / 2) / 2)
# define Q3_2 M_PI + (M_PI / 2)
# define Q4_1 (M_PI * 2) - ((M_PI / 2) / 2)
# define Q4_2 (M_PI * 2) - 0.000001

//#define M_PI 3.14159265358979323846
double	get_delta(double val);
double	degrees_to_radians(double degrees);
void	get_cos_sin(t_player *p);
float	get_quadrant(double aov);
double	get_hypotenus(double x, double y);
double	extract_double(double n_float);

#endif
