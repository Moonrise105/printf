/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctobias <ctobias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 00:12:30 by ctobias           #+#    #+#             */
/*   Updated: 2020/07/29 16:19:44 by ctobias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	x_writer_minus(t_flags *flags, char sym, unsigned int arg, int caps)
{
	int		res;
	int		len;
	char	*str;
	int		flag_nn;

	flag_nn = (!flags->accuracy && flags->point && !arg) ? 1 : 0;
	res = 0;
	len = (arg == 0 && !flag_nn ? 1 : x_count_digits(arg, flag_nn));
	res += put_n_symbols('0', flags->accuracy - len);
	str = ft_itoa_base(arg, 16, caps);
	if (!flag_nn)
		res += ft_putstr(str, len);
	res += put_n_symbols(sym, flags->width - \
	max_int(flags->accuracy, len));
	ft_free(str);
	return (res);
}

static int	x_writer(t_flags *flags, char sym, unsigned int arg, int caps)
{
	int		res;
	char	*str;
	int		len;
	int		flag_nn;

	flag_nn = (!flags->accuracy && flags->point && !arg) ? 1 : 0;
	res = 0;
	len = (arg == 0 && !flag_nn ? 1 : x_count_digits(arg, flag_nn));
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
	str = ft_itoa_base(arg, 16, caps);
	if (!flag_nn)
		res += ft_putstr(str, len);
	ft_free(str);
	return (res);
}

static void	x_ignore_flags(t_flags *flags)
{
	if (flags->null && flags->minus)
		flags->null = 0;
	if (flags->null && flags->point)
		flags->null = 0;
}

static void	x_check_stars(t_flags *flags, va_list argptr)
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

int			x_handler(t_flags *flags, va_list argptr)
{
	int		arg;
	char	sym;
	int		caps;

	x_check_stars(flags, argptr);
	arg = va_arg(argptr, unsigned int);
	x_ignore_flags(flags);
	caps = flags->spec == 'x' ? 0 : 1;
	sym = flags->null ? '0' : ' ';
	if (!flags->minus)
		return (x_writer(flags, sym, arg, caps));
	else
		return (x_writer_minus(flags, sym, arg, caps));
}
