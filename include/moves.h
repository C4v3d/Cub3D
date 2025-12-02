/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 22:59:18 by emonacho          #+#    #+#             */
/*   Updated: 2025/12/02 07:12:18 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVES_H
# define MOVES_H

void	update_plyr_vision(t_player *p, bool k[N_KEYS]);
bool	update_plyr_position(t_player *p, bool k[N_KEYS]);



//bool	update_plyr_position(t_player *p, int kc);
//void	update_plyr_vision(t_player *plyr, int kc);

#endif
