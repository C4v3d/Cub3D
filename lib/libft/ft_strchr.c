/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 09:41:26 by timmi             #+#    #+#             */
/*   Updated: 2024/10/09 15:50:12 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (ft_memchr(s, c, (ft_strlen(s) + 1)))
		return ((char *) ft_memchr(s, c, (ft_strlen(s) + 1)));
	return (NULL);
}
