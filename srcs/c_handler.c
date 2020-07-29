/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctobias <ctobias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 23:31:06 by ctobias           #+#    #+#             */
/*   Updated: 2020/07/29 15:16:34 by ctobias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		c_check_stars(t_flags *flags, va_list argptr)
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
	{
		flags->accuracy = va_arg(argptr, int);
		if (flags->accuracy < 0)
		{
			flags->accuracy = 0;
			flags->point = 0;
		}
	}
}

int				c_handler(t_flags *flags, va_list argptr)
{
	char	arg;
	int		i;

	c_check_stars(flags, argptr);
	arg = va_arg(argptr, int);
	i = 0;
	if (flags->minus)
	{
		i += ft_putchar(arg);
		i += put_n_symbols(' ', flags->width - i);
	}
	else
	{
		++i;
		i += put_n_symbols(' ', flags->width - i);
		ft_putchar(arg);
	}
	return (i);
}
