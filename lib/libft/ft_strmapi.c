/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 11:10:17 by timmi             #+#    #+#             */
/*   Updated: 2024/10/07 09:34:23 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	x;
	char	*ptr;

	x = 0;
	ptr = malloc((ft_strlen(s) * sizeof(char)) + 1);
	if (!ptr)
		return (NULL);
	while (s[x])
	{
		ptr[x] = f(x, s[x]);
		x++;
	}
	ptr[x] = '\0';
	return (ptr);
}
