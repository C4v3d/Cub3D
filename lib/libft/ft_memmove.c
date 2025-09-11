/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:42:59 by timmi             #+#    #+#             */
/*   Updated: 2024/10/06 15:33:07 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;

	i = 0;
	if (!dst && !src)
		return (0);
	if (src < dst)
	{
		i = len;
		while (i > 0)
		{
			i--;
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
