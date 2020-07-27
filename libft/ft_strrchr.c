/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moonrise <moonrise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 18:07:54 by moonrise          #+#    #+#             */
/*   Updated: 2020/05/15 18:36:01 by moonrise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *str, int ch)
{
	char *ptr;

	ptr = NULL;
	while (*str)
	{
		if (*str == ch)
			ptr = (char*)str;
		str++;
	}
	if (ptr)
		return (ptr);
	if (ch == '\0')
		return ((char*)str);
	return (0);
}
