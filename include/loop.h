/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:38:08 by emonacho          #+#    #+#             */
/*   Updated: 2025/12/03 12:27:41 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_H
# define LOOP_H

int	input_loop(int kc, void *param);
int	key_press(int kc, void *param);
int	key_release(int kc, void *param);
int	loop(t_main *cub);

#endif
