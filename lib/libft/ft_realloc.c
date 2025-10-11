/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: timmi <timmi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:43:38 by timmi             #+#    #+#             */
/*   Updated: 2025/09/30 13:46:34 by timmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *The  realloc() function changes the size of
       the memory block pointed to by ptr to  size
       bytes.   The  contents will be unchanged in
       the range from the start of the  region  up
       to  the  minimum  of the old and new sizes.
       If the new size  is  larger  than  the  old
       size, the added memory will not be initial‐
       ized.  If ptr is NULL,  then  the  call  is
       equivalent  to malloc(size), for all values
       of size; if size is equal to zero, and  ptr
       is not NULL, then the call is equivalent to
       free(ptr).  Unless ptr  is  NULL,  it  must
       have  been  returned  by an earlier call to
       malloc(), calloc(), or realloc().   If  the
       area  pointed  to was moved, a free(ptr) is
       done. 
 */

ft_realloc(void *ptr, size_t size)
{
	char	*cp1;
	
}