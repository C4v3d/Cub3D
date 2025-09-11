/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:30:44 by timmi             #+#    #+#             */
/*   Updated: 2024/10/08 10:06:27 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*buffer;

	i = 0;
	if (start >= ft_strlen(s))
	{
		buffer = malloc(1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
		return (buffer);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	buffer = malloc((len + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (i < len)
	{
		buffer[i] = s[start + i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
