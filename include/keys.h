/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:09:56 by emonacho          #+#    #+#             */
/*   Updated: 2025/11/10 14:55:21 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

#ifdef __APPLE__
# define ESC	53
# define Q		12
# define W		13
# define A		0
# define S		1
# define D		2
# define LA		123 // LEFT ARROW
# define RA		124 // RIGHT ARROW
# define DA		125 // DOWN ARROW
# define UA		126 // UP ARROW
# define I		34
# define O		31
# define M		46
# define N		45

#else
# define ESC	65307
# define Q		113
# define W		119
# define A		97
# define S		115
# define D		100
# define UA		65362 // UP ARROW
# define LA		65361 // LEFT ARROW
# define DA		65364 // DOWN ARROW
# define RA		65363 // RIGHT ARROW
# define I		105
# define O		111
# define M		109
# define N		110
#endif

#endif
