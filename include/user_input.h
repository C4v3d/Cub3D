/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 22:59:18 by emonacho          #+#    #+#             */
/*   Updated: 2025/09/19 13:56:23 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_INPUT_H
# define USER_INPUT_H

void	update_plyr_pos(t_player *plyr, int	kc);
int		keyboard_inputs(int keycode, void *param);
//int	mouse_inputs(t_main *cub);

#endif
