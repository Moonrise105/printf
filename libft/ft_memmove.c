/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctobias <ctobias@student.21.ru>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 20:35:18 by moonrise          #+#    #+#             */
/*   Updated: 2020/05/25 15:04:30 by ctobias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	char *src_ptr;
	char *dest_ptr;
	char *last_src;
	char *last_dest;

	if (num == 0 || dest == src)
		return (dest);
	src_ptr = (char*)src;
	dest_ptr = (char*)dest;
	if (dest_ptr < src_ptr)
	{
		while (num-- > 0)
			*dest_ptr++ = *src_ptr++;
	}
	else
	{
		last_src = src_ptr + (num - 1);
		last_dest = dest_ptr + (num - 1);
		while (num--)
		{
			*last_dest-- = *last_src--;
		}
	}
	return (dest);
}
