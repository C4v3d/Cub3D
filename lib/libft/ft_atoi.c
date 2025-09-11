/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:27:22 by timmi             #+#    #+#             */
/*   Updated: 2025/09/11 09:42:31 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The atoi() function converts the ini‐
       tial portion of the string pointed to
       by nptr to int.  The behavior is  the
       same as

           strtol(nptr, NULL, 10);

       except  that  atoi()  does not detect
       errors.
*/
int	ft_atoi(const char *str)
{
	int	neg;
	int	i;
	int	num;

	neg = 1;
	i = 0;
	num = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + (str[i++] - '0');
	return (num * neg);
}
