/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctobias <ctobias@student.21.ru>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 21:46:37 by moonrise          #+#    #+#             */
/*   Updated: 2020/05/25 16:00:59 by ctobias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (!*s2)
		return (char*)s1;
	while (s1[i] && i < len)
	{
		if (s1[i] == s2[0])
		{
			j = 1;
			while (s2[j] && s1[i + j] == s2[j] &&
					(i + j) < len)
				++j;
			if (s2[j] == '\0')
				return ((char*)&s1[i]);
		}
		++i;
	}
	return (NULL);
}
