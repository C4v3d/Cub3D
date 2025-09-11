/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:55:17 by timmi             #+#    #+#             */
/*   Updated: 2025/04/03 10:17:59 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*new_str;

	i = -1;
	new_str = malloc(((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char)) + 1);
	if (!new_str)
		return (NULL);
	while (s1[++i])
		new_str[i] = s1[i];
	j = 0;
	while (s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	return (new_str);
}
