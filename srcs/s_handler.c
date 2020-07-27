/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_handler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctobias <ctobias@student.21.ru>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 22:57:56 by ctobias           #+#    #+#             */
/*   Updated: 2020/07/28 02:58:52 by ctobias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		s_null_writer(t_flags *flags, int max_s)
{
	int i;

	i = 0;
	if (!flags->minus && max_s >= 6)
	{
		i += (put_n_symbols(' ', flags->width - 6 - i));
		i += (ft_putstr(NULL, max_s));
	}
	else if (max_s >= 6)
	{
		i += ft_putstr(NULL, max_s);
		i += put_n_symbols(' ', flags->width - i);
	}
	else
		i += put_n_symbols(' ', flags->width - i);
	return (i);
}

int		s_null_handler(t_flags *flags)
{
	int i;
	int max_s;

	i = 0;
	if (flags->accuracy)
		max_s = flags->accuracy;
	else if (flags->point)
		max_s = 0;
	else
		max_s = 6;
	return (s_null_writer(flags, max_s));
}

int		s_writer(t_flags *flags, int max_s, void *arg)
{
	int i;
	int len;

	len = ft_strlen(arg);
	i = 0;
	if (flags->minus)
	{
		i += ft_putstr(arg, max_s);
		while (i < flags->width)
		{
			ft_putchar(' ');
			++i;
		}
	}
	else
	{
		while (i < flags->width - min_int(max_s, len))
		{
			ft_putchar(' ');
			++i;
		}
		i += ft_putstr(arg, max_s);
	}
	return (i);
}

int		s_handler(t_flags *flags, va_list argptr)
{
	void	*arg;
	int		i;
	int		max_s;
	int		len;

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
	arg = va_arg(argptr, void*);
	if (!arg)
		return (s_null_handler(flags));
	if (flags->accuracy)
		max_s = flags->accuracy;
	else if (flags->point)
		max_s = 0;
	else
		max_s = ft_strlen(arg);
	return (s_writer(flags, max_s, arg));
}
