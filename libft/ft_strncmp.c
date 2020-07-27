/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moonrise <moonrise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 21:33:50 by moonrise          #+#    #+#             */
/*   Updated: 2020/05/14 21:44:44 by moonrise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *string1, const char *string2, size_t num)
{
	size_t i;

	if (num == 0)
		return (0);
	i = 0;
	while (string1[i] && string2[i] && string1[i] == string2[i] && i < num - 1)
		++i;
	return ((unsigned char)string1[i] - (unsigned char)string2[i]);
}
