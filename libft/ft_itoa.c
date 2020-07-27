/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctobias <ctobias@student.21.ru>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 18:47:38 by moonrise          #+#    #+#             */
/*   Updated: 2020/05/30 13:44:36 by ctobias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		int_size(unsigned int a)
{
	int n;

	n = 0;
	while (a > 9)
	{
		a /= 10;
		++n;
	}
	return (n + 1);
}

char			*ft_itoa(int n)
{
	char			*str;
	unsigned int	nu;
	unsigned int	i;
	unsigned int	n_size;

	if (n >= 0)
		nu = (unsigned int)n;
	else
		nu = (unsigned int)(n * -1);
	n_size = int_size(nu) + (n < 0 ? 1 : 0);
	str = (char*)malloc(n_size + 1);
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	i = n_size - 1;
	while (nu > 9)
	{
		str[i--] = (char)(nu % 10 + 48);
		nu /= 10;
	}
	str[i] = (char)(nu % 10 + 48);
	str[n_size] = '\0';
	return (str);
}
