/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 16:09:56 by emonacho          #+#    #+#             */
/*   Updated: 2025/12/03 11:14:49 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

typedef enum	e_keys_list
{
	W,
	A,
	S,
	D,
	RA,
	LA,
	DA,
	UA,
}				t_kl;

# define ESC_KC	65307
# define W_KC	119
# define A_KC	97
# define S_KC	115
# define D_KC	100
# define UA_KC	65362 // UP ARROW
# define LA_KC	65361 // LEFT ARROW
# define DA_KC	65364 // DOWN ARROW
# define RA_KC	65363 // RIGHT ARROW
# define M_KC	109

#endif
