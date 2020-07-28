/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perc_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctobias <ctobias@student.21.ru>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 14:23:15 by ctobias           #+#    #+#             */
/*   Updated: 2020/07/29 02:40:30 by ctobias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		perc_check_stars(t_flags *flags, va_list argptr)
{
	if (flags->width_sub)
	{
		flags->width = va_arg(argptr, int);
		if (flags->width < 0)
		{
			flags->minus = 1;
			flags->width *= -1;
		}
	}
	if (flags->accuracy_sub)
		flags->accuracy = va_arg(argptr, int);
}

int				perc_handler(t_flags *flags, va_list argptr)
{
	char	arg;
	int		i;
	char	sym;

	perc_check_stars(flags, argptr);
	sym = flags->null ? '0' : ' ';
	arg = '%';
	i = 0;
	if (flags->minus)
	{
		i += ft_putchar(arg);
		i += put_n_symbols(' ', flags->width - i);
	}
	else
	{
		++i;
		i += put_n_symbols(sym, flags->width - i);
		ft_putchar(arg);
	}
	return (i);
}
