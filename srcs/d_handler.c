/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctobias <ctobias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 21:37:53 by ctobias           #+#    #+#             */
/*   Updated: 2020/07/29 16:18:25 by ctobias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int			d_writer_minus(t_flags *flags, char sym, int arg)
{
	int neg;
	int res;
	int len;
	int flag_nn;

	res = 0;
	flag_nn = (!flags->accuracy && flags->point && !arg) ? 1 : 0;
	res += (len = (arg == 0 && !flag_nn ? 1 : count_digits(arg)));
	neg = (arg < 0 ? 1 : 0);
	if (arg < 0)
		res += ft_putchar('-');
	res += put_n_symbols('0', flags->accuracy - len);
	arg = (arg >= 0 ? arg : -arg);
	if (!flag_nn)
		putnbr_stdout(arg);
	res += put_n_symbols(sym, flags->width - \
	max_int(flags->accuracy, len) - neg);
	return (res);
}

static int			d_writer(t_flags *flags, char sym, int arg, int res)
{
	int				len;
	unsigned int	nb;
	int				flag_nn;

	flag_nn = (!flags->accuracy && flags->point && !arg) ? 1 : 0;
	res += (len = (arg == 0 && !flag_nn ? 1 : count_digits(arg)));
	if (sym == '0')
	{
		if (arg < 0)
			res += ft_putchar('-');
		res += put_n_symbols(sym, flags->width - \
		max_int(flags->accuracy, len) - (arg < 0 ? 1 : 0));
	}
	else
	{
		res += put_n_symbols(sym, flags->width - \
		max_int(flags->accuracy, len) - (arg < 0 ? 1 : 0));
		if (arg < 0)
			res += ft_putchar('-');
	}
	res += put_n_symbols('0', flags->accuracy - len);
	nb = (arg >= 0 ? arg : arg * -1);
	if (!flag_nn)
		putnbr_stdout(nb);
	return (res);
}

static void			d_ignore_flags(t_flags *flags)
{
	if (flags->null && flags->minus)
		flags->null = 0;
	if (flags->null && flags->point)
		flags->null = 0;
}

static void			d_check_stars(t_flags *flags, va_list argptr)
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

int					d_handler(t_flags *flags, va_list argptr)
{
	int		arg;
	char	sym;

	d_check_stars(flags, argptr);
	arg = va_arg(argptr, int);
	d_ignore_flags(flags);
	sym = flags->null ? '0' : ' ';
	if (!flags->minus)
		return (d_writer(flags, sym, arg, 0));
	else
		return (d_writer_minus(flags, sym, arg));
}
