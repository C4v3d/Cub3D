/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:00:50 by timmi             #+#    #+#             */
/*   Updated: 2024/10/02 14:23:54 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	if (!needle[0])
		return ((char *) haystack);
	while (haystack[x] && x < len)
	{
		while (haystack[x + y] == needle[y] && needle[y] && (x + y) < len)
			y++;
		if (!needle[y])
			return ((char *) haystack + x);
		y = 0;
		x++;
	}
	return (NULL);
}
