/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctobias <ctobias@student.21.ru>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 18:51:52 by moonrise          #+#    #+#             */
/*   Updated: 2020/05/25 16:02:20 by ctobias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;
	char *p;

	if (!s1 && !s2)
		return (NULL);
	str = (char*)malloc(sizeof(char) * \
	((s1 ? ft_strlen(s1) : 0) + (s2 ? ft_strlen(s2) : 0) + 1));
	if (!str)
		return (NULL);
	p = str;
	if (s1)
	{
		while (*s1)
			*str++ = *s1++;
	}
	if (s2)
	{
		while (*s2)
			*str++ = *s2++;
	}
	*str = '\0';
	return (p);
}
