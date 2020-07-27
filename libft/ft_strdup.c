/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moonrise <moonrise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 20:57:56 by moonrise          #+#    #+#             */
/*   Updated: 2020/05/14 21:06:42 by moonrise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		len;
	char	*new_str;
	char	*p;

	len = ft_strlen(str);
	new_str = (char*)malloc(sizeof(char) * len + 1);
	p = new_str;
	if (!new_str)
		return (NULL);
	while (*str)
	{
		*new_str = *str;
		new_str++;
		str++;
	}
	*new_str = *str;
	return (p);
}
