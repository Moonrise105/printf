/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moonrise <moonrise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 20:01:23 by moonrise          #+#    #+#             */
/*   Updated: 2020/05/18 15:16:29 by moonrise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *source, int ch, size_t count)
{
	unsigned char	sym;
	unsigned char	*d;
	unsigned char	*s;

	sym = (unsigned char)ch;
	d = (unsigned char *)dest;
	s = (unsigned char *)source;
	while (count--)
	{
		*d++ = *s++;
		if (*(d - 1) == sym)
			return (d);
	}
	return (NULL);
}
