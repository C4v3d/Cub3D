/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emonacho <emonacho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:33:44 by emonacho          #+#    #+#             */
/*   Updated: 2025/09/16 21:52:49 by emonacho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	init_game_data(t_game_data *gd)
{

}

int	init_data(t_main_struct *s)
{
	int	ret;

	ret = 0;
	if (!ret && init_game_data(&s->gd) != 0)
		ret = 1;
	if (ret)
		free_main_struct(s);
	return (0);
}
