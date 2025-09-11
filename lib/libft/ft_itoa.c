/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 11:04:53 by timmi             #+#    #+#             */
/*   Updated: 2025/09/11 09:45:05 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(int i)
{
	size_t	n;

	n = 0;
	if (i == 0)
		return (1);
	if (i < 0)
	{
		i = -i;
		n++;
	}
	while (i > 0)
	{
		i /= 10;
		n++;
	}
	return (n);
}

char	*ft_itoa(int n)
{
	long int	num;
	size_t		i;
	char		*str;

	num = n;
	i = ft_count(num);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = malloc((i * sizeof(char)) + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		num = -num;
		str[0] = '-';
	}
	while (num > 0)
	{
		str[--i] = (num % 10) + '0';
		num = num / 10;
	}
	return (str);
}
