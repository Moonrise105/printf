/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctobias <ctobias@student.21.ru>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 19:42:42 by moonrise          #+#    #+#             */
/*   Updated: 2020/05/25 15:00:12 by ctobias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dest, const void *src, size_t count)
{
	unsigned char	*dest_ptr;
	unsigned char	*src_ptr;

	if (!count || dest == src)
		return (dest);
	dest_ptr = (unsigned char*)dest;
	src_ptr = (unsigned char*)src;
	while (count-- > 0)
		*(dest_ptr++) = *(src_ptr++);
	return (dest);
}
