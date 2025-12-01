/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:09:56 by emonacho          #+#    #+#             */
/*   Updated: 2025/12/01 16:15:48 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

typedef enum	e_keys_list
{
	ESC,
	W,
	A,
	S,
	D,
	RA,
	DA,
	UA,
	M,
}				t_kl;

#ifdef __APPLE__
# define ESC_KC	53
# define Q_KC	12
# define W_KC	13
# define A_KC	0
# define S_KC	1
# define D_KC	2
# define LA_KC	123 // LEFT ARROW
# define RA_KC	124 // RIGHT ARROW
# define DA_KC	125 // DOWN ARROW
# define UA_KC	126 // UP ARROW
# define I_KC	34
# define O_KC	31
# define M_KC	46
# define N_KC	45

#else
# define ESC_KC	65307
# define Q_KC	113
# define W_KC	119
# define A_KC	97
# define S_KC	115
# define D_KC	100
# define UA_KC	65362 // UP ARROW
# define LA_KC	65361 // LEFT ARROW
# define DA_KC	65364 // DOWN ARROW
# define RA_KC	65363 // RIGHT ARROW
# define I_KC	105
# define O_KC	111
# define M_KC	109
# define N_KC	110
#endif

#endif
