/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:09:56 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/08 09:37:34 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODES_H
# define KEYCODES_H

#ifdef __APPLE__
# define ESC	53
# define Q		12
# define W		13
# define A		0
# define S		1
# define D		2
# define UA		65362 // UP ARROW
# define LA		65361 // LEFT ARROW
# define DA		65364 // DOWN ARROW
# define RA		65363 // RIGHT ARROW
# define I		105
# define O		111

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
#endif

#endif
