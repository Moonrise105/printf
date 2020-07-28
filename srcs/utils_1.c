/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctobias <ctobias@student.21.ru>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 21:23:37 by ctobias           #+#    #+#             */
/*   Updated: 2020/07/29 02:43:08 by ctobias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_free(void *p)
{
	if (p)
	{
		free(p);
		p = NULL;
	}
}

void	init_flags(t_flags *flags)
{
	flags->width_sub = 0;
	flags->accuracy = 0;
	flags->minus = 0;
	flags->null = 0;
	flags->point = 0;
	flags->accuracy_sub = 0;
	flags->width = 0;
	flags->spec = '0';
}

int		min_int(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

int		ft_putstr(char *str, int max_s)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i] && i < max_s)
		{
			ft_putchar(str[i]);
			++i;
		}
	}
	else
	{
		if (max_s >= 6)
			i += write(1, "(null)", 6);
	}
	return (i);
}

int		ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}
