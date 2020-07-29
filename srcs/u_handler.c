/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctobias <ctobias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 23:42:29 by ctobias           #+#    #+#             */
/*   Updated: 2020/07/29 14:35:31 by ctobias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		u_writer_minus(t_flags *flags, char sym, unsigned int arg)
{
	int res;
	int len;

	res = 0;
	res += (len = (arg == 0 ? 1 : u_count_digits(arg)));
	res += put_n_symbols('0', flags->accuracy - len);
	putnbr_stdout(arg);
	res += put_n_symbols(sym, flags->width - \
	max_int(flags->accuracy, len));
	return (res);
}

static int		u_writer(t_flags *flags, char sym, unsigned int arg)
{
	int res;
	int len;

	res = 0;
	res += (len = (arg == 0 ? 1 : u_count_digits(arg)));
	if (sym == '0')
	{
		res += put_n_symbols(sym, flags->width - \
		max_int(flags->accuracy, len));
	}
	else
	{
		res += put_n_symbols(sym, flags->width - \
		max_int(flags->accuracy, len));
	}
	res += put_n_symbols('0', flags->accuracy - len);
	putnbr_stdout(arg);
	return (res);
}

static void		u_ignore_flags(t_flags *flags)
{
	if (flags->null && flags->minus)
		flags->null = 0;
	if (flags->null && flags->point)
		flags->null = 0;
}

static void		u_check_stars(t_flags *flags, va_list argptr)
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

int				u_handler(t_flags *flags, va_list argptr)
{
	unsigned int	arg;
	char			sym;

	u_check_stars(flags, argptr);
	arg = va_arg(argptr, unsigned int);
	u_ignore_flags(flags);
	sym = flags->null ? '0' : ' ';
	if (!flags->minus)
		return (u_writer(flags, sym, arg));
	else
		return (u_writer_minus(flags, sym, arg));
}
