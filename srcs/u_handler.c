/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctobias <ctobias@student.21.ru>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 23:42:29 by ctobias           #+#    #+#             */
/*   Updated: 2020/07/28 02:54:47 by ctobias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			u_writer_minus(t_flags *flags, char sym, int len, unsigned int arg)
{
	int res;

	res += (len = (arg == 0 ? 1 : count_digits(arg)));
	res += put_n_symbols('0', flags->accuracy - len);
	u_putnbr_stdout(arg);
	res += put_n_symbols(sym, flags->width - \
	max_int(flags->accuracy, len));
	return (res);
}

int			u_writer(t_flags *flags, char sym, int len, unsigned int arg)
{
	int res;

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
	u_putnbr_stdout(arg);
	return (res);
}

void		u_ignore_flags(t_flags *flags)
{
	if (flags->null && flags->minus)
		flags->null = 0;
	if (flags->null && flags->point)
		flags->null = 0;
}

int			u_handler(t_flags *flags, va_list argptr)
{
	unsigned int	arg;
	int				len;
	char			sym;
	int				neg;

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
	arg = va_arg(argptr, unsigned int);
	u_ignore_flags(flags);
	sym = flags->null ? '0' : ' ';
	if (flags->point && flags->accuracy == 0)
	{
		return (put_n_symbols(sym, flags->width));
	}
	if (!flags->minus)
		return (u_writer(flags, sym, len, arg));
	else
		return (u_writer_minus(flags, sym, len, arg));
}
