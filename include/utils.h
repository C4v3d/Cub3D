/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 16:46:24 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/04 12:45:32 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

//#define M_PI 3.14159265358979323846
double	get_delta(double val);
void	get_cos_sin(t_player *p);
double	get_hypotenus(double x, double y);
double	extract_double(double n_float);
void	switch_bool(bool *val);

#endif
