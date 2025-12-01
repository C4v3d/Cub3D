/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:38:08 by emonacho          #+#    #+#             */
/*   Updated: 2025/12/01 15:41:57 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOP_H
# define LOOP_H

int	key_press(int kc, void *param);
int	key_release(int kc, void *param);
int	loop(t_main *cub);

#endif
