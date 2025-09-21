/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 22:59:18 by emonacho          #+#    #+#             */
/*   Updated: 2025/09/21 14:54:35 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_INPUT_H
# define USER_INPUT_H

void	update_plyr_position(t_player *plyr, int	kc);
void	update_plyr_vision(t_player *plyr, int	kc);
void	calculate_fov(size_t *fov, size_t fov_val, size_t fov_max, size_t aov);
int		keyboard_inputs(int keycode, void *param);
//int	mouse_inputs(t_main *cub);

#endif
