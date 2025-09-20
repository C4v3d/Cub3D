/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 22:59:18 by emonacho          #+#    #+#             */
/*   Updated: 2025/09/20 19:31:04 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_INPUT_H
# define USER_INPUT_H

void	update_plyr_position(t_player *plyr, int	kc);
void	update_plyr_vision(t_player *plyr, int	kc);
int		keyboard_inputs(int keycode, void *param);
//int	mouse_inputs(t_main *cub);

#endif
