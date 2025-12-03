/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 22:59:18 by emonacho          #+#    #+#             */
/*   Updated: 2025/12/03 12:27:57 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVES_H
# define MOVES_H


//bool	update_plyr_position(t_player *p, int kc);
bool	update_plyr_position(t_player *p, bool k[N_KEYS]);
void	update_plyr_vision(t_player *p, bool k[N_KEYS]);
//void	update_plyr_vision(t_player *plyr, int kc);

#endif
