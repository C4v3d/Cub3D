/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 13:08:16 by timmi             #+#    #+#             */
/*   Updated: 2025/09/30 11:51:40 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

int		parse_file(t_main *cub);
void	parse_data(t_graphic *gfx);
int		get_color(char *line, int len);
int		get_id_len(char *line);
void	parse_map(t_map *map);

/**
 * Utils
 */
int	get_color(char *line, int len);
int	get_id_len(char *line);

#endif