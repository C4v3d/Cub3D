/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 22:59:18 by emonacho          #+#    #+#             */
/*   Updated: 2025/10/04 18:38:46 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVES_H
# define MOVES_H

int		update_plyr_position(t_player *plyr, int	kc);
int		update_plyr_vision(t_player *plyr, int	kc);
void	calculate_fov(size_t *fov, size_t fov_val, size_t fov_max, size_t aov);
//int	mouse_inputs(t_main *cub);

#endif
